#ifndef OUTPUT_PRINTER_H
#define OUTPUT_PRINTER_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include library TinyTrainable
#include "TinyTrainable.h"

// include library for output with Adafruit thermal printer
#include <Adafruit_Thermal.h>

class OutputPrinter : public Output {
public:
  // constructor
  OutputPrinter();

  // TinyTrainable methods
  void playOutput(int classification);

  // TODO: for printer we need several variables
  int _outputPinPrinter = -1;
};

#endif
