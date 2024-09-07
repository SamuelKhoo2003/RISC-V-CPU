module instr_mem #(
    parameter ADDRESS_WIDTH = 8,
    parameter DATA_WIDTH = 32
    
)(
    //input   logic                       clk, //idk this is on the diagram before the instruction memory block
    input   logic [DATA_WIDTH-1:0]   addr_i,
    output  logic [DATA_WIDTH-1:0]      Instr_o
);

logic [ADDRESS_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

initial begin
        $display("Loading rom.");
        $readmemh("f1.mem", rom_array);
end;



assign Instr_o = {{rom_array[addr_i+3]}, {rom_array[addr_i+2]}, {rom_array[addr_i+1]}, {rom_array[addr_i]}};

endmodule
