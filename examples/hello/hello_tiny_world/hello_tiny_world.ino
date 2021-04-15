/// @file hello_tiny_world.ino
/// @brief Test output modes

// define input and output
#define INPUT_NONE
#define OUTPUT_NONE

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(new Input(), new Output());

// output mode to test, possible values:
// outputBuzzer, outputLED, outputMIDI, outputSerialUSB, outputServo
// outputUndefined tests that the arduino is correctly connected
//OutputMode outputToTest = outputServo;

// hardware constants
const int outputPin = 9;

// setup() runs once, at the beginning
void setup() {
  // setup the test

  // setup for outputBuzzer, outputLED, and outputServo (that have pins)
  //  tiny.helloOutputsSetup(outputToTest, outputPin);
  // setup for outputMIDI, outputSerialUSB, and outputUndefined (outputs without
  // pins) tiny.helloOutputsSetup(outputToTest);
}

// loop() runs in a loop, after setup()
void loop() {
  // test the output
  //  tiny.helloOutputs(outputToTest);
}
