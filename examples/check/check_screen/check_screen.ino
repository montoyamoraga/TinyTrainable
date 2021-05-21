// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_SCREEN);

// constants for the hardware
// const int outputPin = 9;

void setup() {

  myTiny.setupOutputScreen();
  myTiny.screenDrawWelcome();
}

void loop() {
  // to test the different tempos, try each output
  //  myTiny.playOutput(0);
  //  myTiny.playOutput(1);
  // myTiny.playOutput(2);
}
