/// @file color_midi.ino
/// @brief input color with output MIDI

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_MIDI);

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// setup() runs once, at the beginning
void setup() {

  myTiny.setupInstrument(true);

  myTiny.setupOutputMIDI(10);
  //  myTiny.setMIDINotes(0, 37);
  //  myTiny.setMIDINotes(1, 38);
  //  myTiny.setMIDINotes(2, 39);

  //  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the input and respond
  //  myTiny.identify();
}
