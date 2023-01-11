#ifndef _DRIVER_H_
#define _DRIVER_H_
#include <systemc.h>

SC_MODULE(driver) {
  void prc_driver() {
    while(true) {
      cout << "Hello: time is " << sc_time_stamp() << endl;
      wait(5, SC_NS);
    }
  }

  SC_CTOR(driver) {
    SC_THREAD(prc_driver);
  }
};
#endif