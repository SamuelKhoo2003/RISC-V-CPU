// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vgreen.h"
#include "Vgreen__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vgreen::Vgreen(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vgreen__Syms(contextp(), _vcname__, this)}
    , PC{vlSymsp->TOP.PC}
    , EQ{vlSymsp->TOP.EQ}
    , RegWrite{vlSymsp->TOP.RegWrite}
    , ALUctrl{vlSymsp->TOP.ALUctrl}
    , ALUsrc{vlSymsp->TOP.ALUsrc}
    , PCsrc{vlSymsp->TOP.PCsrc}
    , instr{vlSymsp->TOP.instr}
    , ImmOp{vlSymsp->TOP.ImmOp}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vgreen::Vgreen(const char* _vcname__)
    : Vgreen(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vgreen::~Vgreen() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vgreen___024root___eval_initial(Vgreen___024root* vlSelf);
void Vgreen___024root___eval_settle(Vgreen___024root* vlSelf);
void Vgreen___024root___eval(Vgreen___024root* vlSelf);
#ifdef VL_DEBUG
void Vgreen___024root___eval_debug_assertions(Vgreen___024root* vlSelf);
#endif  // VL_DEBUG
void Vgreen___024root___final(Vgreen___024root* vlSelf);

static void _eval_initial_loop(Vgreen__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vgreen___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vgreen___024root___eval_settle(&(vlSymsp->TOP));
        Vgreen___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vgreen::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vgreen::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vgreen___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vgreen___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vgreen::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vgreen::final() {
    Vgreen___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vgreen::hierName() const { return vlSymsp->name(); }
const char* Vgreen::modelName() const { return "Vgreen"; }
unsigned Vgreen::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vgreen::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vgreen___024root__trace_init_top(Vgreen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vgreen___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vgreen___024root*>(voidSelf);
    Vgreen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vgreen___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vgreen___024root__trace_register(Vgreen___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vgreen::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vgreen___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
