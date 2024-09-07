module pc_reg #(
    parameter WIDTH = 8
)(
    input logic clk, 
    input logic rst, 
    input logic [WIDTH-1:0] next_PC,
    output logic [WIDTH-1:0] pc,
    output logic [WIDTH-1:0] another_pc
);

always_ff @ (posedge clk)
begin
    if (rst)
        pc <= {WIDTH{1'b0}};
    else
        pc <= next_PC;

    another_pc <= next_PC;
end

endmodule
