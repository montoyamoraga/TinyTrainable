// this sketch is adapted from the GestureToEmoji example
// from the repository ArduinoTensorFlowLiteTutorials by Arduino
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials

// include gesture model
#include "myGestureModel.h"

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_GESTURE, OUTPUT_PRINTER);

// constant for debugging
const bool debugOn = true;

// array to map gesture index to a name
String MY_GESTURES[] = {"gesture0", "gesture1", "gesture2"};

void setup() {
  // setup instrument
  myTiny.setupInstrument(debugOn);

  // use this line to include the default model
  myTiny.setupGestureModel(MY_GESTURES);
  // or use this line to include your own model
  //   myTiny.setupGestureModel(MY_GESTURES, myGestureModel);

  //  myTiny.setupOutputSerial();
}

void loop() {
  // run the classification
  myTiny.identify();
}
