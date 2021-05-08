// include TinyTrainable library
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_PRINTER);

// for wiring instructions, refer to docs/

void setup() {

  myTiny.setupInstrument(false);
  myTiny.setupOutputPrinter();
  myTiny.setPrinterBegin();
  myTiny.setPrinterTest();
}

void loop() {}
