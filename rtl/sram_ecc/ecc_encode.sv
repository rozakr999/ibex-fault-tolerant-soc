// SEC-DED ECC Encoder
// Generates 7 parity check bits for 32-bit data
// Uses Hamming(39,32) code

module ecc_encode (
  input  logic [31:0] data_i,
  output logic [6:0]  ecc_o
);

  // Parity bits P1-P6 + overall parity P7
  // Bit positions in Hamming code (1-indexed):
  // P1=1, P2=2, P3=4, P4=8, P5=16, P6=32, P7=overall

  logic p1, p2, p3, p4, p5, p6, p7;

  // P1 covers bits at positions with bit0=1: 1,3,5,7,9,11...
  assign p1 = data_i[0]  ^ data_i[1]  ^ data_i[3]  ^ data_i[4]  ^
              data_i[6]  ^ data_i[8]  ^ data_i[10] ^ data_i[11] ^
              data_i[13] ^ data_i[15] ^ data_i[17] ^ data_i[19] ^
              data_i[21] ^ data_i[23] ^ data_i[25] ^ data_i[26] ^
              data_i[28] ^ data_i[30];

  // P2 covers bits at positions with bit1=1: 2,3,6,7,10,11...
  assign p2 = data_i[0]  ^ data_i[2]  ^ data_i[3]  ^ data_i[5]  ^
              data_i[6]  ^ data_i[9]  ^ data_i[10] ^ data_i[12] ^
              data_i[13] ^ data_i[16] ^ data_i[17] ^ data_i[20] ^
              data_i[21] ^ data_i[24] ^ data_i[25] ^ data_i[27] ^
              data_i[28] ^ data_i[31];

  // P3 covers bits at positions with bit2=1: 4,5,6,7,12,13...
  assign p3 = data_i[1]  ^ data_i[2]  ^ data_i[3]  ^ data_i[7]  ^
              data_i[8]  ^ data_i[9]  ^ data_i[10] ^ data_i[14] ^
              data_i[15] ^ data_i[16] ^ data_i[17] ^ data_i[22] ^
              data_i[23] ^ data_i[24] ^ data_i[25] ^ data_i[29] ^
              data_i[30] ^ data_i[31];

  // P4 covers bits at positions with bit3=1: 8-15, 24-31
  assign p4 = data_i[4]  ^ data_i[5]  ^ data_i[6]  ^ data_i[7]  ^
              data_i[8]  ^ data_i[9]  ^ data_i[10] ^ data_i[18] ^
              data_i[19] ^ data_i[20] ^ data_i[21] ^ data_i[22] ^
              data_i[23] ^ data_i[24] ^ data_i[25];

  // P5 covers bits at positions with bit4=1: 16-31
  assign p5 = data_i[11] ^ data_i[12] ^ data_i[13] ^ data_i[14] ^
              data_i[15] ^ data_i[16] ^ data_i[17] ^ data_i[18] ^
              data_i[19] ^ data_i[20] ^ data_i[21] ^ data_i[22] ^
              data_i[23] ^ data_i[24] ^ data_i[25];

  // P6 covers bits at positions with bit5=1: 32-63
  assign p6 = data_i[26] ^ data_i[27] ^ data_i[28] ^ data_i[29] ^
              data_i[30] ^ data_i[31];

  // P7 overall parity (for double error detection)
  assign p7 = ^data_i ^ p1 ^ p2 ^ p3 ^ p4 ^ p5 ^ p6;

  assign ecc_o = {p7, p6, p5, p4, p3, p2, p1};

endmodule