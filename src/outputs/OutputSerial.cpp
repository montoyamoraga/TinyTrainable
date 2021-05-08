// include header file
#include "OutputSerial.h"

OutputSerial::OutputSerial() {}

void OutputSerial::setupOutputTest() {
  
}

void OutputSerial::playOutput(int classification) {
  Serial.print("classification: ");
  Serial.println(classification);
}

void OutputSerial::setupOutputSerial() {

  Serial.begin(9600);
  while (!Serial)
    ;
}
