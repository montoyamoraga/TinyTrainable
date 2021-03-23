/// @file hello_tiny_world.ino
/// @brief Test output modes

// include main library
#include <TinyTrainable.h>

// TODO: maybe change this example to only internal things
// TODO: maybe change name to hello_none for consistency
// should only flash internal LED lights and output serial messages
#define TINY_OUTPUT "NONE"

// declare instance of instrument
TinyTrainable tiny;

// output mode to test, possible values:
// outputBuzzer, outputLED, outputMIDI, outputSerialUSB, outputServo
// outputUndefined tests that the arduino is correctly connected
OutputMode outputToTest = outputServo;

// hardware constants
const int outputPin = 9;

// setup() runs once, at the beginning
void setup() {
  // setup the test

  // setup for outputBuzzer, outputLED, and outputServo (that have pins)
  tiny.helloOutputsSetup(outputToTest, outputPin);
  // setup for outputMIDI, outputSerialUSB, and outputUndefined (outputs without
  // pins) tiny.helloOutputsSetup(outputToTest);
}

// loop() runs in a loop, after setup()
void loop() {
  // test the output
  tiny.helloOutputs(outputToTest);
}
