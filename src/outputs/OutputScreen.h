/// @file OutputScreen.h
/// @brief Output screen

#ifndef OUTPUT_SCREEN_H
#define OUTPUT_SCREEN_H

/// @include library Arduino
#include <Arduino.h>

/// @include library Output
#include "Output.h"

/// @include library TinyTrainable
#include "TinyTrainable.h"

/// @include library SPI for screen
#include <SPI.h>

/// @include library Wire for screen
#include <Wire.h>

/// @include library Adafruit_GFX for screen
#include <Adafruit_GFX.h>

/// @include library Adafruit_SSD1306 for screen
#include <Adafruit_SSD1306.h>

/// @class OutputScreen
/// @brief OutputScreen inherits from Output
class OutputScreen : public Output {

public:
  /// @brief constructor
  OutputScreen();

  // TinyTrainable methods
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  // variables
  int _outputPinScreen = -1;
};

#endif
