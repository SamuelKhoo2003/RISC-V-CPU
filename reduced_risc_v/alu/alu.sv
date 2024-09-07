module alu #(
    parameter DATA_WIDTH = 32
)(
    input logic [2:0] ALUctrl,
    input logic [DATA_WIDTH-1:0] ALUop1,
    input logic [DATA_WIDTH-1:0] ALUop2,
    output logic [DATA_WIDTH-1:0] SUM,
    output logic EQ
);

always_comb begin
    case (ALUctrl)
    3'b000: SUM = ALUop1 + ALUop2;
    3'b001: SUM = ALUop1 - ALUop2;
    3'b010: SUM = ALUop1 & ALUop2;
    3'b011: SUM = ALUop1 | ALUop2;
    3'b100: SUM = ALUop1 ^ ALUop2;

    default: SUM = 0;

    endcase 

    assign EQ = (ALUop1 == ALUop2);

end 

endmodule
