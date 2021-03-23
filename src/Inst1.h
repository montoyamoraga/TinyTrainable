/// @file Inst1.h
/// @brief gesture recognition using TensorFlow

#ifndef INST1_H
#define INST1_H

#define INPUT_GESTURE 1

// include Arduino libraries
#include <Arduino.h>

// include TinyTrainable library
#include "TinyTrainable.h"

// include libraries for gesture recognition
#ifdef INPUT_GESTURE
  #include <TensorFlowLite.h>
  #include <tensorflow/lite/micro/all_ops_resolver.h>
  #include <tensorflow/lite/micro/micro_error_reporter.h>
  #include <tensorflow/lite/micro/micro_interpreter.h>
  #include <tensorflow/lite/schema/schema_generated.h>
  #include <tensorflow/lite/version.h>
#endif

// inheritance
class Inst1 : public TinyTrainable {
public:
  // constructor method
  Inst1();

  void setupInstrument(bool serialDebugging);

  // placeholder dummy function
  void print1();
};

#endif
