/*
 * ctrl — Main Control Unit
 *
 * Decodes the 7-bit opcode of the current instruction and asserts the set of
 * control signals that govern the datapath for that instruction class. Outputs
 * cover register write enable, ALU source selection, memory read/write enables,
 * write-back source, branch and jump flags, and the 2-bit alu_op code passed to
 * alu_ctrl for fine-grained ALU selection. This is a purely combinational,
 * single-level ROM-style decode: one case entry per RV32I opcode. Instructions
 * with no valid opcode (illegal encodings) produce all-zero control signals,
 * effectively a NOP, matching the bubble inserted by the hazard unit.
 */

module ctrl (
    input  wire [31:0] instr,
    output reg         reg_write,
    output reg         alu_src,
    output reg [1:0]  alu_op,
    output reg         mem_read,
    output reg         mem_write,
    output reg         mem_to_reg,
    output reg         branch,
    output reg         jump
);
    wire [6:0] opcode = instr[6:0];
    wire [2:0] func3 = instr[14:12];

    always @(*) begin
        reg_write = 1'b0;
        alu_src = 1'b0;
        alu_op = 2'b00;
        mem_read = 1'b0;
        mem_write = 1'b0;
        mem_to_reg = 1'b0;
        branch = 1'b0;
        jump = 1'b0;

        case (opcode)
            7'b011011: begin // LUI
                reg_write = 1'b1;
                alu_src = 1'b1;
                alu_op = 2'b11;
            end
            7'b001011: begin // AUIPC
                reg_write = 1'b1;
                alu_src = 1'b1;
                alu_op = 2'b00;
            end
            7'b110111: begin // JAL
                reg_write = 1'b1;
                jump = 1'b1;
                alu_op = 2'b00;
            end
            7'b110011: begin // JALR
                reg_write = 1'b1;
                jump = 1'b1;
                alu_src = 1'b1;
                alu_op = 2'b00;
            end
            7'b110001: begin // BRANCH (BEQ, BNE, BLT, BGE, BLTU, BGEU)
                branch = 1'b1;
                alu_op = 2'b10;
            end
            7'b000011: begin // OP-IMM (ADDI, SLTI, etc.) or LOAD
                if (func3[2] == 1'b0) begin // OP-IMM
                    reg_write = 1'b1;
                    alu_src = 1'b1;
                    alu_op = 2'b01;
                end else begin // LOAD
                    reg_write = 1'b1;
                    alu_src = 1'b1;
                    mem_read = 1'b1;
                    mem_to_reg = 1'b1;
                    alu_op = 2'b11;
                end
            end
            7'b001100: begin // OP-IMM (ANDI, ORI, XORI)
                reg_write = 1'b1;
                alu_src = 1'b1;
                alu_op = 2'b01;
            end
            7'b011100: begin // R-type
                reg_write = 1'b1;
                alu_op = 2'b00;
            end
            7'b000111: begin // STORE (SB, SH, SW)
                alu_src = 1'b1;
                mem_write = 1'b1;
                alu_op = 2'b11;
            end
            default: begin
                reg_write = 1'b0;
                alu_src = 1'b0;
                alu_op = 2'b00;
                mem_read = 1'b0;
                mem_write = 1'b0;
                mem_to_reg = 1'b0;
                branch = 1'b0;
                jump = 1'b0;
            end
        endcase
    end
endmodule