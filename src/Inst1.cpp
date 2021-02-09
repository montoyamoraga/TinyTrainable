/// @file Inst1.cpp
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang 
/// @date November 2020

#include "Inst1.h"

Inst1::Inst1() {
  
}

void Inst1::setupInstrument() {
  setupLEDs();
  setupSensorLSM9DS1();
  
}

void Inst1::print1() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("this a Inst1");
}
