/*
    Function: Top level file linking the pc, the control unit, data path and hazard handling unit altogether
*/

module cpu #(
    parameter   ADDRESS_WIDTH = 8,
    parameter   DATA_WIDTH = 32,
    parameter   CONTROL_WIDTH = 3,
    parameter   IMM_WIDTH = 2

)(

    input logic                        clk,
    input logic                        rst, //do we need this?
    output logic [DATA_WIDTH-1:0]      a0

);

    //output internal logic for control module 
    logic                           RegWriteW;
    logic                           RegWriteM;
    logic [1:0]                     MemWriteM;
    logic [1:0]                     ResultSrcW;
    logic [2:0]                     ALUControlE;
    logic                           ALUSrcE;
    logic [DATA_WIDTH-1:0]          InstrD;
    logic [DATA_WIDTH-1:0]          ExtImmD;
    logic [DATA_WIDTH-1:0]          PCD;
    logic [DATA_WIDTH-1:0]          PCPlus4D;
    logic [2:0]                     ImmSrcE;


    //output internal logic for alu module 
    logic [DATA_WIDTH-1:0]     ALUResultE;
    logic [DATA_WIDTH-1:0]     PCTarget;
    logic [1:0]                PCSrcE;
    logic [4:0]                Rs1E; 
    logic [4:0]                Rs2E;
    logic [4:0]                RdM;
    logic [4:0]                RdW;
    logic [4:0]                RdE;
    logic [6:0]                OpcodeE;
    logic                      ZeroE;
    

    //output internal logic for pc module
    logic [DATA_WIDTH-1:0]      PCF;
    logic [DATA_WIDTH-1:0]      PCPlus4F;
    

    //output internal logic for hazard module
    logic                       Den;
    logic                       Fen;
    logic                       PCen;
    logic [1:0]                 FowardAE;
    logic [1:0]                 FowardBE;
    logic                       PCrst;
    logic                       Frst;
    logic                       Drst;

pc_top pc(
    .clk            (clk),
    .PCen_i         (PCen),  
    .PCrst_i        (PCrst),        
    .ALUResultE_i   (ALUResultE), //result from data mem to mux4    
    .PCSrc_i        (PCSrcE),
    .PCF_o          (PCF), //32b
    .PCPlus4F_o     (PCPlus4F), //unsure
    .PCTarget_i     (PCTarget)
);

control_top control(
    .clk            (clk),
    .PCF_i          (PCF), //32b
    .PCPlus4F_i     (PCPlus4F),
    .ImmSrcE_o      (ImmSrcE),
    .InstrD_o       (InstrD),//32b
    .RegWriteW_o    (RegWriteW),
    .RegWriteM_o    (RegWriteM), //1b  ==> edited to 3 bits
    .MemWriteM_o    (MemWriteM), //1b ==> edited to 2 bits
    .ResultSrcW_o   (ResultSrcW), //3b ==> edited to 2 bits
    .ALUControlE_o  (ALUControlE), //3b
    .ALUSrcE_o      (ALUSrcE), //1 bit
    .ExtImmD_o      (ExtImmD), //32 bits
    .PCD_o          (PCD),
    .PCPlus4D_o     (PCPlus4D),
    .Fen_i          (Fen),
    .Frst_i         (Frst),
    .Den_i          (Den),
    .Drst_i         (Drst),
    .ZeroE_i        (ZeroE),
    .PCSrcE_o       (PCSrcE)
);


datapath data(
    .clk            (clk),
    .Den_i          (Den),
    .Drst_i         (Drst),
    .ALUSrcE_i      (ALUSrcE),
    .ALUControlE_i  (ALUControlE),
    .RegWriteW_i    (RegWriteW),
    .ResultSrcW_i   (ResultSrcW),
    .MemWriteM_i    (MemWriteM),
    .ExtImmD_i      (ExtImmD),
    .opcodeD_i      (InstrD[6:0]),
    .a0             (a0), //(debug output)
    .ALUResultE_o   (ALUResultE),
    .PCD_i          (PCD),
    .PCPlus4D_i     (PCPlus4D),
    .Rs1D_i         (InstrD[19:15]),
    .Rs2D_i         (InstrD[24:20]),
    .RdD_i          (InstrD[11:7]),  // on diagram this comes from RdW not Instr 
    .FowardAE_i     (FowardAE),
    .FowardBE_i     (FowardBE),
    
    .PCTargetE_o    (PCTarget),
    .opcodeE_o      (OpcodeE),
    .Rs1E_o         (Rs1E),   
    .Rs2E_o         (Rs2E),
    .RdM_o          (RdM),
    .RdW_o          (RdW),
    .RdE_o          (RdE),
    .ZeroE_o        (ZeroE)
    
);  

hazard_unit hazard(
    .Rs1E_i         (Rs1E),
    .Rs2E_i         (Rs2E),
    .Rs1D_i         (InstrD[19:15]),
    .Rs2D_i         (InstrD[24:20]),
    .RdM_i          (RdM),
    .RdW_i          (RdW),
    .RdE_i          (RdE),
    .RegWriteM_i    (RegWriteM),
    .RegWriteW_i    (RegWriteW),
    .opcodeE_i      (OpcodeE),
    .PCSrcE_i       (PCSrcE),
    .ImmSrcE_i      (ImmSrcE),
    .FowardAE_o     (FowardAE),
    .FowardBE_o     (FowardBE),
    .Den_o          (Den),
    .Fen_o          (Fen),
    .PCen_o         (PCen),
    .PCrst_o        (PCrst),
    .Frst_o         (Frst),
    .Drst_o         (Drst)
);

endmodule

