/// @file InputGesture.h
/// @brief TensorFlow model + input gesture

#ifndef INPUT_GESTURE_H
#define INPUT_GESTURE_H

// include Arduino library
#include <Arduino.h>

// include library Input
#include "Input.h"

// include library TinyTrainable
#include "TinyTrainable.h"

// include library for IMU sensor
// 3-axis accelerometer, 3-axis gyroscope, 3-axis magnetometer
// https://www.arduino.cc/en/Reference/ArduinoLSM9DS1/
#include <Arduino_LSM9DS1.h>

// include libraries for gesture recognition
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_error_reporter.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include <tensorflow/lite/version.h>

class InputGesture : public Input {
public:

// constructor
InputGesture();

void setupSensorLSM9DS1();
void setupInstrument(bool serialDebugging);

int _previousClassification = -1;
  String _labels[3];
    void identify();

};

#endif
