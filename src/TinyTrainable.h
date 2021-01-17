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
#include <Arduino_LPS22HB.h>

// include library for IMU sensor
// 3-axis accelerometer, 3-axis gyroscope, 3-axis magnetometer
// https://www.arduino.cc/en/Reference/ArduinoLSM9DS1/
#include <Arduino_LSM9DS1.h>

// include Servo library
// #include <Servo.h>

// include Adafruit Thermal Printer library
#include <Adafruit_Thermal.h>

// colors for setting the RGB LED
enum Colors {red = 0, green = 1, blue= 2, yellow = 3, magenta = 4, cyan = 5};

enum OutputMode {outputBuzzer = 0, outputLCD = 1, outputLED = 2, outputMIDI = 3, outputPrinter = 4, outputSerialUSB = 5, outputServo = 6};

// instead of using numbers to represent the different output modes,
// enum makes the code more readable in if and switch statements
// TODO: i think this should go on TinyTrainable, not here
// since we will be using the same outputs on all the instruments
// and instead of this modes, i would have all the different outputs
// we have so far for inst0, such as: buzzer, midi, servo, etc
enum OutputMode {undefined = 0, usbOut = 1, midiOut = 2, pinOut = 3};

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
    
    // methods for LEDs
    // there are two: built-in orange and RGB
    void setupLEDs();
    void setupLEDBuiltIn();
    void turnOnLEDBuiltIn();
    void turnOffLEDBuiltIn();
    void blinkLEDBuiltIn(int blinks);
    void setupLEDRGB();
    void turnOnLEDRGB(Colors color);
    void turnOffLEDRGB();
    void errorBlink(Colors color, int blinkNum);

    // methods for debugging
    void setSerialDebugging(bool serialDebugging);

    // methods for input sensors
    // TODO: add all sensors on the Arduino Nano BLE 33 Sense
    // APDS9960 sensor for gestures, color, light intensity, proximity 
    void setupSensorAPDS9960();

    // include library for temperature and humidity sensor
    // https://www.arduino.cc/en/Reference/ArduinoHTS221
    void setupSensorHTS221();

    // include library for pressure sensor
    // https://www.arduino.cc/en/Reference/ArduinoLPS22HB/
    void setupSensorLPS22HB();
    
    // LSM9DS1 sensor for IMU (inertial measurement unit)
    //  3-axis accelerometer, gyroscope, magnetometer
    void setupSensorLSM9DS1();

    // TODO: moved from Inst0.h, refactor
    void setOutputMode(OutputMode mode);

    // TODO: methods for outputBuzzer
    void setBuzzerPin(int outputPin);
    void setBuzzerFrequencies(int freq0, int freq1, int freq2);
    void setBuzzerDurations(long newDuration);
    // TODO: methods for outputLCD
    // TODO: methods for outputLED
    // TODO: methods for outputMIDI
    // TODO: methods for outputPrinter
    // TODO: methods for outputSerialUSB
    // TODO: methods for outputServo
    void setServoPin(int outputPin);
    void setServoAngles(int angle0, int angle1, int angle2);
    void setServoAngle(int angle);
    // methods for output MIDI
    void setupSerialMIDI();
    void setSerialMIDIChannel(byte midiChannel);
    void setSerialMIDIVelocity(byte midiVelocity);
    void sendSerialMIDINote(byte channel, byte note, byte velocity);

  protected:
    
    // true: instrument outputs debugging messages over USB serial
    // false: standalone instrument, no debugging message
    bool _serialDebugging = false;
    // variable to store the output mode of the instrument
    OutputMode _outputMode;

    // variables for outputs
    int _outputPinBuzzer = -1;
    int _outputPinLCD = -1;
    int _outputPinLED = -1;
    int _outputPinMIDI = -1;
    // TODO: this might need to be several variables
    int _outputPinPrinter = -1;
    // TODO: delete _outputSerialUSB? since we don't need a pin for USB
    int _outputSerialUSB = -1;
    int _outputPinServo = -1;

    // TODO: variables for outputBuzzer
    int _buzzerFrequencies[3];
    // TODO: does this need to be a long? can it be an int?
    long _buzzerDuration = 1000;
    // TODO: variables for outputLCD
    // TODO: variables for outputLED
    // TODO: variables for outputMIDI
    int _midiNotes[3];
    byte _midiChannel = 1;
    byte _midiVelocity = 127;
    // TODO: variables for outputPrinter
    // TODO: variables for outputSerialUSB
    // TODO: variables for outputServo
    Servo _servo;
    int _servoAngleCurrent = 0;
    int _servoAngleMin = 0;
    int _servoAngleMax = 180;
    int _servoAngles[3];
};

#endif
