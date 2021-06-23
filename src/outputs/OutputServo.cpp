/// @file OutputServo.cpp
/// @brief Output servo

// include header file
#include "OutputServo.h"

// constructor
OutputServo::OutputServo() {}

void OutputServo::setupOutputTest() {
  //   moveServo(0);
}

// methods for TinyTrainable
void OutputServo::playOutput(int classification) {
  // move the servo
  moveServo(classification);
}

void OutputServo::setupOutputServo(int outputPin) {

  pinMode(LED_BUILTIN, OUTPUT);
  // define output servo
  _outputPinServo = outputPin;

  // define default angleMin and angleMax
  _servoAngleMin = 0;
  _servoAngleMax = 30;

  // pinMode is an Arduino function
  pinMode(_outputPinServo, OUTPUT);

  // move to initial position
  _servo.write(_servoAngleCurrent);

  // initialize servo pauses
  for (int i = 0; i < 3; i++) {
    _servoPauses[i] = 1000;
  }
}

void OutputServo::setServoTempo(int object, int tempo) {
  _servoPauses[object] = bpmToMs(tempo) - _servoMoveDuration;
}

void OutputServo::moveServo(int classification) {
  unsigned long servoPause = _servoPauses[classification];

  // update current time
  _servoTimeNow = millis();

  bool isPaused = _servoAngleCurrent == _servoAngleMin;
  // if enough time has passed
  if ((isPaused && _servoTimeNow - _servoTimePrevious >= servoPause) ||
      (!isPaused && _servoTimeNow - _servoTimePrevious >= _servoMoveDuration)) {
    int angle = isPaused ? _servoAngleMax : _servoAngleMin;
    // update _servoTimePrevious
    _servoTimePrevious = _servoTimeNow;
    if (isPaused) {
      servoAttach();
    }
    _servo.write(angle);
    _servoAngleCurrent = angle;
  } else {
    if (isPaused && _servoTimeNow - _servoTimePrevious >= _servoMoveDuration) {
      servoDetach();
    }
  }
}

void OutputServo::servoAttach() {
  if (!_isAttached) {
    _isAttached = true;
    _servo.attach(_outputPinServo);
    digitalWrite(LED_BUILTIN, HIGH);
  }
}

void OutputServo::servoDetach() {
  if (_isAttached) {
    _isAttached = false;
    _servo.detach();
    digitalWrite(LED_BUILTIN, LOW);
  }
}

// function to conver from beats per minute to ms per beat
int OutputServo::bpmToMs(int tempo) {
  // if tempo is valid, do it
  if (tempo > 0) {
    int ms = 60000 / tempo;
    // return result
    return ms;
  }
  // if not valid, make it really slow
  else {
    return 10000;
  }
}

void OutputServo::setServoMaxAngle(int angle) { _servoAngleMax = angle; }

void OutputServo::setServoMinAngle(int angle) { _servoAngleMin = angle; }

int OutputServo::getServoMaxAngle() { return _servoAngleMax; }
int OutputServo::getServoMinAngle() { return _servoAngleMin; }
