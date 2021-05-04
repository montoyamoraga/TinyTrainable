// include header file
#include "OutputBuzzer.h"

OutputBuzzer::OutputBuzzer() {}

// methods for TinyTrainable
void OutputBuzzer::playOutput(int classification) {
  getBuzzerParam(classification, _buzzerParams);
  tone(_outputPinBuzzer, _buzzerParams[0], _buzzerParams[1]);
}

void OutputBuzzer::setupOutputBuzzer(int outputPin) {
  _outputPinBuzzer = outputPin;
  pinMode(_outputPinBuzzer, OUTPUT);
  tiny->debugPrint("setup output pin");
}

// modifies the input array to contain a buzzer frequency and duration (in that
// order) for the indicated object
void OutputBuzzer::getBuzzerParam(int object, int buzzerParamArray[]) {
  switch (_buzzerFreqMode) {
  case singleParam:
    buzzerParamArray[0] = _buzzerFrequencies[object];
    break;
  case rangeParam:
    buzzerParamArray[0] =
        random(_buzzerFrequenciesMin[object], _buzzerFrequenciesMax[object]);
    break;
  case randomParam:
    int randomFreqIndex = rand() % _buzzerFrequenciesArraysSizes[object];
    buzzerParamArray[0] = *(_buzzerFrequenciesArrays[object] + randomFreqIndex);
    break;
  }
  switch (_buzzerDurationMode) {
  case singleParam:
    buzzerParamArray[1] = _buzzerDurations[object];
    break;
  case rangeParam:
    buzzerParamArray[1] =
        random(_buzzerDurationsMin[object], _buzzerFrequenciesMax[object]);
    break;
  case randomParam:
    int randomDurationIndex = rand() % _buzzerDurationsArraysSizes[object];
    buzzerParamArray[1] =
        *(_buzzerDurationsArrays[object] + randomDurationIndex);
    break;
  }
}

void OutputBuzzer::setBuzzerFrequency(int object, int frequency) {
  _buzzerFreqMode = singleParam;
  _buzzerFrequencies[object] = frequency;
}

void OutputBuzzer::setBuzzerFrequency(int object, int freqMin, int freqMax) {
  _buzzerFreqMode = rangeParam;
  _buzzerFrequenciesMin[object] = freqMin;
  _buzzerFrequenciesMax[object] = freqMax;
}

void OutputBuzzer::setBuzzerFrequency(int object, int *arrayFrequencies,
                                      int arrayFreqCount) {
  _buzzerFreqMode = randomParam;
  _buzzerFrequenciesArrays[object] = arrayFrequencies;
  _buzzerFrequenciesArraysSizes[object] = arrayFreqCount;
}

void OutputBuzzer::setBuzzerDuration(int object, int duration) {
  _buzzerDurationMode = singleParam;
  _buzzerDurations[object] = duration;
}

void OutputBuzzer::setBuzzerDuration(int object, int durationMin,
                                     int durationMax) {
  _buzzerDurationMode = rangeParam;
  _buzzerDurationsMin[object] = durationMin;
  _buzzerDurationsMax[object] = durationMax;
}

void OutputBuzzer::setBuzzerDuration(int object, int *arrayDurations,
                                     int arrayDurationCount) {
  _buzzerDurationMode = randomParam;
  _buzzerDurationsArrays[object] = arrayDurations;
  _buzzerDurationsArraysSizes[object] = arrayDurationCount;
}
