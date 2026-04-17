/*
 * dmem — Data Memory (RAM)
 *
 * A 4 KB byte-addressable data store implementing the Harvard-architecture data
 * bus. The memory is organised as a 4096-byte array; accesses are qualified by
 * mem_read and mem_write. Writes are synchronous (rising edge); reads are
 * combinational so the MEM stage can return data without an added pipeline
 * bubble. Sub-word granularity is controlled by funct3 (matching the RV32I
 * load/store encoding): 3'b000/3'b100 for byte (signed/unsigned), 3'b001/3'b101
 * for halfword (signed/unsigned), and 3'b010 for word. Unaligned accesses are
 * not supported and produce undefined results. The memory can be pre-loaded via
 * $readmemh for tests that require an initial data image.
 */

module dmem #(
    parameter DEPTH = 4096 // bytes
) (
    input  wire        clk,
    input  wire        mem_read,
    input  wire        mem_write,
    input  wire [2:0]  funct3,
    input  wire [31:0] addr,
    input  wire [31:0] wr_data,
    output reg  [31:0] rd_data
);

    reg [7:0] mem [0:DEPTH-1];

    // Synchronous write with sub-word granularity
    always @(posedge clk) begin
        if (mem_write) begin
            case (funct3)
                3'b000: mem[addr[11:0]] <= wr_data[7:0]; // SB
                3'b001: begin                              // SH
                    mem[addr[11:0]]   <= wr_data[7:0];
                    mem[addr[11:0]+1] <= wr_data[15:8];
                end
                3'b010: begin                              // SW
                    mem[addr[11:0]]   <= wr_data[7:0];
                    mem[addr[11:0]+1] <= wr_data[15:8];
                    mem[addr[11:0]+2] <= wr_data[23:16];
                    mem[addr[11:0]+3] <= wr_data[31:24];
                end
                default: ;
            endcase
        end
    end

    // Combinational read with sign/zero extension
    always @(*) begin
        rd_data = 32'b0;
        if (mem_read) begin
            case (funct3)
                3'b000: rd_data = {{24{mem[addr[11:0]][7]}},  mem[addr[11:0]]};          // LB
                3'b001: rd_data = {{16{mem[addr[11:0]+1][7]}}, mem[addr[11:0]+1], mem[addr[11:0]]}; // LH
                3'b010: rd_data = {mem[addr[11:0]+3], mem[addr[11:0]+2],                  // LW
                                   mem[addr[11:0]+1], mem[addr[11:0]]};
                3'b100: rd_data = {24'b0, mem[addr[11:0]]};                               // LBU
                3'b101: rd_data = {16'b0, mem[addr[11:0]+1], mem[addr[11:0]]};           // LHU
                default: rd_data = 32'b0;
            endcase
        end
    end

endmodule
