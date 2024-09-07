// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu.h"
#include "Vcpu__Syms.h"

//==========

VL_CTOR_IMP(Vcpu) {
    Vcpu__Syms* __restrict vlSymsp = __VlSymsp = new Vcpu__Syms(this, name());
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcpu::__Vconfigure(Vcpu__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vcpu::~Vcpu() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcpu::_initial__TOP__1(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_initial__TOP__1\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp1[3];
    // Body
    VL_WRITEF("Loading ROM\n");
    __Vtemp1[0U] = 0x2e6d656dU;
    __Vtemp1[1U] = 0x61726f6dU;
    __Vtemp1[2U] = 0x646174U;
    VL_READMEM_N(true, 8, 131073, 0, VL_CVT_PACK_STR_NW(3, __Vtemp1)
                 , vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                 , 0x10000U, ~0ULL);
    VL_WRITEF("Loading rom.\n");
    VL_READMEM_N(true, 8, 256, 0, std::string("f1.mem")
                 , vlTOPp->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                 , 0, ~0ULL);
}

void Vcpu::_settle__TOP__3(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_settle__TOP__3\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->a0 = vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array
        [0xaU];
    vlTOPp->cpu__DOT__Instr = ((vlTOPp->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                [(0xffU & ((IData)(3U) 
                                           + vlTOPp->cpu__DOT__PC))] 
                                << 0x18U) | ((vlTOPp->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                              [(0xffU 
                                                & ((IData)(2U) 
                                                   + vlTOPp->cpu__DOT__PC))] 
                                              << 0x10U) 
                                             | ((vlTOPp->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                                 [(0xffU 
                                                   & ((IData)(1U) 
                                                      + vlTOPp->cpu__DOT__PC))] 
                                                 << 8U) 
                                                | vlTOPp->cpu__DOT__control__DOT__InstrMem__DOT__rom_array
                                                [(0xffU 
                                                  & vlTOPp->cpu__DOT__PC)])));
    if ((0x40U & vlTOPp->cpu__DOT__Instr)) {
        vlTOPp->cpu__DOT__RegWrite = ((0x20U & vlTOPp->cpu__DOT__Instr)
                                       ? ((0x10U & vlTOPp->cpu__DOT__Instr)
                                           ? 1U : (
                                                   (8U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 1U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 
                                                    ((2U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 0U
                                                       : 1U)
                                                      : 1U)
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 0U
                                                       : 1U)
                                                      : 1U))))
                                       : 1U);
        vlTOPp->cpu__DOT__MemWrite = 0U;
        vlTOPp->cpu__DOT__Resultsrc = ((0x20U & vlTOPp->cpu__DOT__Instr)
                                        ? ((0x10U & vlTOPp->cpu__DOT__Instr)
                                            ? 0U : 
                                           ((8U & vlTOPp->cpu__DOT__Instr)
                                             ? ((4U 
                                                 & vlTOPp->cpu__DOT__Instr)
                                                 ? 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__Instr)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 2U
                                                   : 0U)
                                                  : 0U)
                                                 : 0U)
                                             : ((4U 
                                                 & vlTOPp->cpu__DOT__Instr)
                                                 ? 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__Instr)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 2U
                                                   : 0U)
                                                  : 0U)
                                                 : 
                                                ((2U 
                                                  & vlTOPp->cpu__DOT__Instr)
                                                  ? 
                                                 ((1U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 1U
                                                   : 0U)
                                                  : 0U))))
                                        : 0U);
        vlTOPp->cpu__DOT__ALUctrl = ((0x20U & vlTOPp->cpu__DOT__Instr)
                                      ? ((0x10U & vlTOPp->cpu__DOT__Instr)
                                          ? 0U : ((8U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 1U
                                                      : 0U)
                                                     : 0U))))
                                      : 0U);
    } else {
        vlTOPp->cpu__DOT__RegWrite = ((0x20U & vlTOPp->cpu__DOT__Instr)
                                       ? ((0x10U & vlTOPp->cpu__DOT__Instr)
                                           ? 1U : (
                                                   (8U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 1U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 1U
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 0U
                                                       : 1U)
                                                      : 1U))))
                                       : ((0x10U & vlTOPp->cpu__DOT__Instr)
                                           ? 1U : (
                                                   (8U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 1U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 1U
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 
                                                      ((0x4000U 
                                                        & vlTOPp->cpu__DOT__Instr)
                                                        ? 
                                                       ((0x2000U 
                                                         & vlTOPp->cpu__DOT__Instr)
                                                         ? 0U
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->cpu__DOT__Instr)
                                                          ? 6U
                                                          : 7U))
                                                        : 
                                                       ((0x2000U 
                                                         & vlTOPp->cpu__DOT__Instr)
                                                         ? 
                                                        ((0x1000U 
                                                          & vlTOPp->cpu__DOT__Instr)
                                                          ? 0U
                                                          : 1U)
                                                         : 
                                                        ((0x1000U 
                                                          & vlTOPp->cpu__DOT__Instr)
                                                          ? 2U
                                                          : 3U)))
                                                       : 1U)
                                                      : 1U)))));
        vlTOPp->cpu__DOT__MemWrite = ((0x20U & vlTOPp->cpu__DOT__Instr)
                                       ? ((0x10U & vlTOPp->cpu__DOT__Instr)
                                           ? 0U : (
                                                   (8U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 
                                                      ((0U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__Instr 
                                                            >> 0xcU)))
                                                        ? 3U
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__Instr 
                                                             >> 0xcU)))
                                                         ? 2U
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__Instr 
                                                              >> 0xcU)))
                                                          ? 1U
                                                          : 0U)))
                                                       : 0U)
                                                      : 0U))))
                                       : 0U);
        vlTOPp->cpu__DOT__Resultsrc = ((0x20U & vlTOPp->cpu__DOT__Instr)
                                        ? 0U : ((0x10U 
                                                 & vlTOPp->cpu__DOT__Instr)
                                                 ? 0U
                                                 : 
                                                ((8U 
                                                  & vlTOPp->cpu__DOT__Instr)
                                                  ? 0U
                                                  : 
                                                 ((4U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 1U
                                                     : 0U)
                                                    : 0U)))));
        vlTOPp->cpu__DOT__ALUctrl = ((0x20U & vlTOPp->cpu__DOT__Instr)
                                      ? ((0x10U & vlTOPp->cpu__DOT__Instr)
                                          ? ((8U & vlTOPp->cpu__DOT__Instr)
                                              ? 0U : 
                                             ((4U & vlTOPp->cpu__DOT__Instr)
                                               ? ((2U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 7U
                                                    : 0U)
                                                   : 0U)
                                               : ((2U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 
                                                   ((0x4000U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 
                                                    ((0x2000U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 2U
                                                       : 3U)
                                                      : 0U)
                                                     : 
                                                    ((0x2000U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 0U
                                                       : 5U)
                                                      : 
                                                     ((0x1000U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 0U
                                                       : 
                                                      ((3U 
                                                        == 
                                                        ((2U 
                                                          & (vlTOPp->cpu__DOT__Instr 
                                                             >> 4U)) 
                                                         | (1U 
                                                            & (vlTOPp->cpu__DOT__Instr 
                                                               >> 0x1eU))))
                                                        ? 1U
                                                        : 0U))))
                                                    : 0U)
                                                   : 0U)))
                                          : 0U) : (
                                                   (0x10U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__Instr)
                                                        ? 
                                                       ((0U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__Instr 
                                                             >> 0xcU)))
                                                         ? 0U
                                                         : 
                                                        ((1U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__Instr 
                                                              >> 0xcU)))
                                                          ? 5U
                                                          : 0U))
                                                        : 0U)
                                                       : 0U)))
                                                    : 0U));
    }
    vlTOPp->cpu__DOT__alu__DOT__SrcA = vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array
        [(0x1fU & (vlTOPp->cpu__DOT__Instr >> 0xfU))];
    vlTOPp->cpu__DOT__alu__DOT__regOp2 = vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array
        [(0x1fU & (vlTOPp->cpu__DOT__Instr >> 0x14U))];
    vlTOPp->cpu__DOT__control__DOT__ImmSrc = ((0x40U 
                                               & vlTOPp->cpu__DOT__Instr)
                                               ? ((0x20U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 
                                                  ((0x10U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__Instr)
                                                        ? 3U
                                                        : 0U)
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__Instr)
                                                        ? 2U
                                                        : 0U)
                                                       : 0U))))
                                                   : 0U)
                                               : ((0x20U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 
                                                  ((0x10U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__Instr)
                                                        ? 4U
                                                        : 0U)
                                                       : 0U)
                                                      : 0U))
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->cpu__DOT__Instr)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->cpu__DOT__Instr)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->cpu__DOT__Instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->cpu__DOT__Instr)
                                                        ? 1U
                                                        : 0U)
                                                       : 0U))))
                                                   : 0U));
    if ((0U == (IData)(vlTOPp->cpu__DOT__control__DOT__ImmSrc))) {
        vlTOPp->cpu__DOT__ImmOp = ((0xfffff000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->cpu__DOT__Instr 
                                                                  >> 0x1fU)))) 
                                                   << 0xcU)) 
                                   | (0xfffU & (vlTOPp->cpu__DOT__Instr 
                                                >> 0x14U)));
    } else {
        if ((1U == (IData)(vlTOPp->cpu__DOT__control__DOT__ImmSrc))) {
            vlTOPp->cpu__DOT__ImmOp = ((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->cpu__DOT__Instr 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0xfe0U & 
                                           (vlTOPp->cpu__DOT__Instr 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->cpu__DOT__Instr 
                                                >> 7U))));
        } else {
            if ((2U == (IData)(vlTOPp->cpu__DOT__control__DOT__ImmSrc))) {
                vlTOPp->cpu__DOT__ImmOp = ((0xfffff000U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->cpu__DOT__Instr 
                                                              >> 0x1fU)))) 
                                               << 0xcU)) 
                                           | ((0x800U 
                                               & (vlTOPp->cpu__DOT__Instr 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlTOPp->cpu__DOT__Instr 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlTOPp->cpu__DOT__Instr 
                                                       >> 7U)))));
            } else {
                if ((3U == (IData)(vlTOPp->cpu__DOT__control__DOT__ImmSrc))) {
                    vlTOPp->cpu__DOT__ImmOp = ((0xfff00000U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & (vlTOPp->cpu__DOT__Instr 
                                                                  >> 0x1fU)))) 
                                                   << 0x14U)) 
                                               | ((0xff000U 
                                                   & vlTOPp->cpu__DOT__Instr) 
                                                  | ((0x800U 
                                                      & (vlTOPp->cpu__DOT__Instr 
                                                         >> 9U)) 
                                                     | (0x7feU 
                                                        & (vlTOPp->cpu__DOT__Instr 
                                                           >> 0x14U)))));
                } else {
                    if ((4U == (IData)(vlTOPp->cpu__DOT__control__DOT__ImmSrc))) {
                        vlTOPp->cpu__DOT__ImmOp = (0xfffff000U 
                                                   & vlTOPp->cpu__DOT__Instr);
                    }
                }
            }
        }
    }
    vlTOPp->cpu__DOT__alu__DOT__SrcB = ((1U & ((0x40U 
                                                & vlTOPp->cpu__DOT__Instr)
                                                ? (
                                                   (~ 
                                                    (vlTOPp->cpu__DOT__Instr 
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
                                                : (
                                                   (~ 
                                                    (vlTOPp->cpu__DOT__Instr 
                                                     >> 5U)) 
                                                   | ((~ 
                                                       (vlTOPp->cpu__DOT__Instr 
                                                        >> 4U)) 
                                                      | ((vlTOPp->cpu__DOT__Instr 
                                                          >> 3U) 
                                                         | ((vlTOPp->cpu__DOT__Instr 
                                                             >> 2U) 
                                                            | ((~ 
                                                                (vlTOPp->cpu__DOT__Instr 
                                                                 >> 1U)) 
                                                               | (~ vlTOPp->cpu__DOT__Instr))))))))
                                         ? vlTOPp->cpu__DOT__ImmOp
                                         : vlTOPp->cpu__DOT__alu__DOT__regOp2);
    vlTOPp->cpu__DOT__ALUResult_o = ((4U & (IData)(vlTOPp->cpu__DOT__ALUctrl))
                                      ? ((2U & (IData)(vlTOPp->cpu__DOT__ALUctrl))
                                          ? ((1U & (IData)(vlTOPp->cpu__DOT__ALUctrl))
                                              ? vlTOPp->cpu__DOT__alu__DOT__SrcB
                                              : (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                                                 >> 
                                                 (0x1fU 
                                                  & vlTOPp->cpu__DOT__alu__DOT__SrcB)))
                                          : ((1U & (IData)(vlTOPp->cpu__DOT__ALUctrl))
                                              ? (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                                                 << 
                                                 (0x1fU 
                                                  & vlTOPp->cpu__DOT__alu__DOT__SrcB))
                                              : (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                                                 ^ vlTOPp->cpu__DOT__alu__DOT__SrcB)))
                                      : ((2U & (IData)(vlTOPp->cpu__DOT__ALUctrl))
                                          ? ((1U & (IData)(vlTOPp->cpu__DOT__ALUctrl))
                                              ? (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                                                 | vlTOPp->cpu__DOT__alu__DOT__SrcB)
                                              : (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                                                 & vlTOPp->cpu__DOT__alu__DOT__SrcB))
                                          : ((1U & (IData)(vlTOPp->cpu__DOT__ALUctrl))
                                              ? (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                                                 - vlTOPp->cpu__DOT__alu__DOT__SrcB)
                                              : (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                                                 + vlTOPp->cpu__DOT__alu__DOT__SrcB))));
    vlTOPp->cpu__DOT__Zero = (vlTOPp->cpu__DOT__alu__DOT__SrcA 
                              == vlTOPp->cpu__DOT__alu__DOT__SrcB);
    vlTOPp->cpu__DOT__alu__DOT__Result = ((2U & (IData)(vlTOPp->cpu__DOT__Resultsrc))
                                           ? ((1U & (IData)(vlTOPp->cpu__DOT__Resultsrc))
                                               ? vlTOPp->cpu__DOT__alu__DOT__resultMux__DOT__input3
                                               : ((IData)(4U) 
                                                  + vlTOPp->cpu__DOT__pc__DOT__PC))
                                           : ((1U & (IData)(vlTOPp->cpu__DOT__Resultsrc))
                                               ? ((
                                                   ((0x20000U 
                                                     >= 
                                                     (0x3ffffU 
                                                      & ((IData)(3U) 
                                                         + vlTOPp->cpu__DOT__ALUResult_o)))
                                                     ? 
                                                    vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                    [
                                                    (0x3ffffU 
                                                     & ((IData)(3U) 
                                                        + vlTOPp->cpu__DOT__ALUResult_o))]
                                                     : 0U) 
                                                   << 0x18U) 
                                                  | ((((0x20000U 
                                                        >= 
                                                        (0x3ffffU 
                                                         & ((IData)(2U) 
                                                            + vlTOPp->cpu__DOT__ALUResult_o)))
                                                        ? 
                                                       vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                       [
                                                       (0x3ffffU 
                                                        & ((IData)(2U) 
                                                           + vlTOPp->cpu__DOT__ALUResult_o))]
                                                        : 0U) 
                                                      << 0x10U) 
                                                     | ((((0x20000U 
                                                           >= 
                                                           (0x3ffffU 
                                                            & ((IData)(1U) 
                                                               + vlTOPp->cpu__DOT__ALUResult_o)))
                                                           ? 
                                                          vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                          [
                                                          (0x3ffffU 
                                                           & ((IData)(1U) 
                                                              + vlTOPp->cpu__DOT__ALUResult_o))]
                                                           : 0U) 
                                                         << 8U) 
                                                        | ((0x20000U 
                                                            >= 
                                                            (0x3ffffU 
                                                             & vlTOPp->cpu__DOT__ALUResult_o))
                                                            ? 
                                                           vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register
                                                           [
                                                           (0x3ffffU 
                                                            & vlTOPp->cpu__DOT__ALUResult_o)]
                                                            : 0U))))
                                               : vlTOPp->cpu__DOT__ALUResult_o));
    vlTOPp->cpu__DOT__PCsrc = ((0x40U & vlTOPp->cpu__DOT__Instr)
                                ? ((0x20U & vlTOPp->cpu__DOT__Instr)
                                    ? ((0x10U & vlTOPp->cpu__DOT__Instr)
                                        ? 0U : ((8U 
                                                 & vlTOPp->cpu__DOT__Instr)
                                                 ? 
                                                ((4U 
                                                  & vlTOPp->cpu__DOT__Instr)
                                                  ? 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 1U
                                                    : 0U)
                                                   : 0U)
                                                  : 0U)
                                                 : 
                                                ((4U 
                                                  & vlTOPp->cpu__DOT__Instr)
                                                  ? 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 2U
                                                    : 0U)
                                                   : 0U)
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->cpu__DOT__Instr)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->cpu__DOT__Instr)
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__Instr 
                                                         >> 0xcU)))
                                                     ? (IData)(vlTOPp->cpu__DOT__Zero)
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__Instr 
                                                          >> 0xcU)))
                                                      ? 
                                                     (1U 
                                                      & (~ (IData)(vlTOPp->cpu__DOT__Zero)))
                                                      : (IData)(vlTOPp->cpu__DOT__Zero)))
                                                    : 0U)
                                                   : 0U))))
                                    : 0U) : 0U);
    vlTOPp->cpu__DOT__pc__DOT__next_PC = ((2U & (IData)(vlTOPp->cpu__DOT__PCsrc))
                                           ? ((1U & (IData)(vlTOPp->cpu__DOT__PCsrc))
                                               ? vlTOPp->cpu__DOT__pc__DOT__pc_mux__DOT__input3
                                               : vlTOPp->cpu__DOT__ALUResult_o)
                                           : ((1U & (IData)(vlTOPp->cpu__DOT__PCsrc))
                                               ? (vlTOPp->cpu__DOT__pc__DOT__PC 
                                                  + vlTOPp->cpu__DOT__ImmOp)
                                               : ((IData)(4U) 
                                                  + vlTOPp->cpu__DOT__pc__DOT__PC)));
}

void Vcpu::_eval_initial(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_initial\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vcpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::final\n"); );
    // Variables
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu::_eval_settle(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_settle\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vcpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    a0 = VL_RAND_RESET_I(32);
    cpu__DOT__RegWrite = VL_RAND_RESET_I(3);
    cpu__DOT__MemWrite = VL_RAND_RESET_I(2);
    cpu__DOT__Instr = VL_RAND_RESET_I(32);
    cpu__DOT__ALUctrl = VL_RAND_RESET_I(3);
    cpu__DOT__Zero = VL_RAND_RESET_I(1);
    cpu__DOT__ALUResult_o = VL_RAND_RESET_I(32);
    cpu__DOT__Resultsrc = VL_RAND_RESET_I(2);
    cpu__DOT__ImmOp = VL_RAND_RESET_I(32);
    cpu__DOT__PCsrc = VL_RAND_RESET_I(2);
    cpu__DOT__PC = VL_RAND_RESET_I(32);
    cpu__DOT__pc__DOT__next_PC = VL_RAND_RESET_I(32);
    cpu__DOT__pc__DOT__PC = VL_RAND_RESET_I(32);
    cpu__DOT__pc__DOT__pc_mux__DOT__input3 = VL_RAND_RESET_I(32);
    cpu__DOT__control__DOT__ImmSrc = VL_RAND_RESET_I(3);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            cpu__DOT__control__DOT__InstrMem__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(8);
    }}
    cpu__DOT__alu__DOT__SrcA = VL_RAND_RESET_I(32);
    cpu__DOT__alu__DOT__SrcB = VL_RAND_RESET_I(32);
    cpu__DOT__alu__DOT__Result = VL_RAND_RESET_I(32);
    cpu__DOT__alu__DOT__regOp2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            cpu__DOT__alu__DOT__register__DOT__reg_array[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<131073; ++__Vi0) {
            cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vi0] = VL_RAND_RESET_I(8);
    }}
    cpu__DOT__alu__DOT__data__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    cpu__DOT__alu__DOT__data__DOT____Vlvbound2 = VL_RAND_RESET_I(8);
    cpu__DOT__alu__DOT__data__DOT____Vlvbound3 = VL_RAND_RESET_I(8);
    cpu__DOT__alu__DOT__data__DOT____Vlvbound4 = VL_RAND_RESET_I(8);
    cpu__DOT__alu__DOT__data__DOT____Vlvbound5 = VL_RAND_RESET_I(8);
    cpu__DOT__alu__DOT__data__DOT____Vlvbound6 = VL_RAND_RESET_I(8);
    cpu__DOT__alu__DOT__data__DOT____Vlvbound7 = VL_RAND_RESET_I(8);
    cpu__DOT__alu__DOT__resultMux__DOT__input3 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
