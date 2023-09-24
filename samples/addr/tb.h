#ifndef TB_H_
#define TB_H_

#include <systemc.h>

SC_MODULE(tb) {
    sc_in_clk iclk;
    sc_fifo_out<sc_int<32>> out1;
    sc_fifo_out<sc_int<32>> out2;
    sc_fifo_in<sc_int<32>> result;
    int a;
    int b;
    
    SC_CTOR(tb) {
        SC_THREAD(source);
        sensitive << iclk.neg();
        SC_THREAD(sink);
        sensitive << iclk.neg();
        dont_initialize();
        a = 0;
        b = 0;
    }

    void source(void) {
        while(1) {
            std::cout << __func__ << std::endl;
            out1.write(a);
            out2.write(b);
            a++;
            b++;
            printf("a = %d, b = %d\n", a, b);
            wait();
        }
    }

    void sink(void) {
        while(1) {
            std::cout << __func__ << std::endl;
            sc_int<32> add_result = result.read();
            std::cout << "result = " << add_result <<  std::endl;
            wait();
        }
    }
};


#endif /* TB_H_ */
