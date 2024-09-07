// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcpu.h for the primary calling header

#ifndef VERILATED_VCPU___024ROOT_H_
#define VERILATED_VCPU___024ROOT_H_  // guard

#include "verilated.h"

class Vcpu__Syms;

class Vcpu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*2:0*/ cpu__DOT__RegWrite;
    CData/*1:0*/ cpu__DOT__MemWrite;
    CData/*2:0*/ cpu__DOT__ALUctrl;
    CData/*0:0*/ cpu__DOT__ALUsrc;
    CData/*1:0*/ cpu__DOT__Resultsrc;
    CData/*1:0*/ cpu__DOT__PCsrc;
    CData/*2:0*/ cpu__DOT__control__DOT__ImmSrc;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound_h4b1400a6__0;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound_ha43eb5ce__0;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound_ha4b1a5db__0;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound_hd908c1f5__0;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound_h4b1400a6__1;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound_ha43eb5ce__1;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound_he5a30f51__0;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT(a0,31,0);
    IData/*31:0*/ cpu__DOT__Instr;
    IData/*31:0*/ cpu__DOT__ALUResult_o;
    IData/*31:0*/ cpu__DOT__ImmOp;
    IData/*31:0*/ cpu__DOT__PC;
    IData/*31:0*/ cpu__DOT__pc__DOT__next_PC;
    IData/*31:0*/ cpu__DOT__pc__DOT__PC;
    IData/*31:0*/ cpu__DOT__pc__DOT__pc_mux__DOT__input3;
    IData/*31:0*/ cpu__DOT__alu__DOT__SrcA;
    IData/*31:0*/ cpu__DOT__alu__DOT__SrcB;
    IData/*31:0*/ cpu__DOT__alu__DOT__Result;
    IData/*31:0*/ cpu__DOT__alu__DOT__regOp2;
    IData/*31:0*/ cpu__DOT__alu__DOT__resultMux__DOT__input3;
    IData/*31:0*/ __Vchglast__TOP__cpu__DOT__alu__DOT__SrcB;
    VlUnpacked<CData/*7:0*/, 256> cpu__DOT__control__DOT__InstrMem__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> cpu__DOT__alu__DOT__register__DOT__reg_array;
    VlUnpacked<CData/*7:0*/, 131073> cpu__DOT__alu__DOT__data__DOT__data_mem_register;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vcpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcpu___024root(Vcpu__Syms* symsp, const char* name);
    ~Vcpu___024root();
    VL_UNCOPYABLE(Vcpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
