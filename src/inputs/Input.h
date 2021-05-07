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
  virtual void gestureSetupTF(String gestures[3],
                       const unsigned char *model = nullptr) {}
  virtual void gesturePrintHeader() {}
  virtual void gestureReadData() {}

  TinyTrainable *tiny = nullptr;
};

#endif
