// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcontrol_top.h"
#include "Vcontrol_top__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vcontrol_top::Vcontrol_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcontrol_top__Syms(contextp(), _vcname__, this)}
    , PC_i{vlSymsp->TOP.PC_i}
    , Zero_i{vlSymsp->TOP.Zero_i}
    , RegWrite_o{vlSymsp->TOP.RegWrite_o}
    , MemWrite_o{vlSymsp->TOP.MemWrite_o}
    , Resultsrc_o{vlSymsp->TOP.Resultsrc_o}
    , ALUctrl_o{vlSymsp->TOP.ALUctrl_o}
    , ALUsrc_o{vlSymsp->TOP.ALUsrc_o}
    , PCsrc_o{vlSymsp->TOP.PCsrc_o}
    , instr_o{vlSymsp->TOP.instr_o}
    , ImmOp_o{vlSymsp->TOP.ImmOp_o}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcontrol_top::Vcontrol_top(const char* _vcname__)
    : Vcontrol_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcontrol_top::~Vcontrol_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcontrol_top___024root___eval_initial(Vcontrol_top___024root* vlSelf);
void Vcontrol_top___024root___eval_settle(Vcontrol_top___024root* vlSelf);
void Vcontrol_top___024root___eval(Vcontrol_top___024root* vlSelf);
#ifdef VL_DEBUG
void Vcontrol_top___024root___eval_debug_assertions(Vcontrol_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vcontrol_top___024root___final(Vcontrol_top___024root* vlSelf);

static void _eval_initial_loop(Vcontrol_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcontrol_top___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcontrol_top___024root___eval_settle(&(vlSymsp->TOP));
        Vcontrol_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcontrol_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcontrol_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcontrol_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vcontrol_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcontrol_top::final() {
    Vcontrol_top___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcontrol_top::hierName() const { return vlSymsp->name(); }
const char* Vcontrol_top::modelName() const { return "Vcontrol_top"; }
unsigned Vcontrol_top::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vcontrol_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vcontrol_top___024root__trace_init_top(Vcontrol_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vcontrol_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcontrol_top___024root*>(voidSelf);
    Vcontrol_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vcontrol_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vcontrol_top___024root__trace_register(Vcontrol_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vcontrol_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vcontrol_top___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
