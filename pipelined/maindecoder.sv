/*
	Function: This unit generates the control signals from the 7 bit opcode.
	Determines the type of instruction
*/

module maindecoder #(
    parameter  OP_WIDTH = 7
) (
    input   logic [OP_WIDTH-1:0]    op,
    input   logic [2:0]             funct3,
    output  logic [1:0]             ResultSrc,
    output  logic [1:0]             MemWrite,
    output  logic                   Branch,
    output  logic                   ALUSrc,
    output  logic                   RegWrite,
    output  logic                   Jump,
    output  logic [1:0]             ALUOp,
    output  logic [2:0]             ImmSrc
);

logic [14:0] controls;



always_comb
    case (op)
        // RegWrite_ResultSrc_MemWrite_Jump_Branch_ALUSrc_ImmSrc_ALUOp
        7'b0000011:begin
            controls = 13'b1_01_00_0_0_1_000_00; // lw (default to lw)
            case(funct3)
                3'b100: controls = 14'b1_01_10_0_0_1_000_00 ; //lbu
                default: controls = controls; 
            endcase
        end
        7'b0100011: begin
            controls = 13'b000_00_01_0_0_1_010_00; // sw (default to sw)
            case(funct3)
                3'b000: controls = {controls[12:8],{2'b11}, controls[7:0]}; //sb
                default : controls = controls;
            endcase
        end
      
        7'b0110011: controls = 13'b1_00_00_0_0_0_xxx_10; // R-type
        7'b1100011: controls = 13'b0_00_00_0_1_0_010_01; // B-type (beq) - why does ALUOp have to be 01? - that goes into substraction
        7'b0010011: controls = 13'b1_00_00_0_0_1_000_10; // I-type (ALUSrc is 1 - double check)
        7'b0110111: controls = 13'b1_00_00_0_0_1_100_11; // lui (ALUOp used to be 00 but now set to 11)
        7'b1101111: controls = 13'b1_10_00_1_0_0_011_00; // jal - changed jump to 0 and branch to 1
        7'b1100111: controls = 13'b1_10_00_1_0_1_000_00; // jalr
        7'b0000000: controls = 13'b0_00_00_0_0_0_000_00; // for default values on reset
        default: controls = 13'bx_xx_xx_x_x_x_xxx_xx; // instr not implemented
    endcase

    assign {RegWrite, ResultSrc, MemWrite, Jump, Branch, ALUSrc, ImmSrc, ALUOp} = controls;

endmodule
