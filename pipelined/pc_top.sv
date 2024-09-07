module pc_top #(
    parameter   DATA_WIDTH = 32 // changed back to 32 as input for instr mem has to be 32 bit

)(
    // interface signals
    input   logic                            clk,        // clock
    input   logic [DATA_WIDTH-1:0]           ALUResultE_i,        //edited
    input   logic [1:0]                      PCSrc_i,      //edited
    input   logic                            PCen_i,
    input   logic [DATA_WIDTH-1:0]           PCTarget_i, 
    input   logic                            PCrst_i,
    output  logic [DATA_WIDTH-1:0]           PCF_o,
    output  wire  [DATA_WIDTH-1:0]           PCPlus4F_o
);

logic [DATA_WIDTH-1:0]   next_PC; // interconnect wire

assign PCPlus4F_o = PCF_o + 32'b100;  //adding 4

mux3 pc_mux(
    .control    (PCSrc_i),
    .input0     (PCPlus4F_o),
    .input1     (PCTarget_i),
    .input2     (ALUResultE_i),
    .out        (next_PC)
);

pc_reg pc_reg(
    .clk        (clk),
    .rst        (PCrst_i),
    .PCen       (PCen_i),
    .next_PC    (next_PC),
    .pc         (PCF_o)
);

endmodule
