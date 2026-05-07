/*
 * pc_reg — Program Counter Register
 *
 * Holds the address of the instruction currently being fetched. On every
 * rising clock edge the PC advances to next_pc, which is supplied by the
 * surrounding datapath (PC+4 in the normal case, a branch/jump target
 * otherwise). Active-low synchronous reset drives the PC to 0x00000000.
 * The hazard unit may assert stall to freeze the PC for one cycle during a
 * load-use hazard, preventing the fetch stage from moving forward.
 */

`timescale 1ns / 1ps

module pc_reg (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        stall,
    input  wire [31:0] next_pc,
    output reg  [31:0] pc
);

always @(posedge clk or negedge rst_n) begin
    if (!rst_n)
        pc <= 32'h00000000;
    else if (!stall)
        pc <= next_pc;
end

endmodule
