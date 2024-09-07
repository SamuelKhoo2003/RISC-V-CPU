/*
	Function: Control Unit Pipeline Register between Instruction Execution and Memory Access Stage
*/

module reg_execute_control #(
    parameter DATA_WIDTH =32
)(  
    input logic                    clk,     
    input logic                    RegWriteE,
    input logic [1:0]              ResultSrcE,
    input logic [1:0]              MemWriteE,
    
    output logic                    RegWriteM,
    output logic [1:0]              ResultSrcM,
    output logic [1:0]              MemWriteM
);

    always_ff @(posedge clk) begin
        RegWriteM   <=      RegWriteE;
        ResultSrcM  <=      ResultSrcE;
        MemWriteM   <=      MemWriteE;
          
    end
      

endmodule
