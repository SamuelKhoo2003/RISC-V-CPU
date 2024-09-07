module mux2 #(
    parameter DATA_WIDTH = 32
)(
    input   logic                  control,
    input   logic [DATA_WIDTH-1:0] input0,
    input   logic [DATA_WIDTH-1:0] input1,
    output  logic [DATA_WIDTH-1:0] out
);

assign out = control ? input1 : input0;

endmodule
