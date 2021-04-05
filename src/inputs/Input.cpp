// include header file
#include "Input.h"

Input::Input() {}

void Input::setupInstrument(bool serialDebugging) {

  TinyTrainable::_serialDebugging = serialDebugging;

  if (_serialDebugging) {
    Serial.begin(9600);
    while (!Serial)
      ;
  }
}
