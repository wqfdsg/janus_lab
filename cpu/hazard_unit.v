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
    // From ID/EX register
    input  wire       ex_mem_read,
    input  wire [4:0] ex_rd,
    // From IF/ID register (instruction in ID)
    input  wire [4:0] id_rs1,
    input  wire [4:0] id_rs2,
    // Branch/jump resolution from EX stage
    input  wire       branch_taken,
    input  wire       jump,
    // Outputs
    output wire       pc_stall,
    output wire       if_id_stall,
    output wire       if_id_flush,
    output wire       id_ex_flush
);

    wire load_use_hazard = ex_mem_read &&
                           ((ex_rd == id_rs1) || (ex_rd == id_rs2)) &&
                           (ex_rd != 5'b0);

    wire redirect = branch_taken || jump;

    assign pc_stall    = load_use_hazard;
    assign if_id_stall = load_use_hazard;
    assign if_id_flush = redirect && !load_use_hazard;
    assign id_ex_flush = load_use_hazard || redirect;

endmodule
