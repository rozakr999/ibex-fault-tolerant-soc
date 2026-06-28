// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vgpio_top__Syms.h"


void Vgpio_top___024root__trace_chg_0_sub_0(Vgpio_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vgpio_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root__trace_chg_0\n"); );
    // Init
    Vgpio_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgpio_top___024root*>(voidSelf);
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vgpio_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vgpio_top___024root__trace_chg_0_sub_0(Vgpio_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk_i));
    bufp->chgBit(oldp+1,(vlSelf->rst_ni));
    bufp->chgBit(oldp+2,(vlSelf->we_i));
    bufp->chgIData(oldp+3,(vlSelf->wdata_i),32);
    bufp->chgCData(oldp+4,(vlSelf->addr_i),4);
    bufp->chgIData(oldp+5,(vlSelf->rdata_o),32);
    bufp->chgSData(oldp+6,(vlSelf->gpio_in_i),16);
    bufp->chgSData(oldp+7,(vlSelf->gpio_out_o),16);
    bufp->chgSData(oldp+8,(vlSelf->gpio_oe_o),16);
    bufp->chgSData(oldp+9,(vlSelf->gpio_top__DOT__data_out_reg),16);
    bufp->chgSData(oldp+10,(vlSelf->gpio_top__DOT__oe_reg),16);
}

void Vgpio_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root__trace_cleanup\n"); );
    // Init
    Vgpio_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgpio_top___024root*>(voidSelf);
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
