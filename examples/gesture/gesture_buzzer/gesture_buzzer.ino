/// @file gesture_buzzer.ino
/// @brief input gesture with output buzzer

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_GESTURE, OUTPUT_BUZZER);

// include machine learning model
// #include "../assets/modelGesture.h"
// or include your own
#include "myGestureModel.h"

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny;

// constants for the hardware
const int outputPin = 2;

// constant for debugging
const bool tinyDebugging = true;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// arrays of frequencies
int freqArray0[] = {1100, 1200, 1300, 1400, 1500, 1600};
int freqArray1[] = {2100, 2200, 2300, 2400, 2500, 2600};
int freqArray2[] = {3100, 3200, 3300, 3400, 3500, 3600};

// the following looks funny since sizeof returns byte size
// int freqArrayLength = sizeof(freqArray0)/sizeof(*freqArray0);
int paramArrayLength = 6;

// threshold of significant in G's
const float accelerationThreshold = 2.5;

// number of samples per gesture
const int numSamples = 119;

// array to map gesture index to a name
String GESTURES[] = {"gesture0", "gesture1", "gesture2"};

// setup() runs once, at the beginning
void setup() {

  // set debugging over serial port
  myTiny.setupInstrument(tinyDebugging);
  myTiny.setupTF(GESTURES, accelerationThreshold, numSamples);

  // set its output
  myTiny.setupOutputBuzzer(outputPin);

  // set frequencies, in Hz
  myTiny.setBuzzerFrequency(0, freqArray0, paramArrayLength);
  myTiny.setBuzzerFrequency(1, freqArray1, paramArrayLength);
  myTiny.setBuzzerFrequency(2, freqArray2, paramArrayLength);
  // set durations, in milliseconds
  myTiny.setBuzzerDuration(0, 300);
  myTiny.setBuzzerDuration(1, 600);
  myTiny.setBuzzerDuration(2, 900);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the input and respond
  myTiny.identify();
}
