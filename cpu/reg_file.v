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

always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        integer i;
        for (i = 0; i < 32; i = i + 1)
            regs[i] <= 32'b0;
    end else if (we && addr_w != 5'b0) begin
        regs[addr_w] <= data_w;
    end
end

assign data_a = (addr_a == 5'b0) ? 32'b0 : 
               (we && addr_a == addr_w) ? data_w : regs[addr_a];
assign data_b = (addr_b == 5'b0) ? 32'b0 : 
               (we && addr_b == addr_w) ? data_w : regs[addr_b];

endmodule