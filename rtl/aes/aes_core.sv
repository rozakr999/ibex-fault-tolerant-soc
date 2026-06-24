// AES-128 Core
// Performs AES encryption
// 10 rounds, 128-bit key and data

import aes_pkg::*;

module aes_core (
  input  logic          clk_i,
  input  logic          rst_ni,
  input  logic          start_i,        // pulse to start
  input  logic [127:0]  key_i,          // 128-bit key
  input  logic [127:0]  plaintext_i,    // 128-bit plaintext
  output logic [127:0]  ciphertext_o,   // 128-bit ciphertext
  output logic          done_o          // pulse when done
);

  // State types
  typedef enum logic [1:0] {
    IDLE    = 2'b00,
    ROUNDS  = 2'b01,
    DONE    = 2'b10
  } state_t;

  state_t state;

  // AES state (4x4 bytes)
  logic [7:0] aes_state [0:3][0:3];
  logic [7:0] round_key [0:3][0:3];
  logic [3:0] round_cnt;

  // Key schedule storage (11 round keys x 16 bytes)
  logic [7:0] key_sched [0:10][0:3][0:3];

  // ── Functions ──

  // GF(2^8) multiplication by 2
  function automatic logic [7:0] xtime(input logic [7:0] a);
    return (a[7]) ? ((a << 1) ^ 8'h1b) : (a << 1);
  endfunction

  // MixColumns single column
  function automatic logic [31:0] mix_col(input logic [7:0] s0, s1, s2, s3);
    logic [7:0] r0, r1, r2, r3;
    r0 = xtime(s0) ^ (xtime(s1) ^ s1) ^ s2 ^ s3;
    r1 = s0 ^ xtime(s1) ^ (xtime(s2) ^ s2) ^ s3;
    r2 = s0 ^ s1 ^ xtime(s2) ^ (xtime(s3) ^ s3);
    r3 = (xtime(s0) ^ s0) ^ s1 ^ s2 ^ xtime(s3);
    return {r0, r1, r2, r3};
  endfunction

  // ── Key Expansion ──
  task automatic expand_key(input logic [127:0] key);
    integer i, j;
    logic [7:0] temp [0:3];
    logic [7:0] prev [0:3][0:3];

    // Round 0 key = original key
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        key_sched[0][j][i] = key[127 - (i*32 + j*8) -: 8];

    // Generate round keys 1-10
    for (int r = 1; r <= 10; r++) begin
      // RotWord + SubWord + Rcon on last word
      temp[0] = sbox(key_sched[r-1][1][3]) ^ RCON[r-1];
      temp[1] = sbox(key_sched[r-1][2][3]);
      temp[2] = sbox(key_sched[r-1][3][3]);
      temp[3] = sbox(key_sched[r-1][0][3]);

      for (j = 0; j < 4; j++)
        key_sched[r][j][0] = key_sched[r-1][j][0] ^ temp[j];

      for (i = 1; i < 4; i++)
        for (j = 0; j < 4; j++)
          key_sched[r][j][i] = key_sched[r-1][j][i] ^ key_sched[r][j][i-1];
    end
  endtask

  // ── Main FSM ──
  always_ff @(posedge clk_i or negedge rst_ni) begin
    integer i, j;
    logic [31:0] mixed;

    if (!rst_ni) begin
      state         <= IDLE;
      done_o        <= 1'b0;
      round_cnt     <= 4'h0;
      ciphertext_o  <= 128'h0;
    end else begin
      done_o <= 1'b0;

      case (state)

        IDLE: begin
          if (start_i) begin
            // Load plaintext into state
            for (i = 0; i < 4; i++)
              for (j = 0; j < 4; j++)
                aes_state[j][i] <= plaintext_i[127-(i*32+j*8) -: 8];

            // Expand key
            expand_key(key_i);

            // Initial AddRoundKey
            for (i = 0; i < 4; i++)
              for (j = 0; j < 4; j++)
                aes_state[j][i] <= plaintext_i[127-(i*32+j*8) -: 8]
                                    ^ key_sched[0][j][i];
            round_cnt <= 4'h1;
            state     <= ROUNDS;
          end
        end

        ROUNDS: begin
          // SubBytes
          for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
              aes_state[i][j] <= sbox(aes_state[i][j]);

          // ShiftRows
          begin
            logic [7:0] tmp;
            // Row 1: shift left by 1
            tmp = aes_state[1][0];
            aes_state[1][0] <= aes_state[1][1];
            aes_state[1][1] <= aes_state[1][2];
            aes_state[1][2] <= aes_state[1][3];
            aes_state[1][3] <= tmp;
            // Row 2: shift left by 2
            tmp = aes_state[2][0];
            aes_state[2][0] <= aes_state[2][2];
            aes_state[2][2] <= tmp;
            tmp = aes_state[2][1];
            aes_state[2][1] <= aes_state[2][3];
            aes_state[2][3] <= tmp;
            // Row 3: shift left by 3
            tmp = aes_state[3][3];
            aes_state[3][3] <= aes_state[3][2];
            aes_state[3][2] <= aes_state[3][1];
            aes_state[3][1] <= aes_state[3][0];
            aes_state[3][0] <= tmp;
          end

          // MixColumns (skip in last round)
          if (round_cnt < 4'd10) begin
            for (i = 0; i < 4; i++) begin
              mixed = mix_col(
                aes_state[0][i],
                aes_state[1][i],
                aes_state[2][i],
                aes_state[3][i]
              );
              aes_state[0][i] <= mixed[31:24];
              aes_state[1][i] <= mixed[23:16];
              aes_state[2][i] <= mixed[15:8];
              aes_state[3][i] <= mixed[7:0];
            end
          end

          // AddRoundKey
          for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
              aes_state[j][i] <= aes_state[j][i]
                                  ^ key_sched[round_cnt][j][i];

          if (round_cnt == 4'd10) begin
            state <= DONE;
          end else begin
            round_cnt <= round_cnt + 1;
          end
        end

        DONE: begin
          // Collect output
          for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
              ciphertext_o[127-(i*32+j*8) -: 8] <= aes_state[j][i];
          done_o <= 1'b1;
          state  <= IDLE;
        end

      endcase
    end
  end

endmodule