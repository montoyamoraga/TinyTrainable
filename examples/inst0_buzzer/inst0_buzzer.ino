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

  Serial.println("size of integer");
  Serial.println(sizeof(0));
  Serial.println("right?");

  tiny.setupOutputBuzzer(outputPin);
  // TODO: delete old version
  // tiny.setupOutputBuzzer(outputPin, 1000, 1000, 1200, 1400);

  // set fixed frequencies
  tiny.setBuzzerFrequency(0, 1000);
  tiny.setBuzzerFrequency(1, 1200);
  tiny.setBuzzerFrequency(2, 1400);

  // or define ranges of frequencies
  // tiny.setupBuzzerFrequency(0, 1000, 1500);
  // or define arrays of frequencies
  // TODO: cleanup this test
  int testing[] = {1000, 2000, 300, 4000, 5000, 6000};
  tiny.setBuzzerFrequency(0, testing);

  // set duratons, easy
  tiny.setBuzzerDuration(0, 1000);
  tiny.setBuzzerDuration(1, 1000);
  tiny.setBuzzerDuration(2, 1000);

  String objectNames[3] = {"Object 0", "Object 1", "Object 2"};
  // train the KNN algorithm
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  tiny.identify();
}
