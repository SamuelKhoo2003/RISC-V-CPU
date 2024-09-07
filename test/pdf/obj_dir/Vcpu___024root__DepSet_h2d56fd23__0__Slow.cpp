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
    VlWide<3>/*95:0*/ __Vtemp_h2553e7c1__0;
    // Body
    VL_WRITEF("Loading ROM\n");
    __Vtemp_h2553e7c1__0[0U] = 0x2e6d656dU;
    __Vtemp_h2553e7c1__0[1U] = 0x7369616eU;
    __Vtemp_h2553e7c1__0[2U] = 0x67617573U;
    VL_READMEM_N(true, 8, 131073, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h2553e7c1__0)
                 ,  &(vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register)
                 , 0x10000U, ~0ULL);
    VL_WRITEF("Loading rom.\n");
    VL_READMEM_N(true, 8, 256, 0, std::string{"pdf.mem"}
                 ,  &(vlSelf->cpu__DOT__control__DOT__InstrMem__DOT__rom_array)
                 , 0, ~0ULL);
}

extern const VlUnpacked<CData/*2:0*/, 4096> Vcpu__ConstPool__TABLE_h6fbb89d2_0;
extern const VlUnpacked<CData/*2:0*/, 4096> Vcpu__ConstPool__TABLE_hd7ea39bf_0;
extern const VlUnpacked<CData/*0:0*/, 4096> Vcpu__ConstPool__TABLE_h5f2fb561_0;
extern const VlUnpacked<CData/*1:0*/, 4096> Vcpu__ConstPool__TABLE_he565dfbc_0;
extern const VlUnpacked<CData/*1:0*/, 4096> Vcpu__ConstPool__TABLE_h957261ee_0;
extern const VlUnpacked<CData/*2:0*/, 4096> Vcpu__ConstPool__TABLE_h9eb0f28b_0;
extern const VlUnpacked<CData/*1:0*/, 4096> Vcpu__ConstPool__TABLE_h5d79f2f0_0;

VL_ATTR_COLD void Vcpu___024root___settle__TOP__0(Vcpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu___024root___settle__TOP__0\n"); );
    // Init
    SData/*11:0*/ __Vtableidx1;
    // Body
    vlSelf->a0 = vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array
        [0xaU];
    vlSelf->cpu__DOT__Instr = ((vlSelf->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                [(0xffU & ((IData)(3U) 
                                           + vlSelf->cpu__DOT__PC))] 
                                << 0x18U) | ((vlSelf->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                              [(0xffU 
                                                & ((IData)(2U) 
                                                   + vlSelf->cpu__DOT__PC))] 
                                              << 0x10U) 
                                             | ((vlSelf->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                                 [(0xffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->cpu__DOT__PC))] 
                                                 << 8U) 
                                                | vlSelf->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                                [(0xffU 
                                                  & vlSelf->cpu__DOT__PC)])));
    vlSelf->cpu__DOT__alu__DOT__regOp2 = vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array
        [(0x1fU & (vlSelf->cpu__DOT__Instr >> 0x14U))];
    vlSelf->cpu__DOT__alu__DOT__SrcA = vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array
        [(0x1fU & (vlSelf->cpu__DOT__Instr >> 0xfU))];
    __Vtableidx1 = ((0x800U & (vlSelf->cpu__DOT__Instr 
                               >> 0x13U)) | (((vlSelf->cpu__DOT__alu__DOT__SrcA 
                                               == vlSelf->cpu__DOT__alu__DOT__SrcB) 
                                              << 0xaU) 
                                             | ((0x380U 
                                                 & (vlSelf->cpu__DOT__Instr 
                                                    >> 5U)) 
                                                | (0x7fU 
                                                   & vlSelf->cpu__DOT__Instr))));
    vlSelf->cpu__DOT__RegWrite = Vcpu__ConstPool__TABLE_h6fbb89d2_0
        [__Vtableidx1];
    vlSelf->cpu__DOT__control__DOT__ImmSrc = Vcpu__ConstPool__TABLE_hd7ea39bf_0
        [__Vtableidx1];
    vlSelf->cpu__DOT__ALUsrc = Vcpu__ConstPool__TABLE_h5f2fb561_0
        [__Vtableidx1];
    vlSelf->cpu__DOT__MemWrite = Vcpu__ConstPool__TABLE_he565dfbc_0
        [__Vtableidx1];
    vlSelf->cpu__DOT__Resultsrc = Vcpu__ConstPool__TABLE_h957261ee_0
        [__Vtableidx1];
    vlSelf->cpu__DOT__ALUctrl = Vcpu__ConstPool__TABLE_h9eb0f28b_0
        [__Vtableidx1];
    vlSelf->cpu__DOT__PCsrc = Vcpu__ConstPool__TABLE_h5d79f2f0_0
        [__Vtableidx1];
    if ((0U == (IData)(vlSelf->cpu__DOT__control__DOT__ImmSrc))) {
        vlSelf->cpu__DOT__ImmOp = (((- (IData)((vlSelf->cpu__DOT__Instr 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelf->cpu__DOT__Instr 
                                                >> 0x14U));
    } else if ((1U == (IData)(vlSelf->cpu__DOT__control__DOT__ImmSrc))) {
        vlSelf->cpu__DOT__ImmOp = (((- (IData)((vlSelf->cpu__DOT__Instr 
                                                >> 0x1fU))) 
                                    << 0xcU) | ((0xfe0U 
                                                 & (vlSelf->cpu__DOT__Instr 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->cpu__DOT__Instr 
                                                      >> 7U))));
    } else if ((2U == (IData)(vlSelf->cpu__DOT__control__DOT__ImmSrc))) {
        vlSelf->cpu__DOT__ImmOp = (((- (IData)((vlSelf->cpu__DOT__Instr 
                                                >> 0x1fU))) 
                                    << 0xcU) | ((0x800U 
                                                 & (vlSelf->cpu__DOT__Instr 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelf->cpu__DOT__Instr 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->cpu__DOT__Instr 
                                                         >> 7U)))));
    } else if ((3U == (IData)(vlSelf->cpu__DOT__control__DOT__ImmSrc))) {
        vlSelf->cpu__DOT__ImmOp = (((- (IData)((vlSelf->cpu__DOT__Instr 
                                                >> 0x1fU))) 
                                    << 0x14U) | ((0xff000U 
                                                  & vlSelf->cpu__DOT__Instr) 
                                                 | ((0x800U 
                                                     & (vlSelf->cpu__DOT__Instr 
                                                        >> 9U)) 
                                                    | (0x7feU 
                                                       & (vlSelf->cpu__DOT__Instr 
                                                          >> 0x14U)))));
    } else if ((4U == (IData)(vlSelf->cpu__DOT__control__DOT__ImmSrc))) {
        vlSelf->cpu__DOT__ImmOp = (0xfffff000U & vlSelf->cpu__DOT__Instr);
    }
    vlSelf->cpu__DOT__ALUResult_o = ((4U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                      ? ((2U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                          ? ((1U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                              ? vlSelf->cpu__DOT__alu__DOT__SrcB
                                              : (vlSelf->cpu__DOT__alu__DOT__SrcA 
                                                 >> 
                                                 (0x1fU 
                                                  & vlSelf->cpu__DOT__alu__DOT__SrcB)))
                                          : ((1U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                              ? (vlSelf->cpu__DOT__alu__DOT__SrcA 
                                                 << 
                                                 (0x1fU 
                                                  & vlSelf->cpu__DOT__alu__DOT__SrcB))
                                              : (vlSelf->cpu__DOT__alu__DOT__SrcA 
                                                 ^ vlSelf->cpu__DOT__alu__DOT__SrcB)))
                                      : ((2U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                          ? ((1U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                              ? (vlSelf->cpu__DOT__alu__DOT__SrcA 
                                                 | vlSelf->cpu__DOT__alu__DOT__SrcB)
                                              : (vlSelf->cpu__DOT__alu__DOT__SrcA 
                                                 & vlSelf->cpu__DOT__alu__DOT__SrcB))
                                          : ((1U & (IData)(vlSelf->cpu__DOT__ALUctrl))
                                              ? (vlSelf->cpu__DOT__alu__DOT__SrcA 
                                                 - vlSelf->cpu__DOT__alu__DOT__SrcB)
                                              : (vlSelf->cpu__DOT__alu__DOT__SrcA 
                                                 + vlSelf->cpu__DOT__alu__DOT__SrcB))));
    vlSelf->cpu__DOT__alu__DOT__SrcB = ((IData)(vlSelf->cpu__DOT__ALUsrc)
                                         ? vlSelf->cpu__DOT__ImmOp
                                         : vlSelf->cpu__DOT__alu__DOT__regOp2);
    vlSelf->cpu__DOT__pc__DOT__next_PC = ((2U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                           ? ((1U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                               ? vlSelf->cpu__DOT__pc__DOT__pc_mux__DOT__input3
                                               : vlSelf->cpu__DOT__ALUResult_o)
                                           : ((1U & (IData)(vlSelf->cpu__DOT__PCsrc))
                                               ? (vlSelf->cpu__DOT__pc__DOT__PC 
                                                  + vlSelf->cpu__DOT__ImmOp)
                                               : ((IData)(4U) 
                                                  + vlSelf->cpu__DOT__pc__DOT__PC)));
    vlSelf->cpu__DOT__alu__DOT__Result = ((2U & (IData)(vlSelf->cpu__DOT__Resultsrc))
                                           ? ((1U & (IData)(vlSelf->cpu__DOT__Resultsrc))
                                               ? vlSelf->cpu__DOT__alu__DOT__resultMux__DOT__input3
                                               : ((IData)(4U) 
                                                  + vlSelf->cpu__DOT__pc__DOT__PC))
                                           : ((1U & (IData)(vlSelf->cpu__DOT__Resultsrc))
                                               ? ((
                                                   ((0x20000U 
                                                     >= 
                                                     (0x3ffffU 
                                                      & ((IData)(3U) 
                                                         + vlSelf->cpu__DOT__ALUResult_o)))
                                                     ? 
                                                    vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                    [
                                                    (0x3ffffU 
                                                     & ((IData)(3U) 
                                                        + vlSelf->cpu__DOT__ALUResult_o))]
                                                     : 0U) 
                                                   << 0x18U) 
                                                  | ((((0x20000U 
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
                                                            : 0U))))
                                               : vlSelf->cpu__DOT__ALUResult_o));
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
    vlSelf->__Vm_traceActivity[2U] = 1U;
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
    vlSelf->cpu__DOT__RegWrite = VL_RAND_RESET_I(3);
    vlSelf->cpu__DOT__MemWrite = VL_RAND_RESET_I(2);
    vlSelf->cpu__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__ALUctrl = VL_RAND_RESET_I(3);
    vlSelf->cpu__DOT__ALUsrc = VL_RAND_RESET_I(1);
    vlSelf->cpu__DOT__ALUResult_o = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__Resultsrc = VL_RAND_RESET_I(2);
    vlSelf->cpu__DOT__ImmOp = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__PCsrc = VL_RAND_RESET_I(2);
    vlSelf->cpu__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__pc__DOT__next_PC = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__pc__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__pc__DOT__pc_mux__DOT__input3 = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__control__DOT__ImmSrc = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        vlSelf->cpu__DOT__control__DOT__InstrMem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->cpu__DOT__alu__DOT__SrcA = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__alu__DOT__SrcB = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__alu__DOT__Result = VL_RAND_RESET_I(32);
    vlSelf->cpu__DOT__alu__DOT__regOp2 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->cpu__DOT__alu__DOT__register__DOT__reg_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<131073; ++__Vi0) {
        vlSelf->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->cpu__DOT__alu__DOT__data__DOT____Vlvbound_h4b1400a6__0 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__alu__DOT__data__DOT____Vlvbound_ha43eb5ce__0 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__alu__DOT__data__DOT____Vlvbound_ha4b1a5db__0 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__alu__DOT__data__DOT____Vlvbound_hd908c1f5__0 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__alu__DOT__data__DOT____Vlvbound_h4b1400a6__1 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__alu__DOT__data__DOT____Vlvbound_ha43eb5ce__1 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__alu__DOT__data__DOT____Vlvbound_he5a30f51__0 = VL_RAND_RESET_I(8);
    vlSelf->cpu__DOT__alu__DOT__resultMux__DOT__input3 = VL_RAND_RESET_I(32);
    vlSelf->__Vchglast__TOP__cpu__DOT__alu__DOT__SrcB = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
