#ifndef OUTPUT_MIDI_H
#define OUTPUT_MIDI_H

// include Arduino library
#include <Arduino.h>

// include TinyTrainable library
#include "TinyTrainable.h"

class OutputMIDI : public TinyTrainable {

public:
  void setupSerialMIDI();
  int _outputPinMIDI = -1;
  int _midiNotes[3];
  byte _midiChannel = 16;
  byte _midiVelocity = 0;

  // TODO: methods for MIDI
  void setupOutputMIDI(byte midiChannel, byte midiVelocity);
  void setMIDINotes(int object, int note);
};

#endif
