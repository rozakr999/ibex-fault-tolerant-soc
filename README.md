# Ibex Fault-Tolerant Security SoC

A fault-tolerant RISC-V SoC based on the OpenTitan Ibex core with hardware security acceleration.

## Architecture
+----------------+
            |   Ibex Core    |
            |  (RV32IMC)     |
            +----------------+
                    |
             TL-UL Crossbar
                    |
## Features
- Ibex RV32IMC @ 100 MHz
- AES-128/256 hardware accelerator
- ICache ECC (SEC-DED) — fault tolerant instruction cache
- SRAM with SEC-DED ECC — fault tolerant data memory
- UART, GPIO, Timer peripherals
- TL-UL bus interconnect

## Tools
- Simulation: Verilator + GTKWave
- Synthesis: Synopsys DC Compiler (SAED 32nm)
- Place & Route: Synopsys IC Compiler
- STA: Synopsys PrimeTime

## Project Structure
ibex_soc/

├── rtl/          # SystemVerilog RTL

│   ├── aes/      # AES accelerator

│   ├── uart/     # UART controller

│   ├── gpio/     # GPIO controller

│   ├── timer/    # Hardware timer

│   └── sram_ecc/ # SRAM with ECC

├── tb/           # Testbenches

├── syn/          # DC synthesis scripts

├── icc/          # ICC P&R scripts

└── pt/           # PrimeTime STA scripts

## Status
🚧 Work in progress