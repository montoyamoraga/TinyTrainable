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
  virtual void playOutput(int classification) override;
  virtual void setupOutputPrinter() override;
  virtual void setPrinterBaudRate(int rate) override;
  virtual void setPrinterBegin() override;
  virtual void setPrinterPause(int pause) override;
  virtual void setPrinterSleep() override;
  virtual void setPrinterWake() override;

private:
  // instance of Adafruit Thermal Printer, connected to Serial1
  Adafruit_Thermal _printer;
  int _defaultRate = 9600;
};

#endif
