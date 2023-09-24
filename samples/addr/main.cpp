#include <systemc.h>
#include <iostream>
#include <addr.h>
#include <tb.h>

int sc_main(int argc, char* argv[]) {

    sc_fifo<sc_int<32>> addr_in1("addr_in1", 10);
    sc_fifo<sc_int<32>> addr_in2("addr_in2", 90);
    sc_fifo<sc_int<32>> addr_out;

    const sc_time t_PERIOD(10, SC_NS);

    sc_clock clk("clk", t_PERIOD);

    tb itb("itb");
    itb.iclk(clk);
    itb.out1(addr_in1);
    itb.out2(addr_in2);
    itb.result(addr_out);

    Addr iAddr("iAddr");
    iAddr.iclk(clk);
    iAddr.a(addr_in1);
    iAddr.b(addr_in2);
    iAddr.c(addr_out);

    sc_start(50, SC_NS);

    return 0;
}
