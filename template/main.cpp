#include "driver.h"

int sc_main(int argc, char *argv[]) {
  // open vcd file for tracing
  sc_trace_file *tfile = sc_create_vcd_trace_file("wave");

  // create clock signal
  sc_clock clk("clk", 10, SC_NS);
  sc_trace(tfile, clk, "clk");

  driver inst_driver("driver");
  sc_start(100, SC_NS);

  // close vcd file
  sc_close_vcd_trace_file(tfile);
  return 0;
}