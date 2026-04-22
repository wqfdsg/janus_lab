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

module hazard_unit (
    input  wire [4:0]  id_rs1,
    input  wire [4:0]  id_rs2,
    input  wire [4:0]  ex_mem_rd,
    input  wire        ex_mem_reg_write,
    input  wire        ex_mem_mem_read,
    input  wire        branch_taken,
    input  wire        jump_taken,
    output reg         stall,
    output reg         flush_if_id,
    output reg         flush_id_ex
);
    wire load_use_hazard;

    assign load_use_hazard = ex_mem_mem_read && 
                            ex_mem_reg_write &&
                            (ex_mem_rd == id_rs1 || ex_mem_rd == id_rs2);

    always @(*) begin
        stall = 1'b0;
        flush_if_id = 1'b0;
        flush_id_ex = 1'b0;

        if (load_use_hazard) begin
            stall = 1'b1;
            flush_id_ex = 1'b1;
        end

        if (branch_taken || jump_taken) begin
            flush_if_id = 1'b1;
            flush_id_ex = 1'b1;
        end
    end
endmodule