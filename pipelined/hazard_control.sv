module hazard_control(
    input  logic [1:0]   PCSrcE,
    output logic         Frst,
    output logic         Drst
);


assign Frst  = (PCSrcE != 2'b0) ? 1 : 0;
assign Drst  = (PCSrcE != 2'b0) ? 1 : 0;

endmodule
