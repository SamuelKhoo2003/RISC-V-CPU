module InstrMem #(
    parameter ADDRESS_WIDTH = 8,
    DATA_WIDTH = 32
)(
    input logic [DATA_WIDTH-1:0] addr,

    output logic [DATA_WIDTH-1:0]   dout
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

initial begin
        $display("Loading rom.");
        $readmemh("machinecode.mem", rom_array);
end;

always_comb 
dout = rom_array[{addr/4}];


endmodule
