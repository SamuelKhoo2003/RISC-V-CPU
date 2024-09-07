module flopenr #(
    parameter DATA_WIDTH = 32
) (
    input   logic                   clk,
    input   logic                   reset,
    input   logic                   en,
    input   logic [DATA_WIDTH-1:0]  d,
    output   logic [DATA_WIDTH-1:0]  q
);   

always_ff @(posedge clk, posedge reset) begin
    if (reset) q <= 0;
    else if (en) q <= d; 
end

endmodule
