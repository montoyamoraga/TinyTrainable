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
    void setupInstrument(OutputMode mode);
    // void setupMIDI(byte midiChannelDec, byte midiVelocity);
    void setupPin(int outputPin, long noteDuration);
    void setFrequencies(int note0, int note1, int note2);
    void setLabels(String object0, String object1, String object2);
    // TODO: use the builtin LED to signal if instrument is trained or not
    // TODO: maybe use two blinks after it is trained?
    // TODO: add a 'throws exceptions' explanation to the docs
    void trainKNN(int k, int examplesPerClass, float colorThreshold);
    void identify();
  private:
    void readColor(float color[]);
    void checkInst0Setup();
    KNNClassifier _myKNN;
    long _noteDuration;
    int _notes[3];
    int _previousClassification;
    String _labels[3];
    int _k;
    float _colorThreshold;
    float _colorReading[3];
    bool _checkedSetup;
};

#endif
