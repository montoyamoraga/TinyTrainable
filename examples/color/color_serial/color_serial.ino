// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_SERIAL);

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// constant for debugging
const bool debugOn = true;

String myColors[3] = {"color0", "color1", "color2"};

// setup() runs once, at the beginning
void setup() {

  // set debugging over serial port
  myTiny.setupInstrument(debugOn);

  myTiny.setupOutputSerial();

  // train the KNN algorithm
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, myColors);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the item and respond
  myTiny.identify();
}
