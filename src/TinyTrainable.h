// TinyTrainable.h - a library for Tiny Trainable Instruments
// a project by Aarón Montoya-Moraga
// with assistance by Peter Tone
// Started in November 2020
// MIT License

#ifndef TINY_TRAINABLE_H
#define TINY_TRAINABLE_H

// include Arduino library
#include <Arduino.h>

// include library for proximity and light sensor
// https://www.arduino.cc/en/Reference/ArduinoAPDS9960
#include <Arduino_APDS9960.h>

// include library for temperature and humidity sensor
// https://www.arduino.cc/en/Reference/ArduinoHTS221
#include <Arduino_HTS221.h>

// include library for pressure sensor
// https://www.arduino.cc/en/Reference/ArduinoLPS22HB/
#include <Arduino_LPS22HB>

// include library for IMU sensor
// 3-axis accelerometer, 3-axis gyroscope, 3-axis magnetometer
// https://www.arduino.cc/en/Reference/ArduinoLSM9DS1/
#include <Arduino_LSM9DS1>

// colors for setting the RGB LED
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

    void setupLEDs();
    void setupLEDBuiltIn();
    void turnOnLEDBuiltIn();
    void turnOffLEDBuiltIn();
    void setupLEDRGB();
    void turnOnLEDRGB(Colors color);
    void turnOffLEDRGB();

    void setupSerialMIDI();
    void setSerialMIDIChannel(byte midiChannel);
    void setSerialMIDIVelocity(byte midiVelocity);
    void sendSerialMIDINote(byte channel, byte note, byte velocity);


    // void midiCommand(byte midiNote);

  protected:
    bool _serialDebugging;
    byte _midiChannel;
    byte _midiVelocity;
    int _outputPin;
};

#endif
