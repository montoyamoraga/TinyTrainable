// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_LED);

// constant for debugging
const bool debugOn = true;

// constants for the hardware
const int outputPinLED0 = 3;
const int outputPinLED1 = 4;
const int outputPinLED2 = 5;

const int pauseTime = 2000;

void setup() {

  myTiny.setupInstrument(debugOn);

  myTiny.setupOutputLED(0, outputPinLED0);
  myTiny.setupOutputLED(1, outputPinLED1);
  myTiny.setupOutputLED(2, outputPinLED2);
}

void loop() {
  myTiny.playOutput(0);
  delay(pauseTime);
  myTiny.playOutput(1);
  delay(pauseTime);
  myTiny.playOutput(2);
  delay(pauseTime);
}
