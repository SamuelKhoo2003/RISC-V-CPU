#include "Vred_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char **argv, char **env){
    int clk;
    Verilated::commandArgs(argc,argv);
//  initialise top verilog instance
    Vred_top* top = new Vred_top;
// initialise trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp,99);
    tfp->open("Vred_top.vcd");

    // initialise simulation outputs
    top->clk =1;
    top->ALUsrc = 1;
    top->ALUctrl = 1;
    top->ImmOp = 0;
    top->Instr = 0;
    top->RegWrite = 1;

    // run simulation for many clock cycles
    int tick = 0;
    for(int i=0;i< 300; i++){
        // Add to readme, remember to compelete part 2 of challenge
        // dump variables into VCD file and toggle clock
        for(clk=0;clk<2;clk++){
            // in ps
            tfp->dump (2*i+clk);
            // falling edge
            top->clk = !top->clk;
            top->eval ();
        }
        top->clk =1;
        top->ALUsrc = 1;
        top->ALUctrl = 1;
        top->ImmOp = -1;
        top->Instr = 1048595;
        top-> RegWrite = 1;
        if(Verilated::gotFinish()) exit(0);
        
    }
    tfp->close();
    exit(0);
}