#ifndef OUTPUT_MIDI_H
#define OUTPUT_MIDI_H

// include Arduino library
#include <Arduino.h>

// include Output library
#include "Output.h"

// include TinyTrainable library
#include "TinyTrainable.h"

class OutputMIDI : public Output {

public:
  // constructor
  OutputMIDI();

  // TinyTrainable methods
  void playOutput(int classification);

  //   void setupSerialMIDI();
  int _outputPinMIDI = -1;
  int _midiNotes[3];
  byte _midiChannel = 16;
  byte _midiVelocity = 0;

  // TODO: this is public now for testing, later move to protected
  // void sendSerialMIDINote(byte channel, byte note, byte velocity);

  virtual void setupOutputMIDI(byte midiChannel, byte midiVelocity) override;
  virtual void setMIDINote(int object, int note) override;
  void setupSerialMIDI();

};

#endif
