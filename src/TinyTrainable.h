/// @file TinyTrainable.h
/// @page TinyTrainable.h
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang

// conditional compilation
#ifndef TINY_TRAINABLE_H
#define TINY_TRAINABLE_H

// include Arduino library
#include <Arduino.h>

// include base libraries for input and output
#include "inputs/Input.h"
#include "outputs/Output.h"

// conditionally include input libraries
#ifdef INPUT_COLOR
#include "inputs/InputColor.h"
#endif

#ifdef INPUT_GESTURE
#include "inputs/InputGesture.h"
#endif

#ifdef INPUT_SPEECH
#include "inputs/InputSpeech.h"
#endif

// conditionally include output libraries

// #ifdef OUTPUT_BUZZER
#include "outputs/OutputBuzzer.h"
// #endif

#ifdef OUTPUT_LCD
#include "outputs/OutputLCD.h"
#endif

#ifdef OUTPUT_LED
#include "outputs/OutputLED.h"
#endif

#ifdef OUTPUT_MIDI
#include "outputs/OutputMIDI.h"
#endif

#ifdef OUTPUT_PRINTER
#include "outputs/OutputPrinter.h"
#endif

#ifdef OUTPUT_SERIAL
#include "outputs/OutputSerial.h"
#endif

#ifdef OUTPUT_SERVO
#include "outputs/OutputServo.h"
#endif

// colors for setting the RGB LED
enum Colors { red = 0, green = 1, blue = 2, yellow = 3, magenta = 4, cyan = 5 };

/// \class TinyTrainable
/// \brief TinyTrainable base class
class TinyTrainable {

protected:
  // input and output
  // asterisks are pointers
  Input *myInput = nullptr;
  Output *myOutput = nullptr;

  // variables for outputs
  int _outputPinTest = -1;

public:
  // constructor
  TinyTrainable(Input *newInput, Output *newOutput);

  // destructor
  ~TinyTrainable();

  // template datatypes allows any datatype as an argument
  template <typename T> void debugPrint(T message) {
    if (this->_serialDebugging) {
      Serial.print("debug - ");
      Serial.println(message);
    }
  };

  // TODO: this override works, do it for other functions
  // override magic by roy~
  void setupInstrument(bool serialDebugging);

  // variable for debugging
  // TODO: add explanation about static
  // static makes this property to be global for all the instances of the class
  static bool _serialDebugging;
  static int _baudRate;

  // methods for input

  // methods for input color
  void trainKNN(int k, int examplesPerClass, float colorThreshold,
                String objects[3]);
  void identify();

  void setupLEDs();

  // methods for input gesture

  // methods for input speech

  // methods for outputs
  //   void helloOutputsSetup(OutputMode outputToTest);
  //   void helloOutputsSetup(OutputMode outputToTest, int outputPin);
  //   void helloOutputs(OutputMode outputToTest);
  void playOutput(int classification);

  // declaration of functions for output buzzer
  void setupOutputBuzzer(int outputPin);
  void getBuzzerParam(int object, int buzzerParamArray[]){};
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

  // functions for output LED
  void setupOutputLED(int outputPin0, int outputPin1, int outputPin2);

  // functions for output MIDI
  void setupOutputMIDI(byte midiChannel, byte midiVelocity);
  void setMIDINote(int object, int note);

  // declaration of virtual functions for output serial
  void setupOutputSerial();
  
  // declaration of functions for output servo
  void setupOutputServo(int outputPin, int servoAngleMin,
                                int servoAngleMax);
  void setServoTempo(int object, int tempo);
  int bpmToMs(int tempo);
  void moveServo(int classification);

  void setStateLEDBuiltIn(bool turnOn);
  void blinkLEDBuiltIn(int blinks);
  void setStateLEDRGB(bool turnOn, Colors color);
  // TODO: maybe change name, still thinking about it
  //   void errorBlink(Colors color, int blinkNum);
};

// conditional compilation
#endif
