// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpc_top.h for the primary calling header

#ifndef VERILATED_VPC_TOP___024ROOT_H_
#define VERILATED_VPC_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vpc_top__Syms;

class Vpc_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(PCsrc,0,0);
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_IN(ImmOp,31,0);
    VL_OUT(pc_out,31,0);
    IData/*31:0*/ pc_top__DOT__next_PC;
    IData/*31:0*/ pc_top__DOT__pc;

    // INTERNAL VARIABLES
    Vpc_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vpc_top___024root(Vpc_top__Syms* symsp, const char* name);
    ~Vpc_top___024root();
    VL_UNCOPYABLE(Vpc_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
