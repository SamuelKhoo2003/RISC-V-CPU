/*
	Function: Instruction Memory
*/

module imem #(
    parameter DATA_WIDTH = 32,
    parameter ADDRESS_WIDTH = 8
) (
    input   logic [DATA_WIDTH-1:0]  a,
    output  logic [DATA_WIDTH-1:0]  rd
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

initial begin
    $readmemh("pdf.mem", ram_array);
end

assign rd = {{ram_array[a+3]}, {ram_array[a+2]}, {ram_array[a+1]}, {ram_array[a]}};

endmodule
