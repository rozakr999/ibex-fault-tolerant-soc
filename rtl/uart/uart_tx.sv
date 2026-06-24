// UART Transmitter
// Sends 8N1 frame: start bit + 8 data bits + stop bit

module uart_tx #(
  parameter BAUD_DIV = 868
) (
  input  logic       clk_i,
  input  logic       rst_ni,
  input  logic [7:0] data_i,   // byte to transmit
  input  logic       valid_i,  // pulse to start TX
  output logic       busy_o,   // 1 = transmitting
  output logic       tx_o      // serial output
);

  // State machine
  typedef enum logic [1:0] {
    IDLE  = 2'b00,
    START = 2'b01,
    DATA  = 2'b10,
    STOP  = 2'b11
  } state_t;

  state_t      state;
  logic [9:0]  baud_cnt;   // baud rate counter
  logic [2:0]  bit_cnt;    // bit counter (0-7)
  logic [7:0]  tx_shift;   // shift register

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state    <= IDLE;
      tx_o     <= 1'b1;  // idle high
      busy_o   <= 1'b0;
      baud_cnt <= '0;
      bit_cnt  <= '0;
      tx_shift <= '0;
    end else begin
      case (state)

        IDLE: begin
          tx_o   <= 1'b1;
          busy_o <= 1'b0;
          if (valid_i) begin
            tx_shift <= data_i;
            baud_cnt <= '0;
            state    <= START;
            busy_o   <= 1'b1;
          end
        end

        START: begin
          tx_o <= 1'b0; // start bit
          if (baud_cnt == BAUD_DIV - 1) begin
            baud_cnt <= '0;
            bit_cnt  <= '0;
            state    <= DATA;
          end else begin
            baud_cnt <= baud_cnt + 1;
          end
        end

        DATA: begin
          tx_o <= tx_shift[0]; // LSB first
          if (baud_cnt == BAUD_DIV - 1) begin
            baud_cnt <= '0;
            tx_shift <= {1'b0, tx_shift[7:1]};
            if (bit_cnt == 3'd7) begin
              state <= STOP;
            end else begin
              bit_cnt <= bit_cnt + 1;
            end
          end else begin
            baud_cnt <= baud_cnt + 1;
          end
        end

        STOP: begin
          tx_o <= 1'b1; // stop bit
          if (baud_cnt == BAUD_DIV - 1) begin
            baud_cnt <= '0;
            state    <= IDLE;
            busy_o   <= 1'b0;
          end else begin
            baud_cnt <= baud_cnt + 1;
          end
        end

      endcase
    end
  end

endmodule