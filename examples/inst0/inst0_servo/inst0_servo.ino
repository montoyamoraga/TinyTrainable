// include library
#include <Inst0.h>

// declare instance of the instrument0
Inst0 tiny;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// constants for the hardware
const int outputPin = 9;
const int servoAngleMin = 30;
const int servoAngleMax = 60;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = true;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// setup() runs once, at the beginning
void setup() {
  tiny.setupInstrument(tinyDebugging);

  tiny.setupOutputServo(outputPin, servoAngleMin, servoAngleMax);

  tiny.setServoTempo(0, 60);
  tiny.setServoTempo(1, 90);
  tiny.setServoTempo(2, 120);
  
  // train the KNN algorithm
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  tiny.identify();
}
