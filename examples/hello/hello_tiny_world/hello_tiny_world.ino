/// @file hello_tiny_world.ino
/// @brief Test output modes

// include main library
#include <TinyTrainable.h>

// declare instance of instrument
TinyTrainable tiny;

// output mode to test, possible values:
// outputBuzzer, outputLED, outputMIDI, outputSerialUSB
// outputUndefined tests that the arduino is correctly connected
OutputMode outputToTest = outputUndefined;

// hardware constants
const int outputPin = 3;

// setup() runs once, at the beginning
void setup() {
  // setup the test

  // setup for outputBuzzer and outputLED (that have pins)
  // tiny.helloOutputsSetup(outputToTest, outputPin);
  // setup for outputMIDI, outputSerialUSB, and outputUndefined (outputs without pins)
  tiny.helloOutputsSetup(outputToTest);
}

// loop() runs in a loop, after setup()
void loop() {
  // test the output
  tiny.helloOutputs(outputToTest);
}
