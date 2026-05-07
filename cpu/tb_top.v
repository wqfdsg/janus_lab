/*
 * tb_top — Top-Level Testbench
 *
 * Instantiates the cpu module and drives clock and reset to allow simulation.
 * The clock period is 10 ns (100 MHz). Reset is held low for the first four
 * clock cycles to ensure all pipeline registers and the PC are cleared before
 * any instruction is fetched. The testbench is intentionally minimal — it
 * provides infrastructure only. Individual test programs are loaded into the
 * instruction memory via the MEM_FILE parameter on imem and (optionally) a
 * data-memory image; pass-fail is determined by checking the register file or
 * data memory state at a known cycle count, or by having the test program write
 * a sentinel value to a magic address that the testbench monitors. Waveforms
 * are dumped to dump.vcd for post-simulation viewing in GTKWave or equivalent.
 */

`timescale 1ns / 1ps

module tb_top;
    reg         clk;
    reg         rst_n;

    wire [31:0] imem_addr;
    wire [31:0] instr_in;
    wire [31:0] dmem_addr;
    wire [31:0] dmem_wdata;
    wire        dmem_we;
    wire        dmem_re;
    wire [2:0]  dmem_func3;
    reg  [31:0] dmem_rdata;

    reg [31:0] imem [0:1023];
    reg [7:0]  dmem [0:4095];

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_top);
    end

    initial begin
        clk = 1'b0;
        forever #5 clk = ~clk;
    end

    initial begin
        rst_n = 1'b0;
        #40;
        rst_n = 1'b1;
    end

    integer i;

initial begin
    $readmemh("imem.hex", imem);

    for (i = 0; i < 4096; i = i + 1)
        dmem[i] = 8'b0;
end

    assign instr_in = imem[imem_addr[11:2]];

    always @(*) begin
        if (!dmem_re)
            dmem_rdata = 32'b0;
        else case (dmem_func3)
            3'b000: dmem_rdata = {{24{dmem[dmem_addr[11:0]][7]}}, dmem[dmem_addr[11:0]]};
            3'b001: dmem_rdata = {{16{dmem[dmem_addr[11:0]+1][7]}}, dmem[dmem_addr[11:0]+1], dmem[dmem_addr[11:0]]};
            3'b010: dmem_rdata = {dmem[dmem_addr[11:0]+3], dmem[dmem_addr[11:0]+2], dmem[dmem_addr[11:0]+1], dmem[dmem_addr[11:0]]};
            3'b100: dmem_rdata = {24'b0, dmem[dmem_addr[11:0]]};
            3'b101: dmem_rdata = {16'b0, dmem[dmem_addr[11:0]+1], dmem[dmem_addr[11:0]]};
            default: dmem_rdata = 32'b0;
        endcase
    end

    always @(posedge clk) begin
        if (dmem_we) begin
            case (dmem_func3)
                3'b000: dmem[dmem_addr[11:0]]   = dmem_wdata[7:0];
                3'b001: {dmem[dmem_addr[11:0]+1], dmem[dmem_addr[11:0]]} = dmem_wdata[15:0];
                3'b010: {dmem[dmem_addr[11:0]+3], dmem[dmem_addr[11:0]+2],
                         dmem[dmem_addr[11:0]+1], dmem[dmem_addr[11:0]]} = dmem_wdata;
                default;
            endcase
        end
    end

    cpu dut (
        .clk        (clk),
        .rst_n      (rst_n),
        .instr_in   (instr_in),
        .dmem_rdata (dmem_rdata),
        .imem_addr  (imem_addr),
        .dmem_addr  (dmem_addr),
        .dmem_wdata (dmem_wdata),
        .dmem_we    (dmem_we),
        .dmem_re    (dmem_re),
        .dmem_func3 (dmem_func3)
    );


endmodule
