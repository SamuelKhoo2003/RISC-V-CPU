module data_mem #(
    parameter ADDRESS_WIDTH = 8,
    parameter DATA_WIDTH = 32
) (
    input  logic                             clk,
    input  logic                             WE,
    input  logic     [DATA_WIDTH-1:0]        A,
    input  logic     [DATA_WIDTH-1:0]        WD,
    output logic     [DATA_WIDTH-1:0]        RD
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

assign RD = ram_array[A[DATA_WIDTH-1:0]];

always_ff @(posedge clk) begin
    if (WE) ram_array[A[DATA_WIDTH-1:0]] <= WD;
end

endmodule
