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
    input wire clk,
    input wire rst_n
);

    // -------------------------------------------------------------------------
    // IF stage
    // -------------------------------------------------------------------------
    wire [31:0] pc, next_pc, if_instr;
    wire        pc_stall;
    wire        pc_redirect;
    wire [31:0] pc_target;

    assign pc_redirect = mem_branch_taken || mem_jump;
    assign next_pc     = pc_redirect ? mem_pc_target : pc + 32'd4;

    pc_reg u_pc_reg (
        .clk     (clk),
        .rst_n   (rst_n),
        .stall   (pc_stall),
        .next_pc (next_pc),
        .pc      (pc)
    );

    imem u_imem (
        .addr  (pc),
        .instr (if_instr)
    );

    // -------------------------------------------------------------------------
    // IF/ID pipeline register
    // -------------------------------------------------------------------------
    wire [31:0] id_pc, id_instr;
    wire        if_id_stall, if_id_flush;

    if_id_reg u_if_id (
        .clk      (clk),
        .rst_n    (rst_n),
        .stall    (if_id_stall),
        .flush    (if_id_flush),
        .if_pc    (pc),
        .if_instr (if_instr),
        .id_pc    (id_pc),
        .id_instr (id_instr)
    );

    // -------------------------------------------------------------------------
    // ID stage — decode and register file read
    // -------------------------------------------------------------------------
    wire [6:0] id_opcode = id_instr[6:0];
    wire [4:0] id_rd     = id_instr[11:7];
    wire [2:0] id_funct3 = id_instr[14:12];
    wire [4:0] id_rs1    = id_instr[19:15];
    wire [4:0] id_rs2    = id_instr[24:20];
    wire [6:0] id_funct7 = id_instr[31:25];

    wire [31:0] id_rs1_data, id_rs2_data;
    wire [31:0] id_imm;
    wire        id_reg_write, id_alu_src, id_mem_read, id_mem_write;
    wire        id_mem_to_reg, id_branch, id_jump;
    wire [1:0]  id_alu_op;

    // Write-back signals (needed for register file write port)
    wire        wb_reg_write;
    wire [4:0]  wb_rd;
    wire [31:0] wb_rd_data;
    wire [31:0] wb_alu_result, wb_mem_rd_data;
    wire        wb_mem_to_reg;

    assign wb_rd_data = wb_mem_to_reg ? wb_mem_rd_data : wb_alu_result;

    reg_file u_reg_file (
        .clk       (clk),
        .rst_n     (rst_n),
        .reg_write (wb_reg_write),
        .rd        (wb_rd),
        .rd_data   (wb_rd_data),
        .rs1       (id_rs1),
        .rs1_data  (id_rs1_data),
        .rs2       (id_rs2),
        .rs2_data  (id_rs2_data)
    );

    imm_gen u_imm_gen (
        .instr (id_instr),
        .imm   (id_imm)
    );

    ctrl u_ctrl (
        .opcode      (id_opcode),
        .reg_write   (id_reg_write),
        .alu_src     (id_alu_src),
        .alu_op      (id_alu_op),
        .mem_read    (id_mem_read),
        .mem_write   (id_mem_write),
        .mem_to_reg  (id_mem_to_reg),
        .branch      (id_branch),
        .jump        (id_jump)
    );

    // -------------------------------------------------------------------------
    // ID/EX pipeline register
    // -------------------------------------------------------------------------
    wire [31:0] ex_pc, ex_rs1_data_raw, ex_rs2_data_raw, ex_imm;
    wire [4:0]  ex_rs1, ex_rs2, ex_rd;
    wire [2:0]  ex_funct3;
    wire [6:0]  ex_funct7;
    wire        ex_reg_write, ex_alu_src, ex_mem_read, ex_mem_write;
    wire        ex_mem_to_reg, ex_branch, ex_jump;
    wire [1:0]  ex_alu_op;
    wire        id_ex_flush;

    id_ex_reg u_id_ex (
        .clk          (clk),
        .rst_n        (rst_n),
        .flush        (id_ex_flush),
        .id_pc        (id_pc),
        .id_rs1_data  (id_rs1_data),
        .id_rs2_data  (id_rs2_data),
        .id_imm       (id_imm),
        .id_rs1       (id_rs1),
        .id_rs2       (id_rs2),
        .id_rd        (id_rd),
        .id_funct3    (id_funct3),
        .id_funct7    (id_funct7),
        .id_reg_write (id_reg_write),
        .id_alu_src   (id_alu_src),
        .id_alu_op    (id_alu_op),
        .id_mem_read  (id_mem_read),
        .id_mem_write (id_mem_write),
        .id_mem_to_reg(id_mem_to_reg),
        .id_branch    (id_branch),
        .id_jump      (id_jump),
        .ex_pc        (ex_pc),
        .ex_rs1_data  (ex_rs1_data_raw),
        .ex_rs2_data  (ex_rs2_data_raw),
        .ex_imm       (ex_imm),
        .ex_rs1       (ex_rs1),
        .ex_rs2       (ex_rs2),
        .ex_rd        (ex_rd),
        .ex_funct3    (ex_funct3),
        .ex_funct7    (ex_funct7),
        .ex_reg_write (ex_reg_write),
        .ex_alu_src   (ex_alu_src),
        .ex_alu_op    (ex_alu_op),
        .ex_mem_read  (ex_mem_read),
        .ex_mem_write (ex_mem_write),
        .ex_mem_to_reg(ex_mem_to_reg),
        .ex_branch    (ex_branch),
        .ex_jump      (ex_jump)
    );

    // -------------------------------------------------------------------------
    // EX stage — forwarding muxes, ALU, branch resolution
    // -------------------------------------------------------------------------
    wire [1:0]  forward_a, forward_b;
    wire [31:0] mem_alu_result_fwd; // from EX/MEM (declared below)

    // Forward mux for rs1
    wire [31:0] ex_rs1_data = (forward_a == 2'b10) ? mem_alu_result_fwd :
                              (forward_a == 2'b01) ? wb_rd_data          :
                                                     ex_rs1_data_raw;

    // Forward mux for rs2 (pre-ALU-src mux)
    wire [31:0] ex_rs2_fwd  = (forward_b == 2'b10) ? mem_alu_result_fwd :
                              (forward_b == 2'b01) ? wb_rd_data          :
                                                     ex_rs2_data_raw;

    wire [31:0] alu_b_in    = ex_alu_src ? ex_imm : ex_rs2_fwd;

    wire [3:0]  alu_ctrl_out;
    wire [31:0] alu_result;
    wire        alu_zero;

    alu_ctrl u_alu_ctrl (
        .alu_op      (ex_alu_op),
        .funct3      (ex_funct3),
        .funct7      (ex_funct7),
        .alu_ctrl_out(alu_ctrl_out)
    );

    alu u_alu (
        .a        (ex_rs1_data),
        .b        (alu_b_in),
        .alu_ctrl (alu_ctrl_out),
        .result   (alu_result),
        .zero     (alu_zero)
    );

    wire ex_branch_taken;

    branch_unit u_branch_unit (
        .branch   (ex_branch),
        .funct3   (ex_funct3),
        .rs1_data (ex_rs1_data),
        .rs2_data (ex_rs2_fwd),
        .taken    (ex_branch_taken)
    );

    // Branch/jump target: PC + imm (JAL, B-type) or rs1 + imm (JALR)
    wire [31:0] ex_pc_target = ex_jump && (ex_funct3 == 3'b000 && ex_alu_op == 2'b00)
                               ? (ex_rs1_data + ex_imm) & ~32'h1 // JALR: mask LSB
                               : ex_pc + ex_imm;                  // JAL / branch

    // -------------------------------------------------------------------------
    // EX/MEM pipeline register
    // -------------------------------------------------------------------------
    wire [31:0] mem_rs2_data, mem_pc_target;
    wire [4:0]  mem_rd;
    wire [2:0]  mem_funct3;
    wire        mem_branch_taken, mem_jump;
    wire        mem_reg_write, mem_mem_read, mem_mem_write, mem_mem_to_reg;

    ex_mem_reg u_ex_mem (
        .clk             (clk),
        .rst_n           (rst_n),
        .ex_alu_result   (alu_result),
        .ex_rs2_data     (ex_rs2_fwd),
        .ex_rd           (ex_rd),
        .ex_funct3       (ex_funct3),
        .ex_branch_taken (ex_branch_taken),
        .ex_jump         (ex_jump),
        .ex_pc_target    (ex_pc_target),
        .ex_reg_write    (ex_reg_write),
        .ex_mem_read     (ex_mem_read),
        .ex_mem_write    (ex_mem_write),
        .ex_mem_to_reg   (ex_mem_to_reg),
        .mem_alu_result  (mem_alu_result_fwd),
        .mem_rs2_data    (mem_rs2_data),
        .mem_rd          (mem_rd),
        .mem_funct3      (mem_funct3),
        .mem_branch_taken(mem_branch_taken),
        .mem_jump        (mem_jump),
        .mem_pc_target   (mem_pc_target),
        .mem_reg_write   (mem_reg_write),
        .mem_mem_read    (mem_mem_read),
        .mem_mem_write   (mem_mem_write),
        .mem_mem_to_reg  (mem_mem_to_reg)
    );

    // -------------------------------------------------------------------------
    // MEM stage
    // -------------------------------------------------------------------------
    wire [31:0] dmem_rd_data;

    dmem u_dmem (
        .clk       (clk),
        .mem_read  (mem_mem_read),
        .mem_write (mem_mem_write),
        .funct3    (mem_funct3),
        .addr      (mem_alu_result_fwd),
        .wr_data   (mem_rs2_data),
        .rd_data   (dmem_rd_data)
    );

    // -------------------------------------------------------------------------
    // MEM/WB pipeline register
    // -------------------------------------------------------------------------

    mem_wb_reg u_mem_wb (
        .clk          (clk),
        .rst_n        (rst_n),
        .mem_alu_result(mem_alu_result_fwd),
        .mem_rd_data  (dmem_rd_data),
        .mem_rd       (mem_rd),
        .mem_reg_write(mem_reg_write),
        .mem_mem_to_reg(mem_mem_to_reg),
        .wb_alu_result(wb_alu_result),
        .wb_rd_data   (wb_mem_rd_data),
        .wb_rd        (wb_rd),
        .wb_reg_write (wb_reg_write),
        .wb_mem_to_reg(wb_mem_to_reg)
    );

    // -------------------------------------------------------------------------
    // Hazard unit
    // -------------------------------------------------------------------------
    hazard_unit u_hazard (
        .ex_mem_read  (ex_mem_read),
        .ex_rd        (ex_rd),
        .id_rs1       (id_rs1),
        .id_rs2       (id_rs2),
        .branch_taken (mem_branch_taken),
        .jump         (mem_jump),
        .pc_stall     (pc_stall),
        .if_id_stall  (if_id_stall),
        .if_id_flush  (if_id_flush),
        .id_ex_flush  (id_ex_flush)
    );

    // -------------------------------------------------------------------------
    // Forward unit
    // -------------------------------------------------------------------------
    forward_unit u_forward (
        .ex_rs1       (ex_rs1),
        .ex_rs2       (ex_rs2),
        .mem_reg_write(mem_reg_write),
        .mem_rd       (mem_rd),
        .wb_reg_write (wb_reg_write),
        .wb_rd        (wb_rd),
        .forward_a    (forward_a),
        .forward_b    (forward_b)
    );

endmodule
