/// @file Input.h
/// @brief Base class for input

#ifndef INPUT_H
#define INPUT_H

// include Arduino library
#include <Arduino.h>

// declare class
class TinyTrainable;

class Input {

  // friend classes can access protected and private members
  friend class TinyTrainable;

  virtual void setupInstrument(bool serialDebugging) {}
  virtual void trainKNN(int k, int examplesPerClass, float colorThreshold,
                        String objects[3]) {}
  virtual void identify() {}

protected:
  TinyTrainable *tiny = nullptr;

public:
  Input();
};

#endif
