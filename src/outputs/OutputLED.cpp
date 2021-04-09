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

void OutputLED::setupOutputLED(int outputPin0, int outputPin1, int outputPin2) {
  _outputPinsLED[0] = outputPin0;
  _outputPinsLED[1] = outputPin1;
  _outputPinsLED[2] = outputPin2;
  pinMode(outputPin0, OUTPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
}
