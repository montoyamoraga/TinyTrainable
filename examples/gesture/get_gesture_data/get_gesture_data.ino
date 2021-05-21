// this sketch is adapted from the public domain GestureToEmoji example
// from the repository ArduinoTensorFlowLiteTutorials by Arduino
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials
// and as of April 2021 available at
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials/blob/master/GestureToEmoji/ArduinoSketches/IMU_Capture/IMU_Capture.ino

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_GESTURE, OUTPUT_SERIAL);

// constant for debugging
const bool debugOn = true;

// names of gestures
String gestures[] = {"gesture0", "gesture1", "gesture2"};

void setup() {

  myTiny.setupInstrument(debugOn);
  myTiny.setupOutputSerial();

  // print "aX,aY,aZ,gX,gY,gZ"
  myTiny.gesturePrintHeader();
}

void loop() {
  // TODO: right now it is commented out in the source code
  myTiny.gestureReadData();
}
