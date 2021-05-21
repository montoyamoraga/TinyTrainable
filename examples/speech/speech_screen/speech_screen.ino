// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_SPEECH, OUTPUT_SCREEN);

// constants for the hardware
const int outputPin = 8;

// constant for debugging
const bool debugOn = true;

String MY_WORDS[3] = {"word0", "word1", "word2"};

void setup() {
  // set debugging over serial port
  myTiny.setupInstrument(debugOn);

  // set its output
  //   myTiny.setupOutputBuzzer(outputPin);
}

void loop() {}
