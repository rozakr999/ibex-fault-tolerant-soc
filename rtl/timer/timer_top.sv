// 32-bit Hardware Timer
// Features:
// - 32-bit up counter
// - Configurable compare value
// - Interrupt on match
// - Start/stop control

module timer_top (
  input  logic        clk_i,
  input  logic        rst_ni,

  // TL-UL Bus Interface
  input  logic        we_i,
  input  logic [31:0] wdata_i,
  input  logic [3:0]  addr_i,
  output logic [31:0] rdata_o,

  // Interrupt output
  output logic        intr_o
);

  // Register addresses
  localparam ADDR_CTRL    = 4'h0; // control register
  localparam ADDR_COUNT   = 4'h4; // current count (read only)
  localparam ADDR_COMPARE = 4'h8; // compare value
  localparam ADDR_STATUS  = 4'hC; // status register

  // Registers
  logic [31:0] count_reg;
  logic [31:0] compare_reg;
  logic        enable;      // bit 0 of ctrl
  logic        intr_en;     // bit 1 of ctrl
  logic        intr_flag;   // interrupt pending

  // ── Register Write ──
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      count_reg   <= 32'h0;
      compare_reg <= 32'hFFFF_FFFF;
      enable      <= 1'b0;
      intr_en     <= 1'b0;
      intr_flag   <= 1'b0;
    end else begin
      // Clear interrupt if status written
      if (we_i && addr_i == ADDR_STATUS) begin
        intr_flag <= 1'b0;
      end

      // Write control and compare registers
      if (we_i) begin
        case (addr_i)
          ADDR_CTRL: begin
            enable  <= wdata_i[0];
            intr_en <= wdata_i[1];
          end
          ADDR_COMPARE: compare_reg <= wdata_i;
          default: ;
        endcase
      end

      // Counter logic
      if (enable) begin
        if (count_reg == compare_reg) begin
          count_reg <= 32'h0;      // reset counter
          intr_flag <= intr_en;    // set interrupt if enabled
        end else begin
          count_reg <= count_reg + 1;
        end
      end
    end
  end

  // ── Register Read ──
  always_comb begin
    rdata_o = 32'h0;
    case (addr_i)
      ADDR_CTRL:    rdata_o = {30'h0, intr_en, enable};
      ADDR_COUNT:   rdata_o = count_reg;
      ADDR_COMPARE: rdata_o = compare_reg;
      ADDR_STATUS:  rdata_o = {31'h0, intr_flag};
      default:      rdata_o = 32'h0;
    endcase
  end

  // ── Interrupt output ──
  assign intr_o = intr_flag;

endmodule