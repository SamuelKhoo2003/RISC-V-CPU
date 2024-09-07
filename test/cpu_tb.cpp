#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vcpu.h"
#include "vbuddy.cpp"
#include <iostream>
#include <chrono>
#include <thread>


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


#define MAX_SIM_CYC 100

int main(int argc, char **argv, char **env) {
    int simcyc;     // simulation clock count
    int tick;       // each clk cycle has two ticks for two edges

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vcpu* top = new Vcpu;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("cpu.vcd");

    //init Vbuddy
    if (vbdOpen()!=1) return(-1);
    vbdHeader("F1");

    // initialize simulation inputs
    top->clk = 0;
    top->rst = 0;

    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        // dump variables into VCD file and toggle clock
        for (tick=0; tick<2; tick++) {
        tfp->dump (2*simcyc+tick);
        top->clk = !top->clk;
        top->eval ();
                   

        }

            vbdBar(top->a0 & 0xFF);
            sleep_for(nanoseconds(200000000));  //delay for f1 lights


   // either simulation finished, or 'q' is pressed
    if ((Verilated::gotFinish()) || (vbdGetkey()=='q')){
      exit(0);                // ... exit if finish OR 'q' pressed    
    }

    }

    vbdClose();
    tfp->close();
    exit(0);
    
}