// UART Receiver
// Receives 8N1 frame: start bit + 8 data bits + stop bit

module uart_rx #(
  parameter BAUD_DIV = 868
) (
  input  logic       clk_i,
  input  logic       rst_ni,
  input  logic       rx_i,    // serial input
  output logic [7:0] data_o,  // received byte
  output logic       valid_o  // pulse when byte ready
);

  // State machine
  typedef enum logic [1:0] {
    IDLE  = 2'b00,
    START = 2'b01,
    DATA  = 2'b10,
    STOP  = 2'b11
  } state_t;

  state_t      state;
  logic [9:0]  baud_cnt;
  logic [2:0]  bit_cnt;
  logic [7:0]  rx_shift;
  logic        rx_sync;    // synchronized rx input

  // Synchronize rx input to avoid metastability
  logic rx_ff1, rx_ff2;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rx_ff1 <= 1'b1;
      rx_ff2 <= 1'b1;
    end else begin
      rx_ff1 <= rx_i;
      rx_ff2 <= rx_ff1;
    end
  end
  assign rx_sync = rx_ff2;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state    <= IDLE;
      baud_cnt <= '0;
      bit_cnt  <= '0;
      rx_shift <= '0;
      data_o   <= '0;
      valid_o  <= 1'b0;
    end else begin
      valid_o <= 1'b0; // default

      case (state)

        IDLE: begin
          if (!rx_sync) begin // detect start bit (falling edge)
            baud_cnt <= '0;
            state    <= START;
          end
        end

        START: begin
          // Sample in middle of start bit
          if (baud_cnt == (BAUD_DIV/2) - 1) begin
            if (!rx_sync) begin // confirm start bit
              baud_cnt <= '0;
              bit_cnt  <= '0;
              state    <= DATA;
            end else begin
              state <= IDLE; // false start
            end
          end else begin
            baud_cnt <= baud_cnt + 1;
          end
        end

        DATA: begin
          if (baud_cnt == BAUD_DIV - 1) begin
            baud_cnt <= '0;
            rx_shift <= {rx_sync, rx_shift[7:1]}; // LSB first
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
          if (baud_cnt == BAUD_DIV - 1) begin
            baud_cnt <= '0;
            if (rx_sync) begin // valid stop bit
              data_o  <= rx_shift;
              valid_o <= 1'b1;
            end
            state <= IDLE;
          end else begin
            baud_cnt <= baud_cnt + 1;
          end
        end

      endcase
    end
  end

endmodule