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
    
    input  wire        reg_write_in,
    input  wire        alu_src_in,
    input  wire [1:0]  alu_op_in,
    input  wire        mem_read_in,
    input  wire        mem_write_in,
    input  wire        mem_to_reg_in,
    input  wire        branch_in,
    input  wire        jump_in,
    
    input  wire [31:0] pc_in,
    input  wire [31:0] rs1_data_in,
    input  wire [31:0] rs2_data_in,
    input  wire [31:0] imm_in,
    input  wire [4:0]  rd_in,
    input  wire [2:0]  func3_in,

    output reg         reg_write_out,
    output reg         alu_src_out,
    output reg [1:0]  alu_op_out,
    output reg         mem_read_out,
    output reg         mem_write_out,
    output reg         mem_to_reg_out,
    output reg         branch_out,
    output reg         jump_out,
    
    output reg [31:0] pc_out,
    output reg [31:0] rs1_data_out,
    output reg [31:0] rs2_data_out,
    output reg [31:0] imm_out,
    output reg [4:0]  rd_out,
    output reg [2:0]  func3_out
);

always @(posedge clk or negedge rst_n) begin
    if (!rst_n || flush) begin
        reg_write_out  <= 1'b0;
        alu_src_out    <= 1'b0;
        alu_op_out     <= 2'b00;
        mem_read_out   <= 1'b0;
        mem_write_out  <= 1'b0;
        mem_to_reg_out <= 1'b0;
        branch_out     <= 1'b0;
        jump_out       <= 1'b0;
        
        pc_out         <= 32'b0;
        rs1_data_out   <= 32'b0;
        rs2_data_out   <= 32'b0;
        imm_out        <= 32'b0;
        rd_out         <= 5'b0;
        func3_out      <= 3'b0;
    end else begin
        reg_write_out  <= reg_write_in;
        alu_src_out    <= alu_src_in;
        alu_op_out     <= alu_op_in;
        mem_read_out   <= mem_read_in;
        mem_write_out  <= mem_write_in;
        mem_to_reg_out <= mem_to_reg_in;
        branch_out     <= branch_in;
        jump_out       <= jump_in;
        
        pc_out         <= pc_in;
        rs1_data_out   <= rs1_data_in;
        rs2_data_out   <= rs2_data_in;
        imm_out        <= imm_in;
        rd_out         <= rd_in;
        func3_out      <= func3_in;
    end
end

endmodule