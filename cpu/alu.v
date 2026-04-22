/*
 * alu — Arithmetic and Logic Unit
 *
 * Performs all integer computations required by the RV32I ISA. The 4-bit
 * alu_ctrl input selects the operation; encoding is defined by alu_ctrl.v and
 * follows the standard Patterson & Hennessy convention extended for RISC-V.
 * Supported operations: ADD, SUB, AND, OR, XOR, SLL (logical left shift),
 * SRL (logical right shift), SRA (arithmetic right shift), SLT (signed
 * less-than), SLTU (unsigned less-than), and PASS_B (passes operand B
 * unchanged, used by LUI via AUIPC-style datapath). The zero output is asserted
 * when result equals zero and is consumed by the branch_unit to evaluate
 * branch conditions. All logic is combinational with no internal state.
 */

module alu (
    input  wire [31:0] a,
    input  wire [31:0] b,
    input  wire [3:0]  op,
    output reg  [31:0] result,
    output wire        zero,
    output wire        lt,
    output wire        ltu
);
    assign zero = (result == 32'b0);
    assign lt = ($signed(a) < $signed(b));
    assign ltu = (a < b);

    always @(*) begin
        case (op)
            4'b0000: result = a + b;        // ADD
            4'b0001: result = a - b;        // SUB
            4'b0010: result = a & b;        // AND
            4'b0011: result = a | b;        // OR
            4'b0100: result = a ^ b;        // XOR
            4'b0101: result = a << b[4:0]; // SLL
            4'b0110: result = a >> b[4:0]; // SRL
            4'b0111: result = $signed(a) >>> b[4:0]; // SRA
            4'b1000: result = ($signed(a) < $signed(b)) ? 32'b1 : 32'b0; // SLT
            4'b1001: result = (a < b) ? 32'b1 : 32'b0; // SLTU
            4'b1010: result = b; // pass-through (LUI)
            default: result = 32'b0;
        endcase
    end
endmodule
