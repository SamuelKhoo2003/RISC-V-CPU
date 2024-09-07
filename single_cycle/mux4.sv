module mux4 #(
    parameter DATA_WIDTH = 32,
    parameter CONTROL_WIDTH = 2
)(
    input   logic [CONTROL_WIDTH-1:0]   control,
    input   logic [DATA_WIDTH-1:0]      input0,
    input   logic [DATA_WIDTH-1:0]      input1,
    input   logic [DATA_WIDTH-1:0]      input2,
    input   logic [DATA_WIDTH-1:0]      input3,
    output  logic [DATA_WIDTH-1:0]      out
);

always_comb begin
    case (control)
    2'b00: out = input0;
    2'b01: out = input1
    2'b10: out = input2;
    2'b11: out = input3;
    endcase 
end 

endmodule
