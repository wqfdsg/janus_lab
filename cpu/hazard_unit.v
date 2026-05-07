/*
 * hazard_unit — Pipeline Hazard Detection and Control
 *
 * Detects the two hazard classes that require structural intervention in the
 * pipeline and generates the stall and flush signals that resolve them.
 *
 * Load-use hazard: when the instruction in EX is a load (ex_mem_read asserted)
 * and its destination register matches either source register of the instruction
 * currently in ID, the result cannot be forwarded in time. The unit asserts
 * pc_stall and if_id_stall to freeze the fetch and decode stages for one cycle,
 * and asserts id_ex_flush to inject a NOP bubble into EX so the load can
 * complete before the dependent instruction re-enters EX.
 *
 * Control hazard: when the instruction in EX resolves a taken branch or an
 * unconditional jump, the two instructions already fetched speculatively must be
 * squashed. The unit asserts if_id_flush and id_ex_flush to zero out both
 * pipeline registers, redirecting the pipeline to the correct target PC.
 */

`timescale 1ns / 1ps

module hazard_unit (
    input  wire [4:0]  id_rs1,
    input  wire [4:0]  id_rs2,
    input  wire [4:0]  id_ex_rd,
    input  wire        id_ex_mem_read,
    input  wire        branch_taken,
    input  wire        jump_taken,
    output reg         pc_stall,
    output reg         if_id_stall,
    output reg         if_id_flush,
    output reg         id_ex_flush
);

wire load_use_hazard;

assign load_use_hazard = id_ex_mem_read && 
                        (id_ex_rd == id_rs1 || id_ex_rd == id_rs2) &&
                        (id_ex_rd != 5'b0);

always @(*) begin
    pc_stall     = 1'b0;
    if_id_stall  = 1'b0;
    if_id_flush  = 1'b0;
    id_ex_flush  = 1'b0;

    if (load_use_hazard) begin
        pc_stall    = 1'b1;
        if_id_stall = 1'b1;
        id_ex_flush = 1'b1;
    end

    if (branch_taken || jump_taken) begin
        if_id_flush = 1'b1;
        id_ex_flush = 1'b1;
    end
end

endmodule
