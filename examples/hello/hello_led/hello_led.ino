/// @file hello_led.ino
/// @brief Example: Test output with LEDs

// import library
#include <TinyTrainable.h>

// declare instance of the instrument
// you can also do the same with Inst0, Inst1, or Inst2 instances
TinyTrainable tiny;

// constants for the hardware
const int outputPinLED0 = 3;
const int outputPinLED1 = 4;
const int outputPinLED2 = 5;

int pauseTime = 2000;

void setup() {
  tiny.setupOutputLED(outputPinLED0, outputPinLED1, outputPinLED2);
}

void loop() {
  tiny.playOutput(0);
  delay(pauseTime);
  tiny.playOutput(1);
  delay(pauseTime);
  tiny.playOutput(2);
  delay(pauseTime);
}
