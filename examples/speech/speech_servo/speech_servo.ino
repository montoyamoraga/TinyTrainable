// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_SPEECH, OUTPUT_SERVO);

// constant for debugging
const bool debugOn = true;

// constants for the hardware
const int outputPin = 9;

// our servo moves between the minimum and maximum angles
// at a desired tempo measured in beats per minute
const int tempo0 = 20;
const int tempo1 = 90;
const int tempo2 = 200;

String MY_WORDS[3] = {"word0", "word1", "word2"};

void setup() {

  // set debugging over serial port
  myTiny.setupInstrument(debugOn);

  myTiny.setupOutputServo(outputPin);

  // set the tempo (in bpm) for each object
  myTiny.setServoTempo(0, tempo0);
  myTiny.setServoTempo(1, tempo1);
  myTiny.setServoTempo(2, tempo2);
}

void loop() {}
