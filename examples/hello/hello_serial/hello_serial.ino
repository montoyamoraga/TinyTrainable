/// @file hello_serial.ino
/// @brief Example: Test output with serial USB

// define input and output
#define INPUT_NONE
#define OUTPUT_SERIAL

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(new Input(), new OutputSerial());

void setup() {
  // setup output
  // myTiny.setupOutputSerialUSB();
}

void loop() {
  // the object classification number is the only thing sent over serial
  //  myTiny.playOutput(0);
  //  myTiny.playOutput(1);
  //  myTiny.playOutput(2);

  // but you can send other messages directly too
  Serial.println("Hello, Serial!");
}
