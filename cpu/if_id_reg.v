/*
 * if_id_reg — IF/ID Pipeline Register
 *
 * Latches the outputs of the Instruction Fetch stage (PC and fetched
 * instruction word) and presents them to the Instruction Decode stage on the
 * following clock cycle. Two control inputs allow the hazard unit to manage
 * control flow: stall holds both fields frozen for one cycle (used during a
 * load-use hazard), and flush zeroes both fields to inject a NOP bubble (used
 * when a taken branch or jump requires squashing the speculatively fetched
 * instruction). Stall takes priority over flush when both are asserted
 * simultaneously.
 */

`timescale 1ns / 1ps

module if_id_reg (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        stall,
    input  wire        flush,
    input  wire [31:0] pc_in,
    input  wire [31:0] pc_plus4_in,
    input  wire [31:0] instr_in,
    
    output reg  [31:0] pc_out,
    output reg  [31:0] pc_plus4_out,
    output reg  [31:0] instr_out
);

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pc_out <= 32'b0;
        pc_plus4_out <= 32'b0;
        instr_out <= 32'b0;
    end
    else if (stall) begin
        pc_out <= pc_out;
        pc_plus4_out <= pc_plus4_out;
        instr_out <= instr_out;
    end
    else if (flush) begin
        pc_out <= 32'b0;
        pc_plus4_out <= 32'b0;
        instr_out <= 32'b0;
    end
    else begin
        pc_out <= pc_in;
        pc_plus4_out <= pc_plus4_in;
        instr_out <= instr_in;
    end
end

endmodule
