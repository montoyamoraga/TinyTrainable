/// @file color_led.ino
/// @brief input color with output LED

// define input and output
#define INPUT_COLOR
#define OUTPUT_LED

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny(new InputColor(), new OutputLED());

// constants for the hardware
const int outputPinLED0 = 3;
const int outputPinLED1 = 4;
const int outputPinLED2 = 5;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// constant for debugging
const bool tinyDebugging = true;

String objectNames[3] = {"Object 0", "Object 1", "Object 2"};

// setup() runs once, at the beginning
void setup() {
  myTiny.setupInstrument(tinyDebugging);

  myTiny.setupOutputLED(outputPinLED0, outputPinLED1, outputPinLED2);

  // train the KNN algorithm with your objects
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the item and respond
  myTiny.identify();
}
