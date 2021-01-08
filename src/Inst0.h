#ifndef _INST0_H_
#define _INST0_H_

// installed libraries included with <>
#include <Arduino.h>
#include <Arduino_KNN.h>

// local libraries included with ""
#include "TinyTrainable.h"

// rather than using numbers to represent the different output modes, using 
// an enum makes the code more readable in if and switch statements
enum OutputMode {usbOut, midiOut, pinOut};

// inheriting the class TinyTrainable as public
class Inst0 : public TinyTrainable
{
  public:
    Inst0();
    void setupInstrument(OutputMode mode, bool serialDebugging);
    void setupMidi(byte midiChannelDec, byte midiVelocity);
    void setupPin(int outputPin, long noteDuration);
    void setNotes(int note1, int note2, int note3);
    void setLabels(String object1, String object2, String object3);
    void trainKNN(int k, int examplesPerClass, float colorThreshold);
    void identify();
  private:
    void readColor(float color[]);
    OutputMode _outputMode;
    KNNClassifier _myKNN;
    //    long _noteDuration;
    int _notes[3];
    int _previousClassification;
    String _labels[3];
    int _k;
    float _colorThreshold;
    float _colorReading[3];
};

#endif
