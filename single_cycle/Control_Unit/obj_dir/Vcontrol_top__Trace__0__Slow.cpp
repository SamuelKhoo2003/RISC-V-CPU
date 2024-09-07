// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcontrol_top__Syms.h"


VL_ATTR_COLD void Vcontrol_top___024root__trace_init_sub__TOP__0(Vcontrol_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"PC_i", false,-1, 7,0);
    tracep->declBit(c+2,"Zero_i", false,-1);
    tracep->declBus(c+3,"instr_o", false,-1, 31,0);
    tracep->declBit(c+4,"RegWrite_o", false,-1);
    tracep->declBit(c+5,"MemWrite_o", false,-1);
    tracep->declBus(c+6,"Resultsrc_o", false,-1, 1,0);
    tracep->declBus(c+7,"ALUctrl_o", false,-1, 2,0);
    tracep->declBit(c+8,"ALUsrc_o", false,-1);
    tracep->declBus(c+9,"PCsrc_o", false,-1, 1,0);
    tracep->declBus(c+10,"ImmOp_o", false,-1, 31,0);
    tracep->pushNamePrefix("control_top ");
    tracep->declBus(c+18,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+19,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+20,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+21,"IMM_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"PC_i", false,-1, 7,0);
    tracep->declBit(c+2,"Zero_i", false,-1);
    tracep->declBus(c+3,"instr_o", false,-1, 31,0);
    tracep->declBit(c+4,"RegWrite_o", false,-1);
    tracep->declBit(c+5,"MemWrite_o", false,-1);
    tracep->declBus(c+6,"Resultsrc_o", false,-1, 1,0);
    tracep->declBus(c+7,"ALUctrl_o", false,-1, 2,0);
    tracep->declBit(c+8,"ALUsrc_o", false,-1);
    tracep->declBus(c+9,"PCsrc_o", false,-1, 1,0);
    tracep->declBus(c+10,"ImmOp_o", false,-1, 31,0);
    tracep->declBus(c+11,"ImmSrc", false,-1, 1,0);
    tracep->pushNamePrefix("ControlUnit ");
    tracep->declBus(c+19,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+20,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+21,"IMM_WIDTH", false,-1, 31,0);
    tracep->declBit(c+2,"Zero_i", false,-1);
    tracep->declBus(c+3,"instr_i", false,-1, 31,0);
    tracep->declBit(c+4,"RegWrite_o", false,-1);
    tracep->declBit(c+5,"MemWrite_o", false,-1);
    tracep->declBus(c+6,"Resultsrc_o", false,-1, 1,0);
    tracep->declBus(c+7,"ALUctrl_o", false,-1, 2,0);
    tracep->declBit(c+8,"ALUsrc_o", false,-1);
    tracep->declBus(c+11,"ImmSrc_o", false,-1, 1,0);
    tracep->declBus(c+9,"PCsrc_o", false,-1, 1,0);
    tracep->declBus(c+12,"opcode", false,-1, 6,0);
    tracep->declBus(c+13,"funct3", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("InstrMem ");
    tracep->declBus(c+18,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+19,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"addr_i", false,-1, 7,0);
    tracep->declBus(c+3,"Instr_o", false,-1, 31,0);
    tracep->declBus(c+14,"rom_array0", false,-1, 7,0);
    tracep->declBus(c+15,"rom_array1", false,-1, 7,0);
    tracep->declBus(c+16,"rom_array2", false,-1, 7,0);
    tracep->declBus(c+17,"rom_array3", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MySignExtend ");
    tracep->declBus(c+19,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+21,"IMM_WIDTH", false,-1, 31,0);
    tracep->declBus(c+3,"instr_i", false,-1, 31,0);
    tracep->declBus(c+11,"ImmSrc_i", false,-1, 1,0);
    tracep->declBus(c+10,"ImmOp_o", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vcontrol_top___024root__trace_init_top(Vcontrol_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_init_top\n"); );
    // Body
    Vcontrol_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcontrol_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcontrol_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcontrol_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcontrol_top___024root__trace_register(Vcontrol_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vcontrol_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vcontrol_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vcontrol_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcontrol_top___024root__trace_full_sub_0(Vcontrol_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcontrol_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_full_top_0\n"); );
    // Init
    Vcontrol_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol_top___024root*>(voidSelf);
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vcontrol_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcontrol_top___024root__trace_full_sub_0(Vcontrol_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->PC_i),8);
    bufp->fullBit(oldp+2,(vlSelf->Zero_i));
    bufp->fullIData(oldp+3,(vlSelf->instr_o),32);
    bufp->fullBit(oldp+4,(vlSelf->RegWrite_o));
    bufp->fullBit(oldp+5,(vlSelf->MemWrite_o));
    bufp->fullCData(oldp+6,(vlSelf->Resultsrc_o),2);
    bufp->fullCData(oldp+7,(vlSelf->ALUctrl_o),3);
    bufp->fullBit(oldp+8,(vlSelf->ALUsrc_o));
    bufp->fullCData(oldp+9,(vlSelf->PCsrc_o),2);
    bufp->fullIData(oldp+10,(vlSelf->ImmOp_o),32);
    bufp->fullCData(oldp+11,(vlSelf->control_top__DOT__ImmSrc),2);
    bufp->fullCData(oldp+12,((0x7fU & vlSelf->instr_o)),7);
    bufp->fullCData(oldp+13,((7U & (vlSelf->instr_o 
                                    >> 0xcU))),3);
    bufp->fullCData(oldp+14,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                              [vlSelf->PC_i])),8);
    bufp->fullCData(oldp+15,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                              [(0xffU & ((IData)(1U) 
                                         + (IData)(vlSelf->PC_i)))])),8);
    bufp->fullCData(oldp+16,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                              [(0xffU & ((IData)(2U) 
                                         + (IData)(vlSelf->PC_i)))])),8);
    bufp->fullCData(oldp+17,((0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                              [(0xffU & ((IData)(3U) 
                                         + (IData)(vlSelf->PC_i)))])),8);
    bufp->fullIData(oldp+18,(8U),32);
    bufp->fullIData(oldp+19,(0x20U),32);
    bufp->fullIData(oldp+20,(3U),32);
    bufp->fullIData(oldp+21,(2U),32);
}
