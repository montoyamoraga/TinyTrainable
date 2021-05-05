/// @file TinyTrainable.h
/// @page TinyTrainable.h
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang

// conditional compilation
#ifndef TINY_TRAINABLE_H
#define TINY_TRAINABLE_H

// include library Arduino
#include <Arduino.h>

// include base libraries for input and output
#include "inputs/Input.h"
#include "outputs/Output.h"

enum InputType {
	INPUT_NONE = 0,
	INPUT_COLOR,
	INPUT_GESTURE,
	INPUT_SPEECH
};
enum OutputType {
	OUTPUT_NONE = 0,
	OUTPUT_BUZZER,
	OUTPUT_LCD,
	OUTPUT_LED,
	OUTPUT_MIDI,
	OUTPUT_PRINTER,
	OUTPUT_SERIAL,
	OUTPUT_SERVO
};

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
  // TinyTrainable(Input *newInput, Output *newOutput);
  TinyTrainable(InputType inputType, OutputType outputType);
  // destructor
  ~TinyTrainable();

  // template datatypes allows any datatype as an argument
  
  
  template <typename T> void debugPrint(T message) {
    #ifdef DEBUG_TINY
    if (this->_serialDebugging) {
      Serial.print("debug - ");
      Serial.println(message);
    }
    #endif
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
  void setupTF(String gestures[3], float accelerationThreshold, int numSamples);

  // methods for input speech

  // methods for outputs
  //   void helloOutputsSetup(OutputMode outputToTest);
  //   void helloOutputsSetup(OutputMode outputToTest, int outputPin);
  //   void helloOutputs(OutputMode outputToTest);
  void playOutput(int classification);

  // declaration of functions for output buzzer
  void setupOutputBuzzer(int outputPin);
  void getBuzzerParam(int object, int buzzerParamArray[]);
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

  // methods for output LED
  void setupOutputLED(int object, int outputPin);

  // methods for output MIDI
  void setupOutputMIDI(byte midiChannel);
  void setMIDINote(int object, int note);
  void sendMIDINoteOn(byte channel, byte note, byte velocity);
  void sendMIDINoteOff(byte channel, byte note);
  void sendMIDIAllNotesOff(byte channel);

  // methods for output printer
  void setupOutputPrinter();
  void setPrinterBaudRate(int rate);
  void setPrinterBegin();
  void setPrinterPause(int pause);
  void setPrinterSleep();
  void setPrinterWake();
  void setPrinterTest();

  // methods for output serial
  void setupOutputSerial();

  // methods for output servo
  void setupOutputServo(int outputPin);
  void setServoTempo(int object, int tempo);
  int bpmToMs(int tempo);
  void setServoMaxAngle(int angle);
  void setServoMinAngle(int angle);
  int getServoMaxAngle();
  int getServoMinAngle();
  void moveServo(int classification);

  void setStateLEDBuiltIn(bool turnOn);
  void blinkLEDBuiltIn(int blinks);
  void setStateLEDRGB(bool turnOn, Colors color);
  // TODO: maybe change name, still thinking about it
  //   void errorBlink(Colors color, int blinkNum);
};

// conditional compilation
#endif
