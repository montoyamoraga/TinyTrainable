/// @file hello_servo.ino
/// @brief test output servo

// define input and output
#define INPUT_NONE
#define OUTPUT_SERVO

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(new Input(), new OutputServo());

// our servo can move between angles 0 and 180 degrees
// we pick angles 30 and 60 as the minimum and maximum position
const int servoAngleMin = 30;
const int servoAngleMax = 60;

// our servo moves between the minimum and maximum angles
// at a desired tempo measured in beats per minute
const int tempo0 = 60;
const int tempo1 = 90;
const int tempo2 = 120;

// constants for the hardware
const int outputPin = 9;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = true;

void setup() {

  myTiny.setupInstrument(tinyDebugging);

  myTiny.setupOutputServo(outputPin, servoAngleMin, servoAngleMax);

  // set the tempo (in bpm) for each object
  myTiny.setServoTempo(0, tempo0);
  myTiny.setServoTempo(1, tempo1);
  myTiny.setServoTempo(2, tempo2);
}

void loop() {
  // to see the different tempos, try each output
  myTiny.playOutput(0);
  //  myTiny.playOutput(1);
  //  myTiny.playOutput(2);
}
