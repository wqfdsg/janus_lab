/*
 * imem — Instruction Memory (ROM)
 *
 * A 4 KB read-only instruction store modelling the Harvard-architecture
 * instruction bus. The memory is word-addressed (bits [11:2] of the byte
 * address index into a 1024-entry array). Contents are loaded at simulation
 * start from a hex file via $readmemh; the path is controlled by the MEM_FILE
 * parameter so each test can supply its own program. Reads are purely
 * combinational — the instruction word appears on instr in the same cycle that
 * addr is presented, matching a single-cycle or pipelined IF stage with no
 * added latency.
 */

module imem (
    input  wire [31:0] addr,
    output wire [31:0] instr
);
    reg [31:0] rom [0:1023];

    initial begin
        $readmemh("imem.hex", rom);
    end

    assign instr = rom[addr[31:2]];
endmodule