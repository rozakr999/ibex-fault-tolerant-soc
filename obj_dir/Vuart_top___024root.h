// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vuart_top.h for the primary calling header

#ifndef VERILATED_VUART_TOP___024ROOT_H_
#define VERILATED_VUART_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vuart_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vuart_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(we_i,0,0);
    VL_IN8(addr_i,3,0);
    VL_OUT8(tx_o,0,0);
    VL_IN8(rx_i,0,0);
    CData/*7:0*/ uart_top__DOT__tx_data;
    CData/*0:0*/ uart_top__DOT__tx_valid;
    CData/*0:0*/ uart_top__DOT__tx_busy;
    CData/*7:0*/ uart_top__DOT__rx_data;
    CData/*0:0*/ uart_top__DOT__rx_valid;
    CData/*1:0*/ uart_top__DOT__u_uart_tx__DOT__state;
    CData/*2:0*/ uart_top__DOT__u_uart_tx__DOT__bit_cnt;
    CData/*7:0*/ uart_top__DOT__u_uart_tx__DOT__tx_shift;
    CData/*1:0*/ uart_top__DOT__u_uart_rx__DOT__state;
    CData/*2:0*/ uart_top__DOT__u_uart_rx__DOT__bit_cnt;
    CData/*7:0*/ uart_top__DOT__u_uart_rx__DOT__rx_shift;
    CData/*0:0*/ uart_top__DOT__u_uart_rx__DOT__rx_ff1;
    CData/*0:0*/ uart_top__DOT__u_uart_rx__DOT__rx_ff2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk_i__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_ni__0;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ uart_top__DOT__u_uart_tx__DOT__baud_cnt;
    SData/*9:0*/ uart_top__DOT__u_uart_rx__DOT__baud_cnt;
    VL_IN(wdata_i,31,0);
    VL_OUT(rdata_o,31,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vuart_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vuart_top___024root(Vuart_top__Syms* symsp, const char* v__name);
    ~Vuart_top___024root();
    VL_UNCOPYABLE(Vuart_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
