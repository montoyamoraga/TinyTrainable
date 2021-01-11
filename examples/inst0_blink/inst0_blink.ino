// this code is based on the Blink example
// http://www.arduino.cc/en/Tutorial/Blink

// this sketch cycles through all the possible LED colors

// include library
#include "Inst0.h"

// variables for time LEDs are on and off
// measured in milliseconds
int timeOn = 500;
int timeOff = 250;

// declare instance of the instrument0
Inst0 myTiny;

void setup() {
  myTiny.setupLEDBuiltIn();
  myTiny.setupLEDRGB();
}

void loop() {

  // turn on and off builtin LED, it is orange
  myTiny.turnOnLEDBuiltIn();
  delay(timeOn);
  myTiny.turnOffLEDBuiltIn();
  delay(timeOff);
  
  myTiny.turnOnLEDRGB(red);
  delay(timeOn);
  myTiny.turnOnLEDRGB(green);
  delay(timeOn);
  myTiny.turnOnLEDRGB(blue);
  delay(timeOn);
  myTiny.turnOnLEDRGB(yellow);
  delay(timeOn);
  myTiny.turnOnLEDRGB(magenta);
  delay(timeOn);
  myTiny.turnOnLEDRGB(cyan);
  delay(timeOn);

  myTiny.turnOffLEDRGB();
  delay(timeOff);
}
