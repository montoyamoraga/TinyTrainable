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
// #include <TensorFlowLite.h>
// #include <tensorflow/lite/micro/all_ops_resolver.h>
// #include <tensorflow/lite/micro/micro_error_reporter.h>
// #include <tensorflow/lite/micro/micro_interpreter.h>
// #include <tensorflow/lite/schema/schema_generated.h>
// #include <tensorflow/lite/version.h>

class InputGesture : public Input {
public:
  // constructor
  InputGesture();

  // TODO: add virtual void declarations in TinyTrainable.h
  void setupSensorLSM9DS1();
  void setupInstrument(bool serialDebugging);
  void setupGestures(String gestures[3]);
  void setupTF(float accelerationThreshold, int numSamples);
  void classify();

  int _previousClassification = -1;
  String _labels[3];
  void identify();
  String _gestures[3];

  // TODO: copy-pasted from Peter's fork
  // private:
  //   // tflite setup
  //   const int NUM_GESTURES = 3;
  //   float _accelerationThreshold = -1;
  //   int _numSamples = -1;
  //   int _samplesRead = -1;
  //   String _gestures[3];

  //   // tflite variables
  //   tflite::MicroErrorReporter tflErrorReporter;
  //   tflite::AllOpsResolver tflOpsResolver;
  //   const tflite::Model *tflModel = nullptr;
  //   tflite::MicroInterpreter *tflInterpreter = nullptr;
  //   TfLiteTensor *tflInputTensor = nullptr;
  //   TfLiteTensor *tflOutputTensor = nullptr;

  //   // TODO - account for this size needing to be changed? add a method?
  //   // Create a static memory buffer for TFLM, the size may need to
  //   // be adjusted based on the model you are using
  //   static constexpr int tensorArenaSize = 8 * 1024;
  //   byte tensorArena[tensorArenaSize];

  //   // classification variables
  //   float aX, aY, aZ, gX, gY, gZ;  // acceleration and gravity in x, y, z
};

#endif
