// include header file
#include "OutputPrinter.h"

OutputPrinter::OutputPrinter() {
  // initialize printer
  _printer = Adafruit_Thermal(&Serial1);
}

void OutputPrinter::setupOutputPrinter() {
  setPrinterBaudRate(_defaultRate);
}

void OutputPrinter::setPrinterBaudRate(int rate) {
  Serial1.flush();
  _defaultRate = rate;
  Serial1.begin(rate);
}

void OutputPrinter::setPrinterBegin() {
  _printer.begin();
}

void OutputPrinter::setPrinterPause(int pause) {
  setPrinterSleep();
  delay(long(pause));
  setPrinterWake();
}

void OutputPrinter::setPrinterSleep() {
  _printer.sleep();
}

void OutputPrinter::setPrinterWake() {
  _printer.wake();
}

// methods for TinyTrainable
void OutputPrinter::playOutput(int classification) {
  Serial.println("TODO OutputPrinter playOutput");
}
