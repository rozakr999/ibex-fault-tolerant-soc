// Timer Testbench
// Tests timer count, compare, and interrupt

#include "Vtimer_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

vluint64_t sim_time = 0;

void tick(Vtimer_top* dut, VerilatedVcdC* vcd) {
    dut->clk_i = 0;
    dut->eval();
    vcd->dump(sim_time++);
    dut->clk_i = 1;
    dut->eval();
    vcd->dump(sim_time++);
}

void write_reg(Vtimer_top* dut, VerilatedVcdC* vcd,
               uint8_t addr, uint32_t data) {
    dut->we_i    = 1;
    dut->addr_i  = addr;
    dut->wdata_i = data;
    tick(dut, vcd);
    dut->we_i = 0;
}

uint32_t read_reg(Vtimer_top* dut, VerilatedVcdC* vcd,
                  uint8_t addr) {
    dut->we_i   = 0;
    dut->addr_i = addr;
    tick(dut, vcd);
    return dut->rdata_o;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtimer_top* dut = new Vtimer_top;
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 5);
    vcd->open("timer_wave.vcd");

    // Reset
    dut->rst_ni  = 0;
    dut->we_i    = 0;
    dut->wdata_i = 0;
    dut->addr_i  = 0;
    for (int i = 0; i < 5; i++) tick(dut, vcd);
    dut->rst_ni = 1;
    tick(dut, vcd);

    std::cout << "=== Timer Test ===" << std::endl;
    bool pass = true;

    // Test 1: Set compare value to 10
    std::cout << "\nTest 1: Set compare = 10" << std::endl;
    write_reg(dut, vcd, 0x8, 10); // COMPARE = 10
    tick(dut, vcd);

    // Test 2: Enable timer with interrupt
    std::cout << "Test 2: Enable timer + interrupt" << std::endl;
    write_reg(dut, vcd, 0x0, 0x3); // CTRL = enable + intr_en
    tick(dut, vcd);

    // Test 3: Wait for counter to reach compare value
    std::cout << "Test 3: Waiting for interrupt..." << std::endl;
    bool intr_fired = false;
    for (int i = 0; i < 20; i++) {
        tick(dut, vcd);
        if (dut->intr_o) {
            intr_fired = true;
            uint32_t count = read_reg(dut, vcd, 0x4);
            std::cout << "✅ Interrupt fired at count = "
                      << count << std::endl;
            break;
        }
    }
    if (!intr_fired) {
        std::cout << "❌ Interrupt never fired!" << std::endl;
        pass = false;
    }

    // Test 4: Counter resets after compare
    std::cout << "\nTest 4: Counter resets after compare" << std::endl;
    uint32_t count = read_reg(dut, vcd, 0x4);
    std::cout << "Count after reset: " << count << std::endl;
    if (count < 10) {
        std::cout << "✅ Counter reset PASS" << std::endl;
    } else {
        std::cout << "❌ Counter reset FAIL" << std::endl;
        pass = false;
    }

    // Test 5: Clear interrupt
    std::cout << "\nTest 5: Clear interrupt" << std::endl;
    write_reg(dut, vcd, 0xC, 0x1); // write STATUS to clear
    tick(dut, vcd);
    if (!dut->intr_o) {
        std::cout << "✅ Interrupt cleared PASS" << std::endl;
    } else {
        std::cout << "❌ Interrupt clear FAIL" << std::endl;
        pass = false;
    }

    // Test 6: Stop timer
    std::cout << "\nTest 6: Stop timer" << std::endl;
    write_reg(dut, vcd, 0x0, 0x0); // CTRL = disable
    uint32_t count_before = read_reg(dut, vcd, 0x4);
    for (int i = 0; i < 5; i++) tick(dut, vcd);
    uint32_t count_after = read_reg(dut, vcd, 0x4);
    if (count_before == count_after) {
        std::cout << "✅ Timer stopped PASS" << std::endl;
    } else {
        std::cout << "❌ Timer stopped FAIL" << std::endl;
        pass = false;
    }

    // Summary
    std::cout << "\n=== Timer Test Summary ===" << std::endl;
    if (pass)
        std::cout << "✅ ALL TIMER TESTS PASSED!" << std::endl;
    else
        std::cout << "❌ SOME TIMER TESTS FAILED!" << std::endl;

    vcd->close();
    delete dut;
    delete vcd;
    return pass ? 0 : 1;
}