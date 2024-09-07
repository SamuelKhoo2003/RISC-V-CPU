// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vred_top.h for the primary calling header

#include "verilated.h"

#include "Vred_top___024root.h"

VL_INLINE_OPT void Vred_top___024root___sequent__TOP__0(Vred_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vred_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vred_top___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__red_top__DOT__register__DOT__reg_array__v0;
    IData/*31:0*/ __Vdlyvval__red_top__DOT__register__DOT__reg_array__v0;
    CData/*0:0*/ __Vdlyvset__red_top__DOT__register__DOT__reg_array__v0;
    // Body
    __Vdlyvset__red_top__DOT__register__DOT__reg_array__v0 = 0U;
    if (vlSelf->RegWrite) {
        __Vdlyvval__red_top__DOT__register__DOT__reg_array__v0 
            = ((4U & (IData)(vlSelf->ALUctrl)) ? ((2U 
                                                   & (IData)(vlSelf->ALUctrl))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->ALUctrl))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->red_top__DOT__ALUop1 
                                                    ^ vlSelf->red_top__DOT__ALUop2)))
                : ((2U & (IData)(vlSelf->ALUctrl)) ? 
                   ((1U & (IData)(vlSelf->ALUctrl))
                     ? (vlSelf->red_top__DOT__ALUop1 
                        | vlSelf->red_top__DOT__ALUop2)
                     : (vlSelf->red_top__DOT__ALUop1 
                        & vlSelf->red_top__DOT__ALUop2))
                    : ((1U & (IData)(vlSelf->ALUctrl))
                        ? (vlSelf->red_top__DOT__ALUop1 
                           - vlSelf->red_top__DOT__ALUop2)
                        : (vlSelf->red_top__DOT__ALUop1 
                           + vlSelf->red_top__DOT__ALUop2))));
        __Vdlyvset__red_top__DOT__register__DOT__reg_array__v0 = 1U;
        __Vdlyvdim0__red_top__DOT__register__DOT__reg_array__v0 
            = (0x1fU & (vlSelf->Instr >> 7U));
    }
    vlSelf->red_top__DOT__ALUop1 = vlSelf->red_top__DOT__register__DOT__reg_array
        [(0x1fU & (vlSelf->Instr >> 0xfU))];
    vlSelf->red_top__DOT__regOp2 = vlSelf->red_top__DOT__register__DOT__reg_array
        [(0x1fU & (vlSelf->Instr >> 0x14U))];
    vlSelf->a0 = vlSelf->red_top__DOT__register__DOT__reg_array
        [0U];
    if (__Vdlyvset__red_top__DOT__register__DOT__reg_array__v0) {
        vlSelf->red_top__DOT__register__DOT__reg_array[__Vdlyvdim0__red_top__DOT__register__DOT__reg_array__v0] 
            = __Vdlyvval__red_top__DOT__register__DOT__reg_array__v0;
    }
}

VL_INLINE_OPT void Vred_top___024root___combo__TOP__0(Vred_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vred_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vred_top___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->red_top__DOT__ALUop2 = ((IData)(vlSelf->ALUsrc)
                                     ? vlSelf->ImmOp
                                     : vlSelf->red_top__DOT__regOp2);
    vlSelf->EQ = (vlSelf->red_top__DOT__ALUop1 == vlSelf->red_top__DOT__ALUop2);
}

void Vred_top___024root___eval(Vred_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vred_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vred_top___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vred_top___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vred_top___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vred_top___024root___eval_debug_assertions(Vred_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vred_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vred_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->ALUsrc & 0xfeU))) {
        Verilated::overWidthError("ALUsrc");}
    if (VL_UNLIKELY((vlSelf->ALUctrl & 0xf8U))) {
        Verilated::overWidthError("ALUctrl");}
    if (VL_UNLIKELY((vlSelf->RegWrite & 0xfeU))) {
        Verilated::overWidthError("RegWrite");}
}
#endif  // VL_DEBUG
