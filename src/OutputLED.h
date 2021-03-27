#ifndef OUTPUT_LED_H
#define OUTPUT_LED_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include TinyTrainable library
// #include "TinyTrainable.h"

class OutputLED : public Output {

public:
  // constructor
  OutputLED();
  int _outputPinsLED[3];

  // TODO: methods for outputLED
  void setupOutputLED(int outputPin0, int outputPin1, int outputPin2);
};

#endif
