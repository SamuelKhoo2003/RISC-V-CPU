/*
	Function: Pipeline register between Datapath Fetch and Datapath Decode Stage
*/

module reg_fetch #(
    parameter DATA_WIDTH = 32
)(       
    input logic                  clk,
    input logic                  en,
    input logic                  rst,
    input logic [DATA_WIDTH-1:0] InstrF,
    input logic [DATA_WIDTH-1:0] PCF,
    input logic [DATA_WIDTH-1:0] PCPlus4F,
    output logic [DATA_WIDTH-1:0] PCPlus4D,
    output logic [DATA_WIDTH-1:0] InstrD,
    output logic [DATA_WIDTH-1:0] PCD

  );  

    always_ff @(posedge clk) begin
        if (en) begin
        InstrD      <= rst? 0   :   InstrF;
        PCD         <= rst? 0   :   PCF;
        PCPlus4D    <= rst? 0   :   PCPlus4F;
        end
        
    end
      

endmodule
