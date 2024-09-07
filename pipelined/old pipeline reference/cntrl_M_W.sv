/*
	Function: Control Unit Pipeline Register for Memory Access - WriteBack Stage
*/

module control_Mem_Wrt #(
) (
    input   logic           clk,
    input   logic           reset,

    input   logic           RegWriteM,
    input   logic [1:0]     ResultSrcM,

    output  logic           RegWriteW,
    output  logic [1:0]     ResultSrcW
);

always_ff @(posedge clk, posedge reset) begin
    RegWriteW    <= reset ? 0 : RegWriteM;
    ResultSrcW   <= reset ? 0 : ResultSrcM;
end
    
endmodule
