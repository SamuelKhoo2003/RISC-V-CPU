module cpu #(

    parameter DATA_WIDTH = 32
    //ADDRESS_WIDTH = 8

)(

    input logic                        clk,
    input logic                        rst,
    output logic [DATA_WIDTH-1:0]      a0


);

    //output internal logic for "green" module 
    logic   RegWrite;
    logic   [2:0] ALUctrl;
    logic   ALUsrc;
    //logic   ImmSrc;
    logic   PCsrc;
    logic   [DATA_WIDTH-1:0] ImmOp;
    logic   [DATA_WIDTH-1:0] Instr;

    //output internal logic for "red" module 
    logic EQ;

    //output internal logic for "blue" module
    logic [DATA_WIDTH-1:0] PC;

    //and then we would specify the "submodules here"   
        //green
        //blue
        //red
    //we can change the names 

pc_top Myblue(
    .clk(clk),
    .rst(rst),
    .pc_out(PC),
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
    .PC(PC),
    .instr(Instr)
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

