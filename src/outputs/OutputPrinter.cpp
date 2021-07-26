/// @file OutputPrinter.cpp
/// @brief Output printer

// include header file
#include "OutputPrinter.h"

OutputPrinter::OutputPrinter() {}

OutputPrinter::~OutputPrinter() {
  if (_printer != nullptr) {
    delete _printer;
    _printer = nullptr;
  }
}

void OutputPrinter::setupOutputPrinter() {
  if (!_printer) {
    _printer = new Adafruit_Thermal(&Serial1);
  }
  Serial1.begin(_printerBaudRate);
}

void OutputPrinter::setPrinterBaudRate(int rate) { _printerBaudRate = rate; }

void OutputPrinter::setPrinterBegin() {
  _printer->setDefault();
  _printer->begin();
}

void OutputPrinter::setPrinterPause(int pause) {
  setPrinterSleep();
  delay(long(pause));
  setPrinterWake();
}

void OutputPrinter::setPrinterSleep() { _printer->sleep(); }

void OutputPrinter::setPrinterWake() { _printer->wake(); }

void OutputPrinter::setPrinterTest() {

  _printer->setFont('B');
  _printer->justify('C');
  _printer->setLineHeight(50);
  _printer->println("tiny");
  _printer->println("trainable");
  _printer->println("instruments");
  _printer->feed(2);
}

void OutputPrinter::setupOutputTest() {}

void OutputPrinter::playOutput(int classification) {
  Serial.println("this is OutputPrinter playOutput");
}
