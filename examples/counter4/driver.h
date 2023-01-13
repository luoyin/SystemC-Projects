#ifndef _DRIVER_H_
#define _DRIVER_H_
#include <systemc.h>

SC_MODULE(driver) {
  sc_out<bool> nrst;
  sc_out<bool> ctrl_up;

  void prc_nrst() {
    nrst = true;
    wait(30, SC_NS);
    nrst = false;
    wait(60, SC_NS);
    nrst = true;
  }

  void prc_ctrl_up() {
    ctrl_up = true;
    wait(600, SC_NS);
    ctrl_up = false;
  }

  SC_CTOR(driver) {
    SC_THREAD(prc_nrst);
    SC_THREAD(prc_ctrl_up);
  }
};
#endif