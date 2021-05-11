/// @file InputGesture.h
/// @brief TensorFlow model + input gesture

#ifndef INPUT_GESTURE_H
#define INPUT_GESTURE_H

/// @include library Arduino
#include <Arduino.h>

/// @include library TinyTrainable
#include "TinyTrainable.h"

/// @include library Input
#include "Input.h"

/// @include library for input sensor
// https://www.arduino.cc/en/Reference/ArduinoLSM9DS1/
#include <Arduino_LSM9DS1.h>

/// @include library for machine learning
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_error_reporter.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include <tensorflow/lite/version.h>

/// @class InputGesture
/// @brief InputGesture inherits from Input
class InputGesture : public Input {
public:

  /// @brief constructor
  InputGesture();

  virtual void setupInstrument(bool serialDebugging) override;
  virtual void setupGestureModel(String gestures[3],
                              const unsigned char *model = nullptr) override;

  virtual void gesturePrintHeader() override;
  virtual void gestureReadData() override;
  virtual void gestureSetAcceleration(float newVal) override;
  virtual void gestureSetNumberSamples(int newVal) override;

    virtual void identify() override;

private:
  void setupGestureSensor();

  /// @brief threshold of significance measured in G's
  float _accelerationThreshold = 2.5;

  /// @brief number of samples per motion
  int _numSamples = 119;

  // initialize as if sampling has already been done
  int _samplesRead = _numSamples;

  // variables for reading
  float _aX;
  float _aY;
  float _aZ;
  float _gX;
  float _gY;
  float _gZ;

  // TFLite setup
  const int NUM_GESTURES = 3;
  String _gestures[3];

  // variables for TensorFlow Lite
  tflite::MicroErrorReporter tflErrorReporter;
  tflite::AllOpsResolver tflOpsResolver;
  const tflite::Model *tflModel = nullptr;
  tflite::MicroInterpreter *tflInterpreter = nullptr;
  TfLiteTensor *tflInputTensor = nullptr;
  TfLiteTensor *tflOutputTensor = nullptr;

  // TODO - account for this size needing to be changed? add a method?
  // Create a static memory buffer for TFLM, the size may need to
  // be adjusted based on the model you are using
  static constexpr int tensorArenaSize = 8 * 1024;
  byte tensorArena[tensorArenaSize];

  /// @brief acceleration in x, y, z 
  float aX, aY, aZ;
  /// @brief gravity in x, y, z
  float gX, gY, gZ; 

  /// @brief header for gesture database
  const String _gestureHeader = "aX,aY,aZ,gX,gY,gZ";

  /// @brief  number of decimals for floating point numbers
  const int _floatDecimals = 3;
};

#endif
