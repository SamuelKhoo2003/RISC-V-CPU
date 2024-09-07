module InstrMem #(
    parameter ADDRESS_WIDTH = 8,
    DATA_WIDTH = 8
    
)(
    input logic                     clk,
    input logic [ADDRESS_WIDTH-1:0] addr,
    output logic [31:0]   dout
);

logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

initial begin
        $display("Loading rom.");
        $readmemh("machinecode.mem", rom_array);
end;


assign dout = {{rom_array[addr+3]}, {rom_array[addr+2]}, {rom_array[addr+1]}, {rom_array[addr]}};

endmodule
