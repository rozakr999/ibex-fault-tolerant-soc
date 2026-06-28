// UART Testbench
// Tests UART TX by sending a byte and checking the serial output

#include "Vuart_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <bitset>

#define CLK_PERIOD 10    // 10ns clock period
#define BAUD_DIV   868   // 100MHz / 115200

vluint64_t sim_time = 0;

void tick(Vuart_top* dut, VerilatedVcdC* vcd) {
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

    // Create DUT
    Vuart_top* dut = new Vuart_top;

    // Create VCD trace
    VerilatedVcdC* vcd = new VerilatedVcdC;
    dut->trace(vcd, 5);
    vcd->open("uart_wave.vcd");

    // Reset
    dut->rst_ni  = 0;
    dut->we_i    = 0;
    dut->wdata_i = 0;
    dut->addr_i  = 0;
    dut->rx_i    = 1; // idle high

    for (int i = 0; i < 10; i++) tick(dut, vcd);
    dut->rst_ni = 1;

    std::cout << "=== UART TX Test ===" << std::endl;
    std::cout << "Sending byte: 0x55 (01010101)" << std::endl;

    // Write 0x55 to TX data register (addr 0x0)
    dut->we_i    = 1;
    dut->addr_i  = 0x0;
    dut->wdata_i = 0x55;
    tick(dut, vcd);
    dut->we_i = 0;

    // Wait for transmission to complete
    // Each bit takes BAUD_DIV cycles
    // Total: start + 8 data + stop = 10 bits x 868 cycles
    int tx_bits[10];
    int bit_idx = 0;
    int wait_cnt = 0;
    bool started = false;

    for (int i = 0; i < BAUD_DIV * 12; i++) {
        tick(dut, vcd);

        // Sample TX at middle of each bit period
        if (!started && dut->tx_o == 0) {
            started = true; // detected start bit
            wait_cnt = BAUD_DIV / 2;
        }

        if (started && wait_cnt > 0) {
            wait_cnt--;
            if (wait_cnt == 0 && bit_idx < 10) {
                tx_bits[bit_idx++] = dut->tx_o;
                wait_cnt = BAUD_DIV;
            }
        }
    }

    // Check results
    std::cout << "Captured bits (start+data+stop): ";
    for (int i = 0; i < 10; i++)
        std::cout << tx_bits[i];
    std::cout << std::endl;

    // Expected: start=0, data=01010101 (LSB first), stop=1
    int expected[10] = {0, 1,0,1,0,1,0,1,0, 1};
    bool pass = true;
    for (int i = 0; i < 10; i++) {
        if (tx_bits[i] != expected[i]) {
            pass = false;
            std::cout << "FAIL at bit " << i
                      << ": got " << tx_bits[i]
                      << " expected " << expected[i] << std::endl;
        }
    }

    if (pass)
        std::cout << "✅ UART TX PASS!" << std::endl;
    else
        std::cout << "❌ UART TX FAIL!" << std::endl;

    vcd->close();
    delete dut;
    delete vcd;
    return pass ? 0 : 1;
}