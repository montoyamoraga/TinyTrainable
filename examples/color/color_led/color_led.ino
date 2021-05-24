// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_LED);

// constants for the hardware
const int outputPinLED0 = 3;
const int outputPinLED1 = 4;
const int outputPinLED2 = 5;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// constant for debugging
const bool debugOn = true;

String myColors[3] = {"color0", "color1", "color2"};

// setup() runs once, at the beginning
void setup() {
  myTiny.setupInstrument(debugOn);

  myTiny.setupOutputLED(0, outputPinLED0);
  myTiny.setupOutputLED(1, outputPinLED1);
  myTiny.setupOutputLED(2, outputPinLED2);

  // train the KNN algorithm with your objects
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, myColors);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the item and respond
  myTiny.identify();
}
