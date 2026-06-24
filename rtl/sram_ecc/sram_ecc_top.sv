// SRAM Controller with SEC-DED ECC
// - 32-bit data width
// - 256 depth (256 x 32-bit words)
// - SEC-DED ECC (Single Error Correct, Double Error Detect)
// - 7 check bits for 32-bit data (Hamming code)

module sram_ecc_top (
  input  logic        clk_i,
  input  logic        rst_ni,

  // TL-UL Bus Interface
  input  logic        we_i,
  input  logic [31:0] wdata_i,
  input  logic [7:0]  addr_i,
  output logic [31:0] rdata_o,

  // ECC status
  output logic        single_err_o,  // single bit error corrected
  output logic        double_err_o   // double bit error detected
);

  // Internal signals
  logic [6:0]  ecc_encode_out;   // 7 check bits
  logic [38:0] sram_wdata;       // 32 data + 7 ECC bits
  logic [38:0] sram_rdata;       // raw read data
  logic [31:0] corrected_data;   // corrected output
  logic        single_err;
  logic        double_err;

  // SRAM array (256 x 39 bits — 32 data + 7 ECC)
  logic [38:0] mem [0:255];

  // ── ECC Encode on Write ──
  ecc_encode u_ecc_encode (
    .data_i (wdata_i),
    .ecc_o  (ecc_encode_out)
  );

  assign sram_wdata = {ecc_encode_out, wdata_i};

  // ── SRAM Write ──
  always_ff @(posedge clk_i) begin
    if (we_i) begin
      mem[addr_i] <= sram_wdata;
    end
  end

  // ── SRAM Read ──
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      sram_rdata <= 39'h0;
    end else begin
      sram_rdata <= mem[addr_i];
    end
  end

  // ── ECC Decode on Read ──
  ecc_decode u_ecc_decode (
    .data_i       (sram_rdata[31:0]),
    .ecc_i        (sram_rdata[38:32]),
    .data_o       (corrected_data),
    .single_err_o (single_err),
    .double_err_o (double_err)
  );

  // ── Output ──
  assign rdata_o      = corrected_data;
  assign single_err_o = single_err;
  assign double_err_o = double_err;

endmodule