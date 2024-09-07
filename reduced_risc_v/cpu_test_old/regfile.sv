module regfile #(
    parameter ADDRESS_WIDTH = 5,
    parameter DATA_WIDTH = 32
)(
    input logic clk,
    input logic WE3,
    input logic [DATA_WIDTH-1:0] WD3,
    input logic [DATA_WIDTH-1:0] Instr,
    output logic [DATA_WIDTH-1:0] RD1,
    output logic [DATA_WIDTH-1:0] RD2,
    output logic [DATA_WIDTH-1:0] a0
);

logic[4:0] rs2 = Instr[24:20];
logic[4:0] rs1 = Instr[19:15];
logic[4:0] rd = Instr[11:7];

logic [DATA_WIDTH-1:0] reg_array [2**ADDRESS_WIDTH-1:0];

assign RD1 = reg_array[rs1];
assign RD2 = reg_array[rs2];

always_ff @(posedge clk) begin 
    if(WE3 == 1) begin
        reg_array[rd] <= WD3;
    end 
end 

assign a0 = reg_array[10];



endmodule
