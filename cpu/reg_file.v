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
    input  wire        we,
    input  wire [4:0]  addr_a,
    input  wire [4:0]  addr_b,
    input  wire [4:0]  addr_w,
    input  wire [31:0] data_w,
    output wire [31:0] data_a,
    output wire [31:0] data_b
);
    reg [31:0] regs [0:31];

    always @(posedge clk) begin
        if (!rst_n) begin
            regs[0] <= 32'b0;
            regs[1] <= 32'b0;
            regs[2] <= 32'b0;
            regs[3] <= 32'b0;
            regs[4] <= 32'b0;
            regs[5] <= 32'b0;
            regs[6] <= 32'b0;
            regs[7] <= 32'b0;
            regs[8] <= 32'b0;
            regs[9] <= 32'b0;
            regs[10] <= 32'b0;
            regs[11] <= 32'b0;
            regs[12] <= 32'b0;
            regs[13] <= 32'b0;
            regs[14] <= 32'b0;
            regs[15] <= 32'b0;
            regs[16] <= 32'b0;
            regs[17] <= 32'b0;
            regs[18] <= 32'b0;
            regs[19] <= 32'b0;
            regs[20] <= 32'b0;
            regs[21] <= 32'b0;
            regs[22] <= 32'b0;
            regs[23] <= 32'b0;
            regs[24] <= 32'b0;
            regs[25] <= 32'b0;
            regs[26] <= 32'b0;
            regs[27] <= 32'b0;
            regs[28] <= 32'b0;
            regs[29] <= 32'b0;
            regs[30] <= 32'b0;
            regs[31] <= 32'b0;
        end else if (we && addr_w != 5'b0) begin
            regs[addr_w] <= data_w;
        end
    end

    assign data_a = (addr_a == 5'b0) ? 32'b0 : 
                   (we && addr_a == addr_w) ? data_w : regs[addr_a];
    assign data_b = (addr_b == 5'b0) ? 32'b0 : 
                   (we && addr_b == addr_w) ? data_w : regs[addr_b];
endmodule