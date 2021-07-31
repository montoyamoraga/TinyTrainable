// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_BUZZER);

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 20;

// constants for the hardware
const int outputPin = 2;

// constant for debugging
const bool debugOn = true;

// names of colors
String myColors[3] = {"color0", "color1", "color2"};

int paramArrayLength = 6;

// setup() runs once, at the beginning
void setup() {

  // setup the instrument
  myTiny.setupInstrument(debugOn);

  // set its output
  myTiny.setupOutputBuzzer(outputPin);

  // see the hello_buzzer example for more parameter options

  // set frequencies, in Hz
  myTiny.setBuzzerFrequency(0, 1000);
  myTiny.setBuzzerFrequency(1, 2000);
  myTiny.setBuzzerFrequency(2, 3000);

  // set durations, in milliseconds
  myTiny.setBuzzerDuration(0,  100);
  myTiny.setBuzzerDuration(1,  500);
  myTiny.setBuzzerDuration(2, 1000);

  // train the instrument's KNN algorithm
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, myColors);
}

// loop() runs after setup(), on a loop
void loop() {
  // identify the input and respond
  myTiny.identify();
}
