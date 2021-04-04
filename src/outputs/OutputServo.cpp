// include header file
#include "OutputServo.h"

OutputServo::OutputServo() {}

void OutputServo::setupOutputServo(int outputPin, int angleMin,
                                     int angleMax) {
  // TODO: add comments about each line

  _outputPinServo = outputPin;
  _servoAngleMin = angleMin;
  _servoAngleMax = angleMax;

  pinMode(_outputPinServo, OUTPUT);
  _servo.attach(_outputPinServo);
}
