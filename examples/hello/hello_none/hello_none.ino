// this code is based on the Blink example
// http://www.arduino.cc/en/Tutorial/Blink

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_NONE);

// constants for time LEDs are on and off
// measured in milliseconds
const int timeOn = 500;
const int timeOff = 250;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool debugOn = false;

// setup() runs once, at the beginning
void setup() {
  // initialize instrument
  myTiny.setupInstrument(debugOn);
}

// loop() runs in a loop, after setup()
void loop() {

  // turn on and off builtin LED, it is orange
  myTiny.setStateLEDBuiltIn(true);
  delay(timeOn);
  myTiny.setStateLEDBuiltIn(false);
  delay(timeOff);

  // turn on the RGB LED in all 6 available colors
  myTiny.setStateLEDRGB(true, red);
  delay(timeOn);
  myTiny.setStateLEDRGB(true, green);
  delay(timeOn);
  myTiny.setStateLEDRGB(true, blue);
  delay(timeOn);
  myTiny.setStateLEDRGB(true, yellow);
  delay(timeOn);
  myTiny.setStateLEDRGB(true, magenta);
  delay(timeOn);
  myTiny.setStateLEDRGB(true, cyan);
  delay(timeOn);

  // turn off the RGB LED, color is irrelevant
  myTiny.setStateLEDRGB(false, red);
  delay(timeOff);
}
