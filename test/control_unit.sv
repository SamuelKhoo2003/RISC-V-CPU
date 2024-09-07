module control_unit #(
    parameter DATA_WIDTH = 32,
    parameter CONTROL_WIDTH = 3,
    parameter IMM_WIDTH = 2
)(
    input   logic                           Zero_i,
    input   logic [DATA_WIDTH-1:0]          instr_i,
    output  logic [2:0]                     RegWrite_o,
    output  logic [1:0]                     MemWrite_o,
    output  logic [IMM_WIDTH-1:0]           Resultsrc_o,
    output  logic [CONTROL_WIDTH-1:0]       ALUctrl_o,
    output  logic                           ALUsrc_o,
    output  logic [2:0]                     ImmSrc_o, 
    output  logic [IMM_WIDTH-1:0]           PCsrc_o
);


    //actual ImmSrc
    //000 -> I
    //001 -> S
    //010 -> B 
    //011 -> J
    //100 -> U



    /*
    3'b000: SUM = ALUop1 + ALUop2;
    3'b001: SUM = ALUop1 - ALUop2;
    3'b010: SUM = ALUop1 & ALUop2;
    3'b011: SUM = ALUop1 | ALUop2;
    3'b100: SUM = ALUop1 ^ ALUop2;
    */

    

    logic [6:0]     opcode = instr_i[6:0];
    logic [2:0]     funct3 = instr_i[14:12];
    logic           funct7 = instr_i[30];
    
    always_comb  begin

    case (opcode)

    7'b0000011: // (3) load instructions - I Type
        begin
            ImmSrc_o = 3'b000;
            ALUsrc_o = 1'b1;
            MemWrite_o = 2'b00; 
            Resultsrc_o = 2'b01;
            PCsrc_o = 2'b000;
            ALUctrl_o = 3'b000;
            case(funct3)
                3'b000: RegWrite_o = 3'b011; //lb
                3'b001: RegWrite_o = 3'b010; //lh
                3'b010: RegWrite_o = 3'b001; //lw
                3'b100: RegWrite_o = 3'b111; //lbu
                3'b101: RegWrite_o = 3'b110; //lhu
                default: RegWrite_o = 3'b000; //(not sure what default should be but 000 for now)
            endcase
        end

    7'b0100011: // (35) store instrucions - S type 
        begin
            ImmSrc_o = 3'b001;
            ALUsrc_o = 1'b1;
            RegWrite_o = 3'b000; 
            Resultsrc_o = 2'b00;
            PCsrc_o = 2'b000;
            ALUctrl_o = 3'b000;
            case(funct3)
                3'b000: MemWrite_o = 2'b11; //sb
                3'b001: MemWrite_o = 2'b10; //sh
                3'b010: MemWrite_o = 2'b01; //sw
                default: MemWrite_o = 2'b00; //(not sure what default should be but 000 for now)
            endcase
        end
    
    7'b0110011: // R-type
        begin
            RegWrite_o = 3'b001;
            ImmSrc_o = 3'b000;
            ALUsrc_o = 1'b0;
            MemWrite_o = 2'b00;
            Resultsrc_o = 2'b00;
            PCsrc_o = 2'b00;
            case(funct3)
                3'b000:
                    begin
                        if({opcode[5], funct7} == {1'b1, 1'b1})
                            ALUctrl_o = 3'b001;
                        else
                            ALUctrl_o = 3'b000;
                    end 
                3'b010: ALUctrl_o = 3'b101;
                3'b110: ALUctrl_o = 3'b011;
                3'b111: ALUctrl_o = 3'b010;
                default: ALUctrl_o = 3'b000;
            endcase
        end
        
    7'b0010011: //Type I (19)
        begin 
            RegWrite_o = 3'b001;
            ImmSrc_o = 3'b000;
            ALUsrc_o = 1'b1;
            MemWrite_o = 2'b00; 
            Resultsrc_o = 2'b00;
            PCsrc_o = 2'b00;

                case(funct3)
                    3'b000:  ALUctrl_o = 3'b000; //addi
                    3'b001:  ALUctrl_o = 3'b101; //slli
                    default: ALUctrl_o = 3'b000;
            endcase
        end

    7'b1100011: //Type B
        begin
            RegWrite_o = 3'b000;
            ImmSrc_o = 3'b010; 
            ALUsrc_o = 1'b0;
            MemWrite_o = 2'b00;
            Resultsrc_o = 2'b01;  //dont care
            ALUctrl_o = 3'b001; //should be 001 - but we dk why it matters

                case(funct3)
                    //func3 shouldnt affect PCsrc?
                    3'b000: PCsrc_o = {1'b0 , Zero_i}; //beq
                    3'b001: PCsrc_o = {1'b0, !Zero_i}; //bne
                    default: PCsrc_o = {1'b0 , Zero_i};
                endcase
        end

    7'b1101111: //Type J - JAL
        begin 
            RegWrite_o = 3'b001;
            ImmSrc_o = 3'b011;
            ALUsrc_o = 1'b1;
            MemWrite_o = 2'b00; 
            Resultsrc_o = 2'b10;
            ALUctrl_o = 3'b000;
            PCsrc_o = 2'b01;
        end

    7'b1100111: //Type I - JALR
        begin 
            RegWrite_o = 3'b000;
            ImmSrc_o = 3'b000;   
            ALUsrc_o = 1'b1; //was blank before - check instr
            MemWrite_o = 2'b00; 
            Resultsrc_o = 2'b10;
            ALUctrl_o = 3'b000; //dont care
            PCsrc_o = 2'b10;
        end

    
    7'b0110111: //lui instr
        begin
            RegWrite_o =3'b001;
            ImmSrc_o = 3'b100;
            ALUsrc_o = 1'b1;
            MemWrite_o = 2'b00;
            Resultsrc_o = 2'b00;
            ALUctrl_o = 3'b111;
            PCsrc_o = 2'b00;
        end

    default: //just in case we have something else
        begin 
            RegWrite_o = 3'b001;
            ImmSrc_o = 3'b000;
            ALUsrc_o = 1'b1;
            MemWrite_o = 2'b00;
            Resultsrc_o = 2'b00;
            ALUctrl_o = 3'b000;
            PCsrc_o = 2'b00;
        end
    endcase 
    
    end

endmodule

