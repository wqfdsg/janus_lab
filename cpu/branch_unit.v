/*
 * branch_unit — Branch Condition Evaluator
 *
 * Determines whether a conditional branch instruction should be taken, given
 * the two register operands and the funct3 encoding of the branch type. All six
 * RV32I branch conditions are supported: BEQ, BNE, BLT, BGE, BLTU, BGEU.
 * Signed comparisons (BLT, BGE) treat operands as 2's-complement integers;
 * unsigned comparisons (BLTU, BGEU) treat them as raw bit patterns. The branch
 * signal from the main control unit gates the taken output so that non-branch
 * instructions never cause a spurious PC redirect. This module is purely
 * combinational and sits in the EX stage alongside the ALU.
 */

module branch_unit (
    input  wire        branch,
    input  wire [2:0]  funct3,
    input  wire [31:0] rs1_data,
    input  wire [31:0] rs2_data,
    output wire        taken
);

    reg condition;

    always @(*) begin
        case (funct3)
            3'b000: condition = (rs1_data == rs2_data);                    // BEQ
            3'b001: condition = (rs1_data != rs2_data);                    // BNE
            3'b100: condition = ($signed(rs1_data) <  $signed(rs2_data));  // BLT
            3'b101: condition = ($signed(rs1_data) >= $signed(rs2_data));  // BGE
            3'b110: condition = (rs1_data <  rs2_data);                    // BLTU
            3'b111: condition = (rs1_data >= rs2_data);                    // BGEU
            default: condition = 1'b0;
        endcase
    end

    assign taken = branch & condition;

endmodule
