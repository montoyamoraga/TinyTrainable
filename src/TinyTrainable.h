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

#ifdef OUTPUT_BUZZER
  #include "outputs/OutputBuzzer.h"
#endif

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

#ifdef OUTPUT_SERVO
  #include "outputs/OutputServo.h"
#endif

// colors for setting the RGB LED
// enum Colors { red = 0, green = 1, blue = 2, yellow = 3, magenta = 4, cyan = 5
// };

/// \class TinyTrainable
/// \brief TinyTrainable base class
class TinyTrainable {

  // public methods
public:
  // member variables
  // input and output
  Input myInput;
  Output myOutput;

  // constructor
  TinyTrainable();
  TinyTrainable(Input newInput, Output newOutput);

    // methods for outputs
  //   void helloOutputsSetup(OutputMode outputToTest);
  //   void helloOutputsSetup(OutputMode outputToTest, int outputPin);
  //   void helloOutputs(OutputMode outputToTest);
  virtual void playOutput(int classification){};

  // declaration of virtual functions for servo
  virtual void setupOutputServo(int outputPin, int servoAngleMin, int servoAngleMax){};
  virtual void setServoTempo(int object, int tempo){};
  virtual int bpmToMs(int tempo){}; 
  virtual void moveServo(int classification){};

  // template datatypes allows any datatype as an argument, like
  // Serial.println(). it is defined here in the header file so it compiles at
  // the beginning
  //   template <typename T> void debugPrint(T message) {
  //     if (_serialDebugging) {
  //       Serial.print("debug - ");
  //       Serial.println(message);
  //     }
  //   };

  //   void setStateLEDBuiltIn(bool turnOn);
  //   void blinkLEDBuiltIn(int blinks);
  //   void setStateLEDRGB(bool turnOn, Colors color);
  // TODO: maybe change name, still thinking about it
  //   void errorBlink(Colors color, int blinkNum);

  // TODO: methods for outputSerialUSB
  //   void setupOutputSerialUSB();

protected:
  //   void setupLEDs();

  // methods for input sensors
  //   void setupSensorAPDS9960();
  //   void setupSensorLSM9DS1();

  // variable for debugging
  //   bool _serialDebugging = false;

  // variables for outputs
    int _outputPinTest = -1;
};

// conditional compilation
#endif
