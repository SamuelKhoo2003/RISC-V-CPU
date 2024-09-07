/*
	Function: Pipeline register between Memory Access and WriteBack Stage
*/

module reg_Mem_Wrt #(
    parameter DATA_WIDTH = 32
) (
    input   logic                       clk,
    input   logic                       reset,

    input   logic [DATA_WIDTH-1:0]      ALUResultM,
    input   logic [DATA_WIDTH-1:0]      ReadDataM,
    input   logic [4:0]                 RdM, 
    input   logic [DATA_WIDTH-1:0]      PCPlus4M, 

    output  logic [DATA_WIDTH-1:0]      ALUResultW,
    output  logic [DATA_WIDTH-1:0]      ReadDataW,
    output  logic [4:0]                 RdW, 
    output  logic [DATA_WIDTH-1:0]      PCPlus4W, 
);

always_ff @(posedge clk, posedge reset) begin
    ALUResultW <= reset ? 0 : ALUResultM;
    ReadDataW  <= reset ? 0 : ReadDataM;
    RdW        <= reset ? 0 : RdM;
    PCPlus4W   <= reset ? 0 : PCPlus4M; 
end
    
endmodule
