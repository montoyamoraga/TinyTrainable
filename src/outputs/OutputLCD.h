/// @file OutputLCD.h
/// @brief Output LCD

#ifndef OUTPUT_LCD_H
#define OUTPUT_LCD_H

/// @include library Arduino
#include <Arduino.h>

/// @include library Output
#include "Output.h"

/// @include library TinyTrainable
#include "TinyTrainable.h"

/// @class OutputLCD
/// @brief OutputLCD inherits from Output
class OutputLCD : public Output {

public:
  /// @brief constructor
  OutputLCD();

  // TinyTrainable methods
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  // variables
  int _outputPinLCD = -1;
};

#endif
