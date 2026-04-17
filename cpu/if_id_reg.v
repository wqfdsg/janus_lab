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

module if_id_reg (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        stall,
    input  wire        flush,
    input  wire [31:0] if_pc,
    input  wire [31:0] if_instr,
    output reg  [31:0] id_pc,
    output reg  [31:0] id_instr
);

    always @(posedge clk) begin
        if (!rst_n || flush) begin
            id_pc    <= 32'b0;
            id_instr <= 32'b0; // NOP (ADDI x0, x0, 0)
        end else if (!stall) begin
            id_pc    <= if_pc;
            id_instr <= if_instr;
        end
    end

endmodule
