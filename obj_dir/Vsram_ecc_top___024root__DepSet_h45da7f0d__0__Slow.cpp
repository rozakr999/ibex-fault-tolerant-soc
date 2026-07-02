// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsram_ecc_top.h for the primary calling header

#include "Vsram_ecc_top__pch.h"
#include "Vsram_ecc_top___024root.h"

VL_ATTR_COLD void Vsram_ecc_top___024root___eval_static(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vsram_ecc_top___024root___eval_initial(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = vlSelf->clk_i;
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = vlSelf->rst_ni;
}

VL_ATTR_COLD void Vsram_ecc_top___024root___eval_final(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__stl(Vsram_ecc_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsram_ecc_top___024root___eval_phase__stl(Vsram_ecc_top___024root* vlSelf);

VL_ATTR_COLD void Vsram_ecc_top___024root___eval_settle(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vsram_ecc_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/sram_ecc/sram_ecc_top.sv", 7, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vsram_ecc_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__stl(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsram_ecc_top___024root___stl_sequent__TOP__0(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0;
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0 = 0;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0;
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0 = 0;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_h0f20bbbd__0;
    sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_h0f20bbbd__0 = 0;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_hb50a552a__0;
    sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_hb50a552a__0 = 0;
    // Body
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2 
        = (1U & VL_REDXOR_32((0x9b33366dU & vlSelf->wdata_i)));
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1 
        = (1U & VL_REDXOR_32((0x56aaad5bU & vlSelf->wdata_i)));
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0 
        = (1U & VL_REDXOR_32((0xe0000000U & vlSelf->wdata_i)));
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0 
        = (1U & VL_REDXOR_32((0x3fc0000U & vlSelf->wdata_i)));
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p 
        = (1U & VL_REDXOR_64(vlSelf->sram_ecc_top__DOT__sram_rdata));
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0 
        = (1U & VL_REDXOR_32((0xe0000000ULL & vlSelf->sram_ecc_top__DOT__sram_rdata)));
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0 
        = (1U & VL_REDXOR_32((0x3fc0000ULL & vlSelf->sram_ecc_top__DOT__sram_rdata)));
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6 
        = (1U & (VL_REDXOR_32((0x1c000000U & vlSelf->wdata_i)) 
                 ^ (IData)(sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0)));
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3 
        = (1U & (VL_REDXOR_32((0x3c3c78eU & vlSelf->wdata_i)) 
                 ^ (IData)(sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0)));
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5 
        = (1U & (VL_REDXOR_32((0x3f800U & vlSelf->wdata_i)) 
                 ^ (IData)(sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0)));
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4 
        = (1U & (VL_REDXOR_16((0x7f0U & vlSelf->wdata_i)) 
                 ^ (IData)(sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0)));
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome 
        = (0x3fU & (((0x20U & ((VL_REDXOR_32((0x1c000000ULL 
                                              & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)) 
                               << 5U)) | ((0x10U & 
                                           ((VL_REDXOR_32(
                                                          (0x3f800ULL 
                                                           & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                             ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)) 
                                            << 4U)) 
                                          | ((8U & 
                                              ((VL_REDXOR_16(
                                                             (0x7f0ULL 
                                                              & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                                ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)) 
                                               << 3U)) 
                                             | ((4U 
                                                 & ((VL_REDXOR_32(
                                                                  (0x3c3c78eULL 
                                                                   & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                                     ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)) 
                                                    << 2U)) 
                                                | ((2U 
                                                    & (VL_REDXOR_32(
                                                                    (0x9b33366dULL 
                                                                     & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & VL_REDXOR_32(
                                                                     (0x56aaad5bULL 
                                                                      & vlSelf->sram_ecc_top__DOT__sram_rdata)))))))) 
                    ^ (IData)((vlSelf->sram_ecc_top__DOT__sram_rdata 
                               >> 0x20U))));
    sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_h0f20bbbd__0 
        = ((~ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p)) 
           & (0U == (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome)));
    sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_hb50a552a__0 
        = ((0U != (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome)) 
           & (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p));
    vlSelf->sram_ecc_top__DOT__single_err = 0U;
    vlSelf->sram_ecc_top__DOT__double_err = 0U;
    vlSelf->sram_ecc_top__DOT__corrected_data = (IData)(vlSelf->sram_ecc_top__DOT__sram_rdata);
    if (sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_h0f20bbbd__0) {
        vlSelf->sram_ecc_top__DOT__single_err = 0U;
        vlSelf->sram_ecc_top__DOT__double_err = 0U;
        vlSelf->sram_ecc_top__DOT__corrected_data = (IData)(vlSelf->sram_ecc_top__DOT__sram_rdata);
    } else {
        if (sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_hb50a552a__0) {
            vlSelf->sram_ecc_top__DOT__single_err = 1U;
            vlSelf->sram_ecc_top__DOT__corrected_data 
                = (IData)(vlSelf->sram_ecc_top__DOT__sram_rdata);
            if ((0x20U >= (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome))) {
                vlSelf->sram_ecc_top__DOT__corrected_data 
                    = (((~ ((IData)(1U) << (0x1fU & 
                                            ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome) 
                                             - (IData)(1U))))) 
                        & vlSelf->sram_ecc_top__DOT__corrected_data) 
                       | (0xffffffffULL & ((1U & (~ (IData)(
                                                            (vlSelf->sram_ecc_top__DOT__sram_rdata 
                                                             >> 
                                                             (0x1fU 
                                                              & ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome) 
                                                                 - (IData)(1U))))))) 
                                           << (0x1fU 
                                               & ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome) 
                                                  - (IData)(1U))))));
            }
        } else {
            vlSelf->sram_ecc_top__DOT__corrected_data 
                = (IData)(vlSelf->sram_ecc_top__DOT__sram_rdata);
        }
        if ((1U & (~ (IData)(sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_hb50a552a__0)))) {
            vlSelf->sram_ecc_top__DOT__double_err = 1U;
        }
    }
    vlSelf->single_err_o = vlSelf->sram_ecc_top__DOT__single_err;
    vlSelf->double_err_o = vlSelf->sram_ecc_top__DOT__double_err;
    vlSelf->rdata_o = vlSelf->sram_ecc_top__DOT__corrected_data;
}

VL_ATTR_COLD void Vsram_ecc_top___024root___eval_stl(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vsram_ecc_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vsram_ecc_top___024root___eval_triggers__stl(Vsram_ecc_top___024root* vlSelf);

VL_ATTR_COLD bool Vsram_ecc_top___024root___eval_phase__stl(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vsram_ecc_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vsram_ecc_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__ico(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__act(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_i)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__nba(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsram_ecc_top___024root___ctor_var_reset(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->we_i = VL_RAND_RESET_I(1);
    vlSelf->wdata_i = VL_RAND_RESET_I(32);
    vlSelf->addr_i = VL_RAND_RESET_I(8);
    vlSelf->rdata_o = VL_RAND_RESET_I(32);
    vlSelf->single_err_o = VL_RAND_RESET_I(1);
    vlSelf->double_err_o = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__sram_rdata = VL_RAND_RESET_Q(39);
    vlSelf->sram_ecc_top__DOT__corrected_data = VL_RAND_RESET_I(32);
    vlSelf->sram_ecc_top__DOT__single_err = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__double_err = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->sram_ecc_top__DOT__mem[__Vi0] = VL_RAND_RESET_Q(39);
    }
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1 = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2 = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3 = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4 = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5 = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6 = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome = VL_RAND_RESET_I(6);
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p = VL_RAND_RESET_I(1);
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0 = 0;
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0 = 0;
    vlSelf->__Vdlyvdim0__sram_ecc_top__DOT__mem__v0 = 0;
    vlSelf->__Vdlyvval__sram_ecc_top__DOT__mem__v0 = VL_RAND_RESET_Q(39);
    vlSelf->__Vdlyvset__sram_ecc_top__DOT__mem__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
