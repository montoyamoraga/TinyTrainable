// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_SERVO);

// constant for debugging
const bool debugOn = true;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 20;
const float COLOR_THRESHOLD = 0.5;

String myColors[3] = {"color0", "color1", "color2"};

// our servo moves between the minimum and maximum angles
// at a desired tempo measured in beats per minute
const int tempo0 = 20;
const int tempo1 = 90;
const int tempo2 = 200;

// constants for the hardware
const int outputPin = 9;

// setup() runs once, at the beginning
void setup() {

  myTiny.setupInstrument(debugOn);

  myTiny.setupOutputServo(outputPin);

  // set the tempo (in bpm) for each object
  myTiny.setServoTempo(0, tempo0);
  myTiny.setServoTempo(1, tempo1);
  myTiny.setServoTempo(2, tempo2);

  // train the KNN algorithm
  myTiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, myColors);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  myTiny.identify();
}
