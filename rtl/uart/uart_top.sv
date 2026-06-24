// UART Controller
// Supports 115200 baud rate at 100MHz clock
// 8 data bits, no parity, 1 stop bit (8N1)

module uart_top #(
  parameter CLK_FREQ  = 100_000_000, // 100 MHz
  parameter BAUD_RATE = 115_200
) (
  input  logic clk_i,
  input  logic rst_ni,

  // TL-UL Bus Interface
  input  logic        we_i,     // write enable
  input  logic [31:0] wdata_i,  // write data
  input  logic [3:0]  addr_i,   // register address
  output logic [31:0] rdata_o,  // read data

  // UART pins
  output logic tx_o,  // transmit pin
  input  logic rx_i   // receive pin
);

  // Baud rate divider
  localparam BAUD_DIV = CLK_FREQ / BAUD_RATE; // = 868

  // Register addresses
  localparam ADDR_TX_DATA  = 4'h0; // write TX data
  localparam ADDR_RX_DATA  = 4'h4; // read RX data
  localparam ADDR_STATUS   = 4'h8; // status register

  // Internal signals
  logic [7:0]  tx_data;
  logic        tx_valid;
  logic        tx_busy;

  logic [7:0]  rx_data;
  logic        rx_valid;

  // Status register
  // bit 0 = tx_busy
  // bit 1 = rx_valid

  // ── Register Write ──
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      tx_data  <= 8'h0;
      tx_valid <= 1'b0;
    end else begin
      tx_valid <= 1'b0; // pulse for one cycle
      if (we_i && addr_i == ADDR_TX_DATA) begin
        tx_data  <= wdata_i[7:0];
        tx_valid <= 1'b1;
      end
    end
  end

  // ── Register Read ──
  always_comb begin
    rdata_o = 32'h0;
    case (addr_i)
      ADDR_RX_DATA: rdata_o = {24'h0, rx_data};
      ADDR_STATUS:  rdata_o = {30'h0, rx_valid, tx_busy};
      default:      rdata_o = 32'h0;
    endcase
  end

  // ── TX Module ──
  uart_tx #(
    .BAUD_DIV(BAUD_DIV)
  ) u_uart_tx (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),
    .data_i   (tx_data),
    .valid_i  (tx_valid),
    .busy_o   (tx_busy),
    .tx_o     (tx_o)
  );

  // ── RX Module ──
  uart_rx #(
    .BAUD_DIV(BAUD_DIV)
  ) u_uart_rx (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),
    .rx_i     (rx_i),
    .data_o   (rx_data),
    .valid_o  (rx_valid)
  );

endmodule