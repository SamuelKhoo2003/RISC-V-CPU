/*
	Function: Receives control signal from the Main Decoder Unit and 
	determines the type of operation that has to be performed by the ALU
*/

module aludecoder #(
    parameter CONTROL_WIDTH = 3
)(
    input   logic [2:0]                 funct3,
    input   logic                       funct7b5,
    input   logic                       opb5,
    input   logic [1:0]                 ALUOp,
    output  logic [CONTROL_WIDTH-1:0]   ALUControl
);

logic  RtypeSub;
assign RtypeSub = funct7b5 & opb5; //TRUE for R-type subtract

    always_comb
        case (ALUOp)
            2'b00: ALUControl = 3'b000; // addition
            2'b01: ALUControl = 3'b001; // subtraction
            2'b11: ALUControl = 3'b111; // set for the lui instruction
            default: // made it a default but in theory just ALUOp = 2'b10
                case (funct3)
                    3'b000: ALUControl = (RtypeSub) ? 3'b001 : 3'b000; // takes into account case where RtypeSub gives add or addi or sub
                    3'b001: ALUControl = 3'b101; // ssl, slli 
                    // 3'b010: ALUControl = 3'b101; // set less than
                    3'b110: ALUControl = 3'b011; // or
                    3'b111: ALUControl = 3'b010; // and 
                                                    //need to add something for lui
                    default: ALUControl = 3'bxxx;
                endcase
        endcase
endmodule
