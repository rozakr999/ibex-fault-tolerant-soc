// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtimer_top__Syms.h"


void Vtimer_top___024root__trace_chg_0_sub_0(Vtimer_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtimer_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root__trace_chg_0\n"); );
    // Init
    Vtimer_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtimer_top___024root*>(voidSelf);
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtimer_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtimer_top___024root__trace_chg_0_sub_0(Vtimer_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->timer_top__DOT__count_reg),32);
        bufp->chgIData(oldp+1,(vlSelf->timer_top__DOT__compare_reg),32);
        bufp->chgBit(oldp+2,(vlSelf->timer_top__DOT__enable));
        bufp->chgBit(oldp+3,(vlSelf->timer_top__DOT__intr_en));
        bufp->chgBit(oldp+4,(vlSelf->timer_top__DOT__intr_flag));
    }
    bufp->chgBit(oldp+5,(vlSelf->clk_i));
    bufp->chgBit(oldp+6,(vlSelf->rst_ni));
    bufp->chgBit(oldp+7,(vlSelf->we_i));
    bufp->chgIData(oldp+8,(vlSelf->wdata_i),32);
    bufp->chgCData(oldp+9,(vlSelf->addr_i),4);
    bufp->chgIData(oldp+10,(vlSelf->rdata_o),32);
    bufp->chgBit(oldp+11,(vlSelf->intr_o));
}

void Vtimer_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtimer_top___024root__trace_cleanup\n"); );
    // Init
    Vtimer_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtimer_top___024root*>(voidSelf);
    Vtimer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
