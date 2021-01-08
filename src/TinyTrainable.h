// TinyTrainable.h - a library for Tiny Trainable Instruments
// a project by Aarón montoya-moraga
// with assistance by Peter Tone
// Started in November 2020
// MIT License

#ifndef _TINY_LIBRARY_H_
#define _TINY_LIBRARY_H_

// include Arduino library
#include <Arduino.h>

// colors for setting the embedded LED
enum Colors {red, green, blue, yellow, magenta, cyan};

class TinyTrainable {
  public:
    TinyTrainable();
    
    // template datatypes allows any datatype as an argument, like Serial.println().
    // it is defined here in the header file so it compiles at the beginning
    // and it can be used on inst0.cpp, among other
    template <typename T> void debugPrint(T message) {
      if (_serialDebugging) {
        Serial.println(message);
      }
    };

  protected:
    void setupLED();
    void setupSerial1();
    void setColorBuiltInLED(Colors color);
    void turnOffBuiltInLED();
    void midiCommand(byte midiNote);
    bool _serialDebugging;
    byte _midiChannelDec;
    byte _midiVelocity;
    // int _outputPin;
};

#endif
