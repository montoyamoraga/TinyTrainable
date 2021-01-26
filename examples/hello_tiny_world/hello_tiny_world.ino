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
  tiny.setupInstrument(true);
}

void loop() {

  // turn on and off builtin LED, it is orange
  tiny.setStateLEDBuiltIn(true);
  delay(timeOn);
  tiny.setStateLEDBuiltIn(false);
  delay(timeOff);

  // turn on the RGB LED in all six available colors  
  // red, green, blue, yellow, magenta, cyan
  tiny.setStateLEDRGB(true, red);
  delay(timeOn);
  tiny.setStateLEDRGB(true, green);
  delay(timeOn);
  tiny.setStateLEDRGB(true, blue);
  delay(timeOn);
  tiny.setStateLEDRGB(true, yellow);
  delay(timeOn);
  tiny.setStateLEDRGB(true, magenta);
  delay(timeOn);
  tiny.setStateLEDRGB(true, cyan);
  delay(timeOn);

  // turn off the RGB LED
  tiny.setStateLEDRGB(false, red);
  delay(timeOff);
}
