// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_SCREEN);

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 20;
const float COLOR_THRESHOLD = 0.5;

// constants for the hardware
// const int outputPin = 2;

// constant for debugging
const bool debugOn = true;

String myColors[3] = {"color0", "color1", "color2"};

// setup() runs once, at the beginning
void setup() {

  // setup the instrument
  myTiny.setupInstrument(debugOn);

  // set its output
  //  myTiny.setupOutputBuzzer(outputPin);

  // train the instrument's KNN algorithm
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, myColors);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the input and respond
  myTiny.identify();
}
