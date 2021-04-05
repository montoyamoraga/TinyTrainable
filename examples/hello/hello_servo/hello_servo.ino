/// @file hello_servo.ino
/// @brief Test output with servo

// define input and output
#define INPUT_NONE
#define OUTPUT_SERVO

// include TinyTrainable library
#include <TinyTrainable.h>

// declare instance of input
// Input myInput;
// declare instance of output
// OutputServo myOutput;

// declare instance of a TinyTrainable instrument
// TinyTrainable myTiny(myInput, myOutput);
// polymorphism
TinyTrainable myTiny(new Input(), new OutputServo());

const int outputPin = 9;

// for the supplies list servo, these values can be >= 0, <= 180
// these are the values the servo will move between at the given bpm
// going right to the limit can sometimes cause the servo to buzz
const int servoAngleMin = 30;
const int servoAngleMax = 60;

void setup() {
  myTiny.setupOutputServo(outputPin, servoAngleMin, servoAngleMax);

  // set the tempo (in bpm) for each object
  //  myTiny.setServoTempo(0, 60);
  //  myTiny.setServoTempo(1, 90);
  //  myTiny.setServoTempo(2, 120);
}

void loop() {
  // to see the different tempos, try each output
  //  myTiny.playOutput(0);
  // myTiny.playOutput(1);
  // myTiny.playOutput(2);
}
