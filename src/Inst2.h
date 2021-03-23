/// @file Inst2.h
/// @brief speech recognition with TensorFlow

#ifndef INST2_H
#define INST2_H

// #define INPUT_SPEECH 1

// include Arduino library
#include <Arduino.h>

// include TinyTrainable library
#include "TinyTrainable.h"

// include TensorFlow Lite Micro library
#ifdef INPUT_SPEECH
  #include <TensorFlowLite.h>
  #include <tensorflow/lite/micro/all_ops_resolver.h>
  #include <tensorflow/lite/micro/micro_error_reporter.h>
  #include <tensorflow/lite/micro/micro_interpreter.h>
  #include <tensorflow/lite/schema/schema_generated.h>
  #include <tensorflow/lite/version.h>
#endif

// inheritance
class Inst2 : public TinyTrainable {
public:
  // constructor
  Inst2();

  void setupInstrument(bool serialDebugging);

  // placeholder dummy function
  void print2();
};

#endif
