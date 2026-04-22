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
    input  wire        reg_write_in,
    input  wire        mem_read_in,
    input  wire        mem_write_in,
    input  wire        mem_to_reg_in,
    input  wire [4:0]  rd_in,
    input  wire [31:0] alu_result_in,
    input  wire [31:0] rs2_data_in,
    output reg         reg_write_out,
    output reg         mem_read_out,
    output reg         mem_write_out,
    output reg         mem_to_reg_out,
    output reg [4:0]  rd_out,
    output reg [31:0] alu_result_out,
    output reg [31:0] rs2_data_out
);
    always @(posedge clk) begin
        if (!rst_n) begin
            reg_write_out <= 1'b0;
            mem_read_out <= 1'b0;
            mem_write_out <= 1'b0;
            mem_to_reg_out <= 1'b0;
            rd_out <= 5'b0;
            alu_result_out <= 32'b0;
            rs2_data_out <= 32'b0;
        end else begin
            reg_write_out <= reg_write_in;
            mem_read_out <= mem_read_in;
            mem_write_out <= mem_write_in;
            mem_to_reg_out <= mem_to_reg_in;
            rd_out <= rd_in;
            alu_result_out <= alu_result_in;
            rs2_data_out <= rs2_data_in;
        end
    end
endmodule