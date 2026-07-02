// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtimer_top.h for the primary calling header

#ifndef VERILATED_VTIMER_TOP___024ROOT_H_
#define VERILATED_VTIMER_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtimer_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtimer_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(we_i,0,0);
    VL_IN8(addr_i,3,0);
    VL_OUT8(intr_o,0,0);
    CData/*0:0*/ timer_top__DOT__enable;
    CData/*0:0*/ timer_top__DOT__intr_en;
    CData/*0:0*/ timer_top__DOT__intr_flag;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(wdata_i,31,0);
    VL_OUT(rdata_o,31,0);
    IData/*31:0*/ timer_top__DOT__count_reg;
    IData/*31:0*/ timer_top__DOT__compare_reg;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtimer_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtimer_top___024root(Vtimer_top__Syms* symsp, const char* v__name);
    ~Vtimer_top___024root();
    VL_UNCOPYABLE(Vtimer_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
