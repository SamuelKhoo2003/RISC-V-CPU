/*
	Function: Pipeline register between Datapath Decode and Execution Stage
*/

module reg_Dec_Exc #(
    parameter DATA_WIDTH = 32
) (
    input   logic                       clk,
    input   logic                       reset,
    input   logic                       clear,

    input   logic [DATA_WIDTH-1:0]      RD1D,
    input   logic [DATA_WIDTH-1:0]      RD2D,
    input   logic [DATA_WIDTH-1:0]      PCD,
    input   logic [4:0]                 Rs1D,
    input   logic [4:0]                 Rs2D,
    input   logic [4:0]                 RdD,
    input   logic [DATA_WIDTH-1:0]      ExtImmD,
    input   logic [DATA_WIDTH-1:0]      PCPlus4D,

    output  logic [DATA_WIDTH-1:0]      RD1E,
    output  logic [DATA_WIDTH-1:0]      RD2E,
    output  logic [DATA_WIDTH-1:0]      PCE,
    output  logic [4:0]                 Rs1E,
    output  logic [4:0]                 Rs2E,
    output  logic [4:0]                 RdE,
    output  logic [DATA_WIDTH-1:0]      ExtImmE,
    output  logic [DATA_WIDTH-1:0]      PCPlus4E
);

always_ff @(posedge clk, posedge reset) begin
    RD1E     <= 0;
    RD2E     <= 0;
    PCE      <= 0;
    Rs1E     <= 0;
    Rs2E     <= 0;
    RdE      <= 0;
    ExtImmE  <= 0;
    PCPlus4E <= 0;
    
    if(!reset && !clear) begin
        RD1E     <= RD1D;
        RD2E     <= RD2D;
        PCE      <= PCD;
        Rs1E     <= Rs1D;
        Rs2E     <= Rs2D;
        RdE      <= RdD;
        ExtImmE  <= ExtImmD;
        PCPlus4E <= PCPlus4D;
    end
end

endmodule
