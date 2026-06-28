// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart_top.h for the primary calling header

#include "Vuart_top__pch.h"
#include "Vuart_top___024root.h"

VL_INLINE_OPT void Vuart_top___024root___ico_sequent__TOP__0(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->rdata_o = 0U;
    vlSelf->rdata_o = ((4U == (IData)(vlSelf->addr_i))
                        ? (IData)(vlSelf->uart_top__DOT__rx_data)
                        : ((8U == (IData)(vlSelf->addr_i))
                            ? (((IData)(vlSelf->uart_top__DOT__rx_valid) 
                                << 1U) | (IData)(vlSelf->uart_top__DOT__tx_busy))
                            : 0U));
}

void Vuart_top___024root___eval_ico(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vuart_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vuart_top___024root___eval_triggers__ico(Vuart_top___024root* vlSelf);

bool Vuart_top___024root___eval_phase__ico(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vuart_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vuart_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vuart_top___024root___eval_act(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vuart_top___024root___nba_sequent__TOP__0(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt;
    __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt = 0;
    CData/*1:0*/ __Vdly__uart_top__DOT__u_uart_tx__DOT__state;
    __Vdly__uart_top__DOT__u_uart_tx__DOT__state = 0;
    SData/*9:0*/ __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt;
    __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt = 0;
    CData/*1:0*/ __Vdly__uart_top__DOT__u_uart_rx__DOT__state;
    __Vdly__uart_top__DOT__u_uart_rx__DOT__state = 0;
    // Body
    __Vdly__uart_top__DOT__u_uart_rx__DOT__state = vlSelf->uart_top__DOT__u_uart_rx__DOT__state;
    __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt 
        = vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt;
    __Vdly__uart_top__DOT__u_uart_tx__DOT__state = vlSelf->uart_top__DOT__u_uart_tx__DOT__state;
    __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt 
        = vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt;
    if (vlSelf->rst_ni) {
        vlSelf->uart_top__DOT__rx_valid = 0U;
        if ((2U & (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__state))) {
            if ((1U & (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__state))) {
                if ((0x363U == (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt))) {
                    __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt = 0U;
                    if (vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff2) {
                        vlSelf->uart_top__DOT__rx_data 
                            = vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_shift;
                        vlSelf->uart_top__DOT__rx_valid = 1U;
                    }
                    __Vdly__uart_top__DOT__u_uart_rx__DOT__state = 0U;
                } else {
                    __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt)));
                }
            } else if ((0x363U == (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt))) {
                vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_shift 
                    = (((IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff2) 
                        << 7U) | (0x7fU & ((IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_shift) 
                                           >> 1U)));
                __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt = 0U;
                if ((7U == (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__bit_cnt))) {
                    __Vdly__uart_top__DOT__u_uart_rx__DOT__state = 3U;
                } else {
                    vlSelf->uart_top__DOT__u_uart_rx__DOT__bit_cnt 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__bit_cnt)));
                }
            } else {
                __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt)));
            }
        } else if ((1U & (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__state))) {
            if ((0x1b1U == (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt))) {
                if (vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff2) {
                    __Vdly__uart_top__DOT__u_uart_rx__DOT__state = 0U;
                } else {
                    vlSelf->uart_top__DOT__u_uart_rx__DOT__bit_cnt = 0U;
                    __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt = 0U;
                    __Vdly__uart_top__DOT__u_uart_rx__DOT__state = 2U;
                }
            } else {
                __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt)));
            }
        } else if ((1U & (~ (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff2)))) {
            __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt = 0U;
            __Vdly__uart_top__DOT__u_uart_rx__DOT__state = 1U;
        }
        if ((2U & (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__state))) {
            if ((1U & (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__state))) {
                vlSelf->tx_o = 1U;
                if ((0x363U == (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt))) {
                    __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt = 0U;
                    __Vdly__uart_top__DOT__u_uart_tx__DOT__state = 0U;
                    vlSelf->uart_top__DOT__tx_busy = 0U;
                } else {
                    __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt)));
                }
            } else {
                vlSelf->tx_o = (1U & (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__tx_shift));
                if ((0x363U == (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt))) {
                    __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt = 0U;
                    vlSelf->uart_top__DOT__u_uart_tx__DOT__tx_shift 
                        = (0x7fU & ((IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__tx_shift) 
                                    >> 1U));
                    if ((7U == (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__bit_cnt))) {
                        __Vdly__uart_top__DOT__u_uart_tx__DOT__state = 3U;
                    } else {
                        vlSelf->uart_top__DOT__u_uart_tx__DOT__bit_cnt 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__bit_cnt)));
                    }
                } else {
                    __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt)));
                }
            }
        } else if ((1U & (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__state))) {
            vlSelf->tx_o = 0U;
            if ((0x363U == (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt))) {
                __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt = 0U;
                vlSelf->uart_top__DOT__u_uart_tx__DOT__bit_cnt = 0U;
                __Vdly__uart_top__DOT__u_uart_tx__DOT__state = 2U;
            } else {
                __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt)));
            }
        } else {
            vlSelf->tx_o = 1U;
            vlSelf->uart_top__DOT__tx_busy = 0U;
            if (vlSelf->uart_top__DOT__tx_valid) {
                vlSelf->uart_top__DOT__u_uart_tx__DOT__tx_shift 
                    = vlSelf->uart_top__DOT__tx_data;
                __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt = 0U;
                __Vdly__uart_top__DOT__u_uart_tx__DOT__state = 1U;
                vlSelf->uart_top__DOT__tx_busy = 1U;
            }
        }
        vlSelf->uart_top__DOT__tx_valid = 0U;
        if (((IData)(vlSelf->we_i) & (0U == (IData)(vlSelf->addr_i)))) {
            vlSelf->uart_top__DOT__tx_valid = 1U;
            vlSelf->uart_top__DOT__tx_data = (0xffU 
                                              & vlSelf->wdata_i);
        }
    } else {
        vlSelf->uart_top__DOT__u_uart_rx__DOT__bit_cnt = 0U;
        vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_shift = 0U;
        __Vdly__uart_top__DOT__u_uart_rx__DOT__state = 0U;
        __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt = 0U;
        vlSelf->uart_top__DOT__rx_data = 0U;
        vlSelf->uart_top__DOT__rx_valid = 0U;
        __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt = 0U;
        vlSelf->uart_top__DOT__u_uart_tx__DOT__bit_cnt = 0U;
        vlSelf->uart_top__DOT__u_uart_tx__DOT__tx_shift = 0U;
        __Vdly__uart_top__DOT__u_uart_tx__DOT__state = 0U;
        vlSelf->tx_o = 1U;
        vlSelf->uart_top__DOT__tx_busy = 0U;
        vlSelf->uart_top__DOT__tx_valid = 0U;
        vlSelf->uart_top__DOT__tx_data = 0U;
    }
    vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt 
        = __Vdly__uart_top__DOT__u_uart_rx__DOT__baud_cnt;
    vlSelf->uart_top__DOT__u_uart_rx__DOT__state = __Vdly__uart_top__DOT__u_uart_rx__DOT__state;
    vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt 
        = __Vdly__uart_top__DOT__u_uart_tx__DOT__baud_cnt;
    vlSelf->uart_top__DOT__u_uart_tx__DOT__state = __Vdly__uart_top__DOT__u_uart_tx__DOT__state;
    vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff2 = 
        ((1U & (~ (IData)(vlSelf->rst_ni))) || (IData)(vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff1));
    vlSelf->rdata_o = 0U;
    vlSelf->rdata_o = ((4U == (IData)(vlSelf->addr_i))
                        ? (IData)(vlSelf->uart_top__DOT__rx_data)
                        : ((8U == (IData)(vlSelf->addr_i))
                            ? (((IData)(vlSelf->uart_top__DOT__rx_valid) 
                                << 1U) | (IData)(vlSelf->uart_top__DOT__tx_busy))
                            : 0U));
    vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff1 = 
        ((1U & (~ (IData)(vlSelf->rst_ni))) || (IData)(vlSelf->rx_i));
}

void Vuart_top___024root___eval_nba(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vuart_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vuart_top___024root___eval_triggers__act(Vuart_top___024root* vlSelf);

bool Vuart_top___024root___eval_phase__act(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vuart_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vuart_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vuart_top___024root___eval_phase__nba(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vuart_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__ico(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__nba(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart_top___024root___dump_triggers__act(Vuart_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vuart_top___024root___eval(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval\n"); );
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
            Vuart_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/uart/uart_top.sv", 5, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vuart_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vuart_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/uart/uart_top.sv", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vuart_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/uart/uart_top.sv", 5, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vuart_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vuart_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vuart_top___024root___eval_debug_assertions(Vuart_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->we_i & 0xfeU))) {
        Verilated::overWidthError("we_i");}
    if (VL_UNLIKELY((vlSelf->addr_i & 0xf0U))) {
        Verilated::overWidthError("addr_i");}
    if (VL_UNLIKELY((vlSelf->rx_i & 0xfeU))) {
        Verilated::overWidthError("rx_i");}
}
#endif  // VL_DEBUG
