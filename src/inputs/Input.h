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
  virtual ~Input() {}
  virtual void setupInstrument(bool serialDebugging) {}
  virtual void identify() {}

  // color
  virtual void trainKNN(int k, int examplesPerClass, float colorThreshold,
                        String objects[3]) {}

  // gesture
  virtual void setupTF(String gestures[3]) {}
  virtual void gesturePrintHeader() {}

  TinyTrainable *tiny = nullptr;
};

#endif
