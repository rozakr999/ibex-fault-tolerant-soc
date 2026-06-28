// GPIO Testbench
// Tests GPIO output, input, and direction control

#include "Vgpio_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

vluint64_t sim_time = 0;

void tick(Vgpio_top* dut, VerilatedVcdC* vcd) {
    dut->clk_i = 0;
    dut->eval();
    vcd->dump(sim_time++);
    dut->clk_i = 1;
    dut->eval();
    vcd->dump(sim_time++);
}

void write_reg(Vgpio_top* dut, VerilatedVcdC* vcd,
               uint8_t addr, uint32_t data) {
    dut->we_i    = 1;
    dut->addr_i  = addr;
    dut->wdata_i = data;
    tick(dut, vcd);
    dut->we_i = 0;
}

uint32_t read_reg(Vgpio_top* dut, VerilatedVcdC* vcd,
                  uint8_t addr) {
    dut->we_i   = 0;
    dut->addr_i = addr;
    tick(dut, vcd);
    return dut->rdata_o;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vgpio_top* dut = new Vgpio_top;
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 5);
    vcd->open("gpio_wave.vcd");

    // Reset
    dut->rst_ni   = 0;
    dut->we_i     = 0;
    dut->wdata_i  = 0;
    dut->addr_i   = 0;
    dut->gpio_in_i = 0;
    for (int i = 0; i < 5; i++) tick(dut, vcd);
    dut->rst_ni = 1;
    tick(dut, vcd);

    std::cout << "=== GPIO Test ===" << std::endl;
    bool pass = true;

    // Test 1: Set all pins as output
    std::cout << "\nTest 1: Set all pins as output" << std::endl;
    write_reg(dut, vcd, 0x8, 0xFFFF); // OE = all outputs
    tick(dut, vcd);
    if (dut->gpio_oe_o == 0xFFFF) {
        std::cout << "✅ OE register = 0xFFFF PASS" << std::endl;
    } else {
        std::cout << "❌ OE register FAIL: got "
                  << std::hex << dut->gpio_oe_o << std::endl;
        pass = false;
    }

    // Test 2: Write output data
    std::cout << "\nTest 2: Write 0xABCD to output" << std::endl;
    write_reg(dut, vcd, 0x0, 0xABCD); // DATA_OUT
    tick(dut, vcd);
    if (dut->gpio_out_o == 0xABCD) {
        std::cout << "✅ GPIO output = 0xABCD PASS" << std::endl;
    } else {
        std::cout << "❌ GPIO output FAIL: got "
                  << std::hex << dut->gpio_out_o << std::endl;
        pass = false;
    }

    // Test 3: Read input pins
    std::cout << "\nTest 3: Read input pins = 0x1234" << std::endl;
    dut->gpio_in_i = 0x1234;
    tick(dut, vcd);
    uint32_t read_val = read_reg(dut, vcd, 0x4); // DATA_IN
    if ((read_val & 0xFFFF) == 0x1234) {
        std::cout << "✅ GPIO input = 0x1234 PASS" << std::endl;
    } else {
        std::cout << "❌ GPIO input FAIL: got "
                  << std::hex << read_val << std::endl;
        pass = false;
    }

    // Test 4: Mixed direction
    std::cout << "\nTest 4: Lower 8 output, upper 8 input" << std::endl;
    write_reg(dut, vcd, 0x8, 0x00FF); // lower 8 = output
    write_reg(dut, vcd, 0x0, 0x0055); // output 0x55
    tick(dut, vcd);
    if (dut->gpio_out_o == 0x0055 && dut->gpio_oe_o == 0x00FF) {
        std::cout << "✅ Mixed direction PASS" << std::endl;
    } else {
        std::cout << "❌ Mixed direction FAIL" << std::endl;
        pass = false;
    }

    // Summary
    std::cout << "\n=== GPIO Test Summary ===" << std::endl;
    if (pass)
        std::cout << "✅ ALL GPIO TESTS PASSED!" << std::endl;
    else
        std::cout << "❌ SOME GPIO TESTS FAILED!" << std::endl;

    vcd->close();
    delete dut;
    delete vcd;
    return pass ? 0 : 1;
}