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
  virtual void sendSerialMIDINote(byte channel, byte note, byte velocity) override;
  void setupSerialMIDI();

  // TODO: in progress

  // notes for volca beats
  byte noteBassDrum = 36;
  byte noteSnare = 38;
  byte noteClosedHiHat = 42;
  byte noteHiTom = 50;

  int currentStep = 0;
  int totalSteps = 16;

  // 0 - bossanova, 1 - chacha, 2 - samba
  int currentGenre = 2;

  int tempoDelay = 100;




  // drum patterns
  byte bossanovaBD[] = {1, 0, 0, 0,
                      0, 0, 1, 0,
                      1, 0, 0, 0,
                      0, 0, 1, 0
                     };

byte bossanovaSN[] = {1, 0, 0, 0,
                      0, 0, 1, 0,
                      0, 0, 0, 0,
                      1, 0, 0, 0
                     };

byte bossanovaCH[] = {1, 0, 1, 0,
                      1, 0, 1, 0,
                      1, 0, 1, 0,
                      1, 0, 1, 0
                     };

byte bossanovaHT[] = {0, 0, 0, 0,
                      0, 0, 0, 0,
                      0, 0, 0, 0,
                      0, 0, 0, 0
                     };

byte chachaBD[] = {1, 0, 0, 0,
                   0, 0, 1, 0,
                   1, 0, 0, 0,
                   0, 0, 1, 0
                  };


byte chachaSN[] = {0, 0, 0, 0,
                   0, 0, 0, 0,
                   0, 0, 0, 0,
                   1, 0, 1, 0
                  };


byte chachaCH[] = {0, 0, 0, 0,
                   1, 0, 0, 0,
                   0, 0, 0, 0,
                   1, 0, 0, 0
                  };


byte chachaHT[] = {0, 0, 1, 0,
                   0, 0, 1, 0,
                   0, 0, 0, 0,
                   0, 0, 0, 0
                  };



byte sambaBD[] = {1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1,
                  1, 0, 0, 1
                 };


byte sambaSN[] = {0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 1,
                  0, 0, 0, 0
                 };


byte sambaCH[] = {0, 1, 1, 0,
                  0, 1, 1, 0,
                  0, 1, 1, 0,
                  0, 1, 1, 0
                 };


byte sambaHT[] = {1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0,
                  1, 0, 0, 0
                 };

};

#endif
