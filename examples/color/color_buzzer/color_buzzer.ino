/// @file color_buzzer.ino
/// @brief input color with output buzzer

// define input and output
#define INPUT_COLOR
#define OUTPUT_BUZZER

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny(new InputColor(), new OutputBuzzer());

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

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

// setup() runs once, at the beginning
void setup() {

  // setup the instrument
  myTiny.setupInstrument(tinyDebugging);

  // set its output
  myTiny.setupOutputBuzzer(outputPin);

  // see the hello_buzzer example for more frequency
  // and duration parameter options

  // set frequencies, in Hz
  myTiny.setBuzzerFrequency(0, freqArray0, paramArrayLength);
  myTiny.setBuzzerFrequency(1, freqArray1, paramArrayLength);
  myTiny.setBuzzerFrequency(2, freqArray2, paramArrayLength);
  // set durations, in milliseconds
  myTiny.setBuzzerDuration(0, 300);
  myTiny.setBuzzerDuration(1, 600);
  myTiny.setBuzzerDuration(2, 900);

  // train the instrument's KNN algorithm
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  myTiny.identify();
}
