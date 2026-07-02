// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsram_ecc_top__Syms.h"


void Vsram_ecc_top___024root__trace_chg_0_sub_0(Vsram_ecc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsram_ecc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_chg_0\n"); );
    // Init
    Vsram_ecc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsram_ecc_top___024root*>(voidSelf);
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vsram_ecc_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsram_ecc_top___024root__trace_chg_0_sub_0(Vsram_ecc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1));
        bufp->chgBit(oldp+1,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2));
        bufp->chgBit(oldp+2,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3));
        bufp->chgBit(oldp+3,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4));
        bufp->chgBit(oldp+4,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5));
        bufp->chgBit(oldp+5,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgQData(oldp+6,(vlSelf->sram_ecc_top__DOT__sram_rdata),39);
        bufp->chgIData(oldp+8,(vlSelf->sram_ecc_top__DOT__corrected_data),32);
        bufp->chgBit(oldp+9,(vlSelf->sram_ecc_top__DOT__single_err));
        bufp->chgBit(oldp+10,(vlSelf->sram_ecc_top__DOT__double_err));
        bufp->chgIData(oldp+11,((IData)(vlSelf->sram_ecc_top__DOT__sram_rdata)),32);
        bufp->chgCData(oldp+12,((0x7fU & (IData)((vlSelf->sram_ecc_top__DOT__sram_rdata 
                                                  >> 0x20U)))),7);
        bufp->chgCData(oldp+13,(((0x40U & (VL_REDXOR_32(
                                                        (0x2da65cb7ULL 
                                                         & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                           << 6U)) 
                                 | ((0x20U & ((VL_REDXOR_32(
                                                            (0x1c000000ULL 
                                                             & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                               ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)) 
                                              << 5U)) 
                                    | ((0x10U & ((VL_REDXOR_32(
                                                               (0x3f800ULL 
                                                                & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                                  ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)) 
                                                 << 4U)) 
                                       | ((8U & ((VL_REDXOR_16(
                                                               (0x7f0ULL 
                                                                & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                                  ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)) 
                                                 << 3U)) 
                                          | ((4U & 
                                              ((VL_REDXOR_32(
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
                                                                   & vlSelf->sram_ecc_top__DOT__sram_rdata)))))))))),7);
        bufp->chgCData(oldp+14,(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome),6);
        bufp->chgBit(oldp+15,(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p));
        bufp->chgBit(oldp+16,((1U & VL_REDXOR_32((0x56aaad5bULL 
                                                  & vlSelf->sram_ecc_top__DOT__sram_rdata)))));
        bufp->chgBit(oldp+17,((1U & VL_REDXOR_32((0x9b33366dULL 
                                                  & vlSelf->sram_ecc_top__DOT__sram_rdata)))));
        bufp->chgBit(oldp+18,((1U & (VL_REDXOR_32((0x3c3c78eULL 
                                                   & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                     ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)))));
        bufp->chgBit(oldp+19,((1U & (VL_REDXOR_16((0x7f0ULL 
                                                   & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                     ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)))));
        bufp->chgBit(oldp+20,((1U & (VL_REDXOR_32((0x3f800ULL 
                                                   & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                     ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)))));
        bufp->chgBit(oldp+21,((1U & (VL_REDXOR_32((0x1c000000ULL 
                                                   & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                     ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)))));
        bufp->chgBit(oldp+22,((1U & VL_REDXOR_32((0x2da65cb7ULL 
                                                  & vlSelf->sram_ecc_top__DOT__sram_rdata)))));
    }
    bufp->chgBit(oldp+23,(vlSelf->clk_i));
    bufp->chgBit(oldp+24,(vlSelf->rst_ni));
    bufp->chgBit(oldp+25,(vlSelf->we_i));
    bufp->chgIData(oldp+26,(vlSelf->wdata_i),32);
    bufp->chgCData(oldp+27,(vlSelf->addr_i),8);
    bufp->chgIData(oldp+28,(vlSelf->rdata_o),32);
    bufp->chgBit(oldp+29,(vlSelf->single_err_o));
    bufp->chgBit(oldp+30,(vlSelf->double_err_o));
    bufp->chgCData(oldp+31,(((0x40U & ((VL_REDXOR_32(vlSelf->wdata_i) 
                                        ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1) 
                                           ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2) 
                                              ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3) 
                                                 ^ 
                                                 ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4) 
                                                  ^ 
                                                  ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5) 
                                                   ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6))))))) 
                                       << 6U)) | (((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6) 
                                                   << 5U) 
                                                  | (((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5) 
                                                      << 4U) 
                                                     | (((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4) 
                                                         << 3U) 
                                                        | (((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3) 
                                                            << 2U) 
                                                           | (((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2) 
                                                               << 1U) 
                                                              | (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1)))))))),7);
    bufp->chgQData(oldp+32,((((QData)((IData)((1U & 
                                               (VL_REDXOR_32(vlSelf->wdata_i) 
                                                ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1) 
                                                   ^ 
                                                   ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2) 
                                                    ^ 
                                                    ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3) 
                                                     ^ 
                                                     ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4) 
                                                      ^ 
                                                      ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5) 
                                                       ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6)))))))))) 
                              << 0x26U) | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6)) 
                                            << 0x25U) 
                                           | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5)) 
                                               << 0x24U) 
                                              | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4)) 
                                                  << 0x23U) 
                                                 | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3)) 
                                                     << 0x22U) 
                                                    | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2)) 
                                                        << 0x21U) 
                                                       | (((QData)((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1)) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(vlSelf->wdata_i)))))))))),39);
    bufp->chgBit(oldp+34,((1U & (VL_REDXOR_32(vlSelf->wdata_i) 
                                 ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1) 
                                    ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2) 
                                       ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3) 
                                          ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4) 
                                             ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5) 
                                                ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6))))))))));
}

void Vsram_ecc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_cleanup\n"); );
    // Init
    Vsram_ecc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsram_ecc_top___024root*>(voidSelf);
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
