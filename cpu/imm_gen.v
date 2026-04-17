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

module imm_gen (
    input  wire [31:0] instr,
    output reg  [31:0] imm
);

    wire [6:0] opcode = instr[6:0];

    localparam OP_I_LOAD  = 7'b000_0011;
    localparam OP_I_ALU   = 7'b001_0011;
    localparam OP_I_JALR  = 7'b110_0111;
    localparam OP_S       = 7'b010_0011;
    localparam OP_B       = 7'b110_0011;
    localparam OP_U_LUI   = 7'b011_0111;
    localparam OP_U_AUIPC = 7'b001_0111;
    localparam OP_J       = 7'b110_1111;

    always @(*) begin
        case (opcode)
            OP_I_LOAD,
            OP_I_ALU,
            OP_I_JALR: // I-type
                imm = {{20{instr[31]}}, instr[31:20]};

            OP_S: // S-type
                imm = {{20{instr[31]}}, instr[31:25], instr[11:7]};

            OP_B: // B-type
                imm = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};

            OP_U_LUI,
            OP_U_AUIPC: // U-type
                imm = {instr[31:12], 12'b0};

            OP_J: // J-type
                imm = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};

            default:
                imm = 32'b0;
        endcase
    end

endmodule
