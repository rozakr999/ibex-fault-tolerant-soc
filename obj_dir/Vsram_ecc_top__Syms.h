// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSRAM_ECC_TOP__SYMS_H_
#define VERILATED_VSRAM_ECC_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsram_ecc_top.h"

// INCLUDE MODULE CLASSES
#include "Vsram_ecc_top___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsram_ecc_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsram_ecc_top* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsram_ecc_top___024root        TOP;

    // CONSTRUCTORS
    Vsram_ecc_top__Syms(VerilatedContext* contextp, const char* namep, Vsram_ecc_top* modelp);
    ~Vsram_ecc_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
