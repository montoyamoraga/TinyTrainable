#ifndef OUTPUT_LCD_H
#define OUTPUT_LCD_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include TinyTrainable library
// #include "TinyTrainable.h"

class OutputLCD : public Output {

public:
  // constructor
  OutputLCD();
  int _outputPinLCD = -1;
};

#endif
