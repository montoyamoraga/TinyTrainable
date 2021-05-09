/// @file OutputLED.h
/// @brief Output LED

#ifndef OUTPUT_LED_H
#define OUTPUT_LED_H

/// @include library Arduino
#include <Arduino.h>

/// @include library Output
#include "Output.h"

/// @include library TinyTrainable
#include "TinyTrainable.h"

/// @class OutputLED
/// @brief OutputLED inherits from Output
class OutputLED : public Output {

public:
  /// @brief constructor
  OutputLED();

  // methods for TinyTrainable
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  // variables
  int _outputPinsLED[3];

  // methods for LED
  virtual void setupOutputLED(int object, int outputPin) override;
};

#endif
