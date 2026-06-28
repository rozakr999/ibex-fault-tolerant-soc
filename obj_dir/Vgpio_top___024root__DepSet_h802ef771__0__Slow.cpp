// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgpio_top.h for the primary calling header

#include "Vgpio_top__pch.h"
#include "Vgpio_top___024root.h"

VL_ATTR_COLD void Vgpio_top___024root___eval_static(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vgpio_top___024root___eval_initial(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = vlSelf->clk_i;
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = vlSelf->rst_ni;
}

VL_ATTR_COLD void Vgpio_top___024root___eval_final(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgpio_top___024root___dump_triggers__stl(Vgpio_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vgpio_top___024root___eval_phase__stl(Vgpio_top___024root* vlSelf);

VL_ATTR_COLD void Vgpio_top___024root___eval_settle(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___eval_settle\n"); );
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
            Vgpio_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/gpio/gpio_top.sv", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vgpio_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgpio_top___024root___dump_triggers__stl(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vgpio_top___024root___stl_sequent__TOP__0(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->gpio_out_o = vlSelf->gpio_top__DOT__data_out_reg;
    vlSelf->gpio_oe_o = vlSelf->gpio_top__DOT__oe_reg;
    vlSelf->rdata_o = 0U;
    vlSelf->rdata_o = ((0U == (IData)(vlSelf->addr_i))
                        ? (IData)(vlSelf->gpio_top__DOT__data_out_reg)
                        : ((4U == (IData)(vlSelf->addr_i))
                            ? (IData)(vlSelf->gpio_in_i)
                            : ((8U == (IData)(vlSelf->addr_i))
                                ? (IData)(vlSelf->gpio_top__DOT__oe_reg)
                                : 0U)));
}

VL_ATTR_COLD void Vgpio_top___024root___eval_stl(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vgpio_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vgpio_top___024root___eval_triggers__stl(Vgpio_top___024root* vlSelf);

VL_ATTR_COLD bool Vgpio_top___024root___eval_phase__stl(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vgpio_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vgpio_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgpio_top___024root___dump_triggers__ico(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vgpio_top___024root___dump_triggers__act(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgpio_top___024root___dump_triggers__nba(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_i or negedge rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vgpio_top___024root___ctor_var_reset(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->we_i = VL_RAND_RESET_I(1);
    vlSelf->wdata_i = VL_RAND_RESET_I(32);
    vlSelf->addr_i = VL_RAND_RESET_I(4);
    vlSelf->rdata_o = VL_RAND_RESET_I(32);
    vlSelf->gpio_in_i = VL_RAND_RESET_I(16);
    vlSelf->gpio_out_o = VL_RAND_RESET_I(16);
    vlSelf->gpio_oe_o = VL_RAND_RESET_I(16);
    vlSelf->gpio_top__DOT__data_out_reg = VL_RAND_RESET_I(16);
    vlSelf->gpio_top__DOT__oe_reg = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk_i__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_ni__0 = VL_RAND_RESET_I(1);
}
