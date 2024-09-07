// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vgreen__Syms.h"


void Vgreen___024root__trace_chg_sub_0(Vgreen___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vgreen___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_chg_top_0\n"); );
    // Init
    Vgreen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgreen___024root*>(voidSelf);
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vgreen___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vgreen___024root__trace_chg_sub_0(Vgreen___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->PC),8);
    bufp->chgBit(oldp+1,(vlSelf->EQ));
    bufp->chgIData(oldp+2,(vlSelf->instr),32);
    bufp->chgBit(oldp+3,(vlSelf->RegWrite));
    bufp->chgCData(oldp+4,(vlSelf->ALUctrl),3);
    bufp->chgBit(oldp+5,(vlSelf->ALUsrc));
    bufp->chgBit(oldp+6,(vlSelf->PCsrc));
    bufp->chgIData(oldp+7,(vlSelf->ImmOp),32);
    bufp->chgCData(oldp+8,(vlSelf->green__DOT__ImmSrc),2);
    bufp->chgCData(oldp+9,((0x7fU & vlSelf->instr)),7);
}

void Vgreen___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_cleanup\n"); );
    // Init
    Vgreen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgreen___024root*>(voidSelf);
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
