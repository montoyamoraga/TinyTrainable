/// @file Input.h
/// @brief Base class for input

#ifndef INPUT_H
#define INPUT_H

// include Arduino library
#include <Arduino.h>

// forwards declare class
class TinyTrainable;

class Input {
public:

  virtual void setupInstrument(bool serialDebugging) {}
  virtual void trainKNN(int k, int examplesPerClass, float colorThreshold,
                        String objects[3]) {}
  virtual void identify() {}

  TinyTrainable *tiny = nullptr;

};

#endif
