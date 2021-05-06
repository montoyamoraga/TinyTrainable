// include header file
#include "OutputLED.h"

OutputLED::OutputLED() {}

// methods for TinyTrainable
void OutputLED::playOutput(int classification) {
  digitalWrite(_outputPinsLED[0], LOW);
  digitalWrite(_outputPinsLED[1], LOW);
  digitalWrite(_outputPinsLED[2], LOW);
  digitalWrite(_outputPinsLED[classification], HIGH);
}

void OutputLED::setupOutputLED(int object, int outputPin) {
  _outputPinsLED[object] = outputPin;
  pinMode(outputPin, OUTPUT);
}
