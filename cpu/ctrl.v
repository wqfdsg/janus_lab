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
    input  wire [6:0] opcode,
    output reg        reg_write,
    output reg        alu_src,
    output reg [1:0]  alu_op,
    output reg        mem_read,
    output reg        mem_write,
    output reg        mem_to_reg,
    output reg        branch,
    output reg        jump
);

    localparam OP_R      = 7'b011_0011;
    localparam OP_I_ALU  = 7'b001_0011;
    localparam OP_I_LOAD = 7'b000_0011;
    localparam OP_S      = 7'b010_0011;
    localparam OP_B      = 7'b110_0011;
    localparam OP_LUI    = 7'b011_0111;
    localparam OP_AUIPC  = 7'b001_0111;
    localparam OP_JAL    = 7'b110_1111;
    localparam OP_JALR   = 7'b110_0111;

    always @(*) begin
        // Safe defaults: NOP
        {reg_write, alu_src, alu_op, mem_read, mem_write, mem_to_reg, branch, jump} = 9'b0;

        case (opcode)
            OP_R: begin
                reg_write  = 1'b1;
                alu_src    = 1'b0;
                alu_op     = 2'b10;
            end
            OP_I_ALU: begin
                reg_write  = 1'b1;
                alu_src    = 1'b1;
                alu_op     = 2'b10;
            end
            OP_I_LOAD: begin
                reg_write  = 1'b1;
                alu_src    = 1'b1;
                alu_op     = 2'b00;
                mem_read   = 1'b1;
                mem_to_reg = 1'b1;
            end
            OP_S: begin
                alu_src    = 1'b1;
                alu_op     = 2'b00;
                mem_write  = 1'b1;
            end
            OP_B: begin
                alu_op     = 2'b01;
                branch     = 1'b1;
            end
            OP_LUI: begin
                reg_write  = 1'b1;
                alu_src    = 1'b1;
                alu_op     = 2'b11; // PASS immediate
            end
            OP_AUIPC: begin
                reg_write  = 1'b1;
                alu_src    = 1'b1;
                alu_op     = 2'b00; // PC + imm
            end
            OP_JAL: begin
                reg_write  = 1'b1;
                jump       = 1'b1;
            end
            OP_JALR: begin
                reg_write  = 1'b1;
                alu_src    = 1'b1;
                alu_op     = 2'b00;
                jump       = 1'b1;
            end
            default: ; // all signals remain 0 (NOP)
        endcase
    end

endmodule
