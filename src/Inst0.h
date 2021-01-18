#ifndef INST0_H
#define INST0_H

// installed libraries included with <>
#include <Arduino.h>
#include <Arduino_KNN.h>

// local libraries included with ""
#include "TinyTrainable.h"

// inheriting the class TinyTrainable as public
class Inst0:public TinyTrainable
{
  public:
    // constructor
    Inst0();

    void setLabels(String object0, String object1, String object2);
    void trainKNN(int k, int examplesPerClass, float colorThreshold);
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
