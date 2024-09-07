// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vgreen.h for the primary calling header

#ifndef VERILATED_VGREEN___024ROOT_H_
#define VERILATED_VGREEN___024ROOT_H_  // guard

#include "verilated.h"

class Vgreen__Syms;

class Vgreen___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(PC,7,0);
    VL_IN8(EQ,0,0);
    VL_OUT8(RegWrite,0,0);
    VL_OUT8(ALUctrl,2,0);
    VL_OUT8(ALUsrc,0,0);
    VL_OUT8(PCsrc,0,0);
    CData/*1:0*/ green__DOT__ImmSrc;
    CData/*0:0*/ green__DOT__MyInstrMem__DOT__clk;
    VL_OUT(instr,31,0);
    VL_OUT(ImmOp,31,0);
    VlUnpacked<CData/*7:0*/, 256> green__DOT__MyInstrMem__DOT__rom_array;

    // INTERNAL VARIABLES
    Vgreen__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vgreen___024root(Vgreen__Syms* symsp, const char* name);
    ~Vgreen___024root();
    VL_UNCOPYABLE(Vgreen___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
