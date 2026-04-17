/*
 * ex_mem_reg — EX/MEM Pipeline Register
 *
 * Latches the outputs of the Execute stage and passes them to the Memory Access
 * stage. Carried fields are: the ALU result (data memory address or arithmetic
 * result), the rs2 register value (store data for SW/SH/SB), the destination
 * register address, funct3 (needed by dmem for sub-word load/store selection),
 * and the control signals relevant to the MEM and WB stages (mem_read,
 * mem_write, mem_to_reg, reg_write). The branch_taken and branch_target signals
 * are also latched here so the top-level CPU can redirect the PC on a taken
 * branch; in a pipelined implementation this register also feeds the hazard
 * unit's flush logic.
 */

module ex_mem_reg (
    input  wire        clk,
    input  wire        rst_n,
    // Datapath fields
    input  wire [31:0] ex_alu_result,
    input  wire [31:0] ex_rs2_data,
    input  wire [4:0]  ex_rd,
    input  wire [2:0]  ex_funct3,
    input  wire        ex_branch_taken,
    input  wire        ex_jump,
    input  wire [31:0] ex_pc_target,
    // Control signals
    input  wire        ex_reg_write,
    input  wire        ex_mem_read,
    input  wire        ex_mem_write,
    input  wire        ex_mem_to_reg,
    // Outputs
    output reg  [31:0] mem_alu_result,
    output reg  [31:0] mem_rs2_data,
    output reg  [4:0]  mem_rd,
    output reg  [2:0]  mem_funct3,
    output reg         mem_branch_taken,
    output reg         mem_jump,
    output reg  [31:0] mem_pc_target,
    output reg         mem_reg_write,
    output reg         mem_mem_read,
    output reg         mem_mem_write,
    output reg         mem_mem_to_reg
);

    always @(posedge clk) begin
        if (!rst_n) begin
            mem_alu_result  <= 32'b0;
            mem_rs2_data    <= 32'b0;
            mem_rd          <= 5'b0;
            mem_funct3      <= 3'b0;
            mem_branch_taken<= 1'b0;
            mem_jump        <= 1'b0;
            mem_pc_target   <= 32'b0;
            mem_reg_write   <= 1'b0;
            mem_mem_read    <= 1'b0;
            mem_mem_write   <= 1'b0;
            mem_mem_to_reg  <= 1'b0;
        end else begin
            mem_alu_result  <= ex_alu_result;
            mem_rs2_data    <= ex_rs2_data;
            mem_rd          <= ex_rd;
            mem_funct3      <= ex_funct3;
            mem_branch_taken<= ex_branch_taken;
            mem_jump        <= ex_jump;
            mem_pc_target   <= ex_pc_target;
            mem_reg_write   <= ex_reg_write;
            mem_mem_read    <= ex_mem_read;
            mem_mem_write   <= ex_mem_write;
            mem_mem_to_reg  <= ex_mem_to_reg;
        end
    end

endmodule
