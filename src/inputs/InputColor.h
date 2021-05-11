/// @file InputColor.h
/// @brief K-nearest neighbors algorithm + input color

#ifndef INPUT_COLOR_H
#define INPUT_COLOR_H

/// @include library Arduino
#include <Arduino.h>

/// @include library TinyTrainable
#include "TinyTrainable.h"

/// @include library Input
#include "Input.h"

/// @include library Arduino_APDS9960 for color and distance input
// https://www.arduino.cc/en/Reference/ArduinoAPDS9960
#include <Arduino_APDS9960.h>

/// @include library Arduino KNN for machine learning
#include <Arduino_KNN.h>

/// @class InputColor
/// @brief InputColor inherits from Input
class InputColor : public Input {

public:
  /// @brief constructor
  InputColor();

  /// @brief setup color and proximity sensor
  void setupSensorAPDS9960();

  virtual void setupInstrument(bool serialDebugging) override;
  virtual void trainKNN(int k, int examplesPerClass, float colorThreshold,
                        String objects[3]) override;
  virtual void identify() override;

  // @brief instance of K-nearest neighbors algorithm
  KNNClassifier _myKNN;
  String _labels[3];
  int _previousClassification = -1;

  void readColor(float color[]);

  /// @brief parameter for K-nearest neighbors algorithm
  int _k = -1;

  float _colorThreshold;
  float _colorReading[3];
  bool _checkedSetup = false;
};

#endif
