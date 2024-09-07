/*
	Function: Pipeline register between Datapath Execution and Memory Access Stage
*/

module reg_execute #(
    parameter DATA_WIDTH =32
)(  
    input logic                    clk,     
    input logic [DATA_WIDTH-1:0]   ALUResultE,
    input logic [4:0]              RdE,
    input logic [DATA_WIDTH-1:0]   WriteDataE,
    input logic [DATA_WIDTH-1:0]   PCPlus4E,
    
    output logic [DATA_WIDTH-1:0]   ALUResultM,
    output logic [4:0]              RdM,
    output logic [DATA_WIDTH-1:0]   WriteDataM,
    output logic [DATA_WIDTH-1:0]   PCPlus4M
);

    always_ff @(posedge clk) begin
        ALUResultM  <=      ALUResultE;
        RdM         <=      RdE;
        WriteDataM  <=      WriteDataE;
        PCPlus4M     <=      PCPlus4E;   
          
    end
      

endmodule
