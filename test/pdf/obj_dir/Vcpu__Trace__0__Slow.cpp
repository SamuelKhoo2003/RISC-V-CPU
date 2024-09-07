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
    tracep->declBit(c+60,"clk", false,-1);
    tracep->declBit(c+61,"rst", false,-1);
    tracep->declBus(c+62,"a0", false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+67,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"IMM_WIDTH", false,-1, 31,0);
    tracep->declBit(c+60,"clk", false,-1);
    tracep->declBit(c+61,"rst", false,-1);
    tracep->declBus(c+62,"a0", false,-1, 31,0);
    tracep->declBus(c+47,"RegWrite", false,-1, 2,0);
    tracep->declBus(c+48,"MemWrite", false,-1, 1,0);
    tracep->declBus(c+1,"Instr", false,-1, 31,0);
    tracep->declBus(c+49,"ALUctrl", false,-1, 2,0);
    tracep->declBit(c+50,"ALUsrc", false,-1);
    tracep->declBit(c+63,"Zero", false,-1);
    tracep->declBus(c+51,"ALUResult_o", false,-1, 31,0);
    tracep->declBus(c+52,"Resultsrc", false,-1, 1,0);
    tracep->declBus(c+53,"ImmOp", false,-1, 31,0);
    tracep->declBus(c+54,"PCsrc", false,-1, 1,0);
    tracep->declBus(c+2,"PC", false,-1, 31,0);
    tracep->declBus(c+3,"PCPlus4", false,-1, 31,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+67,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+60,"clk", false,-1);
    tracep->declBit(c+50,"ALUsrc_i", false,-1);
    tracep->declBus(c+49,"ALUctrl_i", false,-1, 2,0);
    tracep->declBus(c+1,"Instr_i", false,-1, 31,0);
    tracep->declBus(c+47,"RegWrite_i", false,-1, 2,0);
    tracep->declBus(c+52,"ResultSrc_i", false,-1, 1,0);
    tracep->declBus(c+48,"MemWrite_i", false,-1, 1,0);
    tracep->declBus(c+53,"ImmOp_i", false,-1, 31,0);
    tracep->declBus(c+3,"PCPlus4_i", false,-1, 31,0);
    tracep->declBit(c+63,"Zero_o", false,-1);
    tracep->declBus(c+62,"a0", false,-1, 31,0);
    tracep->declBus(c+51,"ALUResult_o", false,-1, 31,0);
    tracep->declBus(c+4,"SrcA", false,-1, 31,0);
    tracep->declBus(c+55,"SrcB", false,-1, 31,0);
    tracep->declBus(c+56,"Result", false,-1, 31,0);
    tracep->declBus(c+5,"regOp2", false,-1, 31,0);
    tracep->declBus(c+64,"ReadData", false,-1, 31,0);
    tracep->pushNamePrefix("ALU ");
    tracep->declBus(c+67,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+49,"ALUctrl_i", false,-1, 2,0);
    tracep->declBus(c+4,"SrcA_i", false,-1, 31,0);
    tracep->declBus(c+55,"SrcB_i", false,-1, 31,0);
    tracep->declBus(c+51,"ALUResult_o", false,-1, 31,0);
    tracep->declBit(c+63,"Zero_o", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ALUMux ");
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+50,"control", false,-1);
    tracep->declBus(c+5,"input0", false,-1, 31,0);
    tracep->declBus(c+53,"input1", false,-1, 31,0);
    tracep->declBus(c+55,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("data ");
    tracep->declBus(c+69,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+70,"START_ADDRESS", false,-1, 31,0);
    tracep->declBit(c+60,"clk", false,-1);
    tracep->declBus(c+48,"WE_i", false,-1, 1,0);
    tracep->declBus(c+51,"A_i", false,-1, 31,0);
    tracep->declBus(c+5,"WD_i", false,-1, 31,0);
    tracep->declBus(c+64,"RD_o", false,-1, 31,0);
    tracep->declBus(c+57,"add", false,-1, 17,0);
    tracep->declBus(c+6,"data16", false,-1, 15,0);
    tracep->declBus(c+7,"data8", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("register ");
    tracep->declBus(c+71,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+60,"clk", false,-1);
    tracep->declBus(c+47,"WE3", false,-1, 2,0);
    tracep->declBus(c+56,"WD3", false,-1, 31,0);
    tracep->declBus(c+1,"Instr", false,-1, 31,0);
    tracep->declBus(c+4,"RD1", false,-1, 31,0);
    tracep->declBus(c+5,"RD2", false,-1, 31,0);
    tracep->declBus(c+62,"a0", false,-1, 31,0);
    tracep->declBus(c+8,"A2", false,-1, 4,0);
    tracep->declBus(c+9,"A1", false,-1, 4,0);
    tracep->declBus(c+10,"A3", false,-1, 4,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+11+i*1,"reg_array", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("resultMux ");
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+52,"control", false,-1, 1,0);
    tracep->declBus(c+51,"input0", false,-1, 31,0);
    tracep->declBus(c+64,"input1", false,-1, 31,0);
    tracep->declBus(c+3,"input2", false,-1, 31,0);
    tracep->declBus(c+72,"input3", false,-1, 31,0);
    tracep->declBus(c+56,"out", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("control ");
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+67,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"IMM_WIDTH", false,-1, 31,0);
    tracep->declBus(c+2,"PC_i", false,-1, 31,0);
    tracep->declBit(c+63,"Zero_i", false,-1);
    tracep->declBus(c+1,"instr_o", false,-1, 31,0);
    tracep->declBus(c+47,"RegWrite_o", false,-1, 2,0);
    tracep->declBus(c+48,"MemWrite_o", false,-1, 1,0);
    tracep->declBus(c+52,"Resultsrc_o", false,-1, 1,0);
    tracep->declBus(c+49,"ALUctrl_o", false,-1, 2,0);
    tracep->declBit(c+50,"ALUsrc_o", false,-1);
    tracep->declBus(c+54,"PCsrc_o", false,-1, 1,0);
    tracep->declBus(c+53,"ImmOp_o", false,-1, 31,0);
    tracep->declBus(c+58,"ImmSrc", false,-1, 2,0);
    tracep->pushNamePrefix("ControlUnit ");
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+67,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"IMM_WIDTH", false,-1, 31,0);
    tracep->declBit(c+63,"Zero_i", false,-1);
    tracep->declBus(c+1,"instr_i", false,-1, 31,0);
    tracep->declBus(c+47,"RegWrite_o", false,-1, 2,0);
    tracep->declBus(c+48,"MemWrite_o", false,-1, 1,0);
    tracep->declBus(c+52,"Resultsrc_o", false,-1, 1,0);
    tracep->declBus(c+49,"ALUctrl_o", false,-1, 2,0);
    tracep->declBit(c+50,"ALUsrc_o", false,-1);
    tracep->declBus(c+58,"ImmSrc_o", false,-1, 2,0);
    tracep->declBus(c+54,"PCsrc_o", false,-1, 1,0);
    tracep->declBus(c+43,"opcode", false,-1, 6,0);
    tracep->declBus(c+44,"funct3", false,-1, 2,0);
    tracep->declBit(c+45,"funct7", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("InstrMem ");
    tracep->declBus(c+69,"ADDRESS_WIDTH", false,-1, 31,0);
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+2,"addr_i", false,-1, 31,0);
    tracep->declBus(c+1,"Instr_o", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("MySignExtend ");
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+1,"instr_i", false,-1, 31,0);
    tracep->declBus(c+58,"ImmSrc_i", false,-1, 2,0);
    tracep->declBus(c+53,"ImmOp_o", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("pc ");
    tracep->declBus(c+66,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+60,"clk", false,-1);
    tracep->declBit(c+61,"rst", false,-1);
    tracep->declBus(c+51,"ALUResult_i", false,-1, 31,0);
    tracep->declBus(c+53,"ImmOp_i", false,-1, 31,0);
    tracep->declBus(c+54,"PCsrc_i", false,-1, 1,0);
    tracep->declBus(c+2,"pc_out", false,-1, 31,0);
    tracep->declBus(c+3,"PCPlus4_o", false,-1, 31,0);
    tracep->declBus(c+59,"next_PC", false,-1, 31,0);
    tracep->declBus(c+46,"PC", false,-1, 31,0);
    tracep->declBus(c+65,"PCTarget", false,-1, 31,0);
    tracep->pushNamePrefix("pc_mux ");
    tracep->declBus(c+66,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+68,"CONTROL_WIDTH", false,-1, 31,0);
    tracep->declBus(c+54,"control", false,-1, 1,0);
    tracep->declBus(c+3,"input0", false,-1, 31,0);
    tracep->declBus(c+65,"input1", false,-1, 31,0);
    tracep->declBus(c+51,"input2", false,-1, 31,0);
    tracep->declBus(c+73,"input3", false,-1, 31,0);
    tracep->declBus(c+59,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pc_reg ");
    tracep->declBus(c+66,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+60,"clk", false,-1);
    tracep->declBit(c+61,"rst", false,-1);
    tracep->declBus(c+59,"next_PC", false,-1, 31,0);
    tracep->declBus(c+46,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"another_pc", false,-1, 31,0);
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
    bufp->fullIData(oldp+1,(vlSelf->cpu__DOT__Instr),32);
    bufp->fullIData(oldp+2,(vlSelf->cpu__DOT__PC),32);
    bufp->fullIData(oldp+3,(((IData)(4U) + vlSelf->cpu__DOT__pc__DOT__PC)),32);
    bufp->fullIData(oldp+4,(vlSelf->cpu__DOT__alu__DOT__SrcA),32);
    bufp->fullIData(oldp+5,(vlSelf->cpu__DOT__alu__DOT__regOp2),32);
    bufp->fullSData(oldp+6,((0xffffU & vlSelf->cpu__DOT__alu__DOT__regOp2)),16);
    bufp->fullCData(oldp+7,((0xffU & vlSelf->cpu__DOT__alu__DOT__regOp2)),8);
    bufp->fullCData(oldp+8,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                      >> 0x14U))),5);
    bufp->fullCData(oldp+9,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+10,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+11,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[0]),32);
    bufp->fullIData(oldp+12,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[1]),32);
    bufp->fullIData(oldp+13,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[2]),32);
    bufp->fullIData(oldp+14,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[3]),32);
    bufp->fullIData(oldp+15,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[4]),32);
    bufp->fullIData(oldp+16,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[5]),32);
    bufp->fullIData(oldp+17,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[6]),32);
    bufp->fullIData(oldp+18,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[7]),32);
    bufp->fullIData(oldp+19,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[8]),32);
    bufp->fullIData(oldp+20,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[9]),32);
    bufp->fullIData(oldp+21,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[10]),32);
    bufp->fullIData(oldp+22,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[11]),32);
    bufp->fullIData(oldp+23,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[12]),32);
    bufp->fullIData(oldp+24,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[13]),32);
    bufp->fullIData(oldp+25,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[14]),32);
    bufp->fullIData(oldp+26,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[15]),32);
    bufp->fullIData(oldp+27,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[16]),32);
    bufp->fullIData(oldp+28,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[17]),32);
    bufp->fullIData(oldp+29,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[18]),32);
    bufp->fullIData(oldp+30,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[19]),32);
    bufp->fullIData(oldp+31,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[20]),32);
    bufp->fullIData(oldp+32,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[21]),32);
    bufp->fullIData(oldp+33,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[22]),32);
    bufp->fullIData(oldp+34,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[23]),32);
    bufp->fullIData(oldp+35,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[24]),32);
    bufp->fullIData(oldp+36,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[25]),32);
    bufp->fullIData(oldp+37,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[26]),32);
    bufp->fullIData(oldp+38,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[27]),32);
    bufp->fullIData(oldp+39,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[28]),32);
    bufp->fullIData(oldp+40,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[29]),32);
    bufp->fullIData(oldp+41,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[30]),32);
    bufp->fullIData(oldp+42,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[31]),32);
    bufp->fullCData(oldp+43,((0x7fU & vlSelf->cpu__DOT__Instr)),7);
    bufp->fullCData(oldp+44,((7U & (vlSelf->cpu__DOT__Instr 
                                    >> 0xcU))),3);
    bufp->fullBit(oldp+45,((1U & (vlSelf->cpu__DOT__Instr 
                                  >> 0x1eU))));
    bufp->fullIData(oldp+46,(vlSelf->cpu__DOT__pc__DOT__PC),32);
    bufp->fullCData(oldp+47,(vlSelf->cpu__DOT__RegWrite),3);
    bufp->fullCData(oldp+48,(vlSelf->cpu__DOT__MemWrite),2);
    bufp->fullCData(oldp+49,(vlSelf->cpu__DOT__ALUctrl),3);
    bufp->fullBit(oldp+50,(vlSelf->cpu__DOT__ALUsrc));
    bufp->fullIData(oldp+51,(vlSelf->cpu__DOT__ALUResult_o),32);
    bufp->fullCData(oldp+52,(vlSelf->cpu__DOT__Resultsrc),2);
    bufp->fullIData(oldp+53,(vlSelf->cpu__DOT__ImmOp),32);
    bufp->fullCData(oldp+54,(vlSelf->cpu__DOT__PCsrc),2);
    bufp->fullIData(oldp+55,(vlSelf->cpu__DOT__alu__DOT__SrcB),32);
    bufp->fullIData(oldp+56,(vlSelf->cpu__DOT__alu__DOT__Result),32);
    bufp->fullIData(oldp+57,((0x3ffffU & vlSelf->cpu__DOT__ALUResult_o)),18);
    bufp->fullCData(oldp+58,(vlSelf->cpu__DOT__control__DOT__ImmSrc),3);
    bufp->fullIData(oldp+59,(vlSelf->cpu__DOT__pc__DOT__next_PC),32);
    bufp->fullBit(oldp+60,(vlSelf->clk));
    bufp->fullBit(oldp+61,(vlSelf->rst));
    bufp->fullIData(oldp+62,(vlSelf->a0),32);
    bufp->fullBit(oldp+63,((vlSelf->cpu__DOT__alu__DOT__SrcA 
                            == vlSelf->cpu__DOT__alu__DOT__SrcB)));
    bufp->fullIData(oldp+64,(((((0x20000U >= (0x3ffffU 
                                              & ((IData)(3U) 
                                                 + vlSelf->cpu__DOT__ALUResult_o)))
                                 ? vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                [(0x3ffffU & ((IData)(3U) 
                                              + vlSelf->cpu__DOT__ALUResult_o))]
                                 : 0U) << 0x18U) | 
                              ((((0x20000U >= (0x3ffffU 
                                               & ((IData)(2U) 
                                                  + vlSelf->cpu__DOT__ALUResult_o)))
                                  ? vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                 [(0x3ffffU & ((IData)(2U) 
                                               + vlSelf->cpu__DOT__ALUResult_o))]
                                  : 0U) << 0x10U) | 
                               ((((0x20000U >= (0x3ffffU 
                                                & ((IData)(1U) 
                                                   + vlSelf->cpu__DOT__ALUResult_o)))
                                   ? vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                  [(0x3ffffU & ((IData)(1U) 
                                                + vlSelf->cpu__DOT__ALUResult_o))]
                                   : 0U) << 8U) | (
                                                   (0x20000U 
                                                    >= 
                                                    (0x3ffffU 
                                                     & vlSelf->cpu__DOT__ALUResult_o))
                                                    ? 
                                                   vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                   [
                                                   (0x3ffffU 
                                                    & vlSelf->cpu__DOT__ALUResult_o)]
                                                    : 0U))))),32);
    bufp->fullIData(oldp+65,((vlSelf->cpu__DOT__pc__DOT__PC 
                              + vlSelf->cpu__DOT__ImmOp)),32);
    bufp->fullIData(oldp+66,(0x20U),32);
    bufp->fullIData(oldp+67,(3U),32);
    bufp->fullIData(oldp+68,(2U),32);
    bufp->fullIData(oldp+69,(8U),32);
    bufp->fullIData(oldp+70,(0x10000U),32);
    bufp->fullIData(oldp+71,(5U),32);
    bufp->fullIData(oldp+72,(vlSelf->cpu__DOT__alu__DOT__resultMux__DOT__input3),32);
    bufp->fullIData(oldp+73,(vlSelf->cpu__DOT__pc__DOT__pc_mux__DOT__input3),32);
}
