// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_MIDI);

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

String myColors[3] = {"color0", "color1", "color2"};

// setup() runs once, at the beginning
void setup() {

  myTiny.setupInstrument(true);

  myTiny.setupOutputMIDI(10);
  //  myTiny.setMIDINotes(0, 37);
  //  myTiny.setMIDINotes(1, 38);
  //  myTiny.setMIDINotes(2, 39);

  //  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, myColors);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the input and respond
  //  myTiny.identify();
}
