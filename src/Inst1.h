/// @file Inst1.h
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang
/// @date November 2020

#ifndef INST1_H
#define INST1_H

// include libraries
#include "TinyTrainable.h"
#include <Arduino.h>

// TODO: uncommmented, testing compilation time
// #include <TensorFlowLite.h>
// #include <tensorflow/lite/micro/all_ops_resolver.h>
// #include <tensorflow/lite/micro/micro_error_reporter.h>
// #include <tensorflow/lite/micro/micro_interpreter.h>
// #include <tensorflow/lite/schema/schema_generated.h>
// #include <tensorflow/lite/version.h>

// inheritance
class Inst1 : public TinyTrainable {
public:
  // constructor method
  Inst1();

  void setupInstrument();

  // placeholder dummy function
  void print1();
};

#endif
