// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_SPEECH, OUTPUT_SERIAL);

// constant for debugging
const bool debugOn = true;

String myItems[3] = {"item0", "item1", "item2"};

// setup() runs once, at the beginning
void setup() {

  // set debugging over serial port
  myTiny.setupInstrument(debugOn);

  // setup the serial output
  myTiny.setupOutputSerial();
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the item and respond
  myTiny.identify();
}
