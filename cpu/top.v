module top (
    input  wire        clk,
    input  wire        rst_n,
    output wire [31:0] imem_addr,
    input  wire [31:0] imem_rdata,
    output wire [31:0] dmem_addr,
    output wire [31:0] dmem_wdata,
    output wire        dmem_we,
    output wire        dmem_re,
    output wire [2:0]  dmem_func3,
    input  wire [31:0] dmem_rdata
);
    cpu cpu_inst (
        .clk(clk),
        .rst_n(rst_n),
        .instr_in(imem_rdata),
        .dmem_rdata(dmem_rdata),
        .imem_addr(imem_addr),
        .dmem_addr(dmem_addr),
        .dmem_wdata(dmem_wdata),
        .dmem_we(dmem_we),
        .dmem_re(dmem_re),
        .dmem_func3(dmem_func3)
    );
endmodule