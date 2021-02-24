/// @file hello_buzzer.ino
/// @brief Test buzzer output

// include all libraries
#include <Inst0.h>
#include <Inst1.h>
#include <Inst2.h>

// declare instance of the instrument
// default is Inst0, change Inst0 to Inst1 or Inst2 if necessary
Inst0 tiny;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = false;

// setup() runs once, at the beginning
void setup() {
  // initialize instrument
  tiny.setupInstrument(tinyDebugging);
}

// loop() runs in a loop, after setup()
void loop() {

  // TODO: add functions for testing buzzer
}
