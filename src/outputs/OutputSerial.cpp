/// @file OutputSerial.cpp
/// @brief Output serial

// include header file
#include "OutputSerial.h"

OutputSerial::OutputSerial() {}

void OutputSerial::setupOutputTest() {
  //     Serial.println("hello world!");
}

void OutputSerial::playOutput(int classification) {
  Serial.print("classification: ");
  Serial.println(classification);
}

void OutputSerial::setupOutputSerial() {

  Serial.begin(9600);
  while (!Serial)
    ;
  if (tiny->_serialDebugging) {
    tiny->debugPrint("setupOutputSerial");
  }
}
