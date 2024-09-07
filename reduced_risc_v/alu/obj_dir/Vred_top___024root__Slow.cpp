// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vred_top.h for the primary calling header

#include "verilated.h"

#include "Vred_top__Syms.h"
#include "Vred_top___024root.h"

void Vred_top___024root___ctor_var_reset(Vred_top___024root* vlSelf);

Vred_top___024root::Vred_top___024root(Vred_top__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vred_top___024root___ctor_var_reset(this);
}

void Vred_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vred_top___024root::~Vred_top___024root() {
}
