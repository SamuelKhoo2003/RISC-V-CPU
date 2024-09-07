/*
    Function: Adding unit that adds the value of 2 inputs together and returns the result
*/

module adder #(
    parameter DATA_WIDTH = 32
)(
    input   logic [DATA_WIDTH-1:0]    input0,
    input   logic [DATA_WIDTH-1:0]    input1,
    output  logic [DATA_WIDTH-1:0]    out
);

assign out = input0 + input1;

endmodule
