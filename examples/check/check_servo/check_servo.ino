// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_SERVO);

// servo has 3 cables:
// yellow: signal
// orange: 3.3 V
// brown: ground

// the servo moves between the minimum and maximum angles
// at a desired tempo measured in beats per minute
const int tempo0 = 20;
const int tempo1 = 90;
const int tempo2 = 200;

// constants for the hardware
// connect servo signal pin to D9 on the Arduino
const int outputPin = 9;

void setup() {

  myTiny.setupOutputServo(outputPin);

  // set the tempo (in bpm) for each object
  myTiny.setServoTempo(0, tempo0);
  myTiny.setServoTempo(1, tempo1);
  myTiny.setServoTempo(2, tempo2);
}

void loop() {
  
  // to test the different tempos, try each output
  myTiny.playOutput(0);
  // myTiny.playOutput(1);
  // myTiny.playOutput(2);
}
