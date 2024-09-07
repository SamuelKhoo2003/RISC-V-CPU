// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgreen.h for the primary calling header

#include "verilated.h"

#include "Vgreen___024root.h"

VL_INLINE_OPT void Vgreen___024root___combo__TOP__0(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->instr = ((vlSelf->green__DOT__MyInstrMem__DOT__rom_array
                      [(0xffU & ((IData)(3U) + (IData)(vlSelf->PC)))] 
                      << 0x18U) | ((vlSelf->green__DOT__MyInstrMem__DOT__rom_array
                                    [(0xffU & ((IData)(2U) 
                                               + (IData)(vlSelf->PC)))] 
                                    << 0x10U) | ((vlSelf->green__DOT__MyInstrMem__DOT__rom_array
                                                  [
                                                  (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->PC)))] 
                                                  << 8U) 
                                                 | vlSelf->green__DOT__MyInstrMem__DOT__rom_array
                                                 [vlSelf->PC])));
    vlSelf->RegWrite = ((0x13U == (0x7fU & vlSelf->instr)) 
                        | (0x63U != (0x7fU & vlSelf->instr)));
    vlSelf->ALUsrc = ((0x13U == (0x7fU & vlSelf->instr)) 
                      | (0x63U != (0x7fU & vlSelf->instr)));
    vlSelf->PCsrc = ((0x13U != (0x7fU & vlSelf->instr)) 
                     & ((0x63U == (0x7fU & vlSelf->instr)) 
                        & (IData)(vlSelf->EQ)));
    vlSelf->green__DOT__ImmSrc = ((0x13U == (0x7fU 
                                             & vlSelf->instr))
                                   ? 1U : ((0x63U == 
                                            (0x7fU 
                                             & vlSelf->instr))
                                            ? 3U : 0U));
    vlSelf->ImmOp = ((1U == (IData)(vlSelf->green__DOT__ImmSrc))
                      ? (((- (IData)((vlSelf->instr 
                                      >> 0x1fU))) << 0xcU) 
                         | (vlSelf->instr >> 0x14U))
                      : ((3U == (IData)(vlSelf->green__DOT__ImmSrc))
                          ? (((- (IData)((vlSelf->instr 
                                          >> 0x1fU))) 
                              << 0xcU) | ((0x800U & 
                                           (vlSelf->instr 
                                            << 4U)) 
                                          | ((0x7e0U 
                                              & (vlSelf->instr 
                                                 >> 0x14U)) 
                                             | (0x1eU 
                                                & (vlSelf->instr 
                                                   >> 7U)))))
                          : 0U));
}

void Vgreen___024root___eval(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval\n"); );
    // Body
    Vgreen___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vgreen___024root___eval_debug_assertions(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->EQ & 0xfeU))) {
        Verilated::overWidthError("EQ");}
}
#endif  // VL_DEBUG
