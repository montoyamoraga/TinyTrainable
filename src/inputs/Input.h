#ifndef INPUT_H
#define INPUT_H

// include Arduino library
#include <Arduino.h>

class Input {
public:
  Input();
  void setupInstrument(bool serialDebugging);
};

#endif
