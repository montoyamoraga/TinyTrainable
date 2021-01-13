// include local library
#include "TinyTrainable.h"

// constructor for the TinyTrainable class
TinyTrainable::TinyTrainable()
{
  // hardcoded for now
  _serialDebugging = true;
}

void TinyTrainable:: setupLEDs() {
  setupLEDBuiltIn();
  setupLEDRGB();
}

void TinyTrainable:: setupLEDBuiltIn() {
  pinMode(LED_BUILTIN, OUTPUT);
  // default state off is LOW
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

  // default state off is HIGH
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

void TinyTrainable::setSerialDebugging(bool serialDebugging) {
  
  // update boolean
  _serialDebugging = serialDebugging;

  if (_serialDebugging) {
        Serial.begin(9600);
        while (!Serial);
  }


}

void TinyTrainable::setupSensorAPDS9960() {
    if (!APDS.begin()) {
    while (1);
  }
}

// sets up Serial MIDI output on TX pin
void TinyTrainable::setupSerialMIDI() {

  // open serial tranmission on TX pin
  Serial1.begin(9600);

  // desired baudrate for MIDI
  uint32_t baudrate = 0x800000;

  // declare pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}

void TinyTrainable::setSerialMIDIChannel(byte midiChannel) {
 _midiChannel = midiChannel;
    
}
void TinyTrainable::setSerialMIDIVelocity(byte midiVelocity) {
  _midiVelocity = midiVelocity;
}

void TinyTrainable::sendSerialMIDINote(byte channel, byte note, byte velocity) {
  Serial1.write(143 + channel);
  Serial1.write(note);
  Serial1.write(velocity);
}
