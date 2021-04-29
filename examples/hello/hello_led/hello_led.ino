/// @file hello_led.ino
/// @brief Test output with LED

// define input and output
#define INPUT_NONE
#define OUTPUT_LED

// include TinyTrainable library
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(new Input(), new OutputLED());

// constant for debugging
const bool tinyDebugging = true;

// constants for the hardware
const int outputPinLED0 = 3;
const int outputPinLED1 = 4;
const int outputPinLED2 = 5;

const int pauseTime = 2000;

void setup() {

  myTiny.setupInstrument(tinyDebugging);
  
  myTiny.setupOutputLED(outputPinLED0, outputPinLED1, outputPinLED2);
}

void loop() {
  myTiny.playOutput(0);
  delay(pauseTime);
  myTiny.playOutput(1);
  delay(pauseTime);
  myTiny.playOutput(2);
  delay(pauseTime);
}
