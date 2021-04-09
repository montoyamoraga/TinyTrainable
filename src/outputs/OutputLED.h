#ifndef OUTPUT_LED_H
#define OUTPUT_LED_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

class OutputLED : public Output {

public:
  // constructor
  OutputLED();

  // methods for TinyTrainable
  void playOutput(int classification);

  // variables
  int _outputPinsLED[3];

  // methods for LED
  void setupOutputLED(int outputPin0, int outputPin1, int outputPin2);
};

#endif
