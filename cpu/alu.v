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
    input  wire [3:0]  alu_ctrl,
    output reg  [31:0] result,
    output wire        zero
);

    // ALU control encodings (must match alu_ctrl.v)
    localparam ALU_ADD  = 4'd0;
    localparam ALU_SUB  = 4'd1;
    localparam ALU_AND  = 4'd2;
    localparam ALU_OR   = 4'd3;
    localparam ALU_XOR  = 4'd4;
    localparam ALU_SLL  = 4'd5;
    localparam ALU_SRL  = 4'd6;
    localparam ALU_SRA  = 4'd7;
    localparam ALU_SLT  = 4'd8;
    localparam ALU_SLTU = 4'd9;
    localparam ALU_PASS = 4'd10; // pass b (for LUI)

    always @(*) begin
        case (alu_ctrl)
            ALU_ADD:  result = a + b;
            ALU_SUB:  result = a - b;
            ALU_AND:  result = a & b;
            ALU_OR:   result = a | b;
            ALU_XOR:  result = a ^ b;
            ALU_SLL:  result = a << b[4:0];
            ALU_SRL:  result = a >> b[4:0];
            ALU_SRA:  result = $signed(a) >>> b[4:0];
            ALU_SLT:  result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
            ALU_SLTU: result = (a < b)                   ? 32'd1 : 32'd0;
            ALU_PASS: result = b;
            default:  result = 32'b0;
        endcase
    end

    assign zero = (result == 32'b0);

endmodule
