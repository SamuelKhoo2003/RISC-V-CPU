// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpc_top.h for the primary calling header

#include "verilated.h"

#include "Vpc_top___024root.h"

VL_ATTR_COLD void Vpc_top___024root___eval_initial(Vpc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vpc_top___024root___combo__TOP__0(Vpc_top___024root* vlSelf);

VL_ATTR_COLD void Vpc_top___024root___eval_settle(Vpc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_top___024root___eval_settle\n"); );
    // Body
    Vpc_top___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vpc_top___024root___final(Vpc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_top___024root___final\n"); );
}

VL_ATTR_COLD void Vpc_top___024root___ctor_var_reset(Vpc_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vpc_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpc_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->ImmOp = VL_RAND_RESET_I(32);
    vlSelf->PCsrc = VL_RAND_RESET_I(1);
    vlSelf->pc_out = VL_RAND_RESET_I(32);
    vlSelf->pc_top__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->pc_top__DOT__pc = VL_RAND_RESET_I(32);
}
