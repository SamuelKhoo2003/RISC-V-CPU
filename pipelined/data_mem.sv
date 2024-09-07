module data_mem #(
    parameter ADDRESS_WIDTH = 8,
    parameter DATA_WIDTH = 32,
                START_ADDRESS = 32'h10000
) (
    input  logic                         clk,
    input  logic [1:0]                   WE,
    input  logic [DATA_WIDTH-1:0]        A,
    input  logic [DATA_WIDTH-1:0]        WD,
    output logic [DATA_WIDTH-1:0]        RD
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
        $readmemh("gaussian.mem", data_mem_register, START_ADDRESS);
     end

    logic [17:0] add =  A[31:0];


    always_ff @(posedge clk) begin
        case(WE) // this could be done cleaner
        2'b01: 
        begin //word write
            data_mem_register[add] <= WD[7:0];
            data_mem_register[add+1] <= WD[15:8];
            data_mem_register[add+2] <= WD[23:16];
            data_mem_register[add+3] <= WD[31:24];
        end
        2'b11:
        begin //write byte
            data_mem_register[A] <=  WD[7:0];
        end
        default: data_mem_register[A] <= data_mem_register[A];
        endcase
        
    end 

    // assign the RD to half the word or resultant data_mem_register
    assign RD = (WE==2'b10) ?  {24'b0, data_mem_register[add]} :{data_mem_register[add+3], data_mem_register[add+2], data_mem_register[add+1], data_mem_register[add]}; //we read and output the [A] register value

endmodule
