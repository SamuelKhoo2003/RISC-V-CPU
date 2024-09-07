#include "Vcontrol_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc, char **argv, char **env){
    int clk;
    Verilated::commandArgs(argc,argv);
//  initialise top verilog instance
    Vcontrol_top* top = new Vcontrol_top;
// initialise trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("Vcontrol_top.vcd");

    // initialise simulation outputs
    clk = 0;
    top->PC_i = 0;
    top->Zero_i = 0;
    

    // run simulation for many clock cycles
    int tick = 0;
    for(int i=0;i< 10; i++){

        for(clk=0;clk<2;clk++){
            // in ps
            tfp->dump (2*i+clk);
            // falling edge
            clk = !clk;
            top->eval ();
        }
        top->PC_i = 4*i;

        std::cout << std::hex << int(top->PC_i) << " instr: " << int(top->instr_o) << " ALUctrl: " << int(top->ALUctrl_o) << std::endl;

        if(Verilated::gotFinish()) exit(0);
        
    }
    tfp->close();
    exit(0);
}