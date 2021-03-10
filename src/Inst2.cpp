/// @file Inst2.cpp
/// @brief speech recognition with TensorFlow

#include "Inst2.h"


// constructor method
Inst2::Inst2() {}

// placeholder function
void Inst2::print2() {
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("this a Inst2");
}
