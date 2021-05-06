/// @file gesture_classifier.ino
/// @brief input gesture with output classifier?

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

#define INPUT_GESTURE
#define OUTPUT_SERIAL

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny(new InputGesture(), new OutputSerial());

// TODO - see friday 04/30 notes about this
// include machine learning model
// #include "../assets/modelGesture.h"
// or include your own
//#include "myModel.h"

// threshold of significant in G's
const float accelerationThreshold = 2.5;

// number of samples per gesture
const int numSamples = 119;

// array to map gesture index to a name
String GESTURES[] = {"gesture0", "gesture1", "gesture2"};

void setup() {
  // setup instrument
  myTiny.setupInstrument(true);
  myTiny.setupTF(GESTURES, accelerationThreshold, numSamples);

  myTiny.setupOutputSerial();
}

void loop() {
  myTiny.identify();
}
