module pc_top #(
    parameter   WIDTH = 8
)(
    // interface signals
    input   logic                       clk,        // clock
    input   logic                       rst,        // reset        
    input   logic [WIDTH-1:0]           ImmOp,     
    input   logic                       PCsrc,
    output logic [WIDTH-1:0]            pc_out
);

logic [WIDTH-1:0]   next_PC, pc;    // interconnect wire

pc_mux pc_mux(
    //.clk (clk),
    .PCsrc (PCsrc),
    .ImmOp (ImmOp),
    .next_PC (next_PC),
    .pc (pc)
);

pc_reg pc_reg(
    .clk (clk),
    .rst (rst),
    .next_PC (next_PC),
    .pc (pc),
    .another_pc(pc_out)
);

endmodule
