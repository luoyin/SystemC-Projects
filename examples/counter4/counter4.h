#ifndef _COUNTER4_H_
#define _COUNTER4_H_
#include <systemc.h>

SC_MODULE(counter4) {
  // input pin
  sc_in_clk   clk;
  sc_in<bool> nrst;
  sc_in<bool> ctrl_up;

  // output pin
  sc_out<sc_uint<4>> data;

  void prc_counter4() {
    while(true) {
      if (!nrst) {
        data = 0;
      } else {
        if (ctrl_up) data = data.read() + 1;
        else         data = data.read() - 1;
      }
      wait();
    }
  }

  SC_CTOR(counter4) {
    SC_CTHREAD(prc_counter4, clk.pos());
  }
};
#endif
