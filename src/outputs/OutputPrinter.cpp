// include header file
#include "OutputPrinter.h"

OutputPrinter::OutputPrinter() {
  // initialize printer
  _printer = Adafruit_Thermal(&Serial1);

}

void OutputPrinter::setupOutputPrinter() {
    Serial1.begin(19200);
}

// methods for TinyTrainable
void OutputPrinter::playOutput(int classification) {
  Serial.println("TODO OutputPrinter playOutput");
}
