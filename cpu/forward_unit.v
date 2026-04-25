/*
 * forward_unit — Operand Forwarding Unit
 *
 * Eliminates RAW data hazards that can be resolved by forwarding without a
 * stall. When a register value produced by an instruction in EX/MEM or MEM/WB
 * is needed by the instruction currently in EX, this unit selects the most
 * recent in-flight value rather than the (potentially stale) value read from the
 * register file in ID stage. Two 2-bit mux-select outputs: forward_a controls
 * ALU operand A, forward_b controls operand B. Encoding: 2'b00 = register file,
 * 2'b01 = MEM/WB result, 2'b10 = EX/MEM result. EX/MEM has higher priority.
 */

module forward_unit (
    input  wire [4:0]  ex_rs1,
    input  wire [4:0]  ex_rs2,
    input  wire [4:0]  ex_mem_rd,
    input  wire [4:0]  mem_wb_rd,
    input  wire        ex_mem_reg_write,
    input  wire        mem_wb_reg_write,
    output reg  [1:0]  forward_a,
    output reg  [1:0]  forward_b
);

always @(*) begin
    forward_a = 2'b00;
    forward_b = 2'b00;

    // Forward A
    if (ex_mem_reg_write && ex_mem_rd != 5'd0 && ex_mem_rd == ex_rs1)
        forward_a = 2'b10;
    else if (mem_wb_reg_write && mem_wb_rd != 5'd0 && mem_wb_rd == ex_rs1)
        forward_a = 2'b01;

    // Forward B
    if (ex_mem_reg_write && ex_mem_rd != 5'd0 && ex_mem_rd == ex_rs2)
        forward_b = 2'b10;
    else if (mem_wb_reg_write && mem_wb_rd != 5'd0 && mem_wb_rd == ex_rs2)
        forward_b = 2'b01;
end

endmodule