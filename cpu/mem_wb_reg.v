/*
 * mem_wb_reg — MEM/WB Pipeline Register
 *
 * Latches the outputs of the Memory Access stage and delivers them to the
 * Write-Back stage. Two data paths converge here: the ALU result (for
 * instructions that do not access memory) and the data memory read value (for
 * load instructions). The mem_to_reg control signal, also latched here,
 * selects which of these two values is written back to the register file.
 * The destination register address (rd) and the reg_write enable are carried
 * forward so the Write-Back stage can commit results without needing to
 * re-decode the original instruction.
 */

module mem_wb_reg (
    input  wire        clk,
    input  wire        rst_n,
    // Datapath fields
    input  wire [31:0] mem_alu_result,
    input  wire [31:0] mem_rd_data,
    input  wire [4:0]  mem_rd,
    // Control signals
    input  wire        mem_reg_write,
    input  wire        mem_mem_to_reg,
    // Outputs
    output reg  [31:0] wb_alu_result,
    output reg  [31:0] wb_rd_data,
    output reg  [4:0]  wb_rd,
    output reg         wb_reg_write,
    output reg         wb_mem_to_reg
);

    always @(posedge clk) begin
        if (!rst_n) begin
            wb_alu_result <= 32'b0;
            wb_rd_data    <= 32'b0;
            wb_rd         <= 5'b0;
            wb_reg_write  <= 1'b0;
            wb_mem_to_reg <= 1'b0;
        end else begin
            wb_alu_result <= mem_alu_result;
            wb_rd_data    <= mem_rd_data;
            wb_rd         <= mem_rd;
            wb_reg_write  <= mem_reg_write;
            wb_mem_to_reg <= mem_mem_to_reg;
        end
    end

endmodule
