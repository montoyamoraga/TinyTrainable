#ifndef OUTPUT_SERIAL_H
#define OUTPUT_SERIAL_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include library TinyTrainable
#include "TinyTrainable.h"

class OutputSerial : public Output {
public:
  // constructor
  OutputSerial();

  // TinyTrainable methods
  void playOutput(int classification);

  // methods for output with serial
  void setupOutputSerial();
};

#endif
