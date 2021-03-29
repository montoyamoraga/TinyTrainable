/// @file hello_servo.ino
/// @brief Test servo output

// include all libraries
#include <InputColor.h>
#include <OutputBuzzer.h>
#include <TinyTrainable.h>

// declare instance of input
InputColor myInput;
// declare instance of output
OutputBuzzer myOutput;

// declare instance of a TinyTrainable instrument
TinyTrainable tiny(myInput, myOutput);

const int outputPin = 9;

// for the supplies list servo, these values can be >= 0, <= 180
// these are the values the servo will move between at the given bpm
// going right to the limit can sometimes cause the servo to buzz
const int servoAngleMin = 30;
const int servoAngleMax = 60;

void setup() {
  //  tiny.setupOutputServo(outputPin, servoAngleMin, servoAngleMax);

  // set the tempo (in bpm) for each object
  //  tiny.setServoTempo(0, 60);
  //  tiny.setServoTempo(1, 90);
  //  tiny.setServoTempo(2, 120);
}

void loop() {
  // to see the different tempos, try each output
  //  tiny.playOutput(0);
  // tiny.playOutput(1);
  // tiny.playOutput(2);
}
