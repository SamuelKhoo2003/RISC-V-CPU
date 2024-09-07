module hazardunit(
    input   logic [4:0]   Rs1D, 
    input   logic         Rs2D, 
    input   logic         Rs1E, 
    input   logic         Rs2E,
    input   logic [4:0]   RdE, 
    input   logic         RdM, 
    input   logic         RdW,
    input   logic         RegWriteM, 
    input   logic         RegWriteW,
	input   logic         ResultSrcE0, 
    input   logic         PCSrcE,
    output  logic [1:0]   ForwardAE, 
    output  logic         ForwardBE,
    output  logic         StallD, 
    output  logic         StallF, 
    output  logic         FlushD, 
    output  logic         FlushE
);
					 
logic lwStall;

always_comb begin
    ForwardAE = 2'b00;
    ForwardBE = 2'b00;
    
    if ((Rs1E == RdM) & (RegWriteM) & (Rs1E != 0)) 
        ForwardAE = 2'b10; 
    else if ((Rs1E == RdW) & (RegWriteW) & (Rs1E != 0))
        ForwardAE = 2'b01; 


    if ((Rs2E == RdM) & (RegWriteM) & (Rs2E != 0))
        ForwardBE = 2'b10; 
    else if ((Rs2E == RdW) & (RegWriteW) & (Rs2E != 0))
        ForwardBE = 2'b01; 
    
    end

assign lwStall = (ResultSrcE0 == 1) & ((RdE == Rs1D) | (RdE == Rs2D));

assign StallF = lwStall;
assign StallD = lwStall;

assign FlushE = lwStall | PCSrcE;
assign FlushD = PCSrcE;

endmodule



    
