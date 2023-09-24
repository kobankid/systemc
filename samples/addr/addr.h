#ifndef ADDR_H_
#define ADDR_H_

#include <systemc.h>
#include <iostream>

SC_MODULE(Addr) {
    sc_in_clk iclk;
    sc_fifo_in<sc_int<32>>  a;
    sc_fifo_in<sc_int<32>>  b;
    sc_fifo_out<sc_int<32>> c;

    SC_CTOR(Addr) {
        SC_THREAD(add);
        sensitive << iclk.neg();
        dont_initialize();
    }

    void add(void) {
        while(1) {
            // std::cout << sc_time_stamp() << std::endl;
            std::cout << __func__ << " start" << std::endl;
            c.write(a.read() + b.read());
            std::cout << __func__ << " end" << std::endl;
            wait();
        }
    }
};

#endif /* ADDR_H_ */
