// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_SERIAL);

int pauseTime = 500;

void setup() {
  // setup output
  myTiny.setupOutputSerial();
}

void loop() {

  // print the classification number over serial
  myTiny.playOutput(0);
  delay(pauseTime);
  myTiny.playOutput(1);
  delay(pauseTime);
  myTiny.playOutput(2);
  delay(pauseTime);

  // you can also send your own messages over Serial
  Serial.println("hi! :)");
  delay(pauseTime);

  // turn on and off the orange built-in LED
  myTiny.setStateLEDBuiltIn(true);
  delay(pauseTime);
  myTiny.setStateLEDBuiltIn(false);
  delay(pauseTime);

  // cycle through the 6 colors of the RGB LED
  myTiny.setStateLEDRGB(true, red);
  delay(pauseTime);
  myTiny.setStateLEDRGB(true, green);
  delay(pauseTime);
  myTiny.setStateLEDRGB(true, blue);
  delay(pauseTime);
  myTiny.setStateLEDRGB(true, yellow);
  delay(pauseTime);
  myTiny.setStateLEDRGB(true, magenta);
  delay(pauseTime);
  myTiny.setStateLEDRGB(true, cyan);
  delay(pauseTime);

  // to turn off the RGB LED, color is irrelevant
  myTiny.setStateLEDRGB(false, red);
  delay(pauseTime);
}
