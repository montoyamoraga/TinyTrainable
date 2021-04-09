// include header file
#include "OutputSerial.h"

OutputSerial::OutputSerial() {}

// methods for TinyTrainable
void OutputSerial::playOutput(int classification) {
  Serial.println("TODO OutputSerial playOutput");
}

void OutputSerial::setupOutputSerial() {

  Serial.begin(9600);
  while (!Serial)
    ;
}
