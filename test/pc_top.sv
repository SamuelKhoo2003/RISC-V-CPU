module pc_top #(
    parameter   WIDTH = 32 // changed back to 32 as input for instr mem has to be 32 bit

)(
    // interface signals
    input   logic                       clk,        // clock
    input   logic                       rst,        // reset 
    input   logic [WIDTH-1:0]           ALUResult_i,        //edited
    input   logic [WIDTH-1:0]           ImmOp_i,     
    input   logic [1:0]                 PCsrc_i,                   //edited
    output  logic [WIDTH-1:0]           pc_out,
    output  wire  [WIDTH-1:0]           PCPlus4_o
);

logic [WIDTH-1:0]   next_PC, PC, PCTarget;    // interconnect wire

assign PCPlus4_o = PC + 32'b100;  //adding 4
assign PCTarget = PC + ImmOp_i;

mux4 pc_mux(
    .control    (PCsrc_i),
    .input0     (PCPlus4_o),
    .input1     (PCTarget),
    .input2     (ALUResult_i),
    .out        (next_PC)
);

pc_reg pc_reg(
    .clk        (clk),
    .rst        (rst),
    .next_PC    (next_PC),
    .pc         (PC),
    .another_pc (pc_out)
);

endmodule
