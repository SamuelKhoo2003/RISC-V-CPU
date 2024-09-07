`include "/home/vish/Documents/iac/Reduced_RISC-V-Team1-/pc/pc_top.sv"
`include "/home/vish/Documents/iac/Reduced_RISC-V-Team1-/alu/red_top.sv"
`include "/home/vish/Documents/iac/Reduced_RISC-V-Team1-/control_unit/green.sv"


module cpu #(

    parameter DATA_WIDTH = 32

)(

    input logic                        clk,
    input logic                        rst,
    output logic [DATA_WIDTH-1:0]      a0

);

    //output internal logic for "green" module 
    logic   RegWrite;
    logic   ALUctrl;
    logic   ALUsrc;
    logic   ImmSrc;
    logic   PCsrc;
    logic   ImmOp;
    logic   Instr;

    //output internal logic for "red" module 
    logic EQ;

    //output internal logic for "blue" module
    logic PC;

    //and then we would specify the "submodules here"   
        //green
        //blue
        //red
    //we can change the names 

PCtop Myblue(
    .clk(clk),
    .rst(rst),
    .PC(PC),
    .PCsrc(PCsrc),
    .ImmOp(ImmOp)
);

green Mygreen(
    .EQ(EQ),
    .RegWrite(RegWrite),
    .ALUctrl(ALUctrl),
    .ALUsrc(ALUsrc),
    //.ImmSrc(ImmSrc),
    .PCsrc(PCsrc),
    .ImmOp(ImmOp),
    .PC(PC)
);

red_top Myred(
    .clk(clk),
    .a0(a0),
    .Instr(Instr),//we pass the whole Instruction, and then we separate inside red
    .RegWrite(RegWrite),
    .EQ(EQ),
    .ALUctrl(ALUctrl),
    .ALUsrc(ALUsrc),
    .ImmOp(ImmOp)
);
    
endmodule

