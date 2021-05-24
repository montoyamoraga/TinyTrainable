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

// constants for OLED screen
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C

/// @class OutputScreen
/// @brief OutputScreen inherits from Output
class OutputScreen : public Output {

public:
  /// @brief constructor
  OutputScreen();

  /// @brief destructor
  ~OutputScreen();

  // TinyTrainable methods
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  virtual void setupOutputScreen() override;
  virtual void screenDrawWelcome() override;

  // variables
  int _outputPinScreen = -1;

  int _screenWidth = 128;
  int _screenHeight = 32;
  int _oledReset = 4;

  // instance of Adafruit_SSD1306
  Adafruit_SSD1306 *_screen = nullptr;
};

#endif
