// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCPU_H_
#define _VCPU_H_  // guard

#include "verilated_heavy.h"

//==========

class Vcpu__Syms;
class Vcpu_VerilatedVcd;


//----------

VL_MODULE(Vcpu) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT(a0,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*2:0*/ cpu__DOT__RegWrite;
    CData/*1:0*/ cpu__DOT__MemWrite;
    CData/*2:0*/ cpu__DOT__ALUctrl;
    CData/*0:0*/ cpu__DOT__Zero;
    CData/*1:0*/ cpu__DOT__Resultsrc;
    CData/*1:0*/ cpu__DOT__PCsrc;
    CData/*2:0*/ cpu__DOT__control__DOT__ImmSrc;
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
    CData/*7:0*/ cpu__DOT__control__DOT__InstrMem__DOT__rom_array[256];
    IData/*31:0*/ cpu__DOT__alu__DOT__register__DOT__reg_array[32];
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT__data_mem_register[131073];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound1;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound2;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound3;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound4;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound5;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound6;
    CData/*7:0*/ cpu__DOT__alu__DOT__data__DOT____Vlvbound7;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcpu__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcpu();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcpu__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vcpu__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
