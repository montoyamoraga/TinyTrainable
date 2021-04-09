#ifndef INPUT_SPEECH_H
#define INPUT_SPEECH_H

// include Arduino library
#include <Arduino.h>

// include Input library
#include "Input.h"

// include TinyTrainable library
#include "TinyTrainable.h"

// include libraries for speech recognition
#include <TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_error_reporter.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include <tensorflow/lite/version.h>

#include "../tensorflow/main_functions.h"
#include "../tensorflow/command_responder.h"
#include "../tensorflow/feature_provider.h"
#include "../tensorflow/micro_features_micro_model_settings.h"
#include "../tensorflow/micro_features_model.h"
#include "../tensorflow/recognize_commands.h"

// Globals, used for compatibility with Arduino-style sketches.
namespace {
tflite::ErrorReporter* error_reporter = nullptr;
const tflite::Model* model = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* model_input = nullptr;
FeatureProvider* feature_provider = nullptr;
RecognizeCommands* recognizer = nullptr;
int32_t previous_time = 0;

// Create an area of memory to use for input, output, and intermediate arrays.
// The size of this will depend on the model you're using, and may need to be
// determined by experimentation.
constexpr int kTensorArenaSize = 10 * 1024;
uint8_t tensor_arena[kTensorArenaSize];
int8_t feature_buffer[kFeatureElementCount];
int8_t* model_input_buffer = nullptr;
}  // namespace

class InputSpeech : public Input {
public:
};

#endif
