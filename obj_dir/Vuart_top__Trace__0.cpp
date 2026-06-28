// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vuart_top__Syms.h"


void Vuart_top___024root__trace_chg_0_sub_0(Vuart_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vuart_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root__trace_chg_0\n"); );
    // Init
    Vuart_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vuart_top___024root*>(voidSelf);
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vuart_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vuart_top___024root__trace_chg_0_sub_0(Vuart_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->uart_top__DOT__tx_data),8);
        bufp->chgBit(oldp+1,(vlSelf->uart_top__DOT__tx_valid));
        bufp->chgBit(oldp+2,(vlSelf->uart_top__DOT__tx_busy));
        bufp->chgCData(oldp+3,(vlSelf->uart_top__DOT__rx_data),8);
        bufp->chgBit(oldp+4,(vlSelf->uart_top__DOT__rx_valid));
        bufp->chgCData(oldp+5,(vlSelf->uart_top__DOT__u_uart_rx__DOT__state),2);
        bufp->chgSData(oldp+6,(vlSelf->uart_top__DOT__u_uart_rx__DOT__baud_cnt),10);
        bufp->chgCData(oldp+7,(vlSelf->uart_top__DOT__u_uart_rx__DOT__bit_cnt),3);
        bufp->chgCData(oldp+8,(vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_shift),8);
        bufp->chgBit(oldp+9,(vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff2));
        bufp->chgBit(oldp+10,(vlSelf->uart_top__DOT__u_uart_rx__DOT__rx_ff1));
        bufp->chgCData(oldp+11,(vlSelf->uart_top__DOT__u_uart_tx__DOT__state),2);
        bufp->chgSData(oldp+12,(vlSelf->uart_top__DOT__u_uart_tx__DOT__baud_cnt),10);
        bufp->chgCData(oldp+13,(vlSelf->uart_top__DOT__u_uart_tx__DOT__bit_cnt),3);
        bufp->chgCData(oldp+14,(vlSelf->uart_top__DOT__u_uart_tx__DOT__tx_shift),8);
    }
    bufp->chgBit(oldp+15,(vlSelf->clk_i));
    bufp->chgBit(oldp+16,(vlSelf->rst_ni));
    bufp->chgBit(oldp+17,(vlSelf->we_i));
    bufp->chgIData(oldp+18,(vlSelf->wdata_i),32);
    bufp->chgCData(oldp+19,(vlSelf->addr_i),4);
    bufp->chgIData(oldp+20,(vlSelf->rdata_o),32);
    bufp->chgBit(oldp+21,(vlSelf->tx_o));
    bufp->chgBit(oldp+22,(vlSelf->rx_i));
}

void Vuart_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart_top___024root__trace_cleanup\n"); );
    // Init
    Vuart_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vuart_top___024root*>(voidSelf);
    Vuart_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
