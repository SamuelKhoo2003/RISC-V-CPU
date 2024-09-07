/*
	Function: Control Unit Pipeline Register between Decode and Execution Stage
*/

module control_Dec_Exc #(
    parameters CONTROL_WIDTH = 3
) (
    input   logic                       clk,
    input   logic                       reset,
    input   logic                       clear,

    input   logic                       RegWriteD,
    input   logic                       MemWriteD,
    input   logic                       JumpD,
    input   logic                       BranchD,
    input   logic                       ALUSrcD,
    input   logic [1:0]                 ResultSrcD,
    input   logic [CONTROL_WIDTH-1:0]   ALUControlD,

              
    output  logic                       RegWriteE,
    output  logic                       MemWriteE,
    output  logic                       JumpE,
    output  logic                       BranchE,
    output  logic                       ALUSrcE,
    output  logic [1:0]                 ResultSrcE,
    output  logic [CONTROL_WIDTH-1:0]   ALUControlE
);

always_ff @(posedge clk, posedge reset) begin
    RegWriteE     <= 0;
    MemWriteE     <= 0;
    JumpE         <= 0;
    BranchE       <= 0;
    ALUSrcAE      <= 0;
    ALUSrcBE      <= 0;
    ResultSrcE    <= 0;
    ALUControlE   <= 0;

    // Update only if reset is low and clear is low
    if (!reset && !clear) begin
        RegWriteE     <= RegWriteD;
        MemWriteE     <= MemWriteD;
        JumpE         <= JumpD;
        BranchE       <= BranchD;
        ALUSrcAE      <= ALUSrcAD;
        ALUSrcBE      <= ALUSrcBD;
        ResultSrcE    <= ResultSrcD;
        ALUControlE   <= ALUControlD;
    end
end

endmodule
