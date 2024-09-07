/*
	Function: Receives control signals from the ALU Decoder and performs the operations
*/

module alu #(
    parameter CONTROL_WIDTH = 3,
    parameter DATA_WIDTH = 32
)(
    input   logic   [CONTROL_WIDTH-1:0] ALUControl,
    input   logic   [DATA_WIDTH-1:0]    SrcA,
    input   logic   [DATA_WIDTH-1:0]    SrcB,
    output  logic   [DATA_WIDTH-1:0]    ALUResult,
    output  logic                       Zero
);
//hello
always_comb begin

    case (ALUControl)
        3'b000: ALUResult = SrcA + SrcB;
        3'b001: ALUResult = SrcA - SrcB;
        3'b010: ALUResult = SrcA & SrcB;
        3'b011: ALUResult = SrcA | SrcB;
        3'b100: ALUResult = SrcA ^ SrcB;
        3'b101: ALUResult = SrcA << SrcB[4:0];
        // 3'b110: ALUResult = SrcB; //why do we have the same operation twice? - cuz you dont have anything assigned for it in aludecoder...
        3'b111: ALUResult = SrcB; //^^

        default: ALUResult = 32'bx; 

    endcase 

    assign Zero = (SrcA == SrcB);

end 

endmodule
