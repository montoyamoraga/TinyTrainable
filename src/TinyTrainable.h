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
enum Colors {red = 0, green = 1, blue = 2, yellow = 3, magenta = 4, cyan = 5};

class TinyTrainable {
  public:
    // constructor method
    TinyTrainable();
    
    // template datatypes allows any datatype as an argument, like Serial.println().
    // it is defined here in the header file so it compiles at the beginning
    template <typename T> void debugPrint(T message) {
      if (_serialDebugging) {
        Serial.println(message);
      }
    };

    void setupLEDBuiltIn();
    void turnOnLEDBuiltIn();
    void turnOffLEDBuiltIn();

    void setupLEDRGB();
    void turnOnLEDRGB(Colors color);
    void turnOffLEDRGB();



    void setupSerial1();
    void midiCommand(byte midiNote);

  protected:
    bool _serialDebugging;
    byte _midiChannelDec;
    byte _midiVelocity;
    int _outputPin;
};

#endif
