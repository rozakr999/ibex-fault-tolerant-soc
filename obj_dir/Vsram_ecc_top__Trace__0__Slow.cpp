// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsram_ecc_top__Syms.h"


VL_ATTR_COLD void Vsram_ecc_top___024root__trace_init_sub__TOP__0(Vsram_ecc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+24,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+29,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+30,0,"single_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"double_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("sram_ecc_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+24,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+29,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+30,0,"single_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"double_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"ecc_encode_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+33,0,"sram_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declQuad(c+7,0,"sram_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+9,0,"corrected_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,0,"single_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"double_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_ecc_decode", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+12,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"ecc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+9,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,0,"single_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"double_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"ecc_recalc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+15,0,"syndrome",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+16,0,"overall_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_ecc_recheck", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+12,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"ecc_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+17,0,"p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"p3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"p4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"p5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"p6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"p7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ecc_encode", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+27,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"ecc_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1,0,"p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"p2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"p3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"p4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"p5",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"p6",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"p7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsram_ecc_top___024root__trace_init_top(Vsram_ecc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_init_top\n"); );
    // Body
    Vsram_ecc_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vsram_ecc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vsram_ecc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsram_ecc_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vsram_ecc_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vsram_ecc_top___024root__trace_register(Vsram_ecc_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vsram_ecc_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vsram_ecc_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vsram_ecc_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vsram_ecc_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vsram_ecc_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_const_0\n"); );
    // Init
    Vsram_ecc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsram_ecc_top___024root*>(voidSelf);
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vsram_ecc_top___024root__trace_full_0_sub_0(Vsram_ecc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vsram_ecc_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_full_0\n"); );
    // Init
    Vsram_ecc_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsram_ecc_top___024root*>(voidSelf);
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vsram_ecc_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vsram_ecc_top___024root__trace_full_0_sub_0(Vsram_ecc_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vsram_ecc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsram_ecc_top___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1));
    bufp->fullBit(oldp+2,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2));
    bufp->fullBit(oldp+3,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3));
    bufp->fullBit(oldp+4,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4));
    bufp->fullBit(oldp+5,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5));
    bufp->fullBit(oldp+6,(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6));
    bufp->fullQData(oldp+7,(vlSelf->sram_ecc_top__DOT__sram_rdata),39);
    bufp->fullIData(oldp+9,(vlSelf->sram_ecc_top__DOT__corrected_data),32);
    bufp->fullBit(oldp+10,(vlSelf->sram_ecc_top__DOT__single_err));
    bufp->fullBit(oldp+11,(vlSelf->sram_ecc_top__DOT__double_err));
    bufp->fullIData(oldp+12,((IData)(vlSelf->sram_ecc_top__DOT__sram_rdata)),32);
    bufp->fullCData(oldp+13,((0x7fU & (IData)((vlSelf->sram_ecc_top__DOT__sram_rdata 
                                               >> 0x20U)))),7);
    bufp->fullCData(oldp+14,(((0x40U & (VL_REDXOR_32(
                                                     (0x2da65cb7ULL 
                                                      & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                        << 6U)) | (
                                                   (0x20U 
                                                    & ((VL_REDXOR_32(
                                                                     (0x1c000000ULL 
                                                                      & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                                        ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)) 
                                                       << 5U)) 
                                                   | ((0x10U 
                                                       & ((VL_REDXOR_32(
                                                                        (0x3f800ULL 
                                                                         & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                                           ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)) 
                                                          << 4U)) 
                                                      | ((8U 
                                                          & ((VL_REDXOR_16(
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
                                                                                & vlSelf->sram_ecc_top__DOT__sram_rdata)))))))))),7);
    bufp->fullCData(oldp+15,(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__syndrome),6);
    bufp->fullBit(oldp+16,(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__overall_p));
    bufp->fullBit(oldp+17,((1U & VL_REDXOR_32((0x56aaad5bULL 
                                               & vlSelf->sram_ecc_top__DOT__sram_rdata)))));
    bufp->fullBit(oldp+18,((1U & VL_REDXOR_32((0x9b33366dULL 
                                               & vlSelf->sram_ecc_top__DOT__sram_rdata)))));
    bufp->fullBit(oldp+19,((1U & (VL_REDXOR_32((0x3c3c78eULL 
                                                & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                  ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)))));
    bufp->fullBit(oldp+20,((1U & (VL_REDXOR_16((0x7f0ULL 
                                                & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                  ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)))));
    bufp->fullBit(oldp+21,((1U & (VL_REDXOR_32((0x3f800ULL 
                                                & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                  ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h4cddbc3c__0)))));
    bufp->fullBit(oldp+22,((1U & (VL_REDXOR_32((0x1c000000ULL 
                                                & vlSelf->sram_ecc_top__DOT__sram_rdata)) 
                                  ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_decode__DOT__u_ecc_recheck__DOT____VdfgTmp_h34b7dcec__0)))));
    bufp->fullBit(oldp+23,((1U & VL_REDXOR_32((0x2da65cb7ULL 
                                               & vlSelf->sram_ecc_top__DOT__sram_rdata)))));
    bufp->fullBit(oldp+24,(vlSelf->clk_i));
    bufp->fullBit(oldp+25,(vlSelf->rst_ni));
    bufp->fullBit(oldp+26,(vlSelf->we_i));
    bufp->fullIData(oldp+27,(vlSelf->wdata_i),32);
    bufp->fullCData(oldp+28,(vlSelf->addr_i),8);
    bufp->fullIData(oldp+29,(vlSelf->rdata_o),32);
    bufp->fullBit(oldp+30,(vlSelf->single_err_o));
    bufp->fullBit(oldp+31,(vlSelf->double_err_o));
    bufp->fullCData(oldp+32,(((0x40U & ((VL_REDXOR_32(vlSelf->wdata_i) 
                                         ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1) 
                                            ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2) 
                                               ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3) 
                                                  ^ 
                                                  ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4) 
                                                   ^ 
                                                   ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5) 
                                                    ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6))))))) 
                                        << 6U)) | (
                                                   ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6) 
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
    bufp->fullQData(oldp+33,((((QData)((IData)((1U 
                                                & (VL_REDXOR_32(vlSelf->wdata_i) 
                                                   ^ 
                                                   ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1) 
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
    bufp->fullBit(oldp+35,((1U & (VL_REDXOR_32(vlSelf->wdata_i) 
                                  ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p1) 
                                     ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p2) 
                                        ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p3) 
                                           ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p4) 
                                              ^ ((IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p5) 
                                                 ^ (IData)(vlSelf->sram_ecc_top__DOT__u_ecc_encode__DOT__p6))))))))));
}
