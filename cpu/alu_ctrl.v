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
    input  wire [1:0] alu_op,
    input  wire [2:0] funct3,
    input  wire [6:0] funct7,
    output reg  [3:0] alu_ctrl_out
);

    // ALU control encodings (must match alu.v)
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
    localparam ALU_PASS = 4'd10;

    always @(*) begin
        case (alu_op)
            2'b00: alu_ctrl_out = ALU_ADD;  // load / store
            2'b01: alu_ctrl_out = ALU_SUB;  // branch (compare via subtraction)
            2'b11: alu_ctrl_out = ALU_PASS; // LUI: pass immediate unchanged
            2'b10: begin                    // R-type and I-type ALU
                case (funct3)
                    3'h0: alu_ctrl_out = (funct7[5] && alu_op == 2'b10)
                                         ? ALU_SUB : ALU_ADD; // ADD/SUB
                    3'h4: alu_ctrl_out = ALU_XOR;
                    3'h6: alu_ctrl_out = ALU_OR;
                    3'h7: alu_ctrl_out = ALU_AND;
                    3'h1: alu_ctrl_out = ALU_SLL;
                    3'h5: alu_ctrl_out = funct7[5] ? ALU_SRA : ALU_SRL;
                    3'h2: alu_ctrl_out = ALU_SLT;
                    3'h3: alu_ctrl_out = ALU_SLTU;
                    default: alu_ctrl_out = ALU_ADD;
                endcase
            end
            default: alu_ctrl_out = ALU_ADD;
        endcase
    end

endmodule
