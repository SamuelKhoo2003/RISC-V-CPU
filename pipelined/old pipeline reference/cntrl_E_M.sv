/*
	Function: Control Unit Pipeline Register between Instruction Execution and Memory Access Stage
*/

module control_Exc_Mem #(
) (
    input   logic           clk,
    input   logic           reset,

    input   logic           RegWriteE,
    input   logic [1:0]     ResultSrcE,
    input   logic           MemWriteE,

    output  logic           RegWriteM,
    output  logic [1:0]     ResultSrcM, 
    output  logic           MemWriteM
);

always_ff @(posedge clk, posedge reset) begin
    RegWriteM   <= reset ? 0 : RegWriteE;
    MemWriteM   <= reset ? 0 : MemWriteE;
    ResultSrcM  <= reset ? 0 : ResultSrcE;
end
    
endmodule
