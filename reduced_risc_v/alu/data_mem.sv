module data_mem #(
    parameter ADDRESS_WIDTH = 32,
    parameter DATA_WIDTH = 32
) (
    input  logic                             clk,
    input  logic                             WE,
    input  logic     [ADDRESS_WIDTH-1:0]     A,
    input  logic     [DATA_WIDTH-1:0]        WD,
    output logic     [DATA_WIDTH-1:0]        RD
);
    logic [DATA_WIDTH-1:0]  data_mem_register [2**ADDRESS_WIDTH-1:0] //we set our reg file which will be filled with initial values

    initial begin
        // still missing initial info to write into data mem register
    end
    
    always_ff @(posedge clk) begin
        if (WE == 1'b1) // if write enable is high, we input new data into the [A] register
            data_mem_register[A] <= WD;
    end

    assign RD = data_mem_register[A]; //we read and output the [A] register value


endmodule