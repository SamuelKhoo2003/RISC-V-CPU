// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


VL_ATTR_COLD void Vcpu___024root__trace_init_sub__TOP__0(Vcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBus(c+60,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBus(c+60,"a0", false,-1, 31,0);
    tracep->declBit(c+1,"RegWrite", false,-1);
    tracep->declBus(c+62,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+1,"ALUsrc", false,-1);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBus(c+3,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+4,"Instr", false,-1, 31,0);
    tracep->declBit(c+5,"EQ", false,-1);
    tracep->declBus(c+6,"PC", false,-1, 31,0);
    tracep->pushNamePrefix("Myblue ");
    tracep->declBus(c+63,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBus(c+7,"ImmOp", false,-1, 7,0);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBus(c+8,"pc_out", false,-1, 7,0);
    tracep->declBus(c+9,"next_PC", false,-1, 7,0);
    tracep->declBus(c+10,"pc", false,-1, 7,0);
    tracep->pushNamePrefix("pc_mux ");
    tracep->declBus(c+61,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBus(c+11,"pc", false,-1, 31,0);
    tracep->declBus(c+12,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+13,"next_PC", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBus(c+61,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBus(c+14,"next_PC", false,-1, 31,0);
    tracep->declBus(c+15,"pc", false,-1, 31,0);
    tracep->declBus(c+16,"another_pc", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Mygreen ");
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+6,"PC", false,-1, 31,0);
    tracep->declBit(c+5,"EQ", false,-1);
    tracep->declBus(c+4,"instr", false,-1, 31,0);
    tracep->declBit(c+1,"RegWrite", false,-1);
    tracep->declBus(c+62,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+1,"ALUsrc", false,-1);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBus(c+3,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+17,"ImmSrc", false,-1, 1,0);
    tracep->pushNamePrefix("MyControlUnit ");
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+5,"EQ", false,-1);
    tracep->declBus(c+4,"instr", false,-1, 31,0);
    tracep->declBus(c+4,"instr2", false,-1, 31,0);
    tracep->declBit(c+1,"RegWrite", false,-1);
    tracep->declBus(c+62,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+1,"ALUsrc", false,-1);
    tracep->declBus(c+17,"ImmSrc", false,-1, 1,0);
    tracep->declBit(c+2,"PCsrc", false,-1);
    tracep->declBus(c+18,"opcode", false,-1, 6,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MyInstrMem ");
    tracep->declBus(c+63,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+6,"addr", false,-1, 31,0);
    tracep->declBus(c+4,"dout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MySignExtend ");
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+4,"instr", false,-1, 31,0);
    tracep->declBus(c+17,"ImmSrc", false,-1, 1,0);
    tracep->declBus(c+3,"ImmOp", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("Myred ");
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+1,"ALUsrc", false,-1);
    tracep->declBus(c+62,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+4,"Instr", false,-1, 31,0);
    tracep->declBit(c+1,"RegWrite", false,-1);
    tracep->declBus(c+3,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+5,"EQ", false,-1);
    tracep->declBus(c+60,"a0", false,-1, 31,0);
    tracep->declBus(c+19,"ALUout", false,-1, 31,0);
    tracep->declBus(c+20,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+21,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+22,"regOp2", false,-1, 31,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+62,"ALUctrl", false,-1, 2,0);
    tracep->declBus(c+20,"ALUop1", false,-1, 31,0);
    tracep->declBus(c+21,"ALUop2", false,-1, 31,0);
    tracep->declBus(c+19,"SUM", false,-1, 31,0);
    tracep->declBus(c+62,"aluctrl2", false,-1, 2,0);
    tracep->declBit(c+5,"EQ", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ALUMux ");
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+22,"regOp2", false,-1, 31,0);
    tracep->declBus(c+3,"ImmOp", false,-1, 31,0);
    tracep->declBit(c+1,"ALUsrc", false,-1);
    tracep->declBus(c+21,"ALUop2", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register ");
    tracep->declBus(c+64,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+61,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+1,"WE3", false,-1);
    tracep->declBus(c+19,"WD3", false,-1, 31,0);
    tracep->declBus(c+4,"Instr", false,-1, 31,0);
    tracep->declBus(c+20,"RD1", false,-1, 31,0);
    tracep->declBus(c+22,"RD2", false,-1, 31,0);
    tracep->declBus(c+60,"a0", false,-1, 31,0);
    tracep->declBus(c+23,"rs2", false,-1, 4,0);
    tracep->declBus(c+24,"rs1", false,-1, 4,0);
    tracep->declBus(c+25,"rd", false,-1, 4,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+26+i*1,"reg_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void Vcpu___024root__trace_init_top(Vcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_init_top\n"); );
    // Body
    Vcpu___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcpu___024root__trace_register(Vcpu___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vcpu___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vcpu___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vcpu___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcpu___024root__trace_full_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcpu___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_full_top_0\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vcpu___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcpu___024root__trace_full_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(((0x13U == (0x7fU & vlSelf->cpu__DOT__Instr)) 
                           | (0x63U != (0x7fU & vlSelf->cpu__DOT__Instr)))));
    bufp->fullBit(oldp+2,(((0x13U != (0x7fU & vlSelf->cpu__DOT__Instr)) 
                           & ((0x63U == (0x7fU & vlSelf->cpu__DOT__Instr)) 
                              & (vlSelf->cpu__DOT__Myred__DOT__ALUop1 
                                 != vlSelf->cpu__DOT__Myred__DOT__ALUop2)))));
    bufp->fullIData(oldp+3,(vlSelf->cpu__DOT__ImmOp),32);
    bufp->fullIData(oldp+4,(vlSelf->cpu__DOT__Instr),32);
    bufp->fullBit(oldp+5,((vlSelf->cpu__DOT__Myred__DOT__ALUop1 
                           == vlSelf->cpu__DOT__Myred__DOT__ALUop2)));
    bufp->fullIData(oldp+6,((0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__another_pc)),32);
    bufp->fullCData(oldp+7,((0xffU & vlSelf->cpu__DOT__ImmOp)),8);
    bufp->fullCData(oldp+8,((0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__another_pc)),8);
    bufp->fullCData(oldp+9,((0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_mux__next_PC)),8);
    bufp->fullCData(oldp+10,((0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__pc)),8);
    bufp->fullIData(oldp+11,((0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__pc)),32);
    bufp->fullIData(oldp+12,((0xffU & vlSelf->cpu__DOT__ImmOp)),32);
    bufp->fullIData(oldp+13,(vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_mux__next_PC),32);
    bufp->fullIData(oldp+14,((0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_mux__next_PC)),32);
    bufp->fullIData(oldp+15,(vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__pc),32);
    bufp->fullIData(oldp+16,(vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__another_pc),32);
    bufp->fullCData(oldp+17,(vlSelf->cpu__DOT__Mygreen__DOT__ImmSrc),2);
    bufp->fullCData(oldp+18,((0x7fU & vlSelf->cpu__DOT__Instr)),7);
    bufp->fullIData(oldp+19,((vlSelf->cpu__DOT__Myred__DOT__ALUop1 
                              + vlSelf->cpu__DOT__Myred__DOT__ALUop2)),32);
    bufp->fullIData(oldp+20,(vlSelf->cpu__DOT__Myred__DOT__ALUop1),32);
    bufp->fullIData(oldp+21,(vlSelf->cpu__DOT__Myred__DOT__ALUop2),32);
    bufp->fullIData(oldp+22,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array
                             [(0x1fU & (vlSelf->cpu__DOT__Instr 
                                        >> 0x14U))]),32);
    bufp->fullCData(oldp+23,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+24,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+25,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+26,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[0]),32);
    bufp->fullIData(oldp+27,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[1]),32);
    bufp->fullIData(oldp+28,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[2]),32);
    bufp->fullIData(oldp+29,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[3]),32);
    bufp->fullIData(oldp+30,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[4]),32);
    bufp->fullIData(oldp+31,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[5]),32);
    bufp->fullIData(oldp+32,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[6]),32);
    bufp->fullIData(oldp+33,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[7]),32);
    bufp->fullIData(oldp+34,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[8]),32);
    bufp->fullIData(oldp+35,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[9]),32);
    bufp->fullIData(oldp+36,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[10]),32);
    bufp->fullIData(oldp+37,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[11]),32);
    bufp->fullIData(oldp+38,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[12]),32);
    bufp->fullIData(oldp+39,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[13]),32);
    bufp->fullIData(oldp+40,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[14]),32);
    bufp->fullIData(oldp+41,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[15]),32);
    bufp->fullIData(oldp+42,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[16]),32);
    bufp->fullIData(oldp+43,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[17]),32);
    bufp->fullIData(oldp+44,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[18]),32);
    bufp->fullIData(oldp+45,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[19]),32);
    bufp->fullIData(oldp+46,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[20]),32);
    bufp->fullIData(oldp+47,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[21]),32);
    bufp->fullIData(oldp+48,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[22]),32);
    bufp->fullIData(oldp+49,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[23]),32);
    bufp->fullIData(oldp+50,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[24]),32);
    bufp->fullIData(oldp+51,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[25]),32);
    bufp->fullIData(oldp+52,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[26]),32);
    bufp->fullIData(oldp+53,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[27]),32);
    bufp->fullIData(oldp+54,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[28]),32);
    bufp->fullIData(oldp+55,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[29]),32);
    bufp->fullIData(oldp+56,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[30]),32);
    bufp->fullIData(oldp+57,(vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[31]),32);
    bufp->fullBit(oldp+58,(vlSelf->clk));
    bufp->fullBit(oldp+59,(vlSelf->rst));
    bufp->fullIData(oldp+60,(vlSelf->a0),32);
    bufp->fullIData(oldp+61,(0x20U),32);
    bufp->fullCData(oldp+62,(0U),3);
    bufp->fullIData(oldp+63,(8U),32);
    bufp->fullIData(oldp+64,(5U),32);
}
