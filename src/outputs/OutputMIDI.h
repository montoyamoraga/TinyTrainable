/// @file OutputMIDI.h
/// @brief Output MIDI

#ifndef OUTPUT_MIDI_H
#define OUTPUT_MIDI_H

/// @include Arduino library
#include <Arduino.h>

/// @include Output library
#include "Output.h"

/// @include TinyTrainable library
#include "TinyTrainable.h"

// TODO: include MIDIPatterns.h
// #include "MIDIPatterns.h"

/// @class OutputMIDI
/// @brief OutputMIDI inherits from Output
class OutputMIDI : public Output {

public:
  // constructor
  OutputMIDI();

  // TinyTrainable methods
  virtual void setupOutputTest() override;
  virtual void playOutput(int classification) override;

  int _outputPinMIDI = -1;
  int _midiNotes[3];
  byte _midiChannel = 16;
  byte _midiVelocity = 127;

  virtual void setupOutputMIDI(byte midiChannel) override;
  virtual void setMIDINote(int object, int note) override;
  virtual void sendMIDINoteOn(byte channel, byte note, byte velocity) override;
  virtual void sendMIDINoteOff(byte channel, byte note) override;
  virtual void sendMIDIAllNotesOff(byte channel) override;
  void setupSerialMIDI();

  // notes for volca beats
//   byte noteBassDrum = 36;
//   byte noteSnare = 38;
//   byte noteClap = 39;
//   byte noteClosedHiHat = 42;
//   byte noteLowTom = 43;
//   byte noteOpenHiHat = 46;
//   byte noteHiTom = 50;

  int currentStep = 0;
  int totalSteps = 16;

  // 0 - bossanova, 1 - chacha, 2 - samba
  int currentGenre = -1;

  int tempoDelay = 100;
};

#endif
