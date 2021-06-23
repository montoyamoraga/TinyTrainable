/// @file OutputServo.h
/// @brief Output servo

#ifndef OUTPUT_SERVO_H
#define OUTPUT_SERVO_H

/// @include libraryArduino
#include <Arduino.h>

/// @include library Output
#include "Output.h"

/// @include TinyTrainable library
#include "TinyTrainable.h"

/// @include library Servo for servo motors
#include <Servo.h>

/// @class OutputServo
/// @brief OutputServo inherits from Output
class OutputServo : public Output {

  // variables for outputServo
public:
  /// @brief constructor
  OutputServo();

  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  // methods for servo
  // define servo output
  void setupOutputServo(int outputPin);
  //  define for servo tempo in bpm
  void setServoTempo(int object, int tempo);
  // for servo movement
  void moveServo(int classification);
  //   function to convert from beats per minute to milliseconds
  int bpmToMs(int tempo);

  void setServoMaxAngle(int angle);
  void setServoMinAngle(int angle);

  int getServoMaxAngle();
  int getServoMinAngle();

private:
  /// @brief Servo instance
  Servo _servo;

  int _outputPinServo = -1;
  int _servoAngleCurrent = 10;
  int _servoAngleMin = 0;
  int _servoAngleMax = 180;
  unsigned long _servoPauses[3];

  unsigned long _servoTimePrevious = 0;
  unsigned long _servoTimeNow = 0;

  unsigned long _servoMoveDuration = 150;

  bool _isAttached = false;
  void servoAttach();
  void servoDetach();
};

#endif
