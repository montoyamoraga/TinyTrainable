// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_SPEECH, OUTPUT_SERVO);

// constants for the hardware
// const int outputPin = 8;

// constant for debugging
const bool tinyDebugging = true;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

void setup() {
  // set debugging over serial port
  myTiny.setupInstrument(tinyDebugging);

  // set its output
  //  myTiny.setupOutputBuzzer(outputPin);
}

void loop() {
}
