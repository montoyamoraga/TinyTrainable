#ifndef INST1_H
#define INST1_H

// include libraries
#include <Arduino.h>
#include "TinyTrainable.h"
#include <TensorFlowLite.h>


// inheritance
class Inst1:public TinyTrainable {
  public:
    // constructor method
    Inst1();
    // placeholder dummy function
    void print1();
};

#endif
