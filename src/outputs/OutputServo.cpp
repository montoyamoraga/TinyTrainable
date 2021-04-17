// include header file
#include "OutputServo.h"

// constructor
OutputServo::OutputServo() {}

// methods for TinyTrainable
void OutputServo::playOutput(int classification) { 
  // move the servo
  moveServo(classification);
  }

void OutputServo::setupOutputServo(int outputPin, int angleMin, int angleMax) {

  // define output servo
  _outputPinServo = outputPin;

  // define angleMin and angleMax
  _servoAngleMin = angleMin;
  _servoAngleMax = angleMax;

  // pinMode is an Arduino function
  pinMode(_outputPinServo, OUTPUT);
  _servo.attach(_outputPinServo);
}

void OutputServo::setServoTempo(int object, int tempo) {
  // divide by 2 because servo moves twice per cycle
  _servoPauses[object] = bpmToMs(tempo) / 2;
}

void OutputServo::moveServo(int classification) {
  unsigned long servoPause = _servoPauses[classification];
  // update current time
  _servoTimeNow = millis();

  // if enough time has passed
  if (_servoTimeNow - _servoTimePrevious >= servoPause) {
    int angle =
        _servoAngleCurrent == _servoAngleMin ? _servoAngleMax : _servoAngleMin;
    // update _servoTimePrevious
    _servoTimePrevious = _servoTimeNow;
    _servo.write(angle);
    _servoAngleCurrent = angle;

    // if (random(1000)/1000.0 < servoChance) {
    // servoPositionsIndex = (servoPositionsIndex + 1);
    // servoPositionsIndex = servoPositionsIndex %
    // (sizeof(servoPositions)/sizeof(servoPositions[0]));
    // _servo.write(angle);
    // }
  }
}

// function to conver from beats per minute to ms per beat
int OutputServo::bpmToMs(int tempo) {
  int ms = 60000 / tempo;
  // return result
  return ms;
}
