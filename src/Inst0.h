/// @file Inst0.h
/// @brief Arduino library for Tiny Trainable Instruments

#ifndef INST0_H
#define INST0_H

// import libraries
#include "TinyTrainable.h"
#include <Arduino.h>
#include <Arduino_KNN.h>

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
