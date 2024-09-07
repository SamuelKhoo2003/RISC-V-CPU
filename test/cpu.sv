module cpu #(
    parameter   DATA_WIDTH = 32,
    parameter   CONTROL_WIDTH = 3,
    parameter   IMM_WIDTH = 2

)(

    input logic                        clk,
    input logic                        rst,
    output logic [DATA_WIDTH-1:0]      a0

);

    //output internal logic for control module 
    logic   [2:0]            RegWrite;
    logic   [1:0]            MemWrite;
    logic   [DATA_WIDTH-1:0] Instr;

    //output internal logic for alu module 
    logic [CONTROL_WIDTH-1:0]  ALUctrl;
    logic ALUsrc;
    logic Zero;
    logic [DATA_WIDTH-1:0]     ALUResult_o;

    //output internal logic for pc module
    logic [IMM_WIDTH-1:0]  Resultsrc;
    logic [DATA_WIDTH-1:0] ImmOp;
    logic [IMM_WIDTH-1:0]  PCsrc;
    logic [DATA_WIDTH-1:0]  PC;
    logic [DATA_WIDTH-1:0]  PCPlus4;


pc_top pc(
    .clk(clk),        
    .rst(rst),        
    .ALUResult_i(ALUResult_o),    //result from data mem to mux4    
    .ImmOp_i(ImmOp),     
    .PCsrc_i(PCsrc),
    .pc_out(PC), //32b
    .PCPlus4_o(PCPlus4) //unsure
    );

control_top control(
    .PC_i(PC), //8b
    .Zero_i(Zero), //1b
    .instr_o(Instr),//32b
    .RegWrite_o(RegWrite), //1b
    .MemWrite_o(MemWrite), //1b
    .Resultsrc_o(Resultsrc), //3b ==> edited to 2 bits
    .ALUctrl_o(ALUctrl), //3b
    .ALUsrc_o(ALUsrc), //1 bit
    .PCsrc_o(PCsrc), //1 bit ==> edited to 2 bits
    .ImmOp_o(ImmOp) //32 bits
);

alu_top alu(
    .clk(clk),
    .ALUsrc_i(ALUsrc),
    .ALUctrl_i(ALUctrl),
    .Instr_i(Instr),
    .RegWrite_i(RegWrite),
    .ResultSrc_i(Resultsrc),
    .MemWrite_i(MemWrite),
    .ImmOp_i(ImmOp),
    .PCPlus4_i(PCPlus4),
    .Zero_o(Zero),
    .a0(a0),  //(debug output)
    .ALUResult_o(ALUResult_o)
    
);

endmodule

