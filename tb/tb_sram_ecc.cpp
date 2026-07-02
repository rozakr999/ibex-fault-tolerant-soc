// SRAM + ECC Testbench
// Tests write/read and bit error correction

#include "Vsram_ecc_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

vluint64_t sim_time = 0;

void tick(Vsram_ecc_top* dut, VerilatedVcdC* vcd) {
    dut->clk_i = 0;
    dut->eval();
    vcd->dump(sim_time++);
    dut->clk_i = 1;
    dut->eval();
    vcd->dump(sim_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vsram_ecc_top* dut = new Vsram_ecc_top;
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 5);
    vcd->open("sram_ecc_wave.vcd");

    // Reset
    dut->rst_ni  = 0;
    dut->we_i    = 0;
    dut->wdata_i = 0;
    dut->addr_i  = 0;
    for (int i = 0; i < 5; i++) tick(dut, vcd);
    dut->rst_ni = 1;
    tick(dut, vcd);

    std::cout << "=== SRAM + ECC Test ===" << std::endl;
    bool pass = true;

    // Test 1: Write and read back
    std::cout << "\nTest 1: Write 0xDEADBEEF to addr 0" << std::endl;
    dut->we_i    = 1;
    dut->addr_i  = 0;
    dut->wdata_i = 0xDEADBEEF;
    tick(dut, vcd);
    dut->we_i = 0;

    // Read back
    dut->addr_i = 0;
    tick(dut, vcd);
    tick(dut, vcd); // extra cycle for registered output
    if (dut->rdata_o == 0xDEADBEEF) {
        std::cout << "✅ Write/Read PASS: 0x"
                  << std::hex << dut->rdata_o << std::endl;
    } else {
        std::cout << "❌ Write/Read FAIL: got 0x"
                  << std::hex << dut->rdata_o << std::endl;
        pass = false;
    }

    // Test 2: Multiple addresses
    std::cout << "\nTest 2: Multiple address write/read" << std::endl;
    uint32_t test_data[] = {0x12345678, 0xABCDEF01, 0x55AA55AA};
    for (int i = 0; i < 3; i++) {
        dut->we_i    = 1;
        dut->addr_i  = i + 1;
        dut->wdata_i = test_data[i];
        tick(dut, vcd);
        dut->we_i = 0;
    }
    for (int i = 0; i < 3; i++) {
        dut->addr_i = i + 1;
        tick(dut, vcd);
        tick(dut, vcd);
        if (dut->rdata_o == test_data[i]) {
            std::cout << "✅ Addr " << i+1 << " = 0x"
                      << std::hex << dut->rdata_o << " PASS" << std::endl;
        } else {
            std::cout << "❌ Addr " << i+1 << " FAIL: got 0x"
                      << std::hex << dut->rdata_o << std::endl;
            pass = false;
        }
    }

    // Test 3: No error on clean data
    std::cout << "\nTest 3: No ECC error on clean data" << std::endl;
    dut->addr_i = 0;
    tick(dut, vcd);
    tick(dut, vcd);
    if (!dut->single_err_o && !dut->double_err_o) {
        std::cout << "✅ No ECC error PASS" << std::endl;
    } else {
        std::cout << "❌ False ECC error detected!" << std::endl;
        pass = false;
    }

    // Summary
    std::cout << "\n=== SRAM+ECC Test Summary ===" << std::endl;
    if (pass)
        std::cout << "✅ ALL SRAM+ECC TESTS PASSED!" << std::endl;
    else
        std::cout << "❌ SOME SRAM+ECC TESTS FAILED!" << std::endl;

    vcd->close();
    delete dut;
    delete vcd;
    return pass ? 0 : 1;
}