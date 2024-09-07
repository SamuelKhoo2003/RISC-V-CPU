/*
	Function: Pipeline register between Memory Access and WriteBack Stage
*/

module reg_memory #(
    parameter DATA_WIDTH =32
)(  
    input logic                    clk,     
    input logic [DATA_WIDTH-1:0]   ALUResultM,
    input logic [4:0]              RdM,
    input logic [DATA_WIDTH-1:0]   ReadDataM,
    input logic [DATA_WIDTH-1:0]   PCPlus4M,

    output logic [DATA_WIDTH-1:0]   ALUResultW,
    output logic [4:0]              RdW,
    output logic [DATA_WIDTH-1:0]   ReadDataW,
    output logic [DATA_WIDTH-1:0]   PCPlus4W
    );

    always_ff @(posedge clk) begin
        ALUResultW  <=      ALUResultM;
        RdW         <=      RdM;
        ReadDataW   <=      ReadDataM;
        PCPlus4W    <=      PCPlus4M;
    end

endmodule
