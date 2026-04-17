/*
 * id_ex_reg — ID/EX Pipeline Register
 *
 * Latches the decoded instruction fields and control signals produced by the
 * Instruction Decode stage and carries them into the Execute stage. Fields
 * forwarded include the current PC (needed for AUIPC/JAL target calculation),
 * both register read values, the sign-extended immediate, the destination
 * register address, funct3/funct7 for ALU control, and the full set of control
 * signals (reg_write, alu_src, alu_op, mem_read, mem_write, mem_to_reg,
 * branch, jump). Asserting flush zeroes all fields — including control signals
 * — to create a NOP bubble, which is the mechanism used by the hazard unit to
 * handle load-use stalls and branch flushes.
 */

module id_ex_reg (
    input  wire        clk,
    input  wire        rst_n,
    input  wire        flush,
    // Datapath fields
    input  wire [31:0] id_pc,
    input  wire [31:0] id_rs1_data,
    input  wire [31:0] id_rs2_data,
    input  wire [31:0] id_imm,
    input  wire [4:0]  id_rs1,
    input  wire [4:0]  id_rs2,
    input  wire [4:0]  id_rd,
    input  wire [2:0]  id_funct3,
    input  wire [6:0]  id_funct7,
    // Control signals
    input  wire        id_reg_write,
    input  wire        id_alu_src,
    input  wire [1:0]  id_alu_op,
    input  wire        id_mem_read,
    input  wire        id_mem_write,
    input  wire        id_mem_to_reg,
    input  wire        id_branch,
    input  wire        id_jump,
    // Outputs
    output reg  [31:0] ex_pc,
    output reg  [31:0] ex_rs1_data,
    output reg  [31:0] ex_rs2_data,
    output reg  [31:0] ex_imm,
    output reg  [4:0]  ex_rs1,
    output reg  [4:0]  ex_rs2,
    output reg  [4:0]  ex_rd,
    output reg  [2:0]  ex_funct3,
    output reg  [6:0]  ex_funct7,
    output reg         ex_reg_write,
    output reg         ex_alu_src,
    output reg  [1:0]  ex_alu_op,
    output reg         ex_mem_read,
    output reg         ex_mem_write,
    output reg         ex_mem_to_reg,
    output reg         ex_branch,
    output reg         ex_jump
);

    always @(posedge clk) begin
        if (!rst_n || flush) begin
            ex_pc        <= 32'b0;
            ex_rs1_data  <= 32'b0;
            ex_rs2_data  <= 32'b0;
            ex_imm       <= 32'b0;
            ex_rs1       <= 5'b0;
            ex_rs2       <= 5'b0;
            ex_rd        <= 5'b0;
            ex_funct3    <= 3'b0;
            ex_funct7    <= 7'b0;
            ex_reg_write <= 1'b0;
            ex_alu_src   <= 1'b0;
            ex_alu_op    <= 2'b0;
            ex_mem_read  <= 1'b0;
            ex_mem_write <= 1'b0;
            ex_mem_to_reg<= 1'b0;
            ex_branch    <= 1'b0;
            ex_jump      <= 1'b0;
        end else begin
            ex_pc        <= id_pc;
            ex_rs1_data  <= id_rs1_data;
            ex_rs2_data  <= id_rs2_data;
            ex_imm       <= id_imm;
            ex_rs1       <= id_rs1;
            ex_rs2       <= id_rs2;
            ex_rd        <= id_rd;
            ex_funct3    <= id_funct3;
            ex_funct7    <= id_funct7;
            ex_reg_write <= id_reg_write;
            ex_alu_src   <= id_alu_src;
            ex_alu_op    <= id_alu_op;
            ex_mem_read  <= id_mem_read;
            ex_mem_write <= id_mem_write;
            ex_mem_to_reg<= id_mem_to_reg;
            ex_branch    <= id_branch;
            ex_jump      <= id_jump;
        end
    end

endmodule
