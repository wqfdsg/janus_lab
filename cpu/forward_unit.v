/*
 * forward_unit — Operand Forwarding Unit
 *
 * Eliminates RAW data hazards that can be resolved by forwarding without a
 * stall. When a register value produced by an instruction in EX/MEM or MEM/WB
 * is needed by the instruction currently in EX, this unit selects the most
 * recent in-flight value rather than the (potentially stale) value read from the
 * register file in the ID stage. Two 2-bit mux-select outputs are produced:
 * forward_a controls the ALU's first operand source and forward_b controls the
 * second. Encoding: 2'b00 = register file (no hazard), 2'b01 = MEM/WB result,
 * 2'b10 = EX/MEM result. EX/MEM forwarding takes priority over MEM/WB
 * forwarding when both conditions hold, ensuring the most recent write wins.
 */

module forward_unit (
    input  wire [4:0] ex_rs1,
    input  wire [4:0] ex_rs2,
    // EX/MEM stage
    input  wire       mem_reg_write,
    input  wire [4:0] mem_rd,
    // MEM/WB stage
    input  wire       wb_reg_write,
    input  wire [4:0] wb_rd,
    // Forwarding select signals
    output reg  [1:0] forward_a,
    output reg  [1:0] forward_b
);

    always @(*) begin
        // Forward A
        if (mem_reg_write && (mem_rd != 5'b0) && (mem_rd == ex_rs1))
            forward_a = 2'b10; // EX/MEM forwarding
        else if (wb_reg_write && (wb_rd != 5'b0) && (wb_rd == ex_rs1))
            forward_a = 2'b01; // MEM/WB forwarding
        else
            forward_a = 2'b00; // no forwarding

        // Forward B
        if (mem_reg_write && (mem_rd != 5'b0) && (mem_rd == ex_rs2))
            forward_b = 2'b10;
        else if (wb_reg_write && (wb_rd != 5'b0) && (wb_rd == ex_rs2))
            forward_b = 2'b01;
        else
            forward_b = 2'b00;
    end

endmodule
