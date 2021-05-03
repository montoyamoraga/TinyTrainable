#ifndef OUTPUT_H
#define OUTPUT_H

// include Arduino library
#include <Arduino.h>

// Forwards declaration of class TinyTrainable
// this is to avoid a circular include when TinyTrainable includes this class
class TinyTrainable;

class Output {
public:
  // methods for output
  virtual void playOutput(int classification) {}

  // methods for buzzer
  virtual void setupOutputBuzzer(int outputPin) {}
  virtual void getBuzzerParam(int object, int buzzerParamArray[]) {}
  // for frequencies
  virtual void setBuzzerFrequency(int object, int frequency) {}
  virtual void setBuzzerFrequency(int object, int freqMin, int freqMax) {}
  virtual void setBuzzerFrequency(int object, int *arrayFrequencies,
                                  int arrayFreqCount) {}
  virtual void setBuzzerDuration(int object, int duration) {}
  virtual void setBuzzerDuration(int object, int durationMin, int durationMax) {
  }
  virtual void setBuzzerDuration(int object, int *arrayDurations,
                                 int arrayDurationCount) {}

  // functions for output LED
  virtual void setupOutputLED(int outputPin0, int outputPin1, int outputPin2) {}

  // functions for output MIDI
  virtual void setupOutputMIDI(byte midiChannel){}
  virtual void setMIDINote(int object, int note){}
  virtual void sendMIDINoteOn(byte channel, byte note, byte velocity){}
  virtual void sendMIDINoteOff(byte channel, byte note){}
  virtual void sendMIDIAllNotesOff(byte channel){}


  // functions for output serial
  virtual void setupOutputSerial() {}

  // functions for output servo
  virtual void setupOutputServo(int outputPin) {}
  virtual void setServoTempo(int object, int tempo) {}
  virtual int bpmToMs(int tempo) { return 0; }
  virtual void setServoMaxAngle(int angle) {}
  virtual void setServoMinAngle(int angle) {}
  virtual int getServoMaxAngle() { return 0; }
  virtual int getServoMinAngle() { return 0; }
  virtual void moveServo(int classification) {}

  // protected:
  TinyTrainable *tiny = nullptr;
};

#endif
