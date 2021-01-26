#ifndef INST2_H
#define INST2_H

#include <Arduino.h>
#include "TinyTrainable.h"
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_error_reporter.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include <tensorflow/lite/version.h>


// inheritance
class Inst2:public TinyTrainable {
  public:
    // constructor
    Inst2();
    // placeholder dummy function
    void print2();
};

#endif
