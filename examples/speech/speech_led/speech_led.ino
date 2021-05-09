// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_SPEECH, OUTPUT_BUZZER);

// constants for the hardware
const int outputPin = 8;

// constant for debugging
const bool debugOn = true;

String myItems[3] = {"item0", "item1", "item2"};

void setup() {
  // set debugging over serial port
  myTiny.setupInstrument(debugOn);

  // set its output
  //   myTiny.setupOutputBuzzer(outputPin);
}

void loop() {}
