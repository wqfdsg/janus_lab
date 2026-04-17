/*
 * reg_file — 32×32 General-Purpose Register File
 *
 * Implements the RV32I architectural register state: 32 registers each 32 bits
 * wide. Register x0 is hardwired to zero — reads always return 0 and writes
 * are silently discarded. Writes are synchronous (rising clock edge, qualified
 * by reg_write and rst_n). Reads are asynchronous/combinational so that the ID
 * stage can obtain operands in the same cycle as decode. Read-during-write
 * forwarding is applied: if the read address matches the write address and
 * reg_write is asserted, the new write data is returned immediately rather than
 * the stale register value, avoiding a one-cycle RAW hazard within the register
 * file itself.
 */

module reg_file (
    input  wire        clk,
    input  wire        rst_n,
    // Write port
    input  wire        reg_write,
    input  wire [4:0]  rd,
    input  wire [31:0] rd_data,
    // Read port A (rs1)
    input  wire [4:0]  rs1,
    output wire [31:0] rs1_data,
    // Read port B (rs2)
    input  wire [4:0]  rs2,
    output wire [31:0] rs2_data
);

    reg [31:0] regs [1:31];

    integer i;
    always @(posedge clk) begin
        if (!rst_n) begin
            for (i = 1; i < 32; i = i + 1)
                regs[i] <= 32'b0;
        end else if (reg_write && rd != 5'b0) begin
            regs[rd] <= rd_data;
        end
    end

    // Asynchronous read with read-during-write forwarding
    assign rs1_data = (rs1 == 5'b0)                        ? 32'b0    :
                      (reg_write && rs1 == rd)              ? rd_data  :
                                                              regs[rs1];

    assign rs2_data = (rs2 == 5'b0)                        ? 32'b0    :
                      (reg_write && rs2 == rd)              ? rd_data  :
                                                              regs[rs2];

endmodule
