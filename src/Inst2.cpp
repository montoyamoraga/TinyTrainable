/// @file Inst2.cpp
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang
/// @date November 2020

#include "Inst2.h"

Inst2::Inst2() {}

void Inst2::print2() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("this a Inst2");
}
