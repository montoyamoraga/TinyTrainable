/// @file inst0_serial.ino
/// @brief Example: Instrument0 with output serial

// include library
#include <Inst0.h>

// declare instance of the instrument0
Inst0 tiny;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// constant for debugging
const bool tinyDebugging = true;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// setup() runs once, at the beginning
void setup() {

  tiny.setupInstrument(tinyDebugging);

  tiny.setupOutputSerialUSB();

  // train the KNN algorithm with your objects
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

/// loop() runs after setup(), on a loop
void loop() {
  // identify the item and respond
  tiny.identify();
}
