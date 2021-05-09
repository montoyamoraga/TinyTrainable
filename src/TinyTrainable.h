/// @file TinyTrainable.h
/// @brief Arduino library for Tiny Trainable Instruments
/// @author montoyamoraga, peter-parque, maxzwang

// conditional compilation
#ifndef TINY_TRAINABLE_H
#define TINY_TRAINABLE_H

/// @include library Arduino
#include <Arduino.h>

/// @include base library iIput
#include "inputs/Input.h"

/// @include base library Output
#include "outputs/Output.h"

/// @enum to set the input type
enum InputType {
  INPUT_NONE = 0,
  INPUT_COLOR = 1,
  INPUT_GESTURE = 2,
  INPUT_SPEECH = 3
};

/// @enum to set the output type
enum OutputType {
  OUTPUT_NONE = 0,
  OUTPUT_BUZZER = 1,
  OUTPUT_LED = 2,
  OUTPUT_MIDI = 3,
  OUTPUT_PRINTER = 4,
  OUTPUT_SCREEN = 5,
  OUTPUT_SERIAL = 6,
  OUTPUT_SERVO = 7
};

/// @enum colors for setting the RGB LED
enum Colors { red = 0, green = 1, blue = 2, yellow = 3, magenta = 4, cyan = 5 };

/// @class TinyTrainable
/// @brief TinyTrainable base class
class TinyTrainable {

protected:
  /// @brief Input pointer
  Input *myInput = nullptr;

  /// @brief Output pointer
  Output *myOutput = nullptr;

  /// @brief pin for output
  //   int _outputPinTest = -1;

public:
  /// @brief static boolean, toggles debugging over serial port
  static bool _serialDebugging;

  /// @brief static integer, baud rate for serial communication
  static int _baudRate;

  /// @brief static integer, time for blinking LED
  static int _timeBlinkLED;

  /// @brief TinyTrainable constructor
  /// @param InputType
  /// @param OutputType
  TinyTrainable(InputType inputType, OutputType outputType);

  /// @brief TinyTrainable destructor
  ~TinyTrainable();

  // template datatypes allows any datatype as an argument
  template <typename T> void debugPrint(T message) {
    if (this->_serialDebugging) {
      Serial.print("debug - ");
      Serial.println(message);
    }
  };

  /// @brief setup debugging
  /// @param serialDebugging to toggle serial debugging on/off
  void setupInstrument(bool serialDebugging);

  /// @brief initialize LEDs of Arduino
  void setupLEDs();

  /// @brief set state of LED built-in
  /// @param turnOn boolean, on/off
  void setStateLEDBuiltIn(bool turnOn);

  /// @brief set state of LED RGB
  /// @param turnOn boolean, on/off
  /// @param color Color
  void setStateLEDRGB(bool turnOn, Colors color);

  /// @brief blink LED built-in
  /// @param blinks integer, number of blinks
  void blinkLEDBuiltIn(int blinks);

  /// @brief blink LED RGB
  /// @param blinks integer, number of blinks
  void blinkLEDRGB(int blinks, Colors color);

  /// @brief blink LEDs
  /// @param color Color
  void errorBlink(Colors color);

  /// @brief input, identify class
  void identify();

  /// @brief input color, train KNN algorithm
  /// @param k int, for KNN
  /// @param examplesPerClass int, examples per class
  /// @param colorThreshold float, threshold of color for algorithm
  /// @param objects[] String array, names of classes
  void trainKNN(int k, int examplesPerClass, float colorThreshold,
                String objects[3]);

  /// @brief input gesture, setup TensorFlow model
  void gestureSetupTF(String gestures[3], const unsigned char *model = nullptr);

  /// @brief input gesture, print header for database
  void gesturePrintHeader();

  /// @brief input gesture, read data for database
  void gestureReadData();

  /// @brief input speech, setup TensorFlow model
  void speechSetupTF(String sounds[3], const unsigned char *model = nullptr);

  // methods for outputs

  /// @brief output, test if it is working
  void setupOutputTest();

  /// @brief output, react to classification
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

  // methods for output screen
  void setupOutputScreen();
  void screenDrawWelcome();

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
};

// conditional compilation
#endif
