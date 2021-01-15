// include local library
#include "TinyTrainable.h"

// constructor for the TinyTrainable class
TinyTrainable::TinyTrainable() {

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

void TinyTrainable::setupSensorHTS221() {
    if (!HTS.begin()) {
    while (1);
  }
}

void TinyTrainable::setupSensorLPS22HB() {
    if (!BARO.begin()) {
    while (1);
  }
}

void TinyTrainable::setupSensorLSM9DS1() {
  if (!IMU.begin()) {
    while(1);
  }
}

// sets up Serial, Serial1, proximity/color sensor, and LEDs based on 'mode'
// if 'serialDebugging' is true, debugPrint() statements will be printed over Serial
void TinyTrainable::setOutputMode(OutputMode mode) {
  _outputMode = mode;

  if (_outputMode == outputSerialUSB) {
    Serial.begin(9600);
    while (!Serial);
  }

  if (_outputMode == outputMIDI) {
    setupSerialMIDI();
  }

}

void TinyTrainable::setBuzzerPin(int outputPin) {
  _outputPin = outputPin;
  pinMode(_outputPin, OUTPUT);
}

// set note frequencies for buzzer output
void TinyTrainable::setBuzzerFrequencies(int freq0, int freq1, int freq2) {
  _buzzerFrequencies[0] = freq0;
  _buzzerFrequencies[1] = freq1;
  _buzzerFrequencies[2] = freq2;
}

// TODO: why long and not int?
// TODO: for now lets just have one of these functions
// ideally this function could have the slots i mentioned
void TinyTrainable::setBuzzerDurations(long buzzerDuration) {
  _buzzerDuration = buzzerDuration;
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
