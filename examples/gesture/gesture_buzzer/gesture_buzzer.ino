// include gesture model
#include "myGestureModel.h"

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_GESTURE, OUTPUT_BUZZER);

// constants for the hardware
const int outputPin = 2;

// constant for debugging
const bool debugOn = true;

// the following looks funny since sizeof returns byte size
// int freqArrayLength = sizeof(freqArray0)/sizeof(*freqArray0);
int paramArrayLength = 6;

// array to map gesture index to a name
String MY_GESTURES[] = {"gesture0", "gesture1", "gesture2"};

// setup() runs once, at the beginning
void setup() {
  // set debugging over serial port
  myTiny.setupInstrument(debugOn);

  // set its output (see buzzer examples for more buzzer options)
  myTiny.setupOutputBuzzer(outputPin);

  // use this line to include the default model
  myTiny.setupGestureModel(MY_GESTURES);
  // or use this line to include your own model
  //   myTiny.setupGestureModel(MY_GESTURES, myGestureModel);

  // set frequencies, in Hz
  myTiny.setBuzzerFrequency(0, 1000);
  myTiny.setBuzzerFrequency(1, 2000);
  myTiny.setBuzzerFrequency(2, 3000);

  // set durations, in milliseconds
  myTiny.setBuzzerDuration(0,  100);
  myTiny.setBuzzerDuration(1,  500);
  myTiny.setBuzzerDuration(2, 1000);
}

void loop() {
  // identify the input and respond
  myTiny.identify();
}
