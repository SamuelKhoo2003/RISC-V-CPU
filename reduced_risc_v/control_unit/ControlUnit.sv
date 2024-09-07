module ControlUnit #(
    parameter DATA_WIDTH = 32
)(
     input logic                         EQ,
     input logic [DATA_WIDTH-1:0]        instr,
     output logic                        RegWrite,
     output logic [2:0]                  ALUctrl,
     output logic                        ALUsrc,
     output logic [1:0]                 ImmSrc, 
     output logic                        PCsrc,
);
    //for ImmSrc
    //R => 00
    //I => 01
    //J => 10
    //B => 11

    /*
    3'b000: SUM = ALUop1 + ALUop2;
    3'b001: SUM = ALUop1 - ALUop2;
    3'b010: SUM = ALUop1 & ALUop2;
    3'b011: SUM = ALUop1 | ALUop2;
    3'b100: SUM = ALUop1 ^ ALUop2;
    */
    
    logic [6:0] opcode = instr[6:0];
    

    always_comb 
    case (opcode)
    7'b0010011: begin //addi instruction
        RegWrite = 1;
        ALUctrl = 3'b000;
        ALUsrc = 1;
        ImmSrc = 2'b01;
        PCsrc = 0;

    end
    7'b1100011: begin //bne instruction
        RegWrite = 0;
        ALUctrl = 3'b000;
        ALUsrc = 0;
        ImmSrc = 2'b11;
        PCsrc = EQ;

    end
        default begin //just in case we have something else
        RegWrite = 1;
        ALUctrl = 3'b000;
        ALUsrc = 1;
        ImmSrc = 2'b00;
        PCsrc = 0;

    end
    endcase 
    
endmodule
