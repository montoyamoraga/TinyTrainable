// include local library
#include "TinyTrainable.h"

// constructor for the TinyTrainable class
TinyTrainable::TinyTrainable()
{
  _serialDebugging = true;  // hardcoded for now
}


void TinyTrainable:: setupLEDBuiltIn() {
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  // start with everything off
  digitalWrite(LED_BUILTIN, LOW);
}

void TinyTrainable::turnOnLEDBuiltIn() {
  digitalWrite(LED_BUILTIN, HIGH);
}

void TinyTrainable::turnOffLEDBuiltIn() {
  digitalWrite(LED_BUILTIN, LOW);
}

void TinyTrainable::setupLEDRGB() {
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // start with everything off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

void TinyTrainable::turnOnLEDRGB(Colors color) {

    if (color == red) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, HIGH);
  } else if (color == green) {
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
  } else if (color == blue) {
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
  } else if (color == yellow) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
  } else if (color == magenta) {
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
  } else if (color == cyan) {
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
  }
}

void TinyTrainable::turnOffLEDRGB() {
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

// sets up Serial1 (serial output over pins - TX pin on Arduino Nano
// 33 BLE Sense)
void TinyTrainable::setupSerial1() {
  Serial1.begin(9600);

  // desired baudrate
  uint32_t baudrate = 0x800000;

  // pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}


// send 3 byte midi message over Serial1 (pins)
// 'midiNote' is the midi note number in decimal
// midi channel and note velocity are preset
void TinyTrainable::midiCommand(byte midiNote) {
  Serial1.write(_midiChannelDec);
  Serial1.write(midiNote);
  Serial1.write(_midiVelocity);
}
