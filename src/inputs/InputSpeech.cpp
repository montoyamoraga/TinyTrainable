/// @file InputSpeech.cpp
/// @brief TensorFlow model + input speech

// include header file
#include "InputSpeech.h"

// TODO: include machine learning model
// #include "../assets/modelSpeechDefault.h"

// constructor
void InputSpeech::InputSpeech() {
  _sounds[0] = "";
  _sounds[1] = "";
  _sounds[2] = "";
}

void InputSpeech::setupInstrument(bool serialDebugging) {
  tiny->setupLEDs();

  tiny->_serialDebugging = serialDebugging;

  if (tiny->_serialDebugging) {
    Serial.begin(tiny->_baudRate);
    while(!Serial)
    ;
  }
}

void InputSpeech::speechSetupTF(String sounds[3], const unsigned char *model) {
}

void InputSpeech::identify() {
}
