// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_top.h for the primary calling header

#include "verilated.h"

#include "Vcontrol_top___024root.h"

VL_ATTR_COLD void Vcontrol_top___024root___initial__TOP__0(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h2ad0e489__0;
    // Body
    vlSelf->MemWrite_o = 0U;
    VL_WRITEF("Loading rom.\n");
    __Vtemp_h2ad0e489__0[0U] = 0x2e6d656dU;
    __Vtemp_h2ad0e489__0[1U] = 0x636f6465U;
    __Vtemp_h2ad0e489__0[2U] = 0x68696e65U;
    __Vtemp_h2ad0e489__0[3U] = 0x6d6163U;
    VL_READMEM_N(true, 32, 256, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h2ad0e489__0)
                 ,  &(vlSelf->control_top__DOT__InstrMem__DOT__rom_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vcontrol_top___024root___eval_initial(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___eval_initial\n"); );
    // Body
    Vcontrol_top___024root___initial__TOP__0(vlSelf);
}

void Vcontrol_top___024root___combo__TOP__0(Vcontrol_top___024root* vlSelf);

VL_ATTR_COLD void Vcontrol_top___024root___eval_settle(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___eval_settle\n"); );
    // Body
    Vcontrol_top___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vcontrol_top___024root___final(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___final\n"); );
}

VL_ATTR_COLD void Vcontrol_top___024root___ctor_var_reset(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->PC_i = VL_RAND_RESET_I(8);
    vlSelf->Zero_i = VL_RAND_RESET_I(1);
    vlSelf->instr_o = VL_RAND_RESET_I(32);
    vlSelf->RegWrite_o = VL_RAND_RESET_I(1);
    vlSelf->MemWrite_o = VL_RAND_RESET_I(1);
    vlSelf->Resultsrc_o = VL_RAND_RESET_I(2);
    vlSelf->ALUctrl_o = VL_RAND_RESET_I(3);
    vlSelf->ALUsrc_o = VL_RAND_RESET_I(1);
    vlSelf->PCsrc_o = VL_RAND_RESET_I(2);
    vlSelf->ImmOp_o = VL_RAND_RESET_I(32);
    vlSelf->control_top__DOT__ImmSrc = VL_RAND_RESET_I(2);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->control_top__DOT__InstrMem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
}
