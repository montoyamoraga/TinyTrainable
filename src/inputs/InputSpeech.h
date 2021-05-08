/// @file InputSpeech.h
/// @brief TensorFlow model + input speech

#ifndef INPUT_SPEECH_H
#define INPUT_SPEECH_H

/// @include library Arduino
#include <Arduino.h>

/// @include TinyTrainable library
#include "TinyTrainable.h"

/// @include library Input
#include "Input.h"



// include libraries for speech recognition
// #include <TensorFlowLite.h>
// #include <tensorflow/lite/micro/all_ops_resolver.h>
// #include <tensorflow/lite/micro/micro_error_reporter.h>
// #include <tensorflow/lite/micro/micro_interpreter.h>
// #include <tensorflow/lite/schema/schema_generated.h>
// #include <tensorflow/lite/version.h>

// #include "../tensorflow/main_functions.h"
// #include "../tensorflow/command_responder.h"
// #include "../tensorflow/feature_provider.h"
// #include "../tensorflow/micro_features_micro_model_settings.h"
// #include "../tensorflow/micro_features_model.h"
// #include "../tensorflow/recognize_commands.h"

/// @class InputSpeech
/// @brief InputSpeech inherits from Input
class InputSpeech : public Input {
public:

  virtual void speechSetupTF(String sounds[3], const unsigned char *model = nullptr) override;

  virtual void identify() override;


};

#endif
