#ifndef OUTPUT_SERIAL_H
#define OUTPUT_SERIAL_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include library TinyTrainable
#include "TinyTrainable.h"

/// @class OutputSerial
/// @brief OutputSerial inherits from Output
class OutputSerial : public Output {
public:
  // constructor
  OutputSerial();

  // TinyTrainable methods
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  // methods for output with serial
  virtual void setupOutputSerial() override;
};

#endif
