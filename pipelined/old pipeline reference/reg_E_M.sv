/*
	Function: Pipeline register between Datapath Execution and Memory Access Stage
*/

module reg_Exc_Mem #(
    parameter DATA_WIDTH = 32
) (
    input   logic                       clk,
    input   logic                       reset,

    input   logic [DATA_WIDTH-1:0]      ALUResultE,
    input   logic [DATA_WIDTH-1:0]      WriteDataE,
    input   logic [4:0]                 RdE,
    input   logic [DATA_WIDTH-1:0]      PCPlus4E,

    output  logic [DATA_WIDTH-1:0]      ALUResultM,
    output  logic [DATA_WIDTH-1:0]      WriteDataM,
    output  logic [4:0]                 RdM,
    output  logic [DATA_WIDTH-1:0]      PCPlus4M,
);

always_ff @(posedge clk, posedge reset) begin
    ALUResultM <= reset ? 0 : ALUResultE;
    WriteDataM <= reset ? 0 : WriteDataE;
    RdM        <= reset ? 0 : RdE;
    PCPlus4M   <= reset ? 0 : PCPlus4E;
end
    
endmodule
