// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_top.h for the primary calling header

#include "verilated.h"

#include "Vcontrol_top__Syms.h"
#include "Vcontrol_top___024root.h"

void Vcontrol_top___024root___ctor_var_reset(Vcontrol_top___024root* vlSelf);

Vcontrol_top___024root::Vcontrol_top___024root(Vcontrol_top__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcontrol_top___024root___ctor_var_reset(this);
}

void Vcontrol_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vcontrol_top___024root::~Vcontrol_top___024root() {
}
