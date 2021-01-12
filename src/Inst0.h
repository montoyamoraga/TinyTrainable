#ifndef INST0_H
#define INST0_H

// installed libraries included with <>
#include <Arduino.h>
#include <Arduino_KNN.h>

// local libraries included with ""
#include "TinyTrainable.h"

// instead of using numbers to represent the different output modes,
// enum makes the code more readable in if and switch statements
enum OutputMode {usbOut = 0, midiOut = 1, pinOut = 2};

// inheriting the class TinyTrainable as public
class Inst0:public TinyTrainable
{
  public:
    // constructor
    Inst0();
    void setupInstrument(OutputMode mode, bool serialDebugging);
    // void setupMIDI(byte midiChannelDec, byte midiVelocity);
    void setupPin(int outputPin, long noteDuration);
    void setFrequencies(int note0, int note1, int note2);
    void setLabels(String object0, String object1, String object2);
    void trainKNN(int k, int examplesPerClass, float colorThreshold);
    void identify();
  private:
    void readColor(float color[]);
    OutputMode _outputMode;
    KNNClassifier _myKNN;
    long _noteDuration;
    int _notes[3];
    int _previousClassification;
    String _labels[3];
    int _k;
    float _colorThreshold;
    float _colorReading[3];
};

#endif
