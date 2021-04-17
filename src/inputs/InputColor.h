/// @file InputColor.h
/// @brief K-nearest neighbors algorithm + color input

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

class InputColor : public Input {

public:
  // constructor
  InputColor();

  void setupSensorAPDS9960();

  // TODO: keyword override doesnt work with all compilers
  // override is a help for debugging
  virtual void setupInstrument(bool serialDebugging) override;
  virtual void trainKNN(int k, int examplesPerClass, float colorThreshold, String objects[3]) override;

  virtual void identify() override;

  KNNClassifier _myKNN;
  String _labels[3];
  int _previousClassification = -1;



  // private:
  void readColor(float color[]);
  //   void checkInst0Setup();

  int _k = -1;
  float _colorThreshold;
  float _colorReading[3];
  bool _checkedSetup = false;
};

#endif
