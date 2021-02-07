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

// arrays of frequencies
int freqArray0[] = {1100, 1200, 1300, 1400, 1500, 1600};
int freqArray1[] = {2100, 2200, 2300, 2400, 2500, 2600};
int freqArray2[] = {3100, 3200, 3300, 3400, 3500, 3600};
// the following looks funny since sizeof returns byte size
// int freqArrayLength = sizeof(freqArray0)/sizeof(*freqArray0);
int paramArrayLength = 6;

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
  // TODO: cleanup this example, add different duration modes
  tiny.setBuzzerFrequency(0, freqArray0, paramArrayLength);
  tiny.setBuzzerFrequency(1, freqArray1, paramArrayLength);
  tiny.setBuzzerFrequency(2, freqArray2, paramArrayLength);

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
