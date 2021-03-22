/// @file hello_serial.ino
/// @brief Example: Test serial USB output

#include <TinyTrainable.h>

TinyTrainable tiny;

void setup() { tiny.setupOutputSerialUSB(); }

void loop() {
  // the object classification number is the only thing sent over serial
  tiny.playOutput(0);
  tiny.playOutput(1);
  tiny.playOutput(2);

  // but you can send other messages directly too
  Serial.println("Hello, Serial!");
}
