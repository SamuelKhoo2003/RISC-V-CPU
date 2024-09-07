module regfile #(
    parameter ADDRESS_WIDTH = 5,
    parameter DATA_WIDTH = 32
)(
    input   logic                   clk,
    input   logic [2:0]             WE3,
    input   logic [DATA_WIDTH-1:0]  WD3,
    input   logic [4:0]             A1_i,
    input   logic [4:0]             A2_i,
    input   logic [4:0]             A3_i,
    output  logic [DATA_WIDTH-1:0]  RD1D,
    output  logic [DATA_WIDTH-1:0]  RD2D,
    output  logic [DATA_WIDTH-1:0]  a0  //(debug output)
);

logic [DATA_WIDTH-1:0] reg_array [2**ADDRESS_WIDTH-1:0];


// making sure that all A1, A2, and A3 are 8 bits long
logic [4:0] A1 = {3'b0 , A1_i}; 
logic [4:0] A2 = {3'b0 , A2_i};
logic [4:0] A3 = {3'b0 , A3_i};

always @(negedge clk)
    case (WE3)
    3'b001: begin
        reg_array[A3] <= WD3;
    end
    3'b010: begin //lh -sign extended
        reg_array[A3] <= {{16{WD3[15]}}, WD3[15:0]};
    end
    3'b011: begin //lb - sign extended
        reg_array[A3] <= {{24{WD3[7]}}, WD3[7:0]};
    end
    3'b111: begin  //lbu - zero extended
        reg_array[A3] <= {{24'b0}, WD3[7:0]};
    end 
    3'b110: begin  //lhu - zero extended
        reg_array[A3] <= {16'b0, WD3[15:0]};
    end
    default: reg_array[A3] <= reg_array[A3];
        
    endcase

assign RD1D = reg_array[A1];
assign RD2D = reg_array[A2];

endmodule
