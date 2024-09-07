// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vred_top.h"
#include "Vred_top__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vred_top::Vred_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vred_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , ALUsrc{vlSymsp->TOP.ALUsrc}
    , ALUctrl{vlSymsp->TOP.ALUctrl}
    , RegWrite{vlSymsp->TOP.RegWrite}
    , EQ{vlSymsp->TOP.EQ}
    , Instr{vlSymsp->TOP.Instr}
    , ImmOp{vlSymsp->TOP.ImmOp}
    , a0{vlSymsp->TOP.a0}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vred_top::Vred_top(const char* _vcname__)
    : Vred_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vred_top::~Vred_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vred_top___024root___eval_initial(Vred_top___024root* vlSelf);
void Vred_top___024root___eval_settle(Vred_top___024root* vlSelf);
void Vred_top___024root___eval(Vred_top___024root* vlSelf);
#ifdef VL_DEBUG
void Vred_top___024root___eval_debug_assertions(Vred_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vred_top___024root___final(Vred_top___024root* vlSelf);

static void _eval_initial_loop(Vred_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vred_top___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vred_top___024root___eval_settle(&(vlSymsp->TOP));
        Vred_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vred_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vred_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vred_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vred_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vred_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vred_top::final() {
    Vred_top___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vred_top::hierName() const { return vlSymsp->name(); }
const char* Vred_top::modelName() const { return "Vred_top"; }
unsigned Vred_top::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vred_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vred_top___024root__trace_init_top(Vred_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vred_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vred_top___024root*>(voidSelf);
    Vred_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vred_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vred_top___024root__trace_register(Vred_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vred_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vred_top___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
