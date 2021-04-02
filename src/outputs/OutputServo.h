#ifndef OUTPUT_SERVO_H
#define OUTPUT_SERVO_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include TinyTrainable library
// #include "TinyTrainable.h"

// include library for output with servo motors
#include <Servo.h>

class OutputServo : public Output {

  // variables for outputServo
public:
  // constructor
  OutputServo();

    Servo _servo;
    int _outputPinServo = -1;
    int _servoAngleCurrent = 0;
    int _servoAngleMin = 0;
    int _servoAngleMax = 180;
    unsigned long _servoPauses[3];
    // float _servoChances[3];
    unsigned long _servoTimePrevious = 0;
    unsigned long _servoTimeNow = 0;

  //   // methods for servo
  //   void setupOutputServo(int outputPin, int angleMin, int angleMax);
  //   // for servo tempo in bpm
  //   void setServoTempo(int object, int tempo);
  //   // for servo movement
  //   void moveServo(int classification);
  //   int bpmToMs(int tempo);
};

#endif
