// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontrol_top.h for the primary calling header

#ifndef VERILATED_VCONTROL_TOP___024ROOT_H_
#define VERILATED_VCONTROL_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vcontrol_top__Syms;

class Vcontrol_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(PC_i,7,0);
    VL_IN8(Zero_i,0,0);
    VL_OUT8(RegWrite_o,0,0);
    VL_OUT8(MemWrite_o,0,0);
    VL_OUT8(Resultsrc_o,1,0);
    VL_OUT8(ALUctrl_o,2,0);
    VL_OUT8(ALUsrc_o,0,0);
    VL_OUT8(PCsrc_o,1,0);
    CData/*1:0*/ control_top__DOT__ImmSrc;
    VL_OUT(instr_o,31,0);
    VL_OUT(ImmOp_o,31,0);
    VlUnpacked<IData/*31:0*/, 256> control_top__DOT__InstrMem__DOT__rom_array;

    // INTERNAL VARIABLES
    Vcontrol_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcontrol_top___024root(Vcontrol_top__Syms* symsp, const char* name);
    ~Vcontrol_top___024root();
    VL_UNCOPYABLE(Vcontrol_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
