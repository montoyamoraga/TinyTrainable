#ifndef OUTPUT_LCD_H
#define OUTPUT_LCD_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include TinyTrainable library
#include "TinyTrainable.h"

/// @class OutputLCD
/// @brief OutputLCD inherits from Output
class OutputLCD : public Output {

public:
  // constructor
  OutputLCD();

  // TinyTrainable methods
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  // variables
  int _outputPinLCD = -1;
};

#endif
