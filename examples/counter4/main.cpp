#include "counter4.h"
#include "driver.h"

int sc_main(int argc, char *argv[]) {
  // open vcd file for tracing
  sc_trace_file *tfile = sc_create_vcd_trace_file("wave");

  // create clock signal
  sc_clock clk("clk", 10, SC_NS);
  sc_trace(tfile, clk, "inst.clk");

  // signal
  sc_signal<bool> nrst;
  sc_signal<bool> ctrl_up;
  sc_signal<sc_uint<4>> data;
  sc_trace(tfile, nrst, "inst.nrst");
  sc_trace(tfile, ctrl_up, "inst.ctrl_up");
  sc_trace(tfile, data, "inst.data");

  // counter4 instance
  counter4 inst("counter4");
  inst.clk(clk);
  inst.nrst(nrst);
  inst.ctrl_up(ctrl_up);
  inst.data(data);

  // driver instance
  driver drv("driver");
  drv.nrst(nrst);
  drv.ctrl_up(ctrl_up);

  sc_start(1000, SC_NS);

  // close vcd file
  sc_close_vcd_trace_file(tfile);
  return 0;
}
