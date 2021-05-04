/// @file color_servo.ino
/// @brief input color with output servo

// define input and output
#define INPUT_COLOR
#define OUTPUT_SERVO

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny();

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 20;
const float COLOR_THRESHOLD = 0.5;

// String objectNames[3] = {"Object0", "Object1", "Object2"};
String objectNames[3] = {"avocado", "orange", "towel"};

// our servo moves between the minimum and maximum angles
// at a desired tempo measured in beats per minute
const int tempo0 = 20;
const int tempo1 = 90;
const int tempo2 = 200;

// constants for the hardware
const int outputPin = 9;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = true;

// setup() runs once, at the beginning
void setup() {

  myTiny.setupInstrument(tinyDebugging);

  myTiny.setupOutputServo(outputPin);

  // set the tempo (in bpm) for each object
  myTiny.setServoTempo(0, tempo0);
  myTiny.setServoTempo(1, tempo1);
  myTiny.setServoTempo(2, tempo2);

  // train the KNN algorithm
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  myTiny.identify();
}
