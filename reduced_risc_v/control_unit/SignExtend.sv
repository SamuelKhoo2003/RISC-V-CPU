module SignExtend #(
    parameter DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0]        instr,
    input logic [1:0]                   ImmSrc,
    output logic [DATA_WIDTH-1:0]        ImmOp
);

always_comb 
    case (ImmSrc)
    2'b01: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[31:20]}; //I instruction
                    //20                        1           6              4        1      = 32 bits          
    2'b11: ImmOp = {{DATA_WIDTH-12{instr[31]}}, instr[7], instr[30:25], instr[11:8], 1'b0}; //B instructions

    default ImmOp = 32'b0;
    
    endcase 
endmodule
