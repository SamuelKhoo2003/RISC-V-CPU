module green #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH = 32
)(
     input logic [ADDRESS_WIDTH-1:0]     PC, //8b
     input logic                        EQ, //1b
     output logic [DATA_WIDTH-1:0]       instr,//32b
     output logic                        RegWrite, //1b
     output logic [2:0]                  ALUctrl, //3b
     output logic                        ALUsrc, //1 bit
     output logic                        PCsrc, //1 bit
     output logic [DATA_WIDTH-1:0]        ImmOp //32 bits
);

    logic [1:0]                        ImmSrc;

ControlUnit MyControlUnit(
    .EQ(EQ),
    .instr(instr),
    .RegWrite(RegWrite),
    .ALUctrl(ALUctrl),
    .ALUsrc(ALUsrc),
    .ImmSrc(ImmSrc),
    .PCsrc(PCsrc),
);

InstrMem MyInstrMem(
    .addr(PC),
    .dout(instr)
);

SignExtend MySignExtend(
    .instr(instr),
    .ImmSrc(ImmSrc),
    .ImmOp(ImmOp)
);

endmodule 
