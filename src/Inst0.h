/// @file Inst0.h
/// @brief K-nearest neighbors algorithm + color input

#ifndef INST0_H
#define INST0_H

// TODO: temporary fix
#define INPUT_COLOR 1
// include options
#include "options.h"

// import Arduino library
#include <Arduino.h>

// import Tiny Trainable library
#include "TinyTrainable.h"

#ifdef INPUT_COLOR
// import Arduino KNN library
#include <Arduino_KNN.h>
#endif

// inherit from the class TinyTrainable
class Inst0 : public TinyTrainable {

public:
  // constructor
  Inst0();

  void setupInstrument(bool serialDebugging);
  void trainKNN(int k, int examplesPerClass, float colorThreshold,
                String objects[3]);
  void identify();

private:
  void readColor(float color[]);
  void checkInst0Setup();

  KNNClassifier _myKNN;
  int _previousClassification = -1;
  String _labels[3];
  int _k = -1;
  float _colorThreshold;
  float _colorReading[3];
  bool _checkedSetup = false;
};

#endif
