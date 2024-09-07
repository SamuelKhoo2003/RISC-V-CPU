// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


//======================

void Vcpu::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vcpu::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vcpu::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vcpu::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vcpu::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+63,"clk", false,-1);
        tracep->declBit(c+64,"rst", false,-1);
        tracep->declBus(c+65,"a0", false,-1, 31,0);
        tracep->declBus(c+66,"cpu DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+67,"cpu CONTROL_WIDTH", false,-1, 31,0);
        tracep->declBus(c+68,"cpu IMM_WIDTH", false,-1, 31,0);
        tracep->declBit(c+63,"cpu clk", false,-1);
        tracep->declBit(c+64,"cpu rst", false,-1);
        tracep->declBus(c+65,"cpu a0", false,-1, 31,0);
        tracep->declBus(c+1,"cpu RegWrite", false,-1, 2,0);
        tracep->declBus(c+2,"cpu MemWrite", false,-1, 1,0);
        tracep->declBus(c+3,"cpu Instr", false,-1, 31,0);
        tracep->declBus(c+4,"cpu ALUctrl", false,-1, 2,0);
        tracep->declBit(c+5,"cpu ALUsrc", false,-1);
        tracep->declBit(c+6,"cpu Zero", false,-1);
        tracep->declBus(c+7,"cpu ALUResult_o", false,-1, 31,0);
        tracep->declBus(c+8,"cpu Resultsrc", false,-1, 1,0);
        tracep->declBus(c+9,"cpu ImmOp", false,-1, 31,0);
        tracep->declBus(c+10,"cpu PCsrc", false,-1, 1,0);
        tracep->declBus(c+11,"cpu PC", false,-1, 31,0);
        tracep->declBus(c+12,"cpu PCPlus4", false,-1, 31,0);
        tracep->declBus(c+66,"cpu pc WIDTH", false,-1, 31,0);
        tracep->declBit(c+63,"cpu pc clk", false,-1);
        tracep->declBit(c+64,"cpu pc rst", false,-1);
        tracep->declBus(c+7,"cpu pc ALUResult_i", false,-1, 31,0);
        tracep->declBus(c+9,"cpu pc ImmOp_i", false,-1, 31,0);
        tracep->declBus(c+10,"cpu pc PCsrc_i", false,-1, 1,0);
        tracep->declBus(c+11,"cpu pc pc_out", false,-1, 31,0);
        tracep->declBus(c+12,"cpu pc PCPlus4_o", false,-1, 31,0);
        tracep->declBus(c+13,"cpu pc next_PC", false,-1, 31,0);
        tracep->declBus(c+14,"cpu pc PC", false,-1, 31,0);
        tracep->declBus(c+15,"cpu pc PCTarget", false,-1, 31,0);
        tracep->declBus(c+66,"cpu pc pc_mux DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+68,"cpu pc pc_mux CONTROL_WIDTH", false,-1, 31,0);
        tracep->declBus(c+10,"cpu pc pc_mux control", false,-1, 1,0);
        tracep->declBus(c+12,"cpu pc pc_mux input0", false,-1, 31,0);
        tracep->declBus(c+15,"cpu pc pc_mux input1", false,-1, 31,0);
        tracep->declBus(c+7,"cpu pc pc_mux input2", false,-1, 31,0);
        tracep->declBus(c+69,"cpu pc pc_mux input3", false,-1, 31,0);
        tracep->declBus(c+13,"cpu pc pc_mux out", false,-1, 31,0);
        tracep->declBus(c+66,"cpu pc pc_reg WIDTH", false,-1, 31,0);
        tracep->declBit(c+63,"cpu pc pc_reg clk", false,-1);
        tracep->declBit(c+64,"cpu pc pc_reg rst", false,-1);
        tracep->declBus(c+13,"cpu pc pc_reg next_PC", false,-1, 31,0);
        tracep->declBus(c+14,"cpu pc pc_reg pc", false,-1, 31,0);
        tracep->declBus(c+11,"cpu pc pc_reg another_pc", false,-1, 31,0);
        tracep->declBus(c+66,"cpu control DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+67,"cpu control CONTROL_WIDTH", false,-1, 31,0);
        tracep->declBus(c+68,"cpu control IMM_WIDTH", false,-1, 31,0);
        tracep->declBus(c+11,"cpu control PC_i", false,-1, 31,0);
        tracep->declBit(c+6,"cpu control Zero_i", false,-1);
        tracep->declBus(c+3,"cpu control instr_o", false,-1, 31,0);
        tracep->declBus(c+1,"cpu control RegWrite_o", false,-1, 2,0);
        tracep->declBus(c+2,"cpu control MemWrite_o", false,-1, 1,0);
        tracep->declBus(c+8,"cpu control Resultsrc_o", false,-1, 1,0);
        tracep->declBus(c+4,"cpu control ALUctrl_o", false,-1, 2,0);
        tracep->declBit(c+5,"cpu control ALUsrc_o", false,-1);
        tracep->declBus(c+10,"cpu control PCsrc_o", false,-1, 1,0);
        tracep->declBus(c+9,"cpu control ImmOp_o", false,-1, 31,0);
        tracep->declBus(c+16,"cpu control ImmSrc", false,-1, 2,0);
        tracep->declBus(c+66,"cpu control ControlUnit DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+67,"cpu control ControlUnit CONTROL_WIDTH", false,-1, 31,0);
        tracep->declBus(c+68,"cpu control ControlUnit IMM_WIDTH", false,-1, 31,0);
        tracep->declBit(c+6,"cpu control ControlUnit Zero_i", false,-1);
        tracep->declBus(c+3,"cpu control ControlUnit instr_i", false,-1, 31,0);
        tracep->declBus(c+1,"cpu control ControlUnit RegWrite_o", false,-1, 2,0);
        tracep->declBus(c+2,"cpu control ControlUnit MemWrite_o", false,-1, 1,0);
        tracep->declBus(c+8,"cpu control ControlUnit Resultsrc_o", false,-1, 1,0);
        tracep->declBus(c+4,"cpu control ControlUnit ALUctrl_o", false,-1, 2,0);
        tracep->declBit(c+5,"cpu control ControlUnit ALUsrc_o", false,-1);
        tracep->declBus(c+16,"cpu control ControlUnit ImmSrc_o", false,-1, 2,0);
        tracep->declBus(c+10,"cpu control ControlUnit PCsrc_o", false,-1, 1,0);
        tracep->declBus(c+17,"cpu control ControlUnit opcode", false,-1, 6,0);
        tracep->declBus(c+18,"cpu control ControlUnit funct3", false,-1, 2,0);
        tracep->declBit(c+19,"cpu control ControlUnit funct7", false,-1);
        tracep->declBus(c+70,"cpu control InstrMem ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"cpu control InstrMem DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+11,"cpu control InstrMem addr_i", false,-1, 31,0);
        tracep->declBus(c+3,"cpu control InstrMem Instr_o", false,-1, 31,0);
        tracep->declBus(c+66,"cpu control MySignExtend DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+3,"cpu control MySignExtend instr_i", false,-1, 31,0);
        tracep->declBus(c+16,"cpu control MySignExtend ImmSrc_i", false,-1, 2,0);
        tracep->declBus(c+9,"cpu control MySignExtend ImmOp_o", false,-1, 31,0);
        tracep->declBus(c+67,"cpu alu CONTROL_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"cpu alu DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+63,"cpu alu clk", false,-1);
        tracep->declBit(c+5,"cpu alu ALUsrc_i", false,-1);
        tracep->declBus(c+4,"cpu alu ALUctrl_i", false,-1, 2,0);
        tracep->declBus(c+3,"cpu alu Instr_i", false,-1, 31,0);
        tracep->declBus(c+1,"cpu alu RegWrite_i", false,-1, 2,0);
        tracep->declBus(c+8,"cpu alu ResultSrc_i", false,-1, 1,0);
        tracep->declBus(c+2,"cpu alu MemWrite_i", false,-1, 1,0);
        tracep->declBus(c+9,"cpu alu ImmOp_i", false,-1, 31,0);
        tracep->declBus(c+12,"cpu alu PCPlus4_i", false,-1, 31,0);
        tracep->declBit(c+6,"cpu alu Zero_o", false,-1);
        tracep->declBus(c+65,"cpu alu a0", false,-1, 31,0);
        tracep->declBus(c+7,"cpu alu ALUResult_o", false,-1, 31,0);
        tracep->declBus(c+20,"cpu alu SrcA", false,-1, 31,0);
        tracep->declBus(c+21,"cpu alu SrcB", false,-1, 31,0);
        tracep->declBus(c+22,"cpu alu Result", false,-1, 31,0);
        tracep->declBus(c+23,"cpu alu regOp2", false,-1, 31,0);
        tracep->declBus(c+24,"cpu alu ReadData", false,-1, 31,0);
        tracep->declBus(c+71,"cpu alu register ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"cpu alu register DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+63,"cpu alu register clk", false,-1);
        tracep->declBus(c+1,"cpu alu register WE3", false,-1, 2,0);
        tracep->declBus(c+22,"cpu alu register WD3", false,-1, 31,0);
        tracep->declBus(c+3,"cpu alu register Instr", false,-1, 31,0);
        tracep->declBus(c+20,"cpu alu register RD1", false,-1, 31,0);
        tracep->declBus(c+23,"cpu alu register RD2", false,-1, 31,0);
        tracep->declBus(c+65,"cpu alu register a0", false,-1, 31,0);
        tracep->declBus(c+25,"cpu alu register A2", false,-1, 4,0);
        tracep->declBus(c+26,"cpu alu register A1", false,-1, 4,0);
        tracep->declBus(c+27,"cpu alu register A3", false,-1, 4,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+28+i*1,"cpu alu register reg_array", true,(i+0), 31,0);}}
        tracep->declBus(c+66,"cpu alu ALUMux DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+5,"cpu alu ALUMux control", false,-1);
        tracep->declBus(c+23,"cpu alu ALUMux input0", false,-1, 31,0);
        tracep->declBus(c+9,"cpu alu ALUMux input1", false,-1, 31,0);
        tracep->declBus(c+21,"cpu alu ALUMux out", false,-1, 31,0);
        tracep->declBus(c+67,"cpu alu ALU CONTROL_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"cpu alu ALU DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+4,"cpu alu ALU ALUctrl_i", false,-1, 2,0);
        tracep->declBus(c+20,"cpu alu ALU SrcA_i", false,-1, 31,0);
        tracep->declBus(c+21,"cpu alu ALU SrcB_i", false,-1, 31,0);
        tracep->declBus(c+7,"cpu alu ALU ALUResult_o", false,-1, 31,0);
        tracep->declBit(c+6,"cpu alu ALU Zero_o", false,-1);
        tracep->declBus(c+70,"cpu alu data ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+66,"cpu alu data DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+72,"cpu alu data START_ADDRESS", false,-1, 31,0);
        tracep->declBit(c+63,"cpu alu data clk", false,-1);
        tracep->declBus(c+2,"cpu alu data WE_i", false,-1, 1,0);
        tracep->declBus(c+7,"cpu alu data A_i", false,-1, 31,0);
        tracep->declBus(c+23,"cpu alu data WD_i", false,-1, 31,0);
        tracep->declBus(c+24,"cpu alu data RD_o", false,-1, 31,0);
        tracep->declBus(c+60,"cpu alu data add", false,-1, 17,0);
        tracep->declBus(c+61,"cpu alu data data16", false,-1, 15,0);
        tracep->declBus(c+62,"cpu alu data data8", false,-1, 7,0);
        tracep->declBus(c+66,"cpu alu resultMux DATA_WIDTH", false,-1, 31,0);
        tracep->declBus(c+68,"cpu alu resultMux CONTROL_WIDTH", false,-1, 31,0);
        tracep->declBus(c+8,"cpu alu resultMux control", false,-1, 1,0);
        tracep->declBus(c+7,"cpu alu resultMux input0", false,-1, 31,0);
        tracep->declBus(c+24,"cpu alu resultMux input1", false,-1, 31,0);
        tracep->declBus(c+12,"cpu alu resultMux input2", false,-1, 31,0);
        tracep->declBus(c+73,"cpu alu resultMux input3", false,-1, 31,0);
        tracep->declBus(c+22,"cpu alu resultMux out", false,-1, 31,0);
    }
}

void Vcpu::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vcpu::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vcpu::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vcpu__Syms* __restrict vlSymsp = static_cast<Vcpu__Syms*>(userp);
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullCData(oldp+1,(vlTOPp->cpu__DOT__RegWrite),3);
        tracep->fullCData(oldp+2,(vlTOPp->cpu__DOT__MemWrite),2);
        tracep->fullIData(oldp+3,(vlTOPp->cpu__DOT__Instr),32);
        tracep->fullCData(oldp+4,(vlTOPp->cpu__DOT__ALUctrl),3);
        tracep->fullBit(oldp+5,((1U & ((0x40U & vlTOPp->cpu__DOT__Instr)
                                        ? ((~ (vlTOPp->cpu__DOT__Instr 
                                               >> 5U)) 
                                           | ((vlTOPp->cpu__DOT__Instr 
                                               >> 4U) 
                                              | ((vlTOPp->cpu__DOT__Instr 
                                                  >> 3U) 
                                                 | ((vlTOPp->cpu__DOT__Instr 
                                                     >> 2U) 
                                                    | ((~ 
                                                        (vlTOPp->cpu__DOT__Instr 
                                                         >> 1U)) 
                                                       | (~ vlTOPp->cpu__DOT__Instr))))))
                                        : ((~ (vlTOPp->cpu__DOT__Instr 
                                               >> 5U)) 
                                           | ((~ (vlTOPp->cpu__DOT__Instr 
                                                  >> 4U)) 
                                              | ((vlTOPp->cpu__DOT__Instr 
                                                  >> 3U) 
                                                 | ((vlTOPp->cpu__DOT__Instr 
                                                     >> 2U) 
                                                    | ((~ 
                                                        (vlTOPp->cpu__DOT__Instr 
                                                         >> 1U)) 
                                                       | (~ vlTOPp->cpu__DOT__Instr))))))))));
        tracep->fullBit(oldp+6,(vlTOPp->cpu__DOT__Zero));
        tracep->fullIData(oldp+7,(vlTOPp->cpu__DOT__ALUResult_o),32);
        tracep->fullCData(oldp+8,(vlTOPp->cpu__DOT__Resultsrc),2);
        tracep->fullIData(oldp+9,(vlTOPp->cpu__DOT__ImmOp),32);
        tracep->fullCData(oldp+10,(vlTOPp->cpu__DOT__PCsrc),2);
        tracep->fullIData(oldp+11,(vlTOPp->cpu__DOT__PC),32);
        tracep->fullIData(oldp+12,(((IData)(4U) + vlTOPp->cpu__DOT__pc__DOT__PC)),32);
        tracep->fullIData(oldp+13,(vlTOPp->cpu__DOT__pc__DOT__next_PC),32);
        tracep->fullIData(oldp+14,(vlTOPp->cpu__DOT__pc__DOT__PC),32);
        tracep->fullIData(oldp+15,((vlTOPp->cpu__DOT__pc__DOT__PC 
                                    + vlTOPp->cpu__DOT__ImmOp)),32);
        tracep->fullCData(oldp+16,(vlTOPp->cpu__DOT__control__DOT__ImmSrc),3);
        tracep->fullCData(oldp+17,((0x7fU & vlTOPp->cpu__DOT__Instr)),7);
        tracep->fullCData(oldp+18,((7U & (vlTOPp->cpu__DOT__Instr 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+19,((1U & (vlTOPp->cpu__DOT__Instr 
                                        >> 0x1eU))));
        tracep->fullIData(oldp+20,(vlTOPp->cpu__DOT__alu__DOT__SrcA),32);
        tracep->fullIData(oldp+21,(vlTOPp->cpu__DOT__alu__DOT__SrcB),32);
        tracep->fullIData(oldp+22,(vlTOPp->cpu__DOT__alu__DOT__Result),32);
        tracep->fullIData(oldp+23,(vlTOPp->cpu__DOT__alu__DOT__regOp2),32);
        tracep->fullIData(oldp+24,(((((0x20000U >= 
                                       (0x3ffffU & 
                                        ((IData)(3U) 
                                         + vlTOPp->cpu__DOT__ALUResult_o)))
                                       ? vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                      [(0x3ffffU & 
                                        ((IData)(3U) 
                                         + vlTOPp->cpu__DOT__ALUResult_o))]
                                       : 0U) << 0x18U) 
                                    | ((((0x20000U 
                                          >= (0x3ffffU 
                                              & ((IData)(2U) 
                                                 + vlTOPp->cpu__DOT__ALUResult_o)))
                                          ? vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                         [(0x3ffffU 
                                           & ((IData)(2U) 
                                              + vlTOPp->cpu__DOT__ALUResult_o))]
                                          : 0U) << 0x10U) 
                                       | ((((0x20000U 
                                             >= (0x3ffffU 
                                                 & ((IData)(1U) 
                                                    + vlTOPp->cpu__DOT__ALUResult_o)))
                                             ? vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                            [(0x3ffffU 
                                              & ((IData)(1U) 
                                                 + vlTOPp->cpu__DOT__ALUResult_o))]
                                             : 0U) 
                                           << 8U) | 
                                          ((0x20000U 
                                            >= (0x3ffffU 
                                                & vlTOPp->cpu__DOT__ALUResult_o))
                                            ? vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                           [(0x3ffffU 
                                             & vlTOPp->cpu__DOT__ALUResult_o)]
                                            : 0U))))),32);
        tracep->fullCData(oldp+25,((0x1fU & (vlTOPp->cpu__DOT__Instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+26,((0x1fU & (vlTOPp->cpu__DOT__Instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+27,((0x1fU & (vlTOPp->cpu__DOT__Instr 
                                             >> 7U))),5);
        tracep->fullIData(oldp+28,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[0]),32);
        tracep->fullIData(oldp+29,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[1]),32);
        tracep->fullIData(oldp+30,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[2]),32);
        tracep->fullIData(oldp+31,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[3]),32);
        tracep->fullIData(oldp+32,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[4]),32);
        tracep->fullIData(oldp+33,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[5]),32);
        tracep->fullIData(oldp+34,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[6]),32);
        tracep->fullIData(oldp+35,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[7]),32);
        tracep->fullIData(oldp+36,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[8]),32);
        tracep->fullIData(oldp+37,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[9]),32);
        tracep->fullIData(oldp+38,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[10]),32);
        tracep->fullIData(oldp+39,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[11]),32);
        tracep->fullIData(oldp+40,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[12]),32);
        tracep->fullIData(oldp+41,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[13]),32);
        tracep->fullIData(oldp+42,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[14]),32);
        tracep->fullIData(oldp+43,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[15]),32);
        tracep->fullIData(oldp+44,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[16]),32);
        tracep->fullIData(oldp+45,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[17]),32);
        tracep->fullIData(oldp+46,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[18]),32);
        tracep->fullIData(oldp+47,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[19]),32);
        tracep->fullIData(oldp+48,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[20]),32);
        tracep->fullIData(oldp+49,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[21]),32);
        tracep->fullIData(oldp+50,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[22]),32);
        tracep->fullIData(oldp+51,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[23]),32);
        tracep->fullIData(oldp+52,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[24]),32);
        tracep->fullIData(oldp+53,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[25]),32);
        tracep->fullIData(oldp+54,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[26]),32);
        tracep->fullIData(oldp+55,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[27]),32);
        tracep->fullIData(oldp+56,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[28]),32);
        tracep->fullIData(oldp+57,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[29]),32);
        tracep->fullIData(oldp+58,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[30]),32);
        tracep->fullIData(oldp+59,(vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[31]),32);
        tracep->fullIData(oldp+60,((0x3ffffU & vlTOPp->cpu__DOT__ALUResult_o)),18);
        tracep->fullSData(oldp+61,((0xffffU & vlTOPp->cpu__DOT__alu__DOT__regOp2)),16);
        tracep->fullCData(oldp+62,((0xffU & vlTOPp->cpu__DOT__alu__DOT__regOp2)),8);
        tracep->fullBit(oldp+63,(vlTOPp->clk));
        tracep->fullBit(oldp+64,(vlTOPp->rst));
        tracep->fullIData(oldp+65,(vlTOPp->a0),32);
        tracep->fullIData(oldp+66,(0x20U),32);
        tracep->fullIData(oldp+67,(3U),32);
        tracep->fullIData(oldp+68,(2U),32);
        tracep->fullIData(oldp+69,(vlTOPp->cpu__DOT__pc__DOT__pc_mux__DOT__input3),32);
        tracep->fullIData(oldp+70,(8U),32);
        tracep->fullIData(oldp+71,(5U),32);
        tracep->fullIData(oldp+72,(0x10000U),32);
        tracep->fullIData(oldp+73,(vlTOPp->cpu__DOT__alu__DOT__resultMux__DOT__input3),32);
    }
}
