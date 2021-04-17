#ifndef OUTPUT_BUZZER_H
#define OUTPUT_BUZZER_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include library TinyTrainable
#include "TinyTrainable.h"

class OutputBuzzer : public Output {

public:
  // constructor
  OutputBuzzer();

  // methods for TinyTrainable
  virtual void playOutput(int classification) override;

  // methods for buzzer
  virtual void setupOutputBuzzer(int outputPin) override;
  virtual void getBuzzerParam(int object, int buzzerParamArray[]) override;
  // for frequencies
  virtual void setBuzzerFrequency(int object, int frequency) override;
  virtual void setBuzzerFrequency(int object, int freqMin, int freqMax) override;
  virtual void setBuzzerFrequency(int object, int *arrayFrequencies,
                          int arrayFreqCount) override;

  // for durations
  virtual void setBuzzerDuration(int object, int duration) override;
  virtual void setBuzzerDuration(int object, int durationMin, int durationMax) override;
  virtual void setBuzzerDuration(int object, int *arrayDurations,
                         int arrayDurationCount) override;

  // methods and variables for outputBuzzer
  int _outputPinBuzzer = -1;
  enum BuzzerMode { singleParam, rangeParam, randomParam, undefParam };
  BuzzerMode _buzzerFreqMode = undefParam;
  BuzzerMode _buzzerDurationMode = undefParam;
  int _buzzerParams[2]; // to hold the freq and duration each loop
                        //   // for singleParam
  int _buzzerFrequencies[3];
  int _buzzerDurations[3];
  //   // for rangeParam
  int _buzzerFrequenciesMin[3];
  int _buzzerFrequenciesMax[3];
  int _buzzerDurationsMin[3];
  int _buzzerDurationsMax[3];
  //   // for randomParam
  int *_buzzerFrequenciesArrays[3];
  int _buzzerFrequenciesArraysSizes[3];
  int *_buzzerDurationsArrays[3];
  int _buzzerDurationsArraysSizes[3];
};

#endif
