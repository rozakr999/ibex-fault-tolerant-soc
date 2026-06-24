// SEC-DED ECC Decoder
// Corrects single bit errors, detects double bit errors

module ecc_decode (
  input  logic [31:0] data_i,       // raw data from SRAM
  input  logic [6:0]  ecc_i,        // stored ECC bits
  output logic [31:0] data_o,       // corrected data
  output logic        single_err_o, // single error corrected
  output logic        double_err_o  // double error detected
);

  logic [6:0]  ecc_recalc;  // recalculated ECC
  logic [5:0]  syndrome;    // error syndrome (which bit is wrong)
  logic        overall_p;   // overall parity check

  // Recalculate ECC from received data
  ecc_encode u_ecc_recheck (
    .data_i (data_i),
    .ecc_o  (ecc_recalc)
  );

  // Syndrome = recalculated ECC XOR stored ECC (bits 5:0 only)
  assign syndrome  = ecc_recalc[5:0] ^ ecc_i[5:0];

  // Overall parity check
  assign overall_p = ^data_i ^ ^ecc_i;

  // Error detection and correction
  always_comb begin
    data_o       = data_i;
    single_err_o = 1'b0;
    double_err_o = 1'b0;

    if (syndrome == 6'h0 && overall_p == 1'b0) begin
      // No error
      data_o       = data_i;
      single_err_o = 1'b0;
      double_err_o = 1'b0;

    end else if (syndrome != 6'h0 && overall_p == 1'b1) begin
      // Single bit error — correct it
      single_err_o    = 1'b1;
      data_o          = data_i;
      // Flip the erroneous bit
      if (syndrome <= 32)
        data_o[syndrome-1] = ~data_i[syndrome-1];

    end else begin
      // Double bit error — cannot correct
      data_o       = data_i;
      double_err_o = 1'b1;
    end
  end

endmodule