/// @file gesture_serial.ino
/// @brief input gesture with output serial

// this sketch is adapted from the GestureToEmoji example
// from the repository ArduinoTensorFlowLiteTutorials by Arduino
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials

// TODO: rewrite this placeholder code
// at this stage, this code is a placeholder,
// copied from the following file
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials/blob/master/GestureToEmoji/ArduinoSketches/IMU_Classifier/IMU_Classifier.ino
// with only little modifications
// and still without comments about what most lines mean
// and without optimization

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_GESTURE, OUTPUT_SERIAL);

// TODO - see friday 04/30 notes about this
// include machine learning model
// #include "../assets/modelGesture.h"
// or include your own
//#include "myModel.h"

// constant for debugging
const bool tinyDebugging = true;

#include "myGestureModel.h"

// array to map gesture index to a name
String GESTURES[] = {"gesture0", "gesture1", "gesture2"};

void setup() {
  // setup instrument
  myTiny.setupInstrument(tinyDebugging);
  myTiny.setupInstrument(true);
  Serial.println("hello in setup");
  myTiny.setupTF(GESTURES, myGestureModel);

  myTiny.setupOutputSerial();
}

void loop() {
  // run the classification
  myTiny.identify();
}
