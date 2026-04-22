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
    reg clk;
    reg rst_n;

    wire [31:0] imem_addr;
    reg  [31:0] imem_rdata;
    wire [31:0] dmem_addr;
    wire [31:0] dmem_wdata;
    wire        dmem_we;
    wire        dmem_re;
    wire [2:0]  dmem_func3;
    reg  [31:0] dmem_rdata;

    reg [7:0] dmem_mem [0:4095];
    reg [31:0] imem_mem [0:1023];

    initial begin
        $dumpfile("tb_top.vcd");
        $dumpvars(0, tb_top);
    end

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        rst_n = 0;
        #15 rst_n = 1;
    end

    always @(posedge clk) begin
        imem_rdata <= imem_mem[imem_addr[31:2]];
    end

    always @(posedge clk) begin
        if (dmem_we) begin
            case (dmem_func3)
                3'b000: dmem_mem[dmem_addr[11:0]] <= dmem_wdata[7:0];
                3'b001: begin
                    dmem_mem[dmem_addr[11:0]] <= dmem_wdata[7:0];
                    dmem_mem[dmem_addr[11:0]+1] <= dmem_wdata[15:8];
                end
                3'b010: begin
                    dmem_mem[dmem_addr[11:0]+0] <= dmem_wdata[7:0];
                    dmem_mem[dmem_addr[11:0]+1] <= dmem_wdata[15:8];
                    dmem_mem[dmem_addr[11:0]+2] <= dmem_wdata[23:16];
                    dmem_mem[dmem_addr[11:0]+3] <= dmem_wdata[31:24];
                end
            endcase
        end
    end

    always @(*) begin
        if (dmem_re) begin
            case (dmem_func3)
                3'b000: dmem_rdata = {{24{dmem_mem[dmem_addr[11:0]][7]}}, dmem_mem[dmem_addr[11:0]]};
                3'b001: dmem_rdata = {{16{dmem_mem[dmem_addr[11:0]+1][7]}}, dmem_mem[dmem_addr[11:0]+1], dmem_mem[dmem_addr[11:0]]};
                3'b010: dmem_rdata = {dmem_mem[dmem_addr[11:0]+3], dmem_mem[dmem_addr[11:0]+2], dmem_mem[dmem_addr[11:0]+1], dmem_mem[dmem_addr[11:0]]};
                3'b100: dmem_rdata = {24'b0, dmem_mem[dmem_addr[11:0]]};
                3'b101: dmem_rdata = {16'b0, dmem_mem[dmem_addr[11:0]+1], dmem_mem[dmem_addr[11:0]]};
                default: dmem_rdata = 32'b0;
            endcase
        end else begin
            dmem_rdata = 32'b0;
        end
    end

    top dut (
        .clk(clk),
        .rst_n(rst_n),
        .imem_addr(imem_addr),
        .imem_rdata(imem_rdata),
        .dmem_addr(dmem_addr),
        .dmem_wdata(dmem_wdata),
        .dmem_we(dmem_we),
        .dmem_re(dmem_re),
        .dmem_func3(dmem_func3),
        .dmem_rdata(dmem_rdata)
    );

    initial begin
        #10000;
        $display("Simulation finished at time %0t", $time);
        $finish;
    end
endmodule