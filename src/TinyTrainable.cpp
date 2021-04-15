/// @file TinyTrainable.cpp
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang
/// @date November 2020

// include local library
#include "TinyTrainable.h"

// TinyTrainable::TinyTrainable() {}

// initialize static variables
bool TinyTrainable::_serialDebugging = false;

TinyTrainable::TinyTrainable(Input *newInput, Output *newOutput) {

  myInput = newInput;
  myOutput = newOutput;

  // TODO: research the name of this linking way
  if (myInput != nullptr) {
    myInput->tiny = this;
  }

  if (myOutput != nullptr) {
    myOutput->tiny = this;
  }

  setupLEDs();
}

// destructor against memory leaks
TinyTrainable::~TinyTrainable() {
  if (myInput != nullptr) {
    delete myInput;
    myInput = nullptr;
  }

  if (myOutput != nullptr) {
    delete myOutput;
    myOutput = nullptr;
  }
}

void TinyTrainable::setupInstrument(bool serialDebugging){
  if (myInput != nullptr) {
    myInput->setupInstrument(serialDebugging);
  }
};

  // methods for input color
void TinyTrainable::trainKNN(int k, int examplesPerClass, float colorThreshold, String objects[3]){
   if (myInput != nullptr) {
     myInput->trainKNN(k, examplesPerClass, colorThreshold, objects);
  }
};

void TinyTrainable::setupLEDs() {
  // setting up orange built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
  // initial state off is HIGH for on
  digitalWrite(LED_BUILTIN, HIGH);

  // setting up RGB LED
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  // default state off is HIGH
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

// function for turning on and off the built-in LED
void TinyTrainable::setStateLEDBuiltIn(bool turnOn) {
  if (turnOn) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

void TinyTrainable::blinkLEDBuiltIn(int blinks) {

  setStateLEDBuiltIn(false);

  for (int i = 0; i < blinks; i++) {
    setStateLEDBuiltIn(true);
    delay(500);
    setStateLEDBuiltIn(false);
    delay(500);
  }
}

// function for turning on and off the RGB LED
void TinyTrainable::setStateLEDRGB(bool turnOn, Colors color) {

  // first turn off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);

  // then turn on according to color
  if (turnOn) {
    switch (color) {
    case red:
      digitalWrite(LEDR, LOW);
      break;
    case green:
      digitalWrite(LEDG, LOW);
      break;
    case blue:
      digitalWrite(LEDB, LOW);
      break;
    case yellow:
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, LOW);
      break;
    case magenta:
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDB, LOW);
      break;
    case cyan:
      digitalWrite(LEDG, LOW);
      digitalWrite(LEDB, LOW);
      break;
    }
  }
}

// traps the arduino in an infinite loop with RGB LED blinking, to signal
// some setup missing. explanations in docs by instrument.
// void TinyTrainable::errorBlink(Colors color, int blinkNum) {
//   while (true) {
//     for (int i = 0; i <= blinkNum; i++) {
//       // turn on with the color
//       setStateLEDRGB(true, color);
//       delay(1000);
//       // turn off
//       setStateLEDRGB(false, color);
//       delay(1000);
//     }
//     blinkLEDBuiltIn(1);
//   }
// }

// TODO
// void TinyTrainable::helloOutputsSetup(OutputMode outputToTest) {
//   switch (outputToTest) {
//   case outputMIDI:
//     setupOutputMIDI(10, 127);
//     break;
//   case outputSerialUSB:
//     Serial.begin(9600);
//     while (!Serial)
//       ;
//     break;
//   case outputUndefined:
//     pinMode(LED_BUILTIN, OUTPUT);
//     digitalWrite(LED_BUILTIN, LOW);
//     break;
//   }
// }

// TODO
// void TinyTrainable::helloOutputsSetup(OutputMode outputToTest, int outputPin)
// {
//   switch (outputToTest) {
//   case outputBuzzer:
//     // update internal variable
//     _outputPinTest = outputPin;
//     // setup pin
//     pinMode(_outputPinTest, OUTPUT);
//     break;
//   case outputLED:
//     _outputPinTest = outputPin;
//     pinMode(outputPin, OUTPUT);
//     break;
//   case outputServo:
//     setupOutputServo(outputPin, 0, 180);
//     setServoTempo(0, 20);
//     break;
//   }
// }

// TODO
// void TinyTrainable::helloOutputs(OutputMode outputToTest) {
//   int timeDelay = 3000;
//   switch (outputToTest) {
//   case outputBuzzer:
//     tone(_outputPinTest, 260, timeDelay);
//     delay(timeDelay);
//     tone(_outputPinTest, 330, timeDelay);
//     delay(timeDelay);
//     tone(_outputPinTest, 392, timeDelay);
//     delay(timeDelay);
//     tone(_outputPinTest, 523, timeDelay);
//     delay(timeDelay);
//     break;
//   case outputLED:
//     digitalWrite(_outputPinTest, LOW);
//     delay(timeDelay);
//     digitalWrite(_outputPinTest, HIGH);
//     delay(timeDelay);
//     break;
//   case outputMIDI:
//     sendSerialMIDINote(_midiChannel, 37, _midiVelocity);
//     delay(timeDelay);
//     sendSerialMIDINote(_midiChannel, 38, _midiVelocity);
//     delay(timeDelay);
//     sendSerialMIDINote(_midiChannel, 39, _midiVelocity);
//     delay(timeDelay);
//     break;
//   case outputSerialUSB:
//     Serial.println("hello world!");
//     delay(timeDelay);
//     break;
//   case outputServo:
//     moveServo(0);
//     break;
//   case outputUndefined:
//     blinkLEDBuiltIn(3);
//     delay(timeDelay);
//     break;
//   }
// }


// functions for buzzer
void TinyTrainable::setupOutputBuzzer(int outputPin) {
     if (myInput != nullptr) {
     myInput->setupOutputBuzzer(outputPin);
  }
}
