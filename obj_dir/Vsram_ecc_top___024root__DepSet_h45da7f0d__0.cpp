// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsram_ecc_top.h for the primary calling header

#include "Vsram_ecc_top__pch.h"
#include "Vsram_ecc_top___024root.h"

VL_INLINE_OPT void Vsram_ecc_top___024root___ico_sequent__TOP__0(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0;
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0 = 0;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0;
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0 = 0;
    // Body
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2 
        = (1U & VL_REDXOR_32((0x9b33366dU & vlSelf->wdata_i)));
    vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1 
        = (1U & VL_REDXOR_32((0x56aaad5bU & vlSelf->wdata_i)));
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h34b7dcec__0 
        = (1U & VL_REDXOR_32((0xe0000000U & vlSelf->wdata_i)));
    sram_ecc_top__DOT__u_ecc_encode__DOT____VdfgTmp_h4cddbc3c__0 
        = (1U & VL_REDXOR_32((0x3fc0000U & vlSelf->wdata_i)));
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
}

void Vsram_ecc_top___024root___eval_ico(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vsram_ecc_top___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vsram_ecc_top___024root___eval_triggers__ico(Vsram_ecc_top___024root* vlSelf);

bool Vsram_ecc_top___024root___eval_phase__ico(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vsram_ecc_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vsram_ecc_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vsram_ecc_top___024root___eval_act(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsram_ecc_top___024root___nba_sequent__TOP__0(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdlyvset__sram_ecc_top__DOT__mem__v0 = 0U;
    if (vlSelf->we_i) {
        vlSelf->__Vdlyvval__sram_ecc_top__DOT__mem__v0 
            = (((QData)((IData)((1U & (VL_REDXOR_32(vlSelf->wdata_i) 
                                       ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1) 
                                          ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2) 
                                             ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3) 
                                                ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4) 
                                                   ^ 
                                                   ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5) 
                                                    ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6)))))))))) 
                << 0x26U) | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6)) 
                              << 0x25U) | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5)) 
                                            << 0x24U) 
                                           | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4)) 
                                               << 0x23U) 
                                              | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3)) 
                                                  << 0x22U) 
                                                 | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2)) 
                                                     << 0x21U) 
                                                    | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1)) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(vlSelf->wdata_i)))))))));
        vlSelf->__Vdlyvset__sram_ecc_top__DOT__mem__v0 = 1U;
        vlSelf->__Vdlyvdim0__sram_ecc_top__DOT__mem__v0 
            = vlSelf->addr_i;
    }
}

VL_INLINE_OPT void Vsram_ecc_top___024root___nba_sequent__TOP__1(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_h0f20bbbd__0;
    sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_h0f20bbbd__0 = 0;
    CData/*0:0*/ sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_hb50a552a__0;
    sram_ecc_top__DOT__u_ecc_decode__DOT____VdfgExtracted_hb50a552a__0 = 0;
    // Body
    vlSelf->sram_ecc_top__DOT__sram_rdata = ((IData)(vlSelf->rst_ni)
                                              ? vlSelf->sram_ecc_top__DOT__mem
                                             [vlSelf->addr_i]
                                              : 0ULL);
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p 
        = (1U & VL_REDXOR_64(vlSelf->sram_ecc_top__DOT__sram_rdata));
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0 
        = (1U & VL_REDXOR_32((0xe0000000ULL & vlSelf->sram_ecc_top__DOT__sram_rdata)));
    vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0 
        = (1U & VL_REDXOR_32((0x3fc0000ULL & vlSelf->sram_ecc_top__DOT__sram_rdata)));
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

VL_INLINE_OPT void Vsram_ecc_top___024root___nba_sequent__TOP__2(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (vlSelf->__Vdlyvset__sram_ecc_top__DOT__mem__v0) {
        vlSelf->sram_ecc_top__DOT__mem[vlSelf->__Vdlyvdim0__sram_ecc_top__DOT__mem__v0] 
            = vlSelf->__Vdlyvval__sram_ecc_top__DOT__mem__v0;
    }
}

void Vsram_ecc_top___024root___eval_nba(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsram_ecc_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsram_ecc_top___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsram_ecc_top___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vsram_ecc_top___024root___eval_triggers__act(Vsram_ecc_top___024root* vlSelf);

bool Vsram_ecc_top___024root___eval_phase__act(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vsram_ecc_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vsram_ecc_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vsram_ecc_top___024root___eval_phase__nba(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vsram_ecc_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__ico(Vsram_ecc_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__nba(Vsram_ecc_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsram_ecc_top___024root___dump_triggers__act(Vsram_ecc_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vsram_ecc_top___024root___eval(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vsram_ecc_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/sram_ecc/sram_ecc_top.sv", 7, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vsram_ecc_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vsram_ecc_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/sram_ecc/sram_ecc_top.sv", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vsram_ecc_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/sram_ecc/sram_ecc_top.sv", 7, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vsram_ecc_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vsram_ecc_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vsram_ecc_top___024root___eval_debug_assertions(Vsram_ecc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->we_i & 0xfeU))) {
        Verilated::overWidthError("we_i");}
}
#endif  // VL_DEBUG
