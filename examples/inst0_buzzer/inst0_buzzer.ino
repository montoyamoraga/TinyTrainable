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
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = true;

// setup() runs once, at the beginning
void setup() {
  tiny.setupInstrument(tinyDebugging);

  tiny.setupOutputBuzzer(outputPin);
  // TODO: delete old version
  // tiny.setupOutputBuzzer(outputPin, 1000, 1000, 1200, 1400);

  // set fixed frequencies
  tiny.setupBuzzerFrequency(0, 1000);
  tiny.setupBuzzerFrequency(1, 1200);
  tiny.setupBuzzerFrequency(2, 1400);

  // or define ranges of frequencies
  // tiny.setupBuzzerFrequency(0, 1000, 1500);
  // tiny.setupBuzzerFrequency(1, 2000, 2500);
  // tiny.setupBuzzerFrequency(2, 3000, 3500);

  // or define arrays of frequencies
  // tiny.setupBuzzerFrequency(0, [1000, 1500]);
  // tiny.setupBuzzerFrequency(1, 2000, 2500);
  // tiny.setupBuzzerFrequency(2, 3000, 3500);

  // set duratons, easy
  tiny.setupBuzzerDuration(0, 1000);
  tiny.setupBuzzerDuration(1, 1000);
  tiny.setupBuzzerDuration(2, 1000);

  String objectNames[3] = {"Object 0", "Object 1", "Object 2"};
  // train the KNN algorithm
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  tiny.identify();
}
