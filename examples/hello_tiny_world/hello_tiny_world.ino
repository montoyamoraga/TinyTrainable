// this code is based on the Blink example
// http://www.arduino.cc/en/Tutorial/Blink

// this sketch cycles through all the possible LED colors

// include all libraries
#include <Inst0.h>
#include <Inst1.h>
#include <Inst2.h>

// variables for time LEDs are on and off
// measured in milliseconds
int timeOn = 500;
int timeOff = 250;

// declare instance of the instrument
// default is Inst0, change Inst0 to Inst1 or Inst2 if necessary
Inst0 tiny;

void setup() {
  tiny.setupLEDs();
}

void loop() {

  // turn on and off builtin LED, it is orange
  tiny.turnOnLEDBuiltIn();
  delay(timeOn);
  tiny.turnOffLEDBuiltIn();
  delay(timeOff);

  // turn on the RGB LED in all six available colors  
  // red, green, blue, yellow, magenta, cyan
  tiny.turnOnLEDRGB(red);
  delay(timeOn);
  tiny.turnOnLEDRGB(green);
  delay(timeOn);
  tiny.turnOnLEDRGB(blue);
  delay(timeOn);
  tiny.turnOnLEDRGB(yellow);
  delay(timeOn);
  tiny.turnOnLEDRGB(magenta);
  delay(timeOn);
  tiny.turnOnLEDRGB(cyan);
  delay(timeOn);

  // turn off the RGB LED
  tiny.turnOffLEDRGB();
  delay(timeOff);
}
