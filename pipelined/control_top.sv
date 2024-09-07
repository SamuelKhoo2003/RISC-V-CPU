/*
    Function: Top file which manages the control unit pipelining registers.
    Connects components like the sign extend and instruction memory module.
*/

module control_top #(
        parameter   ADDRESS_WIDTH = 8,
        parameter   DATA_WIDTH = 32
)(
    input  logic                           clk,
    input  logic                           Fen_i,
    input  logic                           Frst_i,
    input  logic                           Den_i,
    input  logic                           Drst_i,
    input  logic [DATA_WIDTH-1:0]          PCF_i, //8b ==> edited to 32 bits
    input  logic [DATA_WIDTH-1:0]          PCPlus4F_i, 
    input  logic                           ZeroE_i,
    output logic [DATA_WIDTH-1:0]          InstrD_o,//32b
    output logic                           RegWriteW_o, //1b ==> edited to 3 bits
    output logic                           RegWriteM_o,
    output logic [1:0]                     MemWriteM_o, //1b ==> edited to 2 bits
    output logic [1:0]                     ResultSrcW_o, //3b ==> edited to 2 bits
    output logic [2:0]                     ALUControlE_o, //3b
    output logic                           ALUSrcE_o, //1 bit
    output logic [DATA_WIDTH-1:0]          ExtImmD_o,//32 bits
    output logic [DATA_WIDTH-1:0]          PCD_o,
    output logic [DATA_WIDTH-1:0]          PCPlus4D_o,
    output logic [1:0]                     PCSrcE_o,
    output logic [2:0]                     ImmSrcE_o
);

    logic [2:0]       ImmSrcD;
    logic [31:0]      InstrF;
    logic             ZeroOp;


    wire [1:0]              ResultSrcD;
    wire [1:0]              MemWriteD;
    wire [2:0]              ALUControlD;
    wire                    ALUSrcD;
    wire                    JumpD;
    wire                    BranchD;
    wire                    RegWriteD;

    //Execute Logic
    wire                    RegWriteE;
    wire [1:0]              ResultSrcE;
    wire [1:0]              MemWriteE;
    wire                    JumpE;
    wire                    BranchE;
    wire [2:0]              funct3E;

    //Memory Logic
    
    wire [1:0]              ResultSrcM;



instr_mem InstrMem(
    .addr_i         (PCF_i),
    .Instr_o        (InstrF)
);

control_unit ControlUnit(
    .op            (InstrD_o[6:0]),
    .funct3        (InstrD_o[14:12]),
    .funct7b5      (InstrD_o[30]),
    .RegWriteD     (RegWriteD),
    .MemWriteD     (MemWriteD),
    .ResultSrcD    (ResultSrcD),
    .ALUControlD   (ALUControlD),
    .ALUSrcD       (ALUSrcD),
    .ImmSrcD       (ImmSrcD),
    .JumpD         (JumpD),
    .BranchD       (BranchD)
);

reg_fetch FReg(
    .clk        (clk),
    .en         (Fen_i),
    .rst        (Frst_i),
    .InstrF     (InstrF),
    .PCPlus4F   (PCPlus4F_i),
    .PCF        (PCF_i),
    .PCPlus4D   (PCPlus4D_o),
    .PCD        (PCD_o),
    .InstrD     (InstrD_o)
);

sign_extend MySignExtend(
    .instr        (InstrD_o[31:0]),
    .ImmSrc       (ImmSrcD),
    .ExtImm       (ExtImmD_o)
);

reg_dec_control DReg(
    //inputs - D
    .clk(clk),
    .en(Den_i),
    .rst(Drst_i),
    .RegWriteD(RegWriteD),
    .ResultSrcD(ResultSrcD),
    .MemWriteD(MemWriteD),
    .JumpD(JumpD),
    .BranchD(BranchD),
    .ALUControlD(ALUControlD),
    .ALUSrcD(ALUSrcD),
    .funct3D(InstrD_o[14:12]),
    .ImmSrcD(ImmSrcD), 

    //outputs - E
    .RegWriteE(RegWriteE),
    .ResultSrcE(ResultSrcE),
    .MemWriteE(MemWriteE),
    .JumpE(JumpE),
    .BranchE(BranchE),
    .ALUControlE(ALUControlE_o),
    .ALUSrcE(ALUSrcE_o),
    .funct3E(funct3E),
    .ImmSrcE(ImmSrcE_o)

);

reg_execute_control EREG(
    .clk(clk),
    //inputs E
    .RegWriteE(RegWriteE),
    .ResultSrcE(ResultSrcE),
    .MemWriteE(MemWriteE),

    //outputs M
    .RegWriteM(RegWriteM_o),    
    .ResultSrcM(ResultSrcM),
    .MemWriteM(MemWriteM_o)
);

reg_memory_control MREG(
    //input M
    .clk(clk),
    .RegWriteM(RegWriteM_o),    
    .ResultSrcM(ResultSrcM),

    //outputs W
    .RegWriteW(RegWriteW_o), 
    .ResultSrcW(ResultSrcW_o)
);

assign ZeroOp = ZeroE_i ^ funct3E[0]; // flip the Zero input if BNE

always_comb
    if (JumpE)      PCSrcE_o = ALUSrcE_o ? 2'b10: 2'b01 ; //choose between JAL and JALR without extra logic
    else PCSrcE_o = (BranchE & ZeroOp) ? 2'b01 : 2'b00;


endmodule

