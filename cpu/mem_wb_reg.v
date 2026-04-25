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
    input  wire        reg_write_in,
    input  wire        mem_to_reg_in,
    input  wire [4:0]  rd_in,
    input  wire [31:0] alu_result_in,
    input  wire [31:0] mem_data_in,
    
    output reg         reg_write_out,
    output reg         mem_to_reg_out,
    output reg [4:0]  rd_out,
    output reg [31:0] alu_result_out,
    output reg [31:0] mem_data_out
);

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        reg_write_out  <= 1'b0;
        mem_to_reg_out <= 1'b0;
        rd_out         <= 5'b0;
        alu_result_out <= 32'b0;
        mem_data_out   <= 32'b0;
    end else begin
        reg_write_out  <= reg_write_in;
        mem_to_reg_out <= mem_to_reg_in;
        rd_out         <= rd_in;
        alu_result_out <= alu_result_in;
        mem_data_out   <= mem_data_in;
    end
end

endmodule