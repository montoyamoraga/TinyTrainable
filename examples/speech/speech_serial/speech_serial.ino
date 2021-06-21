// include speech model
#include "mySpeechModel.h"

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_SPEECH, OUTPUT_SERIAL);

// constant for debugging
const bool debugOn = true;

String MY_WORDS[3] = {"agua", "burbuja", "cielo"};

// setup() runs once, at the beginning
void setup() {

  // set debugging over serial port
  myTiny.setupInstrument(debugOn);

  // setup the serial output
  myTiny.setupOutputSerial();

  // use the default model for speech recognition
  myTiny.setupSpeechModel(MY_WORDS);
  // or use this line to include your own model
  // myTiny.setupSpeechModel(MY_WORDS, mySpeechModel);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the item and respond
  myTiny.identify();
}
