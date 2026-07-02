// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsram_ecc_top.h for the primary calling header

#ifndef VERILATED_VSRAM_ECC_TOP___024ROOT_H_
#define VERILATED_VSRAM_ECC_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vsram_ecc_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsram_ecc_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(we_i,0,0);
    VL_IN8(addr_i,7,0);
    VL_OUT8(single_err_o,0,0);
    VL_OUT8(double_err_o,0,0);
    CData/*0:0*/ sram_ecc_top__DOT__single_err;
    CData/*0:0*/ sram_ecc_top__DOT__double_err;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT__p1;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT__p2;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT__p3;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT__p4;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT__p5;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT__p6;
    CData/*5:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0;
    CData/*7:0*/ __Vdlyvdim0__sram_ecc_top__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__sram_ecc_top__DOT__mem__v0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(wdata_i,31,0);
    VL_OUT(rdata_o,31,0);
    IData/*31:0*/ sram_ecc_top__DOT__corrected_data;
    IData/*31:0*/ __VactIterCount;
    QData/*38:0*/ sram_ecc_top__DOT__sram_rdata;
    QData/*38:0*/ __Vdlyvval__sram_ecc_top__DOT__mem__v0;
    VlUnpacked<QData/*38:0*/, 256> sram_ecc_top__DOT__mem;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsram_ecc_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsram_ecc_top___024root(Vsram_ecc_top__Syms* symsp, const char* v__name);
    ~Vsram_ecc_top___024root();
    VL_UNCOPYABLE(Vsram_ecc_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
