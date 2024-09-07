// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcpu__Syms.h"


void Vcpu___024root__trace_chg_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vcpu___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_chg_top_0\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vcpu___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vcpu___024root__trace_chg_sub_0(Vcpu___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->cpu__DOT__Instr),32);
        bufp->chgIData(oldp+1,(vlSelf->cpu__DOT__PC),32);
        bufp->chgIData(oldp+2,(((IData)(4U) + vlSelf->cpu__DOT__pc__DOT__PC)),32);
        bufp->chgIData(oldp+3,(vlSelf->cpu__DOT__alu__DOT__SrcA),32);
        bufp->chgIData(oldp+4,(vlSelf->cpu__DOT__alu__DOT__regOp2),32);
        bufp->chgSData(oldp+5,((0xffffU & vlSelf->cpu__DOT__alu__DOT__regOp2)),16);
        bufp->chgCData(oldp+6,((0xffU & vlSelf->cpu__DOT__alu__DOT__regOp2)),8);
        bufp->chgCData(oldp+7,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+8,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+9,((0x1fU & (vlSelf->cpu__DOT__Instr 
                                         >> 7U))),5);
        bufp->chgIData(oldp+10,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[0]),32);
        bufp->chgIData(oldp+11,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[1]),32);
        bufp->chgIData(oldp+12,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[2]),32);
        bufp->chgIData(oldp+13,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[3]),32);
        bufp->chgIData(oldp+14,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[4]),32);
        bufp->chgIData(oldp+15,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[5]),32);
        bufp->chgIData(oldp+16,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[6]),32);
        bufp->chgIData(oldp+17,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[7]),32);
        bufp->chgIData(oldp+18,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[8]),32);
        bufp->chgIData(oldp+19,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[9]),32);
        bufp->chgIData(oldp+20,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[10]),32);
        bufp->chgIData(oldp+21,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[11]),32);
        bufp->chgIData(oldp+22,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[12]),32);
        bufp->chgIData(oldp+23,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[13]),32);
        bufp->chgIData(oldp+24,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[14]),32);
        bufp->chgIData(oldp+25,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[15]),32);
        bufp->chgIData(oldp+26,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[16]),32);
        bufp->chgIData(oldp+27,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[17]),32);
        bufp->chgIData(oldp+28,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[18]),32);
        bufp->chgIData(oldp+29,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[19]),32);
        bufp->chgIData(oldp+30,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[20]),32);
        bufp->chgIData(oldp+31,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[21]),32);
        bufp->chgIData(oldp+32,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[22]),32);
        bufp->chgIData(oldp+33,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[23]),32);
        bufp->chgIData(oldp+34,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[24]),32);
        bufp->chgIData(oldp+35,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[25]),32);
        bufp->chgIData(oldp+36,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[26]),32);
        bufp->chgIData(oldp+37,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[27]),32);
        bufp->chgIData(oldp+38,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[28]),32);
        bufp->chgIData(oldp+39,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[29]),32);
        bufp->chgIData(oldp+40,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[30]),32);
        bufp->chgIData(oldp+41,(vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[31]),32);
        bufp->chgCData(oldp+42,((0x7fU & vlSelf->cpu__DOT__Instr)),7);
        bufp->chgCData(oldp+43,((7U & (vlSelf->cpu__DOT__Instr 
                                       >> 0xcU))),3);
        bufp->chgBit(oldp+44,((1U & (vlSelf->cpu__DOT__Instr 
                                     >> 0x1eU))));
        bufp->chgIData(oldp+45,(vlSelf->cpu__DOT__pc__DOT__PC),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+46,(vlSelf->cpu__DOT__RegWrite),3);
        bufp->chgCData(oldp+47,(vlSelf->cpu__DOT__MemWrite),2);
        bufp->chgCData(oldp+48,(vlSelf->cpu__DOT__ALUctrl),3);
        bufp->chgBit(oldp+49,(vlSelf->cpu__DOT__ALUsrc));
        bufp->chgIData(oldp+50,(vlSelf->cpu__DOT__ALUResult_o),32);
        bufp->chgCData(oldp+51,(vlSelf->cpu__DOT__Resultsrc),2);
        bufp->chgIData(oldp+52,(vlSelf->cpu__DOT__ImmOp),32);
        bufp->chgCData(oldp+53,(vlSelf->cpu__DOT__PCsrc),2);
        bufp->chgIData(oldp+54,(vlSelf->cpu__DOT__alu__DOT__SrcB),32);
        bufp->chgIData(oldp+55,(vlSelf->cpu__DOT__alu__DOT__Result),32);
        bufp->chgIData(oldp+56,((0x3ffffU & vlSelf->cpu__DOT__ALUResult_o)),18);
        bufp->chgCData(oldp+57,(vlSelf->cpu__DOT__control__DOT__ImmSrc),3);
        bufp->chgIData(oldp+58,(vlSelf->cpu__DOT__pc__DOT__next_PC),32);
    }
    bufp->chgBit(oldp+59,(vlSelf->clk));
    bufp->chgBit(oldp+60,(vlSelf->rst));
    bufp->chgIData(oldp+61,(vlSelf->a0),32);
    bufp->chgBit(oldp+62,((vlSelf->cpu__DOT__alu__DOT__SrcA 
                           == vlSelf->cpu__DOT__alu__DOT__SrcB)));
    bufp->chgIData(oldp+63,(((((0x20000U >= (0x3ffffU 
                                             & ((IData)(3U) 
                                                + vlSelf->cpu__DOT__ALUResult_o)))
                                ? vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                               [(0x3ffffU & ((IData)(3U) 
                                             + vlSelf->cpu__DOT__ALUResult_o))]
                                : 0U) << 0x18U) | (
                                                   (((0x20000U 
                                                      >= 
                                                      (0x3ffffU 
                                                       & ((IData)(2U) 
                                                          + vlSelf->cpu__DOT__ALUResult_o)))
                                                      ? 
                                                     vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                     [
                                                     (0x3ffffU 
                                                      & ((IData)(2U) 
                                                         + vlSelf->cpu__DOT__ALUResult_o))]
                                                      : 0U) 
                                                    << 0x10U) 
                                                   | ((((0x20000U 
                                                         >= 
                                                         (0x3ffffU 
                                                          & ((IData)(1U) 
                                                             + vlSelf->cpu__DOT__ALUResult_o)))
                                                         ? 
                                                        vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                        [
                                                        (0x3ffffU 
                                                         & ((IData)(1U) 
                                                            + vlSelf->cpu__DOT__ALUResult_o))]
                                                         : 0U) 
                                                       << 8U) 
                                                      | ((0x20000U 
                                                          >= 
                                                          (0x3ffffU 
                                                           & vlSelf->cpu__DOT__ALUResult_o))
                                                          ? 
                                                         vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                         [
                                                         (0x3ffffU 
                                                          & vlSelf->cpu__DOT__ALUResult_o)]
                                                          : 0U))))),32);
    bufp->chgIData(oldp+64,((vlSelf->cpu__DOT__pc__DOT__PC 
                             + vlSelf->cpu__DOT__ImmOp)),32);
}

void Vcpu___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root__trace_cleanup\n"); );
    // Init
    Vcpu___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcpu___024root*>(voidSelf);
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
