// GPIO Controller
// 16-bit bidirectional general purpose I/O
// Each pin can be configured as input or output

module gpio_top (
  input  logic        clk_i,
  input  logic        rst_ni,

  // TL-UL Bus Interface
  input  logic        we_i,
  input  logic [31:0] wdata_i,
  input  logic [3:0]  addr_i,
  output logic [31:0] rdata_o,

  // GPIO pins
  input  logic [15:0] gpio_in_i,
  output logic [15:0] gpio_out_o,
  output logic [15:0] gpio_oe_o
);

  // Register addresses
  localparam ADDR_DATA_OUT = 4'h0;
  localparam ADDR_DATA_IN  = 4'h4;
  localparam ADDR_OE       = 4'h8;

  // Registers
  logic [15:0] data_out_reg;
  logic [15:0] oe_reg;

  // Write
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      data_out_reg <= 16'h0;
      oe_reg       <= 16'h0;
    end else begin
      if (we_i) begin
        case (addr_i)
          ADDR_DATA_OUT: data_out_reg <= wdata_i[15:0];
          ADDR_OE:       oe_reg       <= wdata_i[15:0];
          default: ;
        endcase
      end
    end
  end

  // Read
  always_comb begin
    rdata_o = 32'h0;
    case (addr_i)
      ADDR_DATA_OUT: rdata_o = {16'h0, data_out_reg};
      ADDR_DATA_IN:  rdata_o = {16'h0, gpio_in_i};
      ADDR_OE:       rdata_o = {16'h0, oe_reg};
      default:       rdata_o = 32'h0;
    endcase
  end

  assign gpio_out_o = data_out_reg;
  assign gpio_oe_o  = oe_reg;

endmodule