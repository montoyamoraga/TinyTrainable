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
Inst0 tiny;

void setup() {
  tiny.setupLEDBuiltIn();
  tiny.setupLEDRGB();
}

void loop() {

  // turn on and off builtin LED, it is orange
  tiny.turnOnLEDBuiltIn();
  delay(timeOn);
  tiny.turnOffLEDBuiltIn();
  delay(timeOff);

	for (Colors i = red; i <= cyan; i++) {
		tiny.turnOnLEDRGB(i);
		delay(timeOn);
	}
  
  
  // delay(timeOn);
  // tiny.turnOnLEDRGB(green);
  // delay(timeOn);
  // tiny.turnOnLEDRGB(blue);
  // delay(timeOn);
  // tiny.turnOnLEDRGB(yellow);
  // delay(timeOn);
  // tiny.turnOnLEDRGB(magenta);
  // delay(timeOn);
  // tiny.turnOnLEDRGB(cyan);
  // delay(timeOn);

  tiny.turnOffLEDRGB();
  delay(timeOff);
}
