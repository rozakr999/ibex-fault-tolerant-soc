// Ibex Fault-Tolerant Security SoC Top Level
// Connects Ibex CPU to all peripherals via simple address decode
//
// Memory Map:
// 0x00000000 - 0x0000FFFF : Instruction SRAM (64KB)
// 0x10000000 - 0x100003FF : Data SRAM + ECC (1KB)
// 0x40000000 - 0x4000003F : AES Accelerator
// 0x40001000 - 0x4000100F : UART Controller
// 0x40002000 - 0x4000200F : GPIO Controller
// 0x40003000 - 0x4000300F : Timer

module ibex_soc_top (
  input  logic        clk_i,
  input  logic        rst_ni,

  // UART pins
  input  logic        uart_rx_i,
  output logic        uart_tx_o,

  // GPIO pins
  input  logic [15:0] gpio_in_i,
  output logic [15:0] gpio_out_o,
  output logic [15:0] gpio_oe_o,

  // Status LEDs
  output logic        ecc_single_err_o,
  output logic        ecc_double_err_o
);

  // ── Ibex instruction interface ──
  logic        instr_req;
  logic        instr_gnt;
  logic        instr_rvalid;
  logic [31:0] instr_addr;
  logic [31:0] instr_rdata;
  logic        instr_err;

  // ── Ibex data interface ──
  logic        data_req;
  logic        data_gnt;
  logic        data_rvalid;
  logic        data_we;
  logic [3:0]  data_be;
  logic [31:0] data_addr;
  logic [31:0] data_wdata;
  logic [31:0] data_rdata;
  logic        data_err;

  // ── Interrupt signals ──
  logic        timer_intr;
  logic        aes_intr;

  // ── Peripheral read data ──
  logic [31:0] aes_rdata;
  logic [31:0] uart_rdata;
  logic [31:0] gpio_rdata;
  logic [31:0] timer_rdata;
  logic [31:0] sram_rdata;

  // ── Address decode ──
  logic sel_aes, sel_uart, sel_gpio, sel_timer, sel_sram;

  assign sel_aes   = (data_addr[31:12] == 20'h40000);
  assign sel_uart  = (data_addr[31:12] == 20'h40001);
  assign sel_gpio  = (data_addr[31:12] == 20'h40002);
  assign sel_timer = (data_addr[31:12] == 20'h40003);
  assign sel_sram  = (data_addr[31:28] == 4'h1);

  // ── Read data mux ──
  always_comb begin
    data_rdata = 32'h0;
    if      (sel_aes)   data_rdata = aes_rdata;
    else if (sel_uart)  data_rdata = uart_rdata;
    else if (sel_gpio)  data_rdata = gpio_rdata;
    else if (sel_timer) data_rdata = timer_rdata;
    else if (sel_sram)  data_rdata = sram_rdata;
  end

  // ── Bus control ──
  // Simple single-cycle response
  assign data_gnt    = data_req;
  assign instr_gnt   = instr_req;
  assign instr_err   = 1'b0;
  assign data_err    = 1'b0;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      data_rvalid  <= 1'b0;
      instr_rvalid <= 1'b0;
    end else begin
      data_rvalid  <= data_req;
      instr_rvalid <= instr_req;
    end
  end

  // ── Instruction SRAM (64KB) ──
  logic [31:0] instr_mem [0:16383]; // 16K x 32-bit

  always_ff @(posedge clk_i) begin
    instr_rdata <= instr_mem[instr_addr[15:2]];
  end

  // ── Ibex Core Instance ──
  ibex_top #(
    .RV32M         (ibex_pkg::RV32MFast),
    .RV32B         (ibex_pkg::RV32BNone),
    .RegFile       (ibex_pkg::RegFileFF),
    .ICache        (1'b1),
    .ICacheECC     (1'b1),
    .BranchPredictor (1'b0)
  ) u_ibex (
    .clk_i              (clk_i),
    .rst_ni             (rst_ni),
    .test_en_i          (1'b0),
    .scan_rst_ni        (1'b1),
    .ram_cfg_i          ('0),
    .hart_id_i          (32'h0),
    .boot_addr_i        (32'h00000000),

    // Instruction interface
    .instr_req_o        (instr_req),
    .instr_gnt_i        (instr_gnt),
    .instr_rvalid_i     (instr_rvalid),
    .instr_addr_o       (instr_addr),
    .instr_rdata_i      (instr_rdata),
    .instr_rdata_intg_i ('0),
    .instr_err_i        (instr_err),

    // Data interface
    .data_req_o         (data_req),
    .data_gnt_i         (data_gnt),
    .data_rvalid_i      (data_rvalid),
    .data_we_o          (data_we),
    .data_be_o          (data_be),
    .data_addr_o        (data_addr),
    .data_wdata_o       (data_wdata),
    .data_wdata_intg_o  (),
    .data_rdata_i       (data_rdata),
    .data_rdata_intg_i  ('0),
    .data_err_i         (data_err),

    // Interrupts
    .irq_software_i     (1'b0),
    .irq_timer_i        (timer_intr),
    .irq_external_i     (aes_intr),
    .irq_fast_i         (15'h0),
    .irq_nm_i           (1'b0),

    // Debug
    .debug_req_i        (1'b0),
    .crash_dump_o       (),

    // CPU control
    .fetch_enable_i     (ibex_pkg::IbexMuBiOn),
    .alert_minor_o      (),
    .alert_major_internal_o (),
    .alert_major_bus_o  (),
    .core_sleep_o       ()
  );

  // ── AES Accelerator ──
  aes_top u_aes (
    .clk_i   (clk_i),
    .rst_ni  (rst_ni),
    .we_i    (data_we & sel_aes),
    .wdata_i (data_wdata),
    .addr_i  (data_addr[5:0]),
    .rdata_o (aes_rdata),
    .intr_o  (aes_intr)
  );

  // ── UART Controller ──
  uart_top u_uart (
    .clk_i   (clk_i),
    .rst_ni  (rst_ni),
    .we_i    (data_we & sel_uart),
    .wdata_i (data_wdata),
    .addr_i  (data_addr[3:0]),
    .rdata_o (uart_rdata),
    .tx_o    (uart_tx_o),
    .rx_i    (uart_rx_i)
  );

  // ── GPIO Controller ──
  gpio_top u_gpio (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),
    .we_i     (data_we & sel_gpio),
    .wdata_i  (data_wdata),
    .addr_i   (data_addr[3:0]),
    .rdata_o  (gpio_rdata),
    .gpio_in_i  (gpio_in_i),
    .gpio_out_o (gpio_out_o),
    .gpio_oe_o  (gpio_oe_o)
  );

  // ── Timer ──
  timer_top u_timer (
    .clk_i   (clk_i),
    .rst_ni  (rst_ni),
    .we_i    (data_we & sel_timer),
    .wdata_i (data_wdata),
    .addr_i  (data_addr[3:0]),
    .rdata_o (timer_rdata),
    .intr_o  (timer_intr)
  );

  // ── SRAM + ECC ──
  sram_ecc_top u_sram (
    .clk_i        (clk_i),
    .rst_ni       (rst_ni),
    .we_i         (data_we & sel_sram),
    .wdata_i      (data_wdata),
    .addr_i       (data_addr[9:2]),
    .rdata_o      (sram_rdata),
    .single_err_o (ecc_single_err_o),
    .double_err_o (ecc_double_err_o)
  );

endmodule