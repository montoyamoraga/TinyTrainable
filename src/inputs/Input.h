/// @file Input.h
/// @brief Input base class

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
  /// @brief destructor
  virtual ~Input() {}
  virtual void setupInstrument(bool serialDebugging) {}
  virtual void identify() {}

  // color
  virtual void trainKNN(int k, int examplesPerClass, String objects[3]) {}

  // gesture
  virtual void setupGestureModel(String gestures[3],
                                 const unsigned char *model = nullptr) {}
  virtual void gesturePrintHeader() {}
  virtual void gestureReadData() {}
  virtual void gestureSetAcceleration(float newVal) {}
  virtual void gestureSetNumberSamples(int newVal) {}

  // speech
  virtual void setupSpeechModel(String sounds[3],
                                const unsigned char *model = nullptr) {}

  /// @brief pointer to a TinyTrainable instance
  TinyTrainable *tiny = nullptr;
};

#endif
