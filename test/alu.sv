module alu #(
    parameter CONTROL_WIDTH = 3,
    parameter DATA_WIDTH = 32
)(
    input   logic   [CONTROL_WIDTH-1:0] ALUctrl_i,
    input   logic   [DATA_WIDTH-1:0]    SrcA_i,
    input   logic   [DATA_WIDTH-1:0]    SrcB_i,
    output  logic   [DATA_WIDTH-1:0]    ALUResult_o,
    output  logic                       Zero_o
);

always_comb begin

    case (ALUctrl_i)
    3'b000: ALUResult_o = SrcA_i + SrcB_i;
    3'b001: ALUResult_o = SrcA_i - SrcB_i;
    3'b010: ALUResult_o = SrcA_i & SrcB_i;
    3'b011: ALUResult_o = SrcA_i | SrcB_i;
    3'b100: ALUResult_o = SrcA_i ^ SrcB_i;
    3'b101: ALUResult_o = SrcA_i << SrcB_i[4:0];
    3'b110: ALUResult_o = SrcA_i >> SrcB_i[4:0];
    3'b111: ALUResult_o = SrcB_i;

    default: ALUResult_o = 0;

    endcase 

    assign Zero_o = (SrcA_i == SrcB_i);

end 

endmodule
