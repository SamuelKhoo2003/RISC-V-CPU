// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vgreen__Syms.h"


VL_ATTR_COLD void Vgreen___024root__trace_init_sub__TOP__0(Vgreen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"PC", false,-1, 7,0);
    tracep->declBit(c+2,"EQ", false,-1);
    tracep->declBus(c+3,"instr", false,-1, 31,0);
    tracep->declBit(c+4,"RegWrite", false,-1);
    tracep->declBus(c+5,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+6,"ALUsrc", false,-1);
    tracep->declBit(c+7,"PCsrc", false,-1);
    tracep->declBus(c+8,"ImmOp", false,-1, 31,0);
    tracep->pushNamePrefix("green ");
    tracep->declBus(c+11,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+12,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"PC", false,-1, 7,0);
    tracep->declBit(c+2,"EQ", false,-1);
    tracep->declBus(c+3,"instr", false,-1, 31,0);
    tracep->declBit(c+4,"RegWrite", false,-1);
    tracep->declBus(c+5,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+6,"ALUsrc", false,-1);
    tracep->declBit(c+7,"PCsrc", false,-1);
    tracep->declBus(c+8,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+9,"ImmSrc", false,-1, 1,0);
    tracep->pushNamePrefix("MyControlUnit ");
    tracep->declBus(c+12,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+2,"EQ", false,-1);
    tracep->declBus(c+3,"instr", false,-1, 31,0);
    tracep->declBit(c+4,"RegWrite", false,-1);
    tracep->declBus(c+5,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+6,"ALUsrc", false,-1);
    tracep->declBus(c+9,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+7,"PCsrc", false,-1);
    tracep->declBus(c+10,"opcode", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MyInstrMem ");
    tracep->declBus(c+11,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+11,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+13,"clk", false,-1);
    tracep->declBus(c+1,"addr", false,-1, 7,0);
    tracep->declBus(c+3,"dout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MySignExtend ");
    tracep->declBus(c+12,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"instr", false,-1, 31,0);
    tracep->declBus(c+9,"ImmSrc", false,-1, 1,0);
    tracep->declBus(c+8,"ImmOp", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vgreen___024root__trace_init_top(Vgreen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_init_top\n"); );
    // Body
    Vgreen___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vgreen___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vgreen___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vgreen___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vgreen___024root__trace_register(Vgreen___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vgreen___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vgreen___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vgreen___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vgreen___024root__trace_full_sub_0(Vgreen___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vgreen___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_full_top_0\n"); );
    // Init
    Vgreen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgreen___024root*>(voidSelf);
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vgreen___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vgreen___024root__trace_full_sub_0(Vgreen___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->PC),8);
    bufp->fullBit(oldp+2,(vlSelf->EQ));
    bufp->fullIData(oldp+3,(vlSelf->instr),32);
    bufp->fullBit(oldp+4,(vlSelf->RegWrite));
    bufp->fullCData(oldp+5,(vlSelf->ALUctrl),3);
    bufp->fullBit(oldp+6,(vlSelf->ALUsrc));
    bufp->fullBit(oldp+7,(vlSelf->PCsrc));
    bufp->fullIData(oldp+8,(vlSelf->ImmOp),32);
    bufp->fullCData(oldp+9,(vlSelf->green__DOT__ImmSrc),2);
    bufp->fullCData(oldp+10,((0x7fU & vlSelf->instr)),7);
    bufp->fullIData(oldp+11,(8U),32);
    bufp->fullIData(oldp+12,(0x20U),32);
    bufp->fullBit(oldp+13,(vlSelf->green__DOT__MyInstrMem__DOT__clk));
}
