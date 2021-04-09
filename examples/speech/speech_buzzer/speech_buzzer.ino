/// @file gesture_buzzer.ino
/// @brief input gesture with output buzzer

// define input and output
#define INPUT_SPEECH
#define OUTPUT_BUZZER

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny(new InputSpeech(), new OutputBuzzer());

// constants for the hardware
const int outputPin = 8;

// constant for debugging
const bool tinyDebugging = true;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

void setup() {
  // set debugging over serial port
  myTiny.setupInstrument(tinyDebugging);

  // set its output
  myTiny.setupOutputBuzzer(outputPin);

}

void loop() {}
