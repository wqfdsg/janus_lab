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
    input  wire        branch_ctrl,   // Control signal: 1 if branch instruction
    input  wire [31:0] rs1_data,
    input  wire [31:0] rs2_data,
    input  wire [2:0]  funct3,
    output wire       take_branch
);

    wire branch_taken;

    always @(*) begin
        case (funct3)
            3'b000: branch_taken = (rs1_data == rs2_data);   // BEQ
            3'b001: branch_taken = (rs1_data != rs2_data);   // BNE
            3'b100: branch_taken = ($signed(rs1_data) < $signed(rs2_data));   // BLT
            3'b101: branch_taken = ($signed(rs1_data) >= $signed(rs2_data)); // BGE
            3'b110: branch_taken = (rs1_data < rs2_data);   // BLTU
            3'b111: branch_taken = (rs1_data >= rs2_data); // BGEU
            default: branch_taken = 1'b0;
        endcase
    end

    assign take_branch = branch_ctrl & branch_taken;
endmodule