/*
    Function: Top file which controls the pipelining registers in datapath.
    Connects different muxes, the register file and the alu altogether.
*/

module datapath #(
    parameter CONTROL_WIDTH = 3,
    parameter DATA_WIDTH = 32 
)(
    input   wire                        clk,
    input   wire                        Den_i,
    input   wire [DATA_WIDTH-1:0]       PCD_i,
    input   wire [4:0]                  Rs1D_i,
    input   wire [4:0]                  Rs2D_i,
    input   wire [4:0]                  RdD_i,
    input   wire [DATA_WIDTH-1:0]       ExtImmD_i,
    input   wire [DATA_WIDTH-1:0]       PCPlus4D_i,
    input   wire [6:0]                  opcodeD_i,
    input   wire [1:0]                  FowardAE_i,
    input   wire [1:0]                  FowardBE_i,
    input   wire                        Drst_i,
    input   wire                        RegWriteW_i, 
    input   wire [1:0]                  MemWriteM_i, 
    input   wire [1:0]                  ResultSrcW_i, 
    input   wire [CONTROL_WIDTH-1:0]    ALUControlE_i, 
    input   wire                        ALUSrcE_i, 
    
    
    output  wire [DATA_WIDTH-1:0]       a0,  //(debug output)
    output  wire [DATA_WIDTH-1:0]       PCTargetE_o,
    output  wire [6:0]                  opcodeE_o,
    output  wire [4:0]                  Rs1E_o,
    output  wire [4:0]                  Rs2E_o,
    output  wire [4:0]                  RdM_o,
    output  wire [4:0]                  RdW_o,
    output  wire [4:0]                  RdE_o,
    output  wire                        ZeroE_o,
    output  wire [DATA_WIDTH-1:0]       ALUResultE_o
);

wire [DATA_WIDTH-1:0]    RD1D;
wire [DATA_WIDTH-1:0]    RD2D;

//Execute Logic
wire [DATA_WIDTH-1:0]    RD1E;
wire [DATA_WIDTH-1:0]    RD2E;
wire [DATA_WIDTH-1:0]    PCE;
wire [DATA_WIDTH-1:0]    PCPlus4E;
wire [DATA_WIDTH-1:0]    SrcAE;
wire [DATA_WIDTH-1:0]    SrcBE;
wire [DATA_WIDTH-1:0]    WriteDataE;
wire [DATA_WIDTH-1:0]    ExtImmE;



//Memory Logic
wire [DATA_WIDTH-1:0]   ALUResultM;
wire [DATA_WIDTH-1:0]   WriteDataM;
wire [DATA_WIDTH-1:0]   PCPlus4M;
wire [DATA_WIDTH-1:0]   ReadDataM;

//Write Logic
wire [DATA_WIDTH-1:0]   PCPlus4W;
wire [DATA_WIDTH-1:0]   ReadDataW;
wire [DATA_WIDTH-1:0]   ALUResultW;
wire [DATA_WIDTH-1:0]   ResultW;



regfile register(
    .clk        (clk),
    .A1_i       (Rs1D_i),
    .A2_i       (Rs2D_i),
    .A3_i       (RdW_o),
    .WE3        (RegWriteW_i),
    .WD3        (ResultW),
    .RD1        (RD1D),
    .RD2        (RD2D),
    .a0         (a0)
);

mux2 ALUMux( // checked - SK 1/12/2023
    .control    (ALUSrcE_i),
    .input0     (WriteDataE),
    .input1     (ExtImmE),
    .out        (SrcBE)
);

alu ALU( // checked - SK 1/12/2023
    .ALUControl (ALUControlE_i),
    .SrcA       (SrcAE),
    .SrcB       (SrcBE),
    .ALUResult  (ALUResultE_o),
    .Zero       (ZeroE_o)
);

data_mem data(
    .clk        (clk),
    .A          (ALUResultM),
    .WD         (WriteDataM),
    .WE         (MemWriteM_i),
    .RD         (ReadDataM)
);

mux3 resultMux(
    .control    (ResultSrcW_i),
    .input0     (ALUResultW),
    .input1     (ReadDataW),
    .input2     (PCPlus4W),
    .out        (ResultW)
);

mux3 RD1EHazardMux(
    .control    (FowardAE_i),
    .input0     (RD1E),
    .input1     (ResultW),
    .input2     (ALUResultM),
    .out        (SrcAE)
);

mux3 RD2EHazardMux(
    .control    (FowardBE_i),
    .input0     (RD2E),
    .input1     (ResultW),
    .input2     (ALUResultM),
    .out        (WriteDataE)
);

adder addPCTargetE(
    .input0 (PCE),
    .input1 (ExtImmE),
    .out    (PCTargetE_o)
);

reg_dec DREg(
    //inputs - D
    .clk        (clk),
    .en         (Den_i),
    .rst        (Drst_i),
    .RD1D       (RD1D),
    .RD2D       (RD2D),
    .PCD        (PCD_i),
    .Rs1D       (Rs1D_i),
    .Rs2D       (Rs2D_i),
    .RdD        (RdD_i),
    .ExtImmD    (ExtImmD_i),
    .PCPlus4D   (PCPlus4D_i),
    .opcodeD    (opcodeD_i),

    //outputs - E
    .RD1E       (RD1E),
    .RD2E       (RD2E),
    .PCE        (PCE),
    .Rs1E       (Rs1E_o),
    .Rs2E       (Rs2E_o),
    .RdE        (RdE_o),
    .ExtImmE    (ExtImmE),
    .PCPlus4E   (PCPlus4E),
    .opcodeE    (opcodeE_o)
);

reg_execute EREG(
    .clk        (clk),

    //inputs E
    .ALUResultE (ALUResultE_o),
    .RdE        (RdE_o),
    .WriteDataE (WriteDataE),
    .PCPlus4E   (PCPlus4E),

    //outputs M
    .ALUResultM (ALUResultM),
    .WriteDataM (WriteDataM),
    .RdM        (RdM_o),
    .PCPlus4M   (PCPlus4M)
);

reg_memory MREG(
    .clk        (clk),

    //input M
    .ALUResultM (ALUResultM),
    .ReadDataM  (ReadDataM),
    .RdM        (RdM_o),
    .PCPlus4M   (PCPlus4M),

    //outputs W
    .ALUResultW (ALUResultW),
    .ReadDataW  (ReadDataW),
    .RdW        (RdW_o),
    .PCPlus4W   (PCPlus4W)
);

endmodule
