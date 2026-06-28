// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgpio_top.h for the primary calling header

#include "Vgpio_top__pch.h"
#include "Vgpio_top__Syms.h"
#include "Vgpio_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vgpio_top___024root___dump_triggers__stl(Vgpio_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vgpio_top___024root___eval_triggers__stl(Vgpio_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgpio_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpio_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vgpio_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
