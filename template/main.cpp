#include "driver.h"

int sc_main(int argc, char *argv[]) {
  driver inst_driver("driver");
  sc_start(100, SC_NS);
  return 0;
}