/*
	Function: Pipeline register between Datapath Fetch and Datapath Decode Stage
*/

module reg_Ftc_Dec #(
    parameter DATA_WIDTH = 32
) (
    input   logic                       clk,
    input   logic                       reset,
    input   logic                       clear,
    input   logic                       en, 

    input   logic [DATA_WIDTH-1:0]      InstrF,
    input   logic [DATA_WIDTH-1:0]      PCF,
    input   logic [DATA_WIDTH-1:0]      PCPlus4F, 

    output  logic [DATA_WIDTH-1:0]      InstrD,
    output  logic [DATA_WIDTH-1:0]      PCD,
    output  logic [DATA_WIDTH-1:0]      PCPlus4D, 
);

always_ff @(posedge clk, posedge reset) begin
    if (reset) begin
        InstrD   <= 0;
        PCD      <= 0;
        PCPlus4D <= 0;
    end

    else if (en) begin
        if (clear) begin
            InstrD   <= 0;
            PCD      <= 0;
            PCPlus4D <= 0;
        end

        else begin
            InstrD   <= InstrF;
            PCD      <= PCF;
            PCPlus4D <= PCPlus4F;
        end
    end
end

endmodule
