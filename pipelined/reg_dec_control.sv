/*
	Function: Control Unit Pipeline Register between Decode and Execution Stage
*/

module reg_dec_control #(
    parameter DATA_WIDTH = 32
)(
    input logic                     clk,
    input logic                     en,
    input logic                     rst,

    input logic                     RegWriteD,
    input logic [1:0]               ResultSrcD,
    input logic [1:0]               MemWriteD,
    input logic                     JumpD,
    input logic                     BranchD,
    input logic [2:0]               ALUControlD,
    input logic                     ALUSrcD,
    input logic [2:0]               funct3D,
    input logic [2:0]               ImmSrcD,

    output logic                    RegWriteE,
    output logic [1:0]              ResultSrcE,
    output logic [1:0]              MemWriteE,
    output logic                    JumpE,
    output logic                    BranchE,
    output logic [2:0]              ALUControlE,
    output logic                    ALUSrcE,
    output logic [2:0]              funct3E,
    output logic [2:0]              ImmSrcE

);

always_ff @(posedge clk) begin
    
        RegWriteE   <=       rst?   0   :   RegWriteD;
        ResultSrcE  <=       rst?   0   :   ResultSrcD;
        MemWriteE   <=       rst?   0   :   MemWriteD;
        JumpE       <=       rst?   0   :   JumpD;
        BranchE     <=       rst?   0   :   BranchD;
        ALUControlE <=       rst?   0   :   ALUControlD;
        ALUSrcE     <=       rst?   0   :   ALUSrcD;
        funct3E     <=       rst?   0   :   funct3D;
        ImmSrcE    <=     rst?   0   :   ImmSrcD; 

end

endmodule


