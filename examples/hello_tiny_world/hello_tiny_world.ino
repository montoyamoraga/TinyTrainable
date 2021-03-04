/// @file hello_tiny_world.ino
/// @brief Test output modes

// include main library
#include <TinyTrainable.h>

// declare instance of instrument
TinyTrainable tiny;

// output mode to test!
OutputMode outputToTest = outputBuzzer;
// OutputMode outputToTest = outputLED;
// OutputMode outputToTest = outputMIDI;
// OutputMode outputToTest = outputSerialUSB;

// hardware constants
const int outputPin = 8;

// setup() runs once, at the beginning
void setup() { tiny.helloOutputsSetup(outputToTest, outputPin); }

// loop() runs in a loop, after setup()
void loop() { tiny.helloOutputs(outputToTest); }
