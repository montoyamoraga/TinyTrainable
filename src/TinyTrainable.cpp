/// @file TinyTrainable.cpp
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang
/// @date November 2020

// include local library
#include "TinyTrainable.h"

/// @brief Constructor method
/// @param [in] none
/// @param [out] none
TinyTrainable::TinyTrainable() {}

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
void TinyTrainable::errorBlink(Colors color, int blinkNum) {
  while (true) {
    for (int i = 0; i <= blinkNum; i++) {
      // turn on with the color
      setStateLEDRGB(true, color);
      delay(1000);
      // turn off
      setStateLEDRGB(false, color);
      delay(1000);
    }
    blinkLEDBuiltIn(1);
  }
}

// APDS9960 sensor for gestures, color, light intensity, proximity
void TinyTrainable::setupSensorAPDS9960() {
  if (!APDS.begin()) {
    while (1)
      ;
  }
}

// LSM9DS1 sensor for IMU (inertial measurement unit)
//  3-axis accelerometer, gyroscope, magnetometer
void TinyTrainable::setupSensorLSM9DS1() {
  if (!IMU.begin()) {
    while (1)
      ;
  }
}

// TODO
void TinyTrainable::helloOutputsSetup(OutputMode outputToTest) {
  switch (outputToTest) {
  case outputMIDI:
    setupOutputMIDI(10, 127);
    break;
  case outputSerialUSB:
    Serial.begin(9600);
    while (!Serial)
      ;
    break;
  case outputUndefined:
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    break;
  }
}

// TODO
void TinyTrainable::helloOutputsSetup(OutputMode outputToTest, int outputPin) {
  switch (outputToTest) {
  case outputBuzzer:
    // update internal variable
    _outputPinTest = outputPin;
    // setup pin
    pinMode(_outputPinTest, OUTPUT);
    break;
  case outputLED:
    _outputPinTest = outputPin;
    pinMode(outputPin, OUTPUT);
    break;
  case outputServo:
#ifdef OUTPUT_SERVO
    setupOutputServo(outputPin, 0, 180);
    setServoTempo(0, 20);
#endif
    break;
  }
}

// TODO
void TinyTrainable::helloOutputs(OutputMode outputToTest) {
  int timeDelay = 3000;
  switch (outputToTest) {
  case outputBuzzer:
    tone(_outputPinTest, 260, timeDelay);
    delay(timeDelay);
    tone(_outputPinTest, 330, timeDelay);
    delay(timeDelay);
    tone(_outputPinTest, 392, timeDelay);
    delay(timeDelay);
    tone(_outputPinTest, 523, timeDelay);
    delay(timeDelay);
    break;
  case outputLED:
    digitalWrite(_outputPinTest, LOW);
    delay(timeDelay);
    digitalWrite(_outputPinTest, HIGH);
    delay(timeDelay);
    break;
  case outputMIDI:
    sendSerialMIDINote(_midiChannel, 37, _midiVelocity);
    delay(timeDelay);
    sendSerialMIDINote(_midiChannel, 38, _midiVelocity);
    delay(timeDelay);
    sendSerialMIDINote(_midiChannel, 39, _midiVelocity);
    delay(timeDelay);
    break;
  case outputSerialUSB:
    Serial.println("hello world!");
    delay(timeDelay);
    break;
  case outputServo:
#ifdef OUTPUT_SERVO
    moveServo(0);
#endif
    break;
  case outputUndefined:
    blinkLEDBuiltIn(3);
    delay(timeDelay);
    break;
  }
}

// TODO
void TinyTrainable::playOutput(int classification) {
  // TODO: add the corresponding calls to functions
  switch (_outputMode) {
  case outputBuzzer:
    getBuzzerParam(classification, _buzzerParams);
    tone(_outputPinBuzzer, _buzzerParams[0], _buzzerParams[1]);
    break;
  case outputLCD:
    Serial.println("TODO");
    break;
  case outputLED:
    digitalWrite(_outputPinsLED[0], LOW);
    digitalWrite(_outputPinsLED[1], LOW);
    digitalWrite(_outputPinsLED[2], LOW);
    digitalWrite(_outputPinsLED[classification], HIGH);
    break;
  case outputMIDI:
    sendSerialMIDINote(_midiChannel, _midiNotes[classification], _midiVelocity);
    break;
  case outputPrinter:
    Serial.println("TODO");
    break;
  case outputSerialUSB:
    Serial.println(classification);
    break;
  case outputServo:
#ifdef OUTPUT_SERVO
    moveServo(classification);
#endif
    break;
  case outputUndefined:
    Serial.println("TODO");
    break;
  }
}

// TODO: add comments
void TinyTrainable::setupOutputBuzzer(int outputPin) {
  _outputMode = outputBuzzer;
  _outputPinBuzzer = outputPin;
  pinMode(_outputPinBuzzer, OUTPUT);
}

void TinyTrainable::setBuzzerFrequency(int object, int frequency) {
  _buzzerFreqMode = singleParam;
  _buzzerFrequencies[object] = frequency;
}

void TinyTrainable::setBuzzerFrequency(int object, int freqMin, int freqMax) {
  _buzzerFreqMode = rangeParam;
  _buzzerFrequenciesMin[object] = freqMin;
  _buzzerFrequenciesMax[object] = freqMax;
}

void TinyTrainable::setBuzzerFrequency(int object, int *arrayFrequencies,
                                       int arrayFreqCount) {
  _buzzerFreqMode = randomParam;
  _buzzerFrequenciesArrays[object] = arrayFrequencies;
  _buzzerFrequenciesArraysSizes[object] = arrayFreqCount;
}

void TinyTrainable::setBuzzerDuration(int object, int duration) {
  _buzzerDurationMode = singleParam;
  _buzzerDurations[object] = duration;
}

void TinyTrainable::setBuzzerDuration(int object, int durationMin,
                                      int durationMax) {
  _buzzerDurationMode = rangeParam;
  _buzzerDurationsMin[object] = durationMin;
  _buzzerDurationsMax[object] = durationMax;
}

void TinyTrainable::setBuzzerDuration(int object, int *arrayDurations,
                                      int arrayDurationCount) {
  _buzzerDurationMode = randomParam;
  _buzzerDurationsArrays[object] = arrayDurations;
  _buzzerDurationsArraysSizes[object] = arrayDurationCount;
}

// modifies the input array to contain a buzzer frequency and duration (in that
// order) for the indicated object
void TinyTrainable::getBuzzerParam(int object, int buzzerParamArray[]) {
  switch (_buzzerFreqMode) {
  case singleParam:
    buzzerParamArray[0] = _buzzerFrequencies[object];
    break;
  case rangeParam:
    buzzerParamArray[0] =
        random(_buzzerFrequenciesMin[object], _buzzerFrequenciesMax[object]);
    break;
  case randomParam:
    int randomFreqIndex = rand() % _buzzerFrequenciesArraysSizes[object];
    buzzerParamArray[0] = *(_buzzerFrequenciesArrays[object] + randomFreqIndex);
    break;
  }
  switch (_buzzerDurationMode) {
  case singleParam:
    buzzerParamArray[1] = _buzzerDurations[object];
    break;
  case rangeParam:
    buzzerParamArray[1] =
        random(_buzzerDurationsMin[object], _buzzerFrequenciesMax[object]);
    break;
  case randomParam:
    int randomDurationIndex = rand() % _buzzerDurationsArraysSizes[object];
    buzzerParamArray[1] =
        *(_buzzerDurationsArrays[object] + randomDurationIndex);
    break;
  }
}

void TinyTrainable::setupOutputMIDI(byte midiChannel, byte midiVelocity) {
  _outputMode = outputMIDI;
  _midiChannel = midiChannel;
  _midiVelocity = midiVelocity;

  setupSerialMIDI();
}

void TinyTrainable::setMIDINotes(int object, int note) {
  _midiNotes[object] = note;
}

void TinyTrainable::setupOutputSerialUSB() {
  _outputMode = outputSerialUSB;

  Serial.begin(9600);
  while (!Serial)
    ;
}

#ifdef OUTPUT_SERVO_BLA
void TinyTrainable::setupOutputServo(int outputPin, int angleMin,
                                     int angleMax) {
  // TODO: add comments about each line
  _outputMode = outputServo;
  _outputPinServo = outputPin;
  _servoAngleMin = angleMin;
  _servoAngleMax = angleMax;

  pinMode(_outputPinServo, OUTPUT);
  _servo.attach(_outputPinServo);
}

void TinyTrainable::moveServo(int classification) {
  unsigned long servoPause = _servoPauses[classification];
  // update current time
  _servoTimeNow = millis();

  // if enough time has passed
  if (_servoTimeNow - _servoTimePrevious >= servoPause) {
    int angle =
        _servoAngleCurrent == _servoAngleMin ? _servoAngleMax : _servoAngleMin;
    // update _servoTimePrevious
    _servoTimePrevious = _servoTimeNow;
    _servo.write(angle);
    _servoAngleCurrent = angle;

    // if (random(1000)/1000.0 < servoChance) {
    // servoPositionsIndex = (servoPositionsIndex + 1);
    // servoPositionsIndex = servoPositionsIndex %
    // (sizeof(servoPositions)/sizeof(servoPositions[0]));
    // _servo.write(angle);
    // }
  }
}

void TinyTrainable::setServoTempo(int object, int tempo) {
  // divide by 2 because servo moves twice per cycle
  _servoPauses[object] = bpmToMs(tempo) / 2;
}

// helper function for transforming between
// beats per minute to ms per beat
int TinyTrainable::bpmToMs(int tempo) {
  int ms = 60000 / tempo;
  // return result
  return ms;
}
#endif

// sets up Serial MIDI output on TX pin
void TinyTrainable::setupSerialMIDI() {

  // open serial tranmission on TX pin
  Serial1.begin(9600);

  // desired baudrate for MIDI
  uint32_t baudrate = 0x800000;

  // declare pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = (uint32_t *)0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}

void TinyTrainable::sendSerialMIDINote(byte channel, byte note, byte velocity) {
  Serial1.write(143 + channel);
  Serial1.write(note);
  Serial1.write(velocity);
}

void TinyTrainable::setupOutputLED(int outputPin0, int outputPin1,
                                   int outputPin2) {
  _outputMode = outputLED;
  _outputPinsLED[0] = outputPin0;
  _outputPinsLED[1] = outputPin1;
  _outputPinsLED[2] = outputPin2;
  pinMode(outputPin0, OUTPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
}
