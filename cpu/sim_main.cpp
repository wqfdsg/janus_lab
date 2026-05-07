#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtb_top.h"

vluint64_t main_time = 0;

double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {

    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtb_top* tb = new Vtb_top;

    VerilatedVcdC* tfp = new VerilatedVcdC;

    tb->trace(tfp, 99);

    tfp->open("wave.vcd");

    while (!Verilated::gotFinish() && main_time < 300) {

        Verilated::timeInc(1);

        tb->eval();

        tfp->dump(main_time);

        main_time++;
    }

    tb->final();

    tfp->close();

    delete tfp;
    delete tb;

    return 0;
}