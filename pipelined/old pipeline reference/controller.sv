/*
	Function: 5 stage pipelined Control Unit
*/

module controller #(
    parameter OP_WIDTH = 7
) (
    input   logic                   clk,
    input   logic                   reset,

    input   logic [OP_WIDTH-1:0]    op,
    input   logic [2:0]             funct3,
    input   logic                   funct7b5,
    input   logic                   ZeroE,
    input   logic                   FlushE,

    output logic                    ResultSrcE0,
    output  logic [1:0]             ResultSrcW,
    output  logic                   MemWriteM,
    output  logic                   PCSrcE,
    output  logic                   PCJalSrcE,
    output  logic                   ALUSrcE,
    output  logic                   RegWriteW,
    output  logic                   RegWriteM, 
    output  logic [2:0]             ImmSrcD,
    output  logic [2:0]             ALUControlE
);

logic [1:0] ALUOpD;
logic [1:0] ResultSrcD, ResultSrcE, ResultSrcM;
logic [2:0] ALUControlD;
logic BranchD, BranchE, MemWriteD, MemWriteE, JumpD, JumpE;
logic ZeroOp, ALUSrcD, RegWriteD, RegWriteE;

// main decoder 
maindecoder maindec(
    .op (op),
    .ResultSrc (ResultSrcD),
    .MemWrite (MemWriteD),
    .Branch (BranchD),
    .ALUSrc (ALUSrcD),
    .RegWrite (RegWriteD),
    .Jump (JumpD),
    .ALUOp (ALUOpD), 
    .ImmSrc (ImmSrcD),
    .funct3 (funct3)
);

// alu decoder
aludecoder aludec(
    .funct3 (funct3),
    .funct7b5 (funct7b5),
    .opb5 (op[5]),
    .ALUOp (ALUOpD),
    .ALUControl (ALUControlD)
);

// control unit pipeline reg 1 decode -> execute
control_Dec_Exc c_D_E(
    .clk (clk),
    .reset (reset), 
    .clear (FlushE),
    .RegWriteD (RegWriteD),
    .MemWriteD (MemWriteD),
    .JumpD (JumpD),
    .BranchD (BranchD),
    .ALUSrcD (ALUSrcD),
    .ResultSrcD (ResultSrcD),
    .ALUControlD (ALUControlD),
    .RegWriteE (RegWriteE),
    .MemWriteE (MemWriteE),
    .JumpE (JumpE), 
    .BranchE (BranchE),
    .ALUSrcE (ALUSrcE),
    .ResultSrcE (ResultSrcE),
    .ALUControlE (ALUControlE)
);

assign ResultSrcE0 = ResultSrcE[0];

// control unit pipeline reg 2 execute -> memory
control_Exc_Mem c_E_M(
    .clk (clk),
    .reset (reset),
    .RegWriteE (RegWriteE),
    .ResultSrcE (ResultSrcE),
    .MemWriteE (MemWriteE),
    .RegWriteM (RegWriteM),
    .ResultSrcM (ResultSrcM), 
    .MemWriteM (MemWriteM)
);

// control unit pipeline reg 3 memory -> write
control_Mem_Wrt c_M_W(
    .clk (clk),
    .reset (reset),
    .RegWriteM (RegWriteM),
    .ResultSrcM (ResultSrcM),
    .RegWriteW (RegWriteW),
    .ResultSrcW(ResultSrcW)
);

assign ZeroOp = ZeroE ^ funct3[0]; // Complements Zero flag for BNE Instruction
assign PCSrcE = (BranchE & ZeroOp) | JumpE;
assign PCJalSrcE = (op == 7'b1100111) ? 1 : 0; // jalr

endmodule
