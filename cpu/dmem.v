/*
 * dmem — Data Memory (RAM)
 *
 * A 4 KB byte-addressable data store implementing the Harvard-architecture data
 * bus. The memory is organised as a 4096-byte array; accesses are qualified by
 * mem_read and mem_write. Writes are synchronous (rising edge); reads are
 * combinational so the MEM stage can return data without an added pipeline
 * bubble. Sub-word granularity is controlled by funct3 (matching the RV32I
 * load/store encoding): 3'b000/3'b100 for byte (signed/unsigned), 3'b001/3'b101
 * for halfword (signed/unsigned), and 3'b010 for word. Unaligned accesses are
 * not supported and produce undefined results. The memory can be pre-loaded via
 * $readmemh for tests that require an initial data image.
 */

`timescale 1ns / 1ps

module dmem (
    input  wire        clk,
    input  wire        we,
    input  wire        re,
    input  wire [31:0] addr,
    input  wire [31:0] data_in,
    input  wire [2:0]  func3,
    output reg  [31:0] data_out
);

reg [7:0] mem_array [0:4095];
wire [11:0] byte_addr = addr[11:0];

initial $readmemh("dmem.hex", mem_array);

always @(posedge clk) begin
    if (we) begin
        case (func3)
            3'b000: mem_array[byte_addr]   <= data_in[7:0];
            3'b001: {mem_array[byte_addr+1], mem_array[byte_addr]} <= data_in[15:0];
            3'b010: {mem_array[byte_addr+3], mem_array[byte_addr+2],
                     mem_array[byte_addr+1], mem_array[byte_addr]} <= data_in;
            default: ; // No write for unsupported func3 values
        endcase
    end
end

always @(*) begin
    if (!re) data_out = 32'b0;
    else case (func3)
        3'b000: data_out = {{24{mem_array[byte_addr][7]}}, mem_array[byte_addr]};
        3'b001: data_out = {{16{mem_array[byte_addr+1][7]}}, mem_array[byte_addr+1], mem_array[byte_addr]};
        3'b010: data_out = {mem_array[byte_addr+3], mem_array[byte_addr+2], mem_array[byte_addr+1], mem_array[byte_addr]};
        3'b100: data_out = {24'b0, mem_array[byte_addr]};
        3'b101: data_out = {16'b0, mem_array[byte_addr+1], mem_array[byte_addr]};
        default: data_out = 32'b0;
    endcase
end

endmodule
