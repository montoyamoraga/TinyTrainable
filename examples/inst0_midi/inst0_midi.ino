/// @file inst0_midi.ino
/// @brief Example: Instrument0 with output LED
/// @author montoyamoraga, peter-parque, maxzwang
/// @date March 2021

// include library
#include <Inst0.h>

// declare instrument
Inst0 tiny;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

// setup() runs once, at the beginning
void setup() {
  tiny.setupInstrument(true);

  tiny.setupOutputMIDI(10, 127, 37, 38, 39);

  String objectNames[3] = {"Object 0", "Object 1", "Object 2"};
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs once, after setup()
void loop() {
  // perform classification
  tiny.identify();
}
