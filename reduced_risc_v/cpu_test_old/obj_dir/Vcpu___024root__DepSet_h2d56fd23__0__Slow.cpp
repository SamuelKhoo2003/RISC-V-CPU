// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "verilated.h"

#include "Vcpu___024root.h"

VL_ATTR_COLD void Vcpu___024root___initial__TOP__0(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___initial__TOP__0\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h2ad0e489__0;
    // Body
    VL_WRITEF("Loading rom.\n");
    __Vtemp_h2ad0e489__0[0U] = 0x2e6d656dU;
    __Vtemp_h2ad0e489__0[1U] = 0x636f6465U;
    __Vtemp_h2ad0e489__0[2U] = 0x68696e65U;
    __Vtemp_h2ad0e489__0[3U] = 0x6d6163U;
    VL_READMEM_N(true, 32, 256, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_h2ad0e489__0)
                 ,  &(vlSelf->cpu__DOT__Mygreen__DOT__MyInstrMem__DOT__rom_array)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vcpu___024root___settle__TOP__0(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->a0 = vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array
        [0xaU];
    vlSelf->cpu__DOT__Instr = vlSelf->cpu__DOT__Mygreen__DOT__MyInstrMem__DOT__rom_array
        [(0x3fU & (vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__another_pc 
                   >> 2U))];
    vlSelf->cpu__DOT__Myred__DOT__ALUop1 = vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array
        [(0x1fU & (vlSelf->cpu__DOT__Instr >> 0xfU))];
    vlSelf->cpu__DOT__Mygreen__DOT__ImmSrc = ((0x13U 
                                               == (0x7fU 
                                                   & vlSelf->cpu__DOT__Instr))
                                               ? 1U
                                               : ((0x63U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->cpu__DOT__Instr))
                                                   ? 3U
                                                   : 0U));
    vlSelf->cpu__DOT__ImmOp = ((1U == (IData)(vlSelf->cpu__DOT__Mygreen__DOT__ImmSrc))
                                ? (((- (IData)((vlSelf->cpu__DOT__Instr 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelf->cpu__DOT__Instr 
                                                >> 0x14U))
                                : ((3U == (IData)(vlSelf->cpu__DOT__Mygreen__DOT__ImmSrc))
                                    ? (((- (IData)(
                                                   (vlSelf->cpu__DOT__Instr 
                                                    >> 0x1fU))) 
                                        << 0xcU) | 
                                       ((0x800U & (vlSelf->cpu__DOT__Instr 
                                                   << 4U)) 
                                        | ((0x7e0U 
                                            & (vlSelf->cpu__DOT__Instr 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlSelf->cpu__DOT__Instr 
                                                 >> 7U)))))
                                    : 0U));
    vlSelf->cpu__DOT__Myred__DOT__ALUop2 = (((0x13U 
                                              == (0x7fU 
                                                  & vlSelf->cpu__DOT__Instr)) 
                                             | (0x63U 
                                                != 
                                                (0x7fU 
                                                 & vlSelf->cpu__DOT__Instr)))
                                             ? vlSelf->cpu__DOT__ImmOp
                                             : vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array
                                            [(0x1fU 
                                              & (vlSelf->cpu__DOT__Instr 
                                                 >> 0x14U))]);
    vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_mux__next_PC 
        = (((0x13U != (0x7fU & vlSelf->cpu__DOT__Instr)) 
            & ((0x63U == (0x7fU & vlSelf->cpu__DOT__Instr)) 
               & (vlSelf->cpu__DOT__Myred__DOT__ALUop1 
                  != vlSelf->cpu__DOT__Myred__DOT__ALUop2)))
            ? ((0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__pc) 
               + (0xffU & vlSelf->cpu__DOT__ImmOp))
            : ((IData)(4U) + (0xffU & vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__pc)));
}

VL_ATTR_COLD void Vcpu___024root___eval_initial(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_initial\n"); );
    // Body
    Vcpu___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vcpu___024root___eval_settle(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___eval_settle\n"); );
    // Body
    Vcpu___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vcpu___024root___final(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___final\n"); );
}

VL_ATTR_COLD void Vcpu___024root___ctor_var_reset(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->__pinNumber4 = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_mux__next_PC = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__another_pc = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Myblue__DOT____Vcellout__pc_reg__pc = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Mygreen__DOT__ImmSrc = VL_RAND_RESET_I(2);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->cpu__DOT__Mygreen__DOT__MyInstrMem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->cpu__DOT__Myred__DOT__ALUop1 = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Myred__DOT__ALUop2 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->cpu__DOT__Myred__DOT__register__DOT__reg_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
