#ifndef OUTPUT_H
#define OUTPUT_H

// include Arduino library
#include <Arduino.h>

// this is to guard against circular include
// TODO: research the name of this
class TinyTrainable;

class Output {

  friend class TinyTrainable;

  // methods for output
  virtual void playOutput(int classification){}

  // methods for buzzer
  virtual void setupOutputBuzzer(int outputPin) {}
  virtual void getBuzzerParam(int object, int buzzerParamArray[]) {}
  // for frequencies
  virtual void setBuzzerFrequency(int object, int frequency) {}
  virtual void setBuzzerFrequency(int object, int freqMin, int freqMax) {}
  virtual void setBuzzerFrequency(int object, int *arrayFrequencies,
                                  int arrayFreqCount) {}
  virtual void setBuzzerDuration(int object, int duration) {}
  virtual void setBuzzerDuration(int object, int durationMin, int durationMax) {
  }
  virtual void setBuzzerDuration(int object, int *arrayDurations,
                                 int arrayDurationCount) {}

protected:
  TinyTrainable *tiny = nullptr;

public:
  // constructor
  Output();
};

#endif
