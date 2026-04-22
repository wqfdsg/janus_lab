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

module dmem (
    input  wire        clk,
    input  wire        we,
    input  wire        re,
    input  wire [31:0] addr,
    input  wire [31:0] data_in,
    input  wire [2:0]  func3,
    output reg  [31:0] data_out
);
    reg [7:0] ram [0:4095];

    initial begin
        $readmemh("dmem.hex", ram);
    end

    wire [1:0] offset = addr[1:0];
    wire [10:0] word_addr = addr[11:2];

    always @(posedge clk) begin
        if (we) begin
            case (func3)
                3'b000: ram[addr[11:0]] <= data_in[7:0];                           // SB
                3'b001: begin ram[addr[11:0]] <= data_in[7:0]; ram[addr[11:0]+1] <= data_in[15:8]; end // SH
                3'b010: begin ram[addr[11:0]] <= data_in[7:0]; ram[addr[11:0]+1] <= data_in[15:8]; 
                         ram[addr[11:0]+2] <= data_in[23:16]; ram[addr[11:0]+3] <= data_in[31:24]; end // SW
            endcase
        end
    end

    always @(*) begin
        if (re) begin
            case (func3)
                3'b000: data_out = {{24{ram[addr[11:0]][7]}}, ram[addr[11:0]]};           // LB
                3'b001: data_out = {{16{ram[addr[11:0]+1][7]}}, ram[addr[11:0]+1], ram[addr[11:0]]}; // LH
                3'b010: data_out = {ram[addr[11:0]+3], ram[addr[11:0]+2], ram[addr[11:0]+1], ram[addr[11:0]]}; // LW
                3'b100: data_out = {{24{1'b0}}, ram[addr[11:0]]};                    // LBU
                3'b101: data_out = {{16{1'b0}}, ram[addr[11:0]+1], ram[addr[11:0]]}; // LHU
                default: data_out = 32'b0;
            endcase
        end else begin
            data_out = 32'b0;
        end
    end
endmodule