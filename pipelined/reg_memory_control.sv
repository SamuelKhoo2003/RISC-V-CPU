/*
	Function: Control Unit Pipeline Register for Memory Access - WriteBack Stage
*/

module reg_memory_control #(
    parameter DATA_WIDTH =32
)(  
    input logic                    clk,     
    input logic                    RegWriteM,
    input logic [1:0]              ResultSrcM,

    output logic                   RegWriteW,
    output logic [1:0]              ResultSrcW
    );

    always_ff @(posedge clk) begin
        RegWriteW   <=      RegWriteM;
        ResultSrcW  <=      ResultSrcM;
    end

endmodule
