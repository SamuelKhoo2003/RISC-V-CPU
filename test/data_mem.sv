module data_mem #(
    parameter ADDRESS_WIDTH = 8,
    parameter DATA_WIDTH = 32,
                START_ADDRESS = 32'h10000
) (
    input  logic                         clk,
    input  logic [1:0]                   WE_i,
    input  logic [DATA_WIDTH-1:0]        A_i,
    input  logic [DATA_WIDTH-1:0]        WD_i,
    output logic [DATA_WIDTH-1:0]        RD_o
);

    /*
    WE:
        00 - dont write
        01 - write all word (32 bits)
        10 - write half word (16 bits)
        11 - write last byte (8 bits)
    */   

    logic [ADDRESS_WIDTH-1:0]  data_mem_register [2**17:0]; //we set our reg file which will be filled with initial values

    initial begin
        $display("Loading ROM");
        $readmemh("sine.mem", data_mem_register, START_ADDRESS);
     end

    logic [17:0]    add = A_i[31:0];
    logic [15:0]    data16 = WD_i[15:0];
    logic [7:0]     data8 = WD_i[7:0];

    always_ff @(posedge clk) begin
        case(WE_i) // this could be done cleaner
        2'b01: 
        begin //word write
            data_mem_register[add] <= WD_i[7:0];
            data_mem_register[add+1] <= WD_i[15:8];
            data_mem_register[add+2] <= WD_i[23:16];
            data_mem_register[add+3] <= WD_i[31:24];
        end
        2'b10: 
        begin //half word 
            data_mem_register[add] <= data16[7:0];
            data_mem_register[add+1] <= data16[15:8];
        end
        2'b11:
        begin //write byte
            data_mem_register[A_i] <=  WD_i[7:0];
        end
        endcase
    end 

    assign RD_o = {data_mem_register[add+3], data_mem_register[add+2], data_mem_register[add+1], data_mem_register[add]}; //we read and output the [A] register value

endmodule
