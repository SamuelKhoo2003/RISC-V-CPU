// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgreen.h for the primary calling header

#include "verilated.h"

#include "Vgreen___024root.h"

VL_ATTR_COLD void Vgreen___024root___settle__TOP__0(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->ALUctrl = 0U;
}

VL_ATTR_COLD void Vgreen___024root___initial__TOP__0(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h2ad0e489__0;
    // Body
    VL_WRITEF("Loading rom.\n");
    __Vtemp_h2ad0e489__0[0U] = 0x2e6d656dU;
    __Vtemp_h2ad0e489__0[1U] = 0x636f6465U;
    __Vtemp_h2ad0e489__0[2U] = 0x68696e65U;
    __Vtemp_h2ad0e489__0[3U] = 0x6d6163U;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h2ad0e489__0)
                 ,  &(vlSelf->green__DOT__MyInstrMem__DOT__rom_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vgreen___024root___eval_initial(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval_initial\n"); );
    // Body
    Vgreen___024root___initial__TOP__0(vlSelf);
}

void Vgreen___024root___combo__TOP__0(Vgreen___024root* vlSelf);

VL_ATTR_COLD void Vgreen___024root___eval_settle(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___eval_settle\n"); );
    // Body
    Vgreen___024root___settle__TOP__0(vlSelf);
    Vgreen___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vgreen___024root___final(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___final\n"); );
}

VL_ATTR_COLD void Vgreen___024root___ctor_var_reset(Vgreen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgreen___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->PC = VL_RAND_RESET_I(8);
    vlSelf->EQ = VL_RAND_RESET_I(1);
    vlSelf->instr = VL_RAND_RESET_I(32);
    vlSelf->RegWrite = VL_RAND_RESET_I(1);
    vlSelf->ALUctrl = VL_RAND_RESET_I(3);
    vlSelf->ALUsrc = VL_RAND_RESET_I(1);
    vlSelf->PCsrc = VL_RAND_RESET_I(1);
    vlSelf->ImmOp = VL_RAND_RESET_I(32);
    vlSelf->green__DOT__ImmSrc = VL_RAND_RESET_I(2);
    vlSelf->green__DOT__MyInstrMem__DOT__clk = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->green__DOT__MyInstrMem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
}
