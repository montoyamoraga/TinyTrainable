// include library
#include <Inst0.h>

// declare instance of the instrument0
Inst0 tiny;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// constants for the hardware
const int outputPin = 8;

// constant for debugging
const bool tinyDebugging = true;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// array of frequencies
int freqArray[] = {1000, 2000, 3000, 4000, 5000, 6000};
// the following looks funny since sizeof returns byte size
int freqArrayLength = sizeof(freqArray)/sizeof(*freqArray);

// setup() runs once, at the beginning
void setup() {

  tiny.setupInstrument(tinyDebugging);

  tiny.setupOutputBuzzer(outputPin);

  // set fixed frequencies, in Hz
  // tiny.setBuzzerFrequency(0, 1000);
  // tiny.setBuzzerFrequency(1, 1500);
  // tiny.setBuzzerFrequency(2, 2000);

  // or define ranges of frequencies
  // tiny.setBuzzerFrequency(0, 500, 1000);
  // tiny.setBuzzerFrequency(1, 1000, 1500);
  // tiny.setBuzzerFrequency(2, 2000, 2500);

  // or use arrays of frequencies (WHICH MUST BE DECLARED IN THE GLOBAL SCOPE!)
  // TODO: cleanup this test
  tiny.setBuzzerFrequency(0, freqArray, freqArrayLength);
  tiny.setBuzzerFrequency(1, freqArray, freqArrayLength);
  tiny.setBuzzerFrequency(2, freqArray, freqArrayLength);

  // set durations, in milliseconds
  tiny.setBuzzerDuration(0, 300);
  tiny.setBuzzerDuration(1, 600);
  tiny.setBuzzerDuration(2, 900);
  
  // train the KNN algorithm
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  tiny.identify();
}
