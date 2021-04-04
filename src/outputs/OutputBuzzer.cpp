// include header file
#include "OutputBuzzer.h"

OutputBuzzer::OutputBuzzer() {}

// methods for TinyTrainable
void OutputBuzzer::playOutput(int classification) {
    getBuzzerParam(classification, _buzzerParams);
    tone(_outputPinBuzzer, _buzzerParams[0], _buzzerParams[1]);
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
    buzzerParamArray[0] = *(_buzzerFrequenciesArrays[object] +
    randomFreqIndex); break;
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
