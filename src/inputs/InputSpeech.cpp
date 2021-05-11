/// @file InputSpeech.cpp
/// @brief TensorFlow model + input speech

/// @include header file
#include "InputSpeech.h"

/// @include machine learning model
#include "../assets/modelSpeechDefault.h"

InputSpeech::InputSpeech() {
  _sounds[0] = "";
  _sounds[1] = "";
  _sounds[2] = "";
}

void InputSpeech::setupInstrument(bool serialDebugging) {
  tiny->setupLEDs();

  tiny->_serialDebugging = serialDebugging;

  if (tiny->_serialDebugging) {
    Serial.begin(tiny->_baudRate);
    while (!Serial)
      ;
  }
}

void InputSpeech::setupSpeechModel(String sounds[3], const unsigned char *newModel) {
  _sounds[0] = sounds[0];
  _sounds[1] = sounds[1];
  _sounds[2] = sounds[2];

  // load the default model or the custom model
  model = tflite::GetModel((newModel == nullptr) ? modelSpeechDefault : newModel);

}

void InputSpeech::identify() {}
