/// @file TinyTrainable.h
/// @page TinyTrainable.h
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang

// conditional compilation
#ifndef TINY_TRAINABLE_H
#define TINY_TRAINABLE_H

// include Arduino library
#include <Arduino.h>

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
      Serial.print("debug - ");
      Serial.println(message);
    }
  };

  void setStateLEDBuiltIn(bool turnOn);
  void blinkLEDBuiltIn(int blinks);
  void setStateLEDRGB(bool turnOn, Colors color);
  // TODO: maybe change name, still thinking about it
  void errorBlink(Colors color, int blinkNum);

  // methods for outputs
  void helloOutputsSetup(OutputMode outputToTest);
  void helloOutputsSetup(OutputMode outputToTest, int outputPin);
  void helloOutputs(OutputMode outputToTest);
  void playOutput(int classification);

  // methods for servo
  void setupOutputServo(int outputPin, int angleMin, int angleMax);
  // for servo tempo in bpm
  void setServoTempo(int object, int tempo);
  // for servo movement
  void moveServo(int classification);
  int bpmToMs(int tempo);

  // TODO: methods for outputLCD

  // TODO: methods for outputLED
  void setupOutputLED(int outputPin0, int outputPin1, int outputPin2);

  // TODO: methods for MIDI
  void setupOutputMIDI(byte midiChannel, byte midiVelocity);
  void setMIDINotes(int object, int note);

  // TODO: methods for outputPrinter

  // TODO: methods for outputSerialUSB
  void setupOutputSerialUSB();

  // TODO: this is public now for testing, later move to protected
  void sendSerialMIDINote(byte channel, byte note, byte velocity);

protected:
  void setupLEDs();

  // methods for input sensors
  // TODO: decide which sensors will be used
  void setupSensorAPDS9960();
  void setupSensorLSM9DS1();

  // methods for outputs
  
  void getBuzzerParam(int object, int buzzerParamArray[]);

  // variable for debugging
  bool _serialDebugging = false;

  // variables for outputs
  OutputMode _outputMode = outputUndefined;
  int _outputPinTest = -1;

};

// conditional compilation
#endif
