// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_SERIAL);

int pauseTime = 2000;

void setup() {
  // setup output
  myTiny.setupOutputSerial();
}

void loop() {
  // lets send the classification number over serial
  myTiny.playOutput(0);
  delay(pauseTime);
  myTiny.playOutput(1);
  delay(pauseTime);
  myTiny.playOutput(2);
  delay(pauseTime);

  // you can send other messages too
  Serial.println("hi! :)");
  delay(pauseTime);
}
