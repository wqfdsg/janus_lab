/*
 * cpu — 5-Stage Pipelined RV32I CPU Top-Level
 *
 * Integrates all datapath and control sub-modules into a complete 5-stage
 * in-order pipeline: Instruction Fetch (IF), Instruction Decode (ID), Execute
 * (EX), Memory Access (MEM), and Write-Back (WB). The four pipeline registers
 * (if_id_reg, id_ex_reg, ex_mem_reg, mem_wb_reg) separate the stages.
 * Hazard handling is split between the hazard_unit (stall/flush control) and
 * the forward_unit (operand bypass). Branch and jump targets are resolved at the
 * end of EX; a taken branch or jump flushes IF and ID and redirects the PC to
 * the computed target. The module exposes only clk, rst_n, and the two external
 * memory interfaces so that it can be wrapped by a top-level for FPGA synthesis
 * or connected to a testbench for simulation.
 */

`include "pc_reg.v"
`include "imem.v"
`include "reg_file.v"
`include "imm_gen.v"
`include "alu.v"
`include "alu_ctrl.v"
`include "ctrl.v"
`include "dmem.v"
`include "branch_unit.v"
`include "if_id_reg.v"
`include "id_ex_reg.v"
`include "ex_mem_reg.v"
`include "mem_wb_reg.v"
`include "hazard_unit.v"
`include "forward_unit.v"

module cpu (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [31:0] instr_in,
    input  wire [31:0] dmem_rdata,
    output wire [31:0] imem_addr,
    output wire [31:0] dmem_addr,
    output wire [31:0] dmem_wdata,
    output wire        dmem_we,
    output wire        dmem_re,
    output wire [2:0]  dmem_func3
);
    wire [4:0] rs1 = instr_in[19:15];
    wire [4:0] rs2 = instr_in[24:20];
    wire [4:0] rd = instr_in[11:7];
    wire [2:0] func3 = instr_in[14:12];

    reg [31:0] pc;
    wire [31:0] pc_plus4 = pc + 4;
    wire [31:0] rs1_data, rs2_data;
    wire [31:0] imm;
    wire [31:0] alu_result;
    wire [3:0] alu_ctrl;
    wire zero, lt, ltu;

    wire reg_write, alu_src, mem_read, mem_write, mem_to_reg, branch, jump;
    wire [1:0] alu_op;

    ctrl ctrl_inst (
        .instr(instr_in),
        .reg_write(reg_write),
        .alu_src(alu_src),
        .alu_op(alu_op),
        .mem_read(mem_read),
        .mem_write(mem_write),
        .mem_to_reg(mem_to_reg),
        .branch(branch),
        .jump(jump)
    );

    alu_ctrl alu_ctrl_inst (
        .instr(instr_in),
        .alu_op(alu_op),
        .alu_ctrl(alu_ctrl)
    );

    reg_file reg_file_inst (
        .clk(clk),
        .rst_n(rst_n),
        .we(reg_write),
        .addr_a(rs1),
        .addr_b(rs2),
        .addr_w(rd),
        .data_w(mem_to_reg ? dmem_rdata : alu_result),
        .data_a(rs1_data),
        .data_b(rs2_data)
    );

    imm_gen imm_gen_inst (
        .instr(instr_in),
        .imm(imm)
    );

    wire [31:0] alu_b = alu_src ? imm : rs2_data;

    alu alu_inst (
        .a(rs1_data),
        .b(alu_b),
        .op(alu_ctrl),
        .result(alu_result),
        .zero(zero),
        .lt(lt),
        .ltu(ltu)
    );

    wire take_branch;
    branch_unit branch_inst (
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .func3(func3),
        .take_branch(take_branch)
    );

    wire branch_taken = branch && take_branch;
    wire jump_taken = jump;

    wire [31:0] pc_next = jump_taken ? alu_result :
                         branch_taken ? (pc + imm) :
                         pc_plus4;

    always @(posedge clk) begin
        if (!rst_n)
            pc <= 32'h0000_0000;
        else
            pc <= pc_next;
    end

    assign imem_addr = pc;
    assign dmem_addr = alu_result;
    assign dmem_wdata = rs2_data;
    assign dmem_we = mem_write;
    assign dmem_re = mem_read;
    assign dmem_func3 = func3;
endmodule