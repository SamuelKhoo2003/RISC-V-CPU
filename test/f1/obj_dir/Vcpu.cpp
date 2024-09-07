// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu.h"
#include "Vcpu__Syms.h"

//==========

void Vcpu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu::eval\n"); );
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcpu::_eval_initial_loop(Vcpu__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__2\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__register__DOT__reg_array__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__register__DOT__reg_array__v0;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__alu__DOT__register__DOT__reg_array__v0;
    IData/*17:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0;
    IData/*17:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1;
    IData/*17:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2;
    IData/*17:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3;
    IData/*17:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4;
    IData/*17:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5;
    IData/*17:0*/ __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6;
    // Body
    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0 = 0U;
    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1 = 0U;
    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2 = 0U;
    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3 = 0U;
    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4 = 0U;
    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5 = 0U;
    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6 = 0U;
    __Vdlyvset__cpu__DOT__alu__DOT__register__DOT__reg_array__v0 = 0U;
    vlTOPp->cpu__DOT__pc__DOT__PC = ((IData)(vlTOPp->rst)
                                      ? 0U : vlTOPp->cpu__DOT__pc__DOT__next_PC);
    if ((1U == (IData)(vlTOPp->cpu__DOT__MemWrite))) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound1 
            = (0xffU & vlTOPp->cpu__DOT__alu__DOT__regOp2);
        if ((0x20000U >= (0x3ffffU & vlTOPp->cpu__DOT__ALUResult_o))) {
            __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0 
                = vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound1;
            __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0 = 1U;
            __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0 
                = (0x3ffffU & vlTOPp->cpu__DOT__ALUResult_o);
        }
        vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound2 
            = (0xffU & (vlTOPp->cpu__DOT__alu__DOT__regOp2 
                        >> 8U));
        if ((0x20000U >= (0x3ffffU & ((IData)(1U) + vlTOPp->cpu__DOT__ALUResult_o)))) {
            __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1 
                = vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound2;
            __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1 = 1U;
            __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1 
                = (0x3ffffU & ((IData)(1U) + vlTOPp->cpu__DOT__ALUResult_o));
        }
        vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound3 
            = (0xffU & (vlTOPp->cpu__DOT__alu__DOT__regOp2 
                        >> 0x10U));
        if ((0x20000U >= (0x3ffffU & ((IData)(2U) + vlTOPp->cpu__DOT__ALUResult_o)))) {
            __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2 
                = vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound3;
            __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2 = 1U;
            __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2 
                = (0x3ffffU & ((IData)(2U) + vlTOPp->cpu__DOT__ALUResult_o));
        }
        vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound4 
            = (0xffU & (vlTOPp->cpu__DOT__alu__DOT__regOp2 
                        >> 0x18U));
        if ((0x20000U >= (0x3ffffU & ((IData)(3U) + vlTOPp->cpu__DOT__ALUResult_o)))) {
            __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3 
                = vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound4;
            __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3 = 1U;
            __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3 
                = (0x3ffffU & ((IData)(3U) + vlTOPp->cpu__DOT__ALUResult_o));
        }
    } else {
        if ((2U == (IData)(vlTOPp->cpu__DOT__MemWrite))) {
            vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound5 
                = (0xffU & vlTOPp->cpu__DOT__alu__DOT__regOp2);
            if ((0x20000U >= (0x3ffffU & vlTOPp->cpu__DOT__ALUResult_o))) {
                __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4 
                    = vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound5;
                __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4 = 1U;
                __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4 
                    = (0x3ffffU & vlTOPp->cpu__DOT__ALUResult_o);
            }
            vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound6 
                = (0xffU & (vlTOPp->cpu__DOT__alu__DOT__regOp2 
                            >> 8U));
            if ((0x20000U >= (0x3ffffU & ((IData)(1U) 
                                          + vlTOPp->cpu__DOT__ALUResult_o)))) {
                __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5 
                    = vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound6;
                __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5 = 1U;
                __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5 
                    = (0x3ffffU & ((IData)(1U) + vlTOPp->cpu__DOT__ALUResult_o));
            }
        } else {
            if ((3U == (IData)(vlTOPp->cpu__DOT__MemWrite))) {
                vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound7 
                    = (0xffU & vlTOPp->cpu__DOT__alu__DOT__regOp2);
                if ((0x20000U >= (0x3ffffU & vlTOPp->cpu__DOT__ALUResult_o))) {
                    __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6 
                        = vlTOPp->cpu__DOT__alu__DOT__data__DOT____Vlvbound7;
                    __Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6 = 1U;
                    __Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6 
                        = (0x3ffffU & vlTOPp->cpu__DOT__ALUResult_o);
                }
            }
        }
    }
    if ((0U != (0x1fU & (vlTOPp->cpu__DOT__Instr >> 7U)))) {
        __Vdlyvval__cpu__DOT__alu__DOT__register__DOT__reg_array__v0 
            = ((4U & (IData)(vlTOPp->cpu__DOT__RegWrite))
                ? ((2U & (IData)(vlTOPp->cpu__DOT__RegWrite))
                    ? ((1U & (IData)(vlTOPp->cpu__DOT__RegWrite))
                        ? (0xffU & vlTOPp->cpu__DOT__alu__DOT__Result)
                        : (0xffffU & vlTOPp->cpu__DOT__alu__DOT__Result))
                    : vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array
                   [(0x1fU & (vlTOPp->cpu__DOT__Instr 
                              >> 7U))]) : ((2U & (IData)(vlTOPp->cpu__DOT__RegWrite))
                                            ? ((1U 
                                                & (IData)(vlTOPp->cpu__DOT__RegWrite))
                                                ? (
                                                   (0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__alu__DOT__Result 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & vlTOPp->cpu__DOT__alu__DOT__Result))
                                                : (
                                                   (0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->cpu__DOT__alu__DOT__Result 
                                                                      >> 0xfU)))) 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & vlTOPp->cpu__DOT__alu__DOT__Result)))
                                            : ((1U 
                                                & (IData)(vlTOPp->cpu__DOT__RegWrite))
                                                ? vlTOPp->cpu__DOT__alu__DOT__Result
                                                : vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array
                                               [(0x1fU 
                                                 & (vlTOPp->cpu__DOT__Instr 
                                                    >> 7U))])));
        __Vdlyvset__cpu__DOT__alu__DOT__register__DOT__reg_array__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__alu__DOT__register__DOT__reg_array__v0 
            = (0x1fU & (vlTOPp->cpu__DOT__Instr >> 7U));
    }
    vlTOPp->cpu__DOT__PC = vlTOPp->cpu__DOT__pc__DOT__next_PC;
    if (__Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0] 
            = __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v0;
    }
    if (__Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1] 
            = __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v1;
    }
    if (__Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2] 
            = __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v2;
    }
    if (__Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3] 
            = __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v3;
    }
    if (__Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4] 
            = __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v4;
    }
    if (__Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5] 
            = __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v5;
    }
    if (__Vdlyvset__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6) {
        vlTOPp->cpu__DOT__alu__DOT__data__DOT__data_mem_register[__Vdlyvdim0__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6] 
            = __Vdlyvval__cpu__DOT__alu__DOT__data__DOT__data_mem_register__v6;
    }
    if (__Vdlyvset__cpu__DOT__alu__DOT__register__DOT__reg_array__v0) {
        vlTOPp->cpu__DOT__alu__DOT__register__DOT__reg_array[__Vdlyvdim0__cpu__DOT__alu__DOT__register__DOT__reg_array__v0] 
            = __Vdlyvval__cpu__DOT__alu__DOT__register__DOT__reg_array__v0;
    }
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

void Vcpu::_eval(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vcpu::_change_request(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_change_request\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vcpu::_change_request_1(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_change_request_1\n"); );
    Vcpu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
