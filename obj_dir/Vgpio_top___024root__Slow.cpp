// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgpio_top.h for the primary calling header

#include "Vgpio_top__pch.h"
#include "Vgpio_top__Syms.h"
#include "Vgpio_top___024root.h"

void Vgpio_top___024root___ctor_var_reset(Vgpio_top___024root* vlSelf);

Vgpio_top___024root::Vgpio_top___024root(Vgpio_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vgpio_top___024root___ctor_var_reset(this);
}

void Vgpio_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vgpio_top___024root::~Vgpio_top___024root() {
}
