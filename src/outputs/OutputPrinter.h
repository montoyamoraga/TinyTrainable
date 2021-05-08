/// @file OutputPrinter.h
/// @brief Output printer

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

/// @class OutputPrinter
/// @brief OutputPrinter inherits from Output
class OutputPrinter : public Output {
public:
  /// @brief constructor
  OutputPrinter();

  /// @brief destructor
  ~OutputPrinter();

  // TinyTrainable methods
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;
  virtual void setupOutputPrinter() override;
  virtual void setPrinterBaudRate(int rate) override;
  virtual void setPrinterBegin() override;
  virtual void setPrinterPause(int pause) override;
  virtual void setPrinterSleep() override;
  virtual void setPrinterWake() override;
  virtual void setPrinterTest() override;

private:
  // instance of Adafruit Thermal Printer, connected to Serial1
  Adafruit_Thermal *_printer = nullptr;
  int _printerBaudRate = 9600;
};

#endif
