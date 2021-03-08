/// @file inst0_midi.ino
/// @brief Example: Instrument0 with output MIDI

// include library
#include <Inst0.h>

// declare instance of the instrument0
Inst0 tiny;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// setup() runs once, at the beginning
void setup() {
  tiny.setupInstrument(true);

  tiny.setupOutputMIDI(10, 127);
  tiny.setMIDINotes(0, 37);
  tiny.setMIDINotes(1, 38);
  tiny.setMIDINotes(2, 39);

  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

/// loop() runs after setup(), on a loop

void loop() {
  /// identify the input and respond
  tiny.identify();
}
