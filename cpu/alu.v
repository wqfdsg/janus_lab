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

`timescale 1ns / 1ps

module alu (
    input  wire [31:0] a,        // 操作数A
    input  wire [31:0] b,        // 操作数B
    input  wire [3:0]  op,       // 4位ALU操作码（来自alu_ctrl）
    output reg  [31:0] result,   // ALU运算结果
    output wire        zero,     // 结果为0标志（分支用）
    output wire        lt,       // 有符号小于标志（仅SLT有效）
    output wire        ltu       // 无符号小于标志（仅SLTU有效）
);
    // 1. zero：严格按注释——result=0时有效
    assign zero = (result == 32'b0);

    // 2. lt/ltu：严格按注释——仅对应操作时有效，其余为0
    assign lt  = (op == 4'b1000) ? ($signed(a) < $signed(b)) : 1'b0;
    assign ltu = (op == 4'b1001) ? (a < b) : 1'b0;

    // 3. 纯组合逻辑运算核心
    always @(*) begin
        case (op)
            4'b0000: result = a + b;                     // ADD
            4'b0001: result = a - b;                     // SUB
            4'b0010: result = a & b;                     // AND
            4'b0011: result = a | b;                     // OR
            4'b0100: result = a ^ b;                     // XOR
            4'b0101: result = a << b[4:0];               // SLL（逻辑左移，低5位移位）
            4'b0110: result = a >> b[4:0];               // SRL（逻辑右移）
            4'b0111: result = $signed(a) >>> b[4:0];     // SRA（算术右移）
            4'b1000: result = ($signed(a) < $signed(b)) ? 32'b1 : 32'b0; // SLT（有符号比较）
            4'b1001: result = (a < b) ? 32'b1 : 32'b0;  // SLTU（无符号比较）
            4'b1010: result = b;                         // PASS_B（直通B，LUI专用）
            default: result = 32'b0;                     // 无效操作默认输出0
        endcase
    end
endmodule
