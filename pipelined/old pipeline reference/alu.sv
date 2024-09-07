module alu (
    input logic [2:0] ALUControlE,
    input logic [31:0] SrcAE,
    input logic [31:0] SrcBE,

    output logic ZeroE,
    output logic [31:0] ALUResultE
);

always_comb begin
    case (ALUControlE)
    3'b000: ALUResultE = SrcAE + SrcBE; //addition
    3'b001: ALUResultE = SrcAE - SrcBE; //subtraction
    3'b010: ALUResultE = SrcAE & SrcBE; //and
    3'b011: ALUResultE = SrcAE | SrcBE; //or
    3'b100: ALUResultE = SrcAE << SrcBE[4:0];  //slli
    3'b101: ALUResultE = SrcAE < SrcBE; //set less than
    3'b110: ALUResultE = SrcBE; // unknown - undefined 
    3'b111: ALUResultE = SrcBE; // lui        

    default: ALUResultE = 32'bx;

    endcase

    assign ZeroE = (SrcAE == SrcBE);

end

endmodule 
