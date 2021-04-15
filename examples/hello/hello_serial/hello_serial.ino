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
  // tiny.setupOutputSerialUSB();
  }

void loop() {
  // the object classification number is the only thing sent over serial
  tiny.playOutput(0);
  tiny.playOutput(1);
  tiny.playOutput(2);

  // but you can send other messages directly too
  Serial.println("Hello, Serial!");
}
