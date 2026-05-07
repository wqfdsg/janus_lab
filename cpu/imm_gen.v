/*
 * imm_gen — Immediate Generation Unit
 *
 * Extracts and sign-extends the immediate field from a 32-bit RV32I instruction
 * word. The output is always a 32-bit sign-extended value regardless of the
 * original immediate width. The encoding format (I, S, B, U, or J) is
 * determined from the instruction's opcode field (bits [6:0]), and the
 * appropriate bit-gathering and sign-extension logic is applied combinationally.
 * U-type immediates (LUI, AUIPC) are left-shifted by 12 and zero-filled in the
 * lower bits; all other types are sign-extended from their most-significant
 * immediate bit. This module is purely combinational with no registered state.
 */

`timescale 1ns / 1ps

module imm_gen (
    input  wire [31:0] instr,
    output reg  [31:0] imm
);

wire [6:0] opcode = instr[6:0];

always @(*) begin
    case (opcode)
        7'b0010011, 7'b0000011, 7'b1100111:  // I-type
            imm = {{20{instr[31]}}, instr[31:20]};
        
        7'b0100011:                          // S-type
            imm = {{20{instr[31]}}, instr[31:25], instr[11:7]};
        
        7'b1100011:                          // B-type
            imm = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};
        
        7'b0110111, 7'b0010111:              // U-type
            imm = {instr[31:12], 12'b0};
        
        7'b1101111:                          // J-type
            imm = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};
        
        default: 
            imm = 32'b0;
    endcase
end

endmodule
