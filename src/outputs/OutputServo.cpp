// include header file
#include "OutputServo.h"


// constructor
OutputServo::OutputServo() {}

void OutputServo::setupOutputServo(int outputPin, int angleMin,
                                     int angleMax) {
  // TODO: add comments about each line

  // define output servo
  _outputPinServo = outputPin;

  // define angleMin and angleMax
  _servoAngleMin = angleMin;
  _servoAngleMax = angleMax;

  // pinMode is an Arduino function
  pinMode(_outputPinServo, OUTPUT);
  _servo.attach(_outputPinServo);
}
