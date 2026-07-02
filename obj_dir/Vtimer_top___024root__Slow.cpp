// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtimer_top.h for the primary calling header

#include "Vtimer_top__pch.h"
#include "Vtimer_top__Syms.h"
#include "Vtimer_top___024root.h"

void Vtimer_top___024root___ctor_var_reset(Vtimer_top___024root* vlSelf);

Vtimer_top___024root::Vtimer_top___024root(Vtimer_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtimer_top___024root___ctor_var_reset(this);
}

void Vtimer_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtimer_top___024root::~Vtimer_top___024root() {
}
