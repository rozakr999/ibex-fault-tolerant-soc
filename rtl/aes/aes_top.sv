// AES Top Module
// TL-UL bus interface to AES core

module aes_top (
  input  logic        clk_i,
  input  logic        rst_ni,

  // TL-UL Bus Interface
  input  logic        we_i,
  input  logic [31:0] wdata_i,
  input  logic [5:0]  addr_i,
  output logic [31:0] rdata_o,

  // Interrupt
  output logic        intr_o
);

  // Register addresses
  localparam ADDR_KEY_0    = 6'h00; // key word 0 (bits 127:96)
  localparam ADDR_KEY_1    = 6'h04; // key word 1 (bits 95:64)
  localparam ADDR_KEY_2    = 6'h08; // key word 2 (bits 63:32)
  localparam ADDR_KEY_3    = 6'h0C; // key word 3 (bits 31:0)
  localparam ADDR_DATA_0   = 6'h10; // plaintext word 0
  localparam ADDR_DATA_1   = 6'h14; // plaintext word 1
  localparam ADDR_DATA_2   = 6'h18; // plaintext word 2
  localparam ADDR_DATA_3   = 6'h1C; // plaintext word 3
  localparam ADDR_CTRL     = 6'h20; // control (bit0=start)
  localparam ADDR_STATUS   = 6'h24; // status (bit0=done)
  localparam ADDR_RESULT_0 = 6'h28; // ciphertext word 0
  localparam ADDR_RESULT_1 = 6'h2C; // ciphertext word 1
  localparam ADDR_RESULT_2 = 6'h30; // ciphertext word 2
  localparam ADDR_RESULT_3 = 6'h34; // ciphertext word 3

  // Registers
  logic [127:0] key_reg;
  logic [127:0] plaintext_reg;
  logic [127:0] ciphertext_reg;
  logic         start_reg;
  logic         done_flag;

  // AES core signals
  logic [127:0] core_ciphertext;
  logic         core_done;

  // ── AES Core Instance ──
  aes_core u_aes_core (
    .clk_i        (clk_i),
    .rst_ni       (rst_ni),
    .start_i      (start_reg),
    .key_i        (key_reg),
    .plaintext_i  (plaintext_reg),
    .ciphertext_o (core_ciphertext),
    .done_o       (core_done)
  );

  // ── Register Write ──
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      key_reg       <= 128'h0;
      plaintext_reg <= 128'h0;
      start_reg     <= 1'b0;
      done_flag     <= 1'b0;
      ciphertext_reg <= 128'h0;
    end else begin
      start_reg <= 1'b0; // pulse

      if (core_done) begin
        ciphertext_reg <= core_ciphertext;
        done_flag      <= 1'b1;
      end

      if (we_i) begin
        case (addr_i)
          ADDR_KEY_0:  key_reg[127:96] <= wdata_i;
          ADDR_KEY_1:  key_reg[95:64]  <= wdata_i;
          ADDR_KEY_2:  key_reg[63:32]  <= wdata_i;
          ADDR_KEY_3:  key_reg[31:0]   <= wdata_i;
          ADDR_DATA_0: plaintext_reg[127:96] <= wdata_i;
          ADDR_DATA_1: plaintext_reg[95:64]  <= wdata_i;
          ADDR_DATA_2: plaintext_reg[63:32]  <= wdata_i;
          ADDR_DATA_3: plaintext_reg[31:0]   <= wdata_i;
          ADDR_CTRL: begin
            if (wdata_i[0]) begin
              start_reg <= 1'b1;
              done_flag <= 1'b0;
            end
          end
          default: ;
        endcase
      end
    end
  end

  // ── Register Read ──
  always_comb begin
    rdata_o = 32'h0;
    case (addr_i)
      ADDR_KEY_0:    rdata_o = key_reg[127:96];
      ADDR_KEY_1:    rdata_o = key_reg[95:64];
      ADDR_KEY_2:    rdata_o = key_reg[63:32];
      ADDR_KEY_3:    rdata_o = key_reg[31:0];
      ADDR_STATUS:   rdata_o = {31'h0, done_flag};
      ADDR_RESULT_0: rdata_o = ciphertext_reg[127:96];
      ADDR_RESULT_1: rdata_o = ciphertext_reg[95:64];
      ADDR_RESULT_2: rdata_o = ciphertext_reg[63:32];
      ADDR_RESULT_3: rdata_o = ciphertext_reg[31:0];
      default:       rdata_o = 32'h0;
    endcase
  end

  assign intr_o = done_flag;

endmodule