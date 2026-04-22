/*
 * alu_ctrl — ALU Control Decoder
 *
 * Translates the 2-bit alu_op signal from the main control unit together with
 * the instruction's funct3 and funct7 fields into a 4-bit ALU operation code
 * consumed by the ALU. alu_op encodes the broad instruction class: 2'b00 for
 * load/store (always ADD), 2'b01 for branch (always SUB for comparison),
 * 2'b10 for R-type and I-type ALU instructions (funct3/funct7 determine the
 * exact operation), and 2'b11 for U/J-type special cases. This two-level
 * decode keeps the main control unit simple while allowing fine-grained ALU
 * selection. All logic is purely combinational.
 */

module alu_ctrl (
    input  wire [31:0] instr,
    input  wire [1:0]  alu_op,
    output reg  [3:0]  alu_ctrl
);
    wire [6:0] opcode = instr[6:0];
    wire [2:0] func3 = instr[14:12];
    wire [6:0] func7 = instr[31:25];

    always @(*) begin
        case (alu_op)
            2'b00: alu_ctrl = 4'b0000; // R-type: ADD
            2'b01: begin // I-type/ALU
                case (func3)
                    3'b000: alu_ctrl = 4'b0000; // ADDI
                    3'b010: alu_ctrl = 4'b1000; // SLTI
                    3'b011: alu_ctrl = 4'b1001; // SLTIU
                    3'b100: alu_ctrl = 4'b0100; // XORI
                    3'b110: alu_ctrl = 4'b0011; // ORI
                    3'b111: alu_ctrl = 4'b0010; // ANDI
                    3'b001: alu_ctrl = 4'b0101; // SLLI
                    3'b101: begin // SRLI/SRAI
                        if (func7[5])
                            alu_ctrl = 4'b0111; // SRAI
                        else
                            alu_ctrl = 4'b0110; // SRLI
                    end
                    default: alu_ctrl = 4'b0000;
                endcase
            end
            2'b10: begin // Branch
                case (func3)
                    3'b000: alu_ctrl = 4'b0001; // SUB for BEQ
                    3'b001: alu_ctrl = 4'b0001; // SUB for BNE
                    3'b100: alu_ctrl = 4'b1000; // SLT for BLT
                    3'b101: alu_ctrl = 4'b1000; // SLT for BGE
                    3'b110: alu_ctrl = 4'b1001; // SLTU for BLTU
                    3'b111: alu_ctrl = 4'b1001; // SLTU for BGEU
                    default: alu_ctrl = 4'b0001;
                endcase
            end
            2'b11: begin // Load/Store
                case (func3[1:0])
                    2'b00: alu_ctrl = 4'b0000; // byte
                    2'b01: alu_ctrl = 4'b0000; // halfword
                    2'b10: alu_ctrl = 4'b0000; // word
                    default: alu_ctrl = 4'b0000;
                endcase
            end
            default: alu_ctrl = 4'b0000;
        endcase
    end
endmodule