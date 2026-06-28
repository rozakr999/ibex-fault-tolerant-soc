// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vgpio_top.h for the primary calling header

#ifndef VERILATED_VGPIO_TOP___024ROOT_H_
#define VERILATED_VGPIO_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vgpio_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vgpio_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(we_i,0,0);
    VL_IN8(addr_i,3,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(gpio_in_i,15,0);
    VL_OUT16(gpio_out_o,15,0);
    VL_OUT16(gpio_oe_o,15,0);
    SData/*15:0*/ gpio_top__DOT__data_out_reg;
    SData/*15:0*/ gpio_top__DOT__oe_reg;
    VL_IN(wdata_i,31,0);
    VL_OUT(rdata_o,31,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vgpio_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vgpio_top___024root(Vgpio_top__Syms* symsp, const char* v__name);
    ~Vgpio_top___024root();
    VL_UNCOPYABLE(Vgpio_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
