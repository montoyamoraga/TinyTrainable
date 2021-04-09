/// @file color_servo.ino
/// @brief input color with output servo

// define input and output
#define INPUT_COLOR
#define OUTPUT_SERVO

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny(new InputColor(), new OutputServo());

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// for the supplies list servo, these values can be >= 0, <= 180
// these are the values the servo will move between at the given bpm
// going right to the limit can sometimes cause the servo to buzz
const int servoAngleMin = 30;
const int servoAngleMax = 60;

// constants for the hardware
const int outputPin = 9;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = true;

// setup() runs once, at the beginning
void setup() {
  myTiny.setupInstrument(tinyDebugging);

  myTiny.setupOutputServo(outputPin, servoAngleMin, servoAngleMax);

  // set fixed angles, easy version
  myTiny.setServoTempo(0, 30);
  myTiny.setServoTempo(1, 60);
  myTiny.setServoTempo(2, 90);

  // train the KNN algorithm
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  myTiny.identify();
}
