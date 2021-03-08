/// @file TinyTrainable.h
/// @page TinyTrainable.h
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang
/// @date November 2020

// conditional compilation
#ifndef TINY_TRAINABLE_H
#define TINY_TRAINABLE_H

// include Arduino library
#include <Arduino.h>

// include library for proximity and light sensor
// https://www.arduino.cc/en/Reference/ArduinoAPDS9960
#include <Arduino_APDS9960.h>

// include library for temperature and humidity sensor
// https://www.arduino.cc/en/Reference/ArduinoHTS221
// TODO: decide if this library is needed
// #include <Arduino_HTS221.h>

// include library for pressure sensor
// https://www.arduino.cc/en/Reference/ArduinoLPS22HB/
// TODO: decide if this library is needed
// #include <Arduino_LPS22HB.h>

// include library for IMU sensor
// 3-axis accelerometer, 3-axis gyroscope, 3-axis magnetometer
// https://www.arduino.cc/en/Reference/ArduinoLSM9DS1/
#include <Arduino_LSM9DS1.h>

// include library for servo motors
// #include <Servo.h>  // keeps giving me compilation errors

// include library for Adafruit thermal printer
// TODO: uncomment later when this is being tested
// #include <Adafruit_Thermal.h>

// colors for setting the RGB LED
enum Colors { red = 0, green = 1, blue = 2, yellow = 3, magenta = 4, cyan = 5 };

// different instrument output modes
// TODO - check they are the same order as .cpp file
enum OutputMode {
  outputBuzzer = 0,
  outputLCD = 1,
  outputLED = 2,
  outputMIDI = 3,
  outputPrinter = 4,
  outputSerialUSB = 5,
  outputServo = 6,
  outputUndefined = 7
};

/// \class TinyTrainable
/// \brief TinyTrainable base class
///
class TinyTrainable {

  // public methods
public:
  // constructor
  TinyTrainable();

  // template datatypes allows any datatype as an argument, like
  // Serial.println(). it is defined here in the header file so it compiles at
  // the beginning
  template <typename T> void debugPrint(T message) {
    if (_serialDebugging) {
      Serial.println(message);
    }
  };

  void setStateLEDBuiltIn(bool turnOn);
  void blinkLEDBuiltIn(int blinks);
  void setStateLEDRGB(bool turnOn, Colors color);
  // TODO: maybe change name, still thinking about it
  void errorBlink(Colors color, int blinkNum);

  // methods for outputs
  void helloOutputsSetup(OutputMode outputToTest, int outputPin);
  void helloOutputs(OutputMode outputToTest);
  void playOutput(int classification);

  // methods for buzzer
  void setupOutputBuzzer(int outputPin);
  // for frequencies
  void setBuzzerFrequency(int object, int frequency);
  void setBuzzerFrequency(int object, int freqMin, int freqMax);
  void setBuzzerFrequency(int object, int *arrayFrequencies,
                          int arrayFreqCount);
  // for durations
  void setBuzzerDuration(int object, int duration);
  void setBuzzerDuration(int object, int durationMin, int durationMax);
  void setBuzzerDuration(int object, int *arrayDurations,
                         int arrayDurationCount);

  // methods for servo
  void setupOutputServo(int outputPin);
  // for setting minimum and maximum angles
  void setServoAngleRange(int angleMin, int angleMax);
  // for servo movement
  void moveServoAngleTempo(int angle, int tempo);
  // for servo tempo
  void setServoTempo(int object, int tempo);
  int bpmToMs(int tempo);

  // TODO: methods for outputLCD

  // TODO: methods for outputLED

  // TODO: methods for MIDI
  void setupOutputMIDI(byte midiChannel, byte midiVelocity);
  void setMIDINotes(int object, int note);

  // TODO: methods for outputPrinter

  // TODO: methods for outputSerialUSB
  void setupOutputSerialUSB();

protected:
  void setupLEDs();

  // methods for input sensors
  // TODO: decide which sensors will be used
  void setupSensorAPDS9960();
  // void setupSensorHTS221();
  // void setupSensorLPS22HB();
  void setupSensorLSM9DS1();

  // methods for outputs
  void setupSerialMIDI();
  void sendSerialMIDINote(byte channel, byte note, byte velocity);
  void getBuzzerParam(int object, int buzzerParamArray[]);

  // variable for debugging
  bool _serialDebugging = false;

  // variables for outputs
  OutputMode _outputMode = outputUndefined;
  // TODO - these variables are not exposed to the user,
  // peter suggests that all these pin variables be condensed to one variable
  // that get set through different methods
  // i rather not for now, so that the instrument can have different outputs at
  // the same time
  int _outputPinTest = -1;
  int _outputPinBuzzer = -1;
  int _outputPinLCD = -1;
  int _outputPinLED = -1;
  int _outputPinMIDI = -1;
  // TODO: for printer we need several variables
  int _outputPinPrinter = -1;
  int _outputPinServo = -1;

  // methods and variables for outputBuzzer
  enum BuzzerMode { singleParam, rangeParam, randomParam, undefParam };
  BuzzerMode _buzzerFreqMode = undefParam;
  BuzzerMode _buzzerDurationMode = undefParam;
  int _buzzerParams[2]; // to hold the freq and duration each loop
  // for singleParam
  int _buzzerFrequencies[3];
  int _buzzerDurations[3];
  // for rangeParam
  int _buzzerFrequenciesMin[3];
  int _buzzerFrequenciesMax[3];
  int _buzzerDurationsMin[3];
  int _buzzerDurationsMax[3];
  // for randomParam
  int *_buzzerFrequenciesArrays[3];
  int _buzzerFrequenciesArraysSizes[3];
  int *_buzzerDurationsArrays[3];
  int _buzzerDurationsArraysSizes[3];

  // TODO: variables for outputMIDI
  int _midiNotes[3];
  byte _midiChannel = 16;
  byte _midiVelocity = 0;

  // TODO: variables for outputServo
  // Servo _servo;
  int _servoAngleCurrent = 0;
  int _servoAngleMin = 0;
  int _servoAngleMax = 180;
  int _servoTempos[3];
  float _servoChances[3];
  unsigned long _servoTimePrevious = 0;
  unsigned long _servoTimeNow = 0;

  // TODO: variables for outputLCD
  // TODO: variables for outputLED
  // TODO: variables for outputPrinter
  // TODO: variables for outputSerialUSB
};

// conditional compilation
#endif
