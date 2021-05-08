/// @file Input.h
/// @brief Base class for Input

#ifndef INPUT_H
#define INPUT_H

/// @include library Arduino
#include <Arduino.h>

// forwards declare class
class TinyTrainable;

/// @class Input
/// @brief Input base class
class Input {
public:
/// @brief Input destructor
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

  // speech
  virtual void speechSetupTF(String sounds[3], const unsigned char *model = nullptr) {}

 /// @brief pointer to a TinyTrainable instance
  TinyTrainable *tiny = nullptr;
};

#endif
