/// @file TinyTrainable.cpp
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang
/// @date November 2020

/// @include library TinyTrainable
#include "TinyTrainable.h"

/// @include library for each input
#include "inputs/InputColor.h"
#include "inputs/InputGesture.h"
#include "inputs/InputSpeech.h"

/// @include library for each output
#include "outputs/OutputBuzzer.h"
#include "outputs/OutputLED.h"
#include "outputs/OutputMIDI.h"
#include "outputs/OutputPrinter.h"
#include "outputs/OutputScreen.h"
#include "outputs/OutputSerial.h"
#include "outputs/OutputServo.h"

/// @brief static variable, boolean, serial debugging
bool TinyTrainable::_serialDebugging = false;
/// @brief static variable, integer, baud rate
int TinyTrainable::_baudRate = 9600;
int TinyTrainable::_timeBlinkLED = 500;

/// @brief constructor
/// @param InputType
/// @param OutputType
TinyTrainable::TinyTrainable(InputType inputType, OutputType outputType) {

  // initialize input
  if (inputType == INPUT_COLOR) {
    myInput = new InputColor();
  } else if (inputType == INPUT_GESTURE) {
    myInput = new InputGesture();
  } else if (inputType == INPUT_SPEECH) {
    myInput = new InputSpeech();
  } else {
    myInput = new Input();
  }

  // initialize output
  if (outputType == OUTPUT_BUZZER) {
    myOutput = new OutputBuzzer();
  } else if (outputType == OUTPUT_LED) {
    myOutput = new OutputLED();
  } else if (outputType == OUTPUT_MIDI) {
    myOutput = new OutputMIDI();
  } else if (outputType == OUTPUT_PRINTER) {
    myOutput = new OutputPrinter();
  } else if (outputType == OUTPUT_SCREEN) {
    myOutput = new OutputScreen();
  } else if (outputType == OUTPUT_SERIAL) {
    myOutput = new OutputSerial();
  } else if (outputType == OUTPUT_SERVO) {
    myOutput = new OutputServo();
  } else {
    myOutput = new Output();
  }

  // update pointer to input
  if (myInput != nullptr) {
    myInput->tiny = this;
  }

  // update pointer to output
  if (myOutput != nullptr) {
    myOutput->tiny = this;
  }

  setupLEDs();
}

/// @brief destructor
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

/// @brief method for initial setup
/// @param serialDebugging to output or not debug info over serial
void TinyTrainable::setupInstrument(bool serialDebugging) {
  if (myInput != nullptr) {
    myInput->setupInstrument(serialDebugging);
  }
};

void TinyTrainable::identify() {
  if (myInput != nullptr) {
    myInput->identify();
  }
}

void TinyTrainable::playOutput(int classification) {
  debugPrint(classification);
  if (myOutput != nullptr) {
    myOutput->playOutput(classification);
  }
}

/// @brief input color, train KNN algorithm
void TinyTrainable::trainKNN(int k, int examplesPerClass, float colorThreshold,
                             String objects[3]) {
  if (myInput != nullptr) {
    myInput->trainKNN(k, examplesPerClass, colorThreshold, objects);
  }
};

/// @brief input gesture, setup TensorFlow
void TinyTrainable::setupGestureModel(String gestures[3],
                                   const unsigned char *model) {
  if (myInput != nullptr) {
    myInput->setupGestureModel(gestures, model);
  }
}

void TinyTrainable::gesturePrintHeader() {
  if (myInput != nullptr) {
    myInput->gesturePrintHeader();
  }
}

void TinyTrainable::gestureReadData() {
  if (myInput != nullptr) {
    myInput->gestureReadData();
  }
}

void TinyTrainable::gestureSetAcceleration(float newVal) {
  if (myInput != nullptr) {
    myInput->gestureSetAcceleration(newVal);
  }
}

void TinyTrainable::gestureSetNumberSamples(int newVal) {
  if (myInput != nullptr) {
    myInput->gestureSetNumberSamples(newVal);
  }
}

void TinyTrainable::setupSpeechModel(String sounds[3],
                                  const unsigned char *model) {
  if (myInput != nullptr) {
    myInput->setupSpeechModel(sounds, model);
  }
}

void TinyTrainable::setupLEDs() {
  // setup orange LED built-in
  pinMode(LED_BUILTIN, OUTPUT);
  // initial state, HIGH is off, LOW is on
  digitalWrite(LED_BUILTIN, HIGH);

  // setup LED RGB
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  // initial state, HIGH is off, LOW is on
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

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
    delay(_timeBlinkLED);
    setStateLEDBuiltIn(false);
    delay(_timeBlinkLED);
  }
}

void TinyTrainable::blinkLEDRGB(int blinks, Colors color) {
  setStateLEDRGB(false, color);
  for (int i = 0; i < blinks; i++) {
    setStateLEDRGB(true, color);
    delay(_timeBlinkLED);
    setStateLEDRGB(false, color);
    delay(_timeBlinkLED);
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

void TinyTrainable::setupOutputTest() {
  if (myOutput != nullptr) {
    myOutput->setupOutputTest();
  }
}

void TinyTrainable::setupOutputBuzzer(int outputPin) {
  if (myOutput != nullptr) {
    myOutput->setupOutputBuzzer(outputPin);
  }
}

void TinyTrainable::getBuzzerParam(int object, int buzzerParamArray[]) {
  if (myOutput != nullptr) {
    myOutput->getBuzzerParam(object, buzzerParamArray);
  }
}

void TinyTrainable::setBuzzerFrequency(int object, int frequency) {
  if (myOutput != nullptr) {
    myOutput->setBuzzerFrequency(object, frequency);
  }
}

void TinyTrainable::setBuzzerFrequency(int object, int freqMin, int freqMax) {
  if (myOutput != nullptr) {
    myOutput->setBuzzerFrequency(object, freqMin, freqMax);
  }
}

void TinyTrainable::setBuzzerFrequency(int object, int *arrayFrequencies,
                                       int arrayFreqCount) {
  if (myOutput != nullptr) {
    myOutput->setBuzzerFrequency(object, *arrayFrequencies, arrayFreqCount);
  }
}

void TinyTrainable::setBuzzerDuration(int object, int duration) {
  if (myOutput != nullptr) {
    myOutput->setBuzzerDuration(object, duration);
  }
}

void TinyTrainable::setBuzzerDuration(int object, int durationMin,
                                      int durationMax) {
  if (myOutput != nullptr) {
    myOutput->setBuzzerDuration(object, durationMin, durationMax);
  }
}

void TinyTrainable::setBuzzerDuration(int object, int *arrayDurations,
                                      int arrayDurationCount) {
  if (myOutput != nullptr) {
    myOutput->setBuzzerDuration(object, *arrayDurations, arrayDurationCount);
  }
}

// functions for output LED
void TinyTrainable::setupOutputLED(int object, int outputPin) {
  if (myOutput != nullptr) {
    myOutput->setupOutputLED(object, outputPin);
  }
}

// methods for output MIDI
void TinyTrainable::setupOutputMIDI(byte midiChannel) {
  if (myOutput != nullptr) {
    myOutput->setupOutputMIDI(midiChannel);
  }
}
void TinyTrainable::setMIDINote(int object, int note) {
  if (myOutput != nullptr) {
    myOutput->setMIDINote(object, note);
  }
}

void TinyTrainable::sendMIDINoteOn(byte channel, byte note, byte velocity) {
  if (myOutput != nullptr) {
    myOutput->sendMIDINoteOn(channel, note, velocity);
  }
}

void TinyTrainable::sendMIDINoteOff(byte channel, byte note) {
  if (myOutput != nullptr) {
    myOutput->sendMIDINoteOff(channel, note);
  }
}

void TinyTrainable::sendMIDIAllNotesOff(byte channel) {
  if (myOutput != nullptr) {
    myOutput->sendMIDIAllNotesOff(channel);
  }
}

// methods for output printer
void TinyTrainable::setupOutputPrinter() {
  if (myOutput != nullptr) {
    myOutput->setupOutputPrinter();
  }
}

void TinyTrainable::setPrinterBaudRate(int rate) {
  if (myOutput != nullptr) {
    myOutput->setPrinterBaudRate(rate);
  }
}

void TinyTrainable::setPrinterBegin() {
  if (myOutput != nullptr) {
    myOutput->setPrinterBegin();
  }
}

void TinyTrainable::setPrinterPause(int pause) {
  if (myOutput != nullptr) {
    myOutput->setPrinterPause(pause);
  }
}

void TinyTrainable::setPrinterSleep() {
  if (myOutput != nullptr) {
    myOutput->setPrinterSleep();
  }
}

void TinyTrainable::setPrinterWake() {
  if (myOutput != nullptr) {
    myOutput->setPrinterWake();
  }
}

void TinyTrainable::setPrinterTest() {
  if (myOutput != nullptr) {
    myOutput->setPrinterTest();
  }
}

// methods for output screen
void TinyTrainable::setupOutputScreen() {
  if (myOutput != nullptr) {
    myOutput->setupOutputScreen();
  }
}

void TinyTrainable::screenDrawWelcome() {
  if (myOutput != nullptr) {
    myOutput->screenDrawWelcome();
  }
}

// methods for output serial
void TinyTrainable::setupOutputSerial() {
  if (myOutput != nullptr) {
    myOutput->setupOutputSerial();
  }
}

// functions for output servo
void TinyTrainable::setupOutputServo(int outputPin) {
  if (myOutput != nullptr) {
    myOutput->setupOutputServo(outputPin);
  }
}

void TinyTrainable::setServoTempo(int object, int tempo) {
  if (myOutput != nullptr) {
    myOutput->setServoTempo(object, tempo);
  }
}

int TinyTrainable::bpmToMs(int tempo) {
  if (myOutput != nullptr) {
    return myOutput->bpmToMs(tempo);
  } else {
    return -1;
  }
}

void TinyTrainable::setServoMaxAngle(int angle) {
  if (myOutput != nullptr) {
    myOutput->setServoMaxAngle(angle);
  }
}

void TinyTrainable::setServoMinAngle(int angle) {
  if (myOutput != nullptr) {
    myOutput->setServoMinAngle(angle);
  }
}

int TinyTrainable::getServoMaxAngle() {
  if (myOutput != nullptr) {
    return myOutput->getServoMaxAngle();
  } else {
    return -1;
  }
}

int TinyTrainable::getServoMinAngle() {
  if (myOutput != nullptr) {
    return myOutput->getServoMinAngle();
  } else {
    return -1;
  }
}

void TinyTrainable::moveServo(int classification) {
  if (myOutput != nullptr) {
    myOutput->moveServo(classification);
  }
}
