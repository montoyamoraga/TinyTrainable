// this code is based on the Blink example
// http://www.arduino.cc/en/Tutorial/Blink

// this sketch cycles through all the lights
// on the arduino nano 33 ble sense

// include libraries
#include "TinyTrainable.h"
#include "Inst0.h"

int timeOn = 500;
int timeOff = 250;

TinyTrainable myTiny;

void setup() {
    myTiny.setupLED();
}

void loop() {

  // turn on and off the pull-up orange LED
  digitalWrite(LED_BUILTIN, HIGH);
  delay(timeOn);
  digitalWrite(LED_BUILTIN, LOW);
  delay(timeOff);

  // turn on and off the pull-down red, green, blue LEDs

 myInstrument.setColorBuiltInLED(red);
  delay(timeOn);
 myInstrument.turnOffBuiltInLED();
  delay(timeOff);

  digitalWrite(LEDG, LOW);
  delay(timeOn);
  digitalWrite(LEDG, HIGH);
  delay(timeOff);

  digitalWrite(LEDB, LOW);
  delay(timeOn);
  digitalWrite(LEDB, HIGH);
  delay(timeOff);

  // turn on and off the pull-down red, green, blue LEDs
  // now combined to form different colors

  // red + green = yellow
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  delay(timeOn);
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  delay(timeOff);

  // red + blue = magenta
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDR, LOW);
  delay(timeOn);
  digitalWrite(LEDB, HIGH);
  digitalWrite(LEDR, HIGH);
  delay(timeOff);

  // green + blue = cyan
  digitalWrite(LEDG, LOW);
  digitalWrite(LEDB, LOW);
  delay(timeOn);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
  delay(timeOff);
}
