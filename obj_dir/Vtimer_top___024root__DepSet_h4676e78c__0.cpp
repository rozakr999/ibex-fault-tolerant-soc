// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtimer_top.h for the primary calling header

#include "Vtimer_top__pch.h"
#include "Vtimer_top___024root.h"

VL_INLINE_OPT void Vtimer_top___024root___ico_sequent__TOP__0(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->rdata_o = 0U;
    vlSelf->rdata_o = ((8U & (IData)(vlSelf->addr_i))
                        ? ((4U & (IData)(vlSelf->addr_i))
                            ? ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : (IData)(vlSelf->timer_top__DOT__intr_flag)))
                            : ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : vlSelf->timer_top__DOT__compare_reg)))
                        : ((4U & (IData)(vlSelf->addr_i))
                            ? ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : vlSelf->timer_top__DOT__count_reg))
                            : ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : (((IData)(vlSelf->timer_top__DOT__intr_en) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->timer_top__DOT__enable))))));
}

void Vtimer_top___024root___eval_ico(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtimer_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtimer_top___024root___eval_triggers__ico(Vtimer_top___024root* vlSelf);

bool Vtimer_top___024root___eval_phase__ico(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtimer_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtimer_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtimer_top___024root___eval_act(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtimer_top___024root___nba_sequent__TOP__0(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__timer_top__DOT__count_reg;
    __Vdly__timer_top__DOT__count_reg = 0;
    // Body
    __Vdly__timer_top__DOT__count_reg = vlSelf->timer_top__DOT__count_reg;
    if (vlSelf->rst_ni) {
        if (((IData)(vlSelf->we_i) & (0xcU == (IData)(vlSelf->addr_i)))) {
            vlSelf->timer_top__DOT__intr_flag = 0U;
        }
        if (vlSelf->timer_top__DOT__enable) {
            if ((vlSelf->timer_top__DOT__count_reg 
                 == vlSelf->timer_top__DOT__compare_reg)) {
                __Vdly__timer_top__DOT__count_reg = 0U;
                vlSelf->timer_top__DOT__intr_flag = vlSelf->timer_top__DOT__intr_en;
            } else {
                __Vdly__timer_top__DOT__count_reg = 
                    ((IData)(1U) + vlSelf->timer_top__DOT__count_reg);
            }
        }
        if (vlSelf->we_i) {
            if ((0U == (IData)(vlSelf->addr_i))) {
                vlSelf->timer_top__DOT__enable = (1U 
                                                  & vlSelf->wdata_i);
                vlSelf->timer_top__DOT__intr_en = (1U 
                                                   & (vlSelf->wdata_i 
                                                      >> 1U));
            }
            if ((0U != (IData)(vlSelf->addr_i))) {
                if ((8U == (IData)(vlSelf->addr_i))) {
                    vlSelf->timer_top__DOT__compare_reg 
                        = vlSelf->wdata_i;
                }
            }
        }
    } else {
        __Vdly__timer_top__DOT__count_reg = 0U;
        vlSelf->timer_top__DOT__intr_flag = 0U;
        vlSelf->timer_top__DOT__enable = 0U;
        vlSelf->timer_top__DOT__compare_reg = 0xffffffffU;
        vlSelf->timer_top__DOT__intr_en = 0U;
    }
    vlSelf->timer_top__DOT__count_reg = __Vdly__timer_top__DOT__count_reg;
    vlSelf->intr_o = vlSelf->timer_top__DOT__intr_flag;
    vlSelf->rdata_o = 0U;
    vlSelf->rdata_o = ((8U & (IData)(vlSelf->addr_i))
                        ? ((4U & (IData)(vlSelf->addr_i))
                            ? ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : (IData)(vlSelf->timer_top__DOT__intr_flag)))
                            : ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : vlSelf->timer_top__DOT__compare_reg)))
                        : ((4U & (IData)(vlSelf->addr_i))
                            ? ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : vlSelf->timer_top__DOT__count_reg))
                            : ((2U & (IData)(vlSelf->addr_i))
                                ? 0U : ((1U & (IData)(vlSelf->addr_i))
                                         ? 0U : (((IData)(vlSelf->timer_top__DOT__intr_en) 
                                                  << 1U) 
                                                 | (IData)(vlSelf->timer_top__DOT__enable))))));
}

void Vtimer_top___024root___eval_nba(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtimer_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtimer_top___024root___eval_triggers__act(Vtimer_top___024root* vlSelf);

bool Vtimer_top___024root___eval_phase__act(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtimer_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtimer_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtimer_top___024root___eval_phase__nba(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtimer_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtimer_top___024root___dump_triggers__ico(Vtimer_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtimer_top___024root___dump_triggers__nba(Vtimer_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtimer_top___024root___dump_triggers__act(Vtimer_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtimer_top___024root___eval(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval\n"); );
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
            Vtimer_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/timer/timer_top.sv", 8, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtimer_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtimer_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/timer/timer_top.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtimer_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/timer/timer_top.sv", 8, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtimer_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtimer_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtimer_top___024root___eval_debug_assertions(Vtimer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->we_i & 0xfeU))) {
        Verilated::overWidthError("we_i");}
    if (VL_UNLIKELY((vlSelf->addr_i & 0xf0U))) {
        Verilated::overWidthError("addr_i");}
}
#endif  // VL_DEBUG
