// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcontrol_top__Syms.h"


void Vcontrol_top___024root__trace_chg_sub_0(Vcontrol_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcontrol_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_chg_top_0\n"); );
    // Init
    Vcontrol_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol_top___024root*>(voidSelf);
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcontrol_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vcontrol_top___024root__trace_chg_sub_0(Vcontrol_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->PC_i),8);
    bufp->chgBit(oldp+1,(vlSelf->Zero_i));
    bufp->chgIData(oldp+2,(vlSelf->instr_o),32);
    bufp->chgBit(oldp+3,(vlSelf->RegWrite_o));
    bufp->chgBit(oldp+4,(vlSelf->MemWrite_o));
    bufp->chgCData(oldp+5,(vlSelf->Resultsrc_o),2);
    bufp->chgCData(oldp+6,(vlSelf->ALUctrl_o),3);
    bufp->chgBit(oldp+7,(vlSelf->ALUsrc_o));
    bufp->chgCData(oldp+8,(vlSelf->PCsrc_o),2);
    bufp->chgIData(oldp+9,(vlSelf->ImmOp_o),32);
    bufp->chgCData(oldp+10,(vlSelf->control_top__DOT__ImmSrc),2);
    bufp->chgCData(oldp+11,((0x7fU & vlSelf->instr_o)),7);
    bufp->chgCData(oldp+12,((7U & (vlSelf->instr_o 
                                   >> 0xcU))),3);
    bufp->chgCData(oldp+13,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                             [vlSelf->PC_i])),8);
    bufp->chgCData(oldp+14,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                             [(0xffU & ((IData)(1U) 
                                        + (IData)(vlSelf->PC_i)))])),8);
    bufp->chgCData(oldp+15,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                             [(0xffU & ((IData)(2U) 
                                        + (IData)(vlSelf->PC_i)))])),8);
    bufp->chgCData(oldp+16,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                             [(0xffU & ((IData)(3U) 
                                        + (IData)(vlSelf->PC_i)))])),8);
}

void Vcontrol_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_cleanup\n"); );
    // Init
    Vcontrol_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol_top___024root*>(voidSelf);
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
