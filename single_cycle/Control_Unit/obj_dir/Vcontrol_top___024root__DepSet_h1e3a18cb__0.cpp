// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_top.h for the primary calling header

#include "verilated.h"

#include "Vcontrol_top___024root.h"

extern const VlUnpacked<CData/*6:0*/, 2048> Vcontrol_top__ConstPool__TABLE_h8ce1d139_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vcontrol_top__ConstPool__TABLE_h0638d652_0;
extern const VlUnpacked<CData/*1:0*/, 2048> Vcontrol_top__ConstPool__TABLE_h451fada2_0;
extern const VlUnpacked<CData/*2:0*/, 2048> Vcontrol_top__ConstPool__TABLE_h86cc9c99_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vcontrol_top__ConstPool__TABLE_h3793b81c_0;
extern const VlUnpacked<CData/*1:0*/, 2048> Vcontrol_top__ConstPool__TABLE_hf7e03d3b_0;
extern const VlUnpacked<CData/*1:0*/, 2048> Vcontrol_top__ConstPool__TABLE_h8b944ba6_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vcontrol_top__ConstPool__TABLE_h208bbd95_0;

VL_INLINE_OPT void Vcontrol_top___024root___combo__TOP__0(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___combo__TOP__0\n"); );
    // Init
    SData/*10:0*/ __Vtableidx1;
    // Body
    vlSelf->instr_o = ((vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                        [(0xffU & ((IData)(3U) + (IData)(vlSelf->PC_i)))] 
                        << 0x18U) | ((0xff0000U & (
                                                   vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                                                   [
                                                   (0xffU 
                                                    & ((IData)(2U) 
                                                       + (IData)(vlSelf->PC_i)))] 
                                                   << 0x10U)) 
                                     | ((0xff00U & 
                                         (vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                                          [(0xffU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelf->PC_i)))] 
                                          << 8U)) | 
                                        (0xffU & vlSelf->control_top__DOT__InstrMem__DOT__rom_array
                                         [vlSelf->PC_i]))));
    __Vtableidx1 = (((IData)(vlSelf->Zero_i) << 0xaU) 
                    | ((0x380U & (vlSelf->instr_o >> 5U)) 
                       | (0x7fU & vlSelf->instr_o)));
    if ((1U & Vcontrol_top__ConstPool__TABLE_h8ce1d139_0
         [__Vtableidx1])) {
        vlSelf->RegWrite_o = Vcontrol_top__ConstPool__TABLE_h0638d652_0
            [__Vtableidx1];
    }
    if ((2U & Vcontrol_top__ConstPool__TABLE_h8ce1d139_0
         [__Vtableidx1])) {
        vlSelf->Resultsrc_o = Vcontrol_top__ConstPool__TABLE_h451fada2_0
            [__Vtableidx1];
    }
    if ((4U & Vcontrol_top__ConstPool__TABLE_h8ce1d139_0
         [__Vtableidx1])) {
        vlSelf->ALUctrl_o = Vcontrol_top__ConstPool__TABLE_h86cc9c99_0
            [__Vtableidx1];
    }
    if ((8U & Vcontrol_top__ConstPool__TABLE_h8ce1d139_0
         [__Vtableidx1])) {
        vlSelf->ALUsrc_o = Vcontrol_top__ConstPool__TABLE_h3793b81c_0
            [__Vtableidx1];
    }
    if ((0x10U & Vcontrol_top__ConstPool__TABLE_h8ce1d139_0
         [__Vtableidx1])) {
        vlSelf->control_top__DOT__ImmSrc = Vcontrol_top__ConstPool__TABLE_hf7e03d3b_0
            [__Vtableidx1];
    }
    if ((0x20U & Vcontrol_top__ConstPool__TABLE_h8ce1d139_0
         [__Vtableidx1])) {
        vlSelf->PCsrc_o = Vcontrol_top__ConstPool__TABLE_h8b944ba6_0
            [__Vtableidx1];
    }
    if ((0x40U & Vcontrol_top__ConstPool__TABLE_h8ce1d139_0
         [__Vtableidx1])) {
        vlSelf->MemWrite_o = Vcontrol_top__ConstPool__TABLE_h208bbd95_0
            [__Vtableidx1];
    }
    vlSelf->ImmOp_o = ((1U == (IData)(vlSelf->control_top__DOT__ImmSrc))
                        ? (((- (IData)((vlSelf->instr_o 
                                        >> 0x1fU))) 
                            << 0xcU) | (vlSelf->instr_o 
                                        >> 0x14U)) : 
                       ((3U == (IData)(vlSelf->control_top__DOT__ImmSrc))
                         ? (((- (IData)((vlSelf->instr_o 
                                         >> 0x1fU))) 
                             << 0xcU) | ((0x800U & 
                                          (vlSelf->instr_o 
                                           << 4U)) 
                                         | ((0x7e0U 
                                             & (vlSelf->instr_o 
                                                >> 0x14U)) 
                                            | (0x1eU 
                                               & (vlSelf->instr_o 
                                                  >> 7U)))))
                         : ((2U == (IData)(vlSelf->control_top__DOT__ImmSrc))
                             ? (((- (IData)((vlSelf->instr_o 
                                             >> 0x1fU))) 
                                 << 0x14U) | ((0xff000U 
                                               & vlSelf->instr_o) 
                                              | ((0x800U 
                                                  & (vlSelf->instr_o 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->instr_o 
                                                       >> 0x14U)))))
                             : 0U)));
}

void Vcontrol_top___024root___eval(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___eval\n"); );
    // Body
    Vcontrol_top___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vcontrol_top___024root___eval_debug_assertions(Vcontrol_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->Zero_i & 0xfeU))) {
        Verilated::overWidthError("Zero_i");}
}
#endif  // VL_DEBUG
