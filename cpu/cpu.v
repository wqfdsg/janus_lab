/*
 * cpu — 5-Stage Pipelined RV32I CPU Top-Level
 *
 * 5-stage in-order pipeline: IF, ID, EX, MEM, WB.
 * Pipeline registers: if_id_reg, id_ex_reg, ex_mem_reg, mem_wb_reg.
 * Hazard control: hazard_unit; Data forwarding: forward_unit.
 * Branch/jump resolved at EX stage, flush IF/ID on taken.
 * External interfaces for instruction and data memory.
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
    wire stall, flush_if, flush_id;
    wire [1:0] forward_a, forward_b;

    wire [31:0] pc_mem, alu_result_mem, rs2_data_mem;
    wire [4:0] rd_mem;
    wire reg_write_mem, mem_read_mem, mem_write_mem, mem_to_reg_mem;
    wire [2:0] func3_mem;
    wire [31:0] alu_result_wb, mem_data_wb;
    wire [4:0] rd_wb;
    wire reg_write_wb, mem_to_reg_wb;
    wire [31:0] wb_data;

    wire [31:0] pc_if, pc_next_if, pc_plus4_if;
    wire [31:0] instr_if;
    wire       jump_taken, branch_taken;
    wire [31:0] branch_target, jump_target;

    pc_reg pc_inst (
        .clk(clk), .rst_n(rst_n), .stall(stall),
        .pc_next(pc_next_if), .pc(pc_if)
    );

    assign pc_plus4_if = pc_if + 32'd4;
    assign imem_addr = pc_if;
    assign instr_if = instr_in;

    wire [31:0] pc_id, pc_plus4_id;
    wire [31:0] instr_id;
    if_id_reg if_id_inst (
        .clk(clk), .rst_n(rst_n), .stall(if_id_stall), .flush(flush_if),
        .pc_if(pc_if), .pc_plus4_if(pc_plus4_if), .instr_if(instr_if),
        .pc_id(pc_id), .pc_plus4_id(pc_plus4_id), .instr_id(instr_id)
    );

    wire [4:0] rs1_id = instr_id[19:15];
    wire [4:0] rs2_id = instr_id[24:20];
    wire [4:0] rd_id  = instr_id[11:7];
    wire [2:0] func3_id = instr_id[14:12];
    wire [6:0] opcode_id = instr_id[6:0];

    wire reg_write_id, alu_src_id, mem_read_id, mem_write_id, mem_to_reg_id, branch_id, jump_id;
    wire [1:0] alu_op_id;
    wire [31:0] rs1_data_id, rs2_data_id, imm_id;

    ctrl ctrl_inst (
        .instr(instr_id), .reg_write(reg_write_id), .alu_src(alu_src_id),
        .alu_op(alu_op_id), .mem_read(mem_read_id), .mem_write(mem_write_id),
        .mem_to_reg(mem_to_reg_id), .branch(branch_id), .jump(jump_id)
    );

    imm_gen imm_gen_inst (.instr(instr_id), .imm(imm_id));

    reg_file reg_file_inst (
        .clk(clk), .rst_n(rst_n), .we(reg_write_wb), .addr_a(rs1_id), .addr_b(rs2_id), .addr_w(rd_wb),
        .data_w(wb_data),
        .data_a(rs1_data_id), .data_b(rs2_data_id)
    );

    wire [31:0] pc_ex, pc_plus4_ex, imm_ex;
    wire [31:0] rs1_data_ex, rs2_data_ex;
    wire [4:0] rd_ex, rs1_ex, rs2_ex;
    wire [2:0] func3_ex;
    wire reg_write_ex, alu_src_ex, mem_read_ex, mem_write_ex, mem_to_reg_ex, branch_ex, jump_ex;
    wire [1:0] alu_op_ex;

    id_ex_reg id_ex_inst (
        .clk(clk), .rst_n(rst_n), .flush(flush_id),
        .pc_id(pc_id), .pc_plus4_id(pc_plus4_id), .imm_id(imm_id),
        .rs1_data_id(rs1_data_id), .rs2_data_id(rs2_data_id),
        .rd_id(rd_id), .rs1_id(rs1_id), .rs2_id(rs2_id),
        .func3_id(func3_id),
        .reg_write_id(reg_write_id), .alu_src_id(alu_src_id),
        .mem_read_id(mem_read_id), .mem_write_id(mem_write_id),
        .mem_to_reg_id(mem_to_reg_id), .branch_id(branch_id), .jump_id(jump_id),
        .alu_op_id(alu_op_id),
        .pc_ex(pc_ex), .pc_plus4_ex(pc_plus4_ex), .imm_ex(imm_ex),
        .rs1_data_ex(rs1_data_ex), .rs2_data_ex(rs2_data_ex),
        .rd_ex(rd_ex), .rs1_ex(rs1_ex), .rs2_ex(rs2_ex),
        .func3_ex(func3_ex),
        .reg_write_ex(reg_write_ex), .alu_src_ex(alu_src_ex),
        .mem_read_ex(mem_read_ex), .mem_write_ex(mem_write_ex),
        .mem_to_reg_ex(mem_to_reg_ex), .branch_ex(branch_ex), .jump_ex(jump_ex),
        .alu_op_ex(alu_op_ex)
    );

    wire [3:0] alu_ctrl_ex;
    wire [31:0] alu_a_ex, alu_b_ex, alu_result_ex;
    wire zero_ex, lt_ex, ltu_ex, take_branch_ex;

    alu_ctrl alu_ctrl_inst (.instr(instr_id), .alu_op(alu_op_ex), .alu_ctrl(alu_ctrl_ex));

    assign wb_data = mem_to_reg_wb ? mem_data_wb : alu_result_wb;

    assign alu_a_ex = (forward_a == 2'b01) ? wb_data :
                      (forward_a == 2'b10) ? alu_result_mem : rs1_data_ex;
    assign alu_b_ex = alu_src_ex ? imm_ex :
                      (forward_b == 2'b01) ? wb_data :
                      (forward_b == 2'b10) ? alu_result_mem : rs2_data_ex;

    alu alu_inst (
        .a(alu_a_ex), .b(alu_b_ex), .op(alu_ctrl_ex),
        .result(alu_result_ex), .zero(zero_ex), .lt(lt_ex), .ltu(ltu_ex)
    );

    branch_unit branch_inst (
        .branch_ctrl(branch_ex), .rs1_data(alu_a_ex), .rs2_data(alu_b_ex), .funct3(func3_ex),
        .take_branch(take_branch_ex)
    );

    assign branch_taken = branch_ex && take_branch_ex;
    assign jump_taken   = jump_ex;
    assign branch_target = pc_ex + imm_ex;
    assign jump_target   = alu_result_ex;

    ex_mem_reg ex_mem_inst (
        .clk(clk), .rst_n(rst_n), .flush(1'b0),
        .reg_write_in(reg_write_ex), .mem_read_in(mem_read_ex), .mem_write_in(mem_write_ex), .mem_to_reg_in(mem_to_reg_ex),
        .func3_in(func3_ex), .rd_in(rd_ex), .alu_result_in(alu_result_ex), .rs2_data_in(rs2_data_ex),
        .branch_taken_in(branch_taken), .jump_taken_in(jump_taken),
        .reg_write_out(reg_write_mem), .mem_read_out(mem_read_mem), .mem_write_out(mem_write_mem), .mem_to_reg_out(mem_to_reg_mem),
        .func3_out(func3_mem), .rd_out(rd_mem), .alu_result_out(alu_result_mem), .rs2_data_out(rs2_data_mem),
        .branch_taken_out(), .jump_taken_out()
    );

    mem_wb_reg mem_wb_inst (
        .clk(clk), .rst_n(rst_n),
        .reg_write_in(reg_write_mem), .mem_to_reg_in(mem_to_reg_mem), .rd_in(rd_mem),
        .alu_result_in(alu_result_mem), .mem_data_in(dmem_rdata),
        .reg_write_out(reg_write_wb), .mem_to_reg_out(mem_to_reg_wb), .rd_out(rd_wb),
        .alu_result_out(alu_result_wb), .mem_data_out(mem_data_wb)
    );

    wire pc_stall, if_id_stall, if_id_flush, id_ex_flush;

    hazard_unit hazard_inst (
        .id_rs1(rs1_id), .id_rs2(rs2_id), .id_ex_rd(rd_ex), .id_ex_mem_read(mem_read_ex),
        .branch_taken(branch_taken), .jump_taken(jump_taken),
        .pc_stall(pc_stall), .if_id_stall(if_id_stall), .if_id_flush(if_id_flush), .id_ex_flush(id_ex_flush)
    );

    assign stall = pc_stall;
    assign flush_if = if_id_flush;
    assign flush_id = id_ex_flush;

    forward_unit forward_inst (
        .ex_rs1(rs1_ex), .ex_rs2(rs2_ex),
        .ex_mem_rd(rd_mem), .mem_wb_rd(rd_wb),
        .ex_mem_reg_write(reg_write_mem), .mem_wb_reg_write(reg_write_wb),
        .forward_a(forward_a), .forward_b(forward_b)
    );

    assign pc_next_if = jump_taken  ? jump_target :
                        branch_taken ? branch_target :
                        pc_plus4_if;

    assign dmem_addr  = alu_result_mem;
    assign dmem_wdata = rs2_data_mem;
    assign dmem_we    = mem_write_mem;
    assign dmem_re    = mem_read_mem;
    assign dmem_func3 = func3_mem;

endmodule