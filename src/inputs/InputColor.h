/// @file InputColor.h
/// @brief K-nearest neighbors algorithm + input color

#ifndef INPUT_COLOR_H
#define INPUT_COLOR_H

// include Arduino library
#include <Arduino.h>

// include Input library
#include "Input.h"

// include TinyTrainable library
#include "TinyTrainable.h"

// include library for proximity and light sensor
// https://www.arduino.cc/en/Reference/ArduinoAPDS9960
#include <Arduino_APDS9960.h>

// import Arduino KNN library
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
