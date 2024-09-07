module maindecoder #(
    parameter  OP_WIDTH = 7
) (
    input   logic [OP_WIDTH-1:0]    op,
    input   logic [2:0]             funct3,
    output  logic [1:0]             ResultSrc,
    output  logic [1:0]             MemWrite,
    output  logic                   Branch,
    output  logic                   ALUSrc,
    output  logic [2:0]             RegWrite,
    output  logic                   Jump,
    output  logic [1:0]             ALUOp,
    output  logic [2:0]             ImmSrc
);

logic [14:0] controls;

always_comb
    case (op)
        // RegWrite_ResultSrc_MemWrite_Jump_Branch_ALUSrc_ImmSrc_ALUOp
        7'b0000011:begin
            controls = 15'b000_01_00_0_0_1_000_00; // lw
            case(funct3)
                3'b000: controls = {{3'b011}, controls [11:0]}; //lb
                3'b001: controls = {{3'b010}, controls [11:0]}; //lh
                3'b010: controls = {{3'b001}, controls [11:0]}; //lw
                3'b100: controls = {{3'b111}, controls [11:0]}; //lbu (not needed)
                3'b101: controls = {{3'b110}, controls [11:0]}; //lhu (not needed)
                default: controls = controls; 
            endcase
        end
        7'b0100011: begin
            controls = 15'b000_00_00_0_0_1_010_00; // sw
            case(funct3)
                3'b000: controls = {controls[14:10],{2'b11}, controls[7:0]}; //sb
                3'b001: controls = {controls[14:10],{2'b10}, controls[7:0]}; //sh
                3'b010: controls = {controls[14:10],{2'b01}, controls[7:0]}; //sw
                default : controls = controls;
            endcase
        end
      
        7'b0110011: controls = 15'b001_00_00_0_0_0_xxx_10; // R-type
        7'b1100011: controls = 15'b000_00_00_0_1_0_010_01; // B-type (beq)
        7'b0010011: controls = 15'b001_00_00_0_0_1_000_10; // I-type (ALUSrc is 1 - double check)
        7'b0110111: controls = 15'b001_00_00_0_0_1_100_11; // lui (ALUOp used to be 00 but now set to 11)
        7'b1101111: controls = 15'b001_10_00_1_0_0_011_00; // jal - changed jump to 0 and branch to 1
        7'b1100111: controls = 15'b001_10_00_1_0_1_000_00; // jalr
        7'b0000000: controls = 15'b000_00_00_0_0_0_000_00; // for default values on reset
        default: controls = 15'bxxx_xx_xx_x_x_x_xxx_xx; // instr not implemented
    endcase

    assign {RegWrite, ResultSrc, MemWrite, Jump, Branch, ALUSrc, ImmSrc, ALUOp} = controls;

endmodule
