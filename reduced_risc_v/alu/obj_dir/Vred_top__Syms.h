// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VRED_TOP__SYMS_H_
#define VERILATED_VRED_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vred_top.h"

// INCLUDE MODULE CLASSES
#include "Vred_top___024root.h"

// SYMS CLASS (contains all model state)
class Vred_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vred_top* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vred_top___024root             TOP;

    // CONSTRUCTORS
    Vred_top__Syms(VerilatedContext* contextp, const char* namep, Vred_top* modelp);
    ~Vred_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
