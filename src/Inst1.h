/// @file Inst1.h
/// @brief gesture recognition using TensorFlow

#ifndef INST1_H
#define INST1_H

// include libraries
#include "TinyTrainable.h"
#include <Arduino.h>
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_error_reporter.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include <tensorflow/lite/version.h>

tflite::MicroErrorReporter tflErrorReporter;
tflite::AllOpsResolver tflOpsResolver;

// inheritance
class Inst1 : public TinyTrainable {
public:
  // constructor method
  Inst1();

  void setupInstrument(bool serialDebugging, String gestures[3]);
  void setupTF(float accelerationThreshold, int numSamples);
  void classify();

private:
  // tflite setup
  const int NUM_GESTURES = 3;
  float _accelerationThreshold = -1;
  int _numSamples = -1;
  int _samplesRead = -1;
  String _gestures[3];

  // tflite variables
  // tflite::MicroErrorReporter tflErrorReporter;
  // tflite::AllOpsResolver tflOpsResolver;
  const tflite::Model *tflModel = nullptr;
  tflite::MicroInterpreter *tflInterpreter = nullptr;
  TfLiteTensor *tflInputTensor = nullptr;
  TfLiteTensor *tflOutputTensor = nullptr;

  // TODO - account for this size needing to be changed? add a method?
  // Create a static memory buffer for TFLM, the size may need to
  // be adjusted based on the model you are using
  static constexpr int tensorArenaSize = 8 * 1024;
  // alignas(16) byte tensorArena[tensorArenaSize];
  byte tensorArena[tensorArenaSize] __attribute__((aligned(16)));

  // classification variables
  float aX, aY, aZ, gX, gY, gZ;  // acceleration and gravity in x, y, z
};

#endif
