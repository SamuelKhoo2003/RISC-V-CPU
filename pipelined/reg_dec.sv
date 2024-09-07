/*
	Function: Pipeline register between Datapath Decode and Execution Stage
*/

module reg_dec #(
    parameter DATA_WIDTH = 32
)(
    input logic                     clk,
    input logic                     en,
    input logic                     rst,
    input logic [DATA_WIDTH-1:0]    RD1D,
    input logic [DATA_WIDTH-1:0]    RD2D,
    input logic [DATA_WIDTH-1:0]    PCD,
    input logic [4:0]               Rs1D,
    input logic [4:0]               Rs2D,
    input logic [4:0]               RdD,
    input logic [DATA_WIDTH-1:0]    ExtImmD,
    input logic [DATA_WIDTH-1:0]    PCPlus4D,
    input logic [6:0]               opcodeD,

    output logic [DATA_WIDTH-1:0]    RD1E,
    output logic [DATA_WIDTH-1:0]    RD2E,
    output logic [DATA_WIDTH-1:0]    PCE,
    output logic [4:0]               Rs1E,
    output logic [4:0]               Rs2E,
    output logic [4:0]               RdE,
    output logic [DATA_WIDTH-1:0]    ExtImmE,
    output logic [DATA_WIDTH-1:0]    PCPlus4E,
    output logic [6:0]               opcodeE

);

always_ff @(posedge clk) begin
    
        RD1E        <=       rst?   0   :   RD1D;
        RD2E        <=       rst?   0   :   RD2D;
        PCE         <=       rst?   0   :   PCD;
        Rs1E        <=       rst?   0   :   Rs1D;
        Rs2E        <=       rst?   0   :   Rs2D;
        RdE         <=       rst?   0   :   RdD;
        ExtImmE     <=       rst?   0   :   ExtImmD;
        PCPlus4E    <=       rst?   0   :   PCPlus4D;
        opcodeE     <=       rst?   0   :   opcodeD;

end

endmodule


