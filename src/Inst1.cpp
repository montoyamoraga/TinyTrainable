/// @file Inst1.cpp
/// @brief gesture recognition using TensorFlow

/// include library
#include "Inst1.h"

/// constructor method
Inst1::Inst1() {}

void Inst1::setupInstrument(bool serialDebugging) {
  // setup LEDs
  setupLEDs();
  // turn on sensor
  setupSensorLSM9DS1();
}

void Inst1::print1() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("this a Inst1");
}
