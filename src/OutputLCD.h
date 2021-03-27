#ifndef OUTPUT_LCD_H
#define OUTPUT_LCD_H

// include Arduino library
#include <Arduino.h>

// include TinyTrainable library
#include "TinyTrainable.h"

class OutputLCD : public TinyTrainable {

public:
  int _outputPinLCD = -1;

};

#endif
