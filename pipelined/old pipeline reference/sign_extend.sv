/*
Function: This unit is used for extend the immediation for use in immediate-type instructions
*/

module sign_extend #(
    parameter DATA_WIDTH = 32,
    parameter IMM_WIDTH = 3
)(
    input   logic [DATA_WIDTH-1:0]        instr,
    input   logic [IMM_WIDTH-1:0]         ImmSrc,
    output  logic [DATA_WIDTH-1:0]        ExtImm
);

always_comb begin
    case (ImmSrc) //20                12              = 32 bits
    3'b000: ExtImm = {{20{instr[31]}}, instr[31:20]}; //I Type
                    //20                 7              5             = 32 bits
    3'b001: ExtImm = {{20{instr[31]}}, instr[31:25], instr[11:7]}; //S Type
                    //20                        1           6              4        1      = 32 bits          
    3'b010: ExtImm = {{DATA_WIDTH-12{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0}; //B Type
                    //12                        8           1           10          1       = 32 bits
    3'b011: ExtImm = {{DATA_WIDTH-20{instr[31]}}, instr[19:12], instr[20], instr[30:21], 1'b0};//J Type 
    
    3'b100: ExtImm = {instr[31:12], 12'b0}; // U type
    endcase 
end

endmodule

