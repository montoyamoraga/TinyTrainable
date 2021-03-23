/// @file hello_midi.ino
/// @brief Example: Test MIDI output

#include <TinyTrainable.h>

#define TINY_OUTPUT "MIDI"

TinyTrainable tiny;

// MIDI sound numbers
int MIDINotes[3] = {37, 38, 39};

// midi channel and velocity in decimal (not hex)
int midiChannel = 10;
int midiVelocity = 127;

int pauseTime = 1000;

void setup() {
  tiny.setupOutputMIDI(midiChannel, midiVelocity);

  // set the MIDI note for each object
  tiny.setMIDINotes(0, MIDINotes[0]);
  tiny.setMIDINotes(1, MIDINotes[1]);
  tiny.setMIDINotes(2, MIDINotes[2]);
}

void loop() {
  // play the output associated with each object
  tiny.playOutput(0);
  delay(pauseTime);
  tiny.playOutput(1);
  delay(pauseTime);
  tiny.playOutput(2);
  delay(pauseTime);

  // or directly send a command to your MIDI device!
  // these parameters can be different from those above
  tiny.sendSerialMIDINote(midiChannel, 56, midiVelocity);
  delay(pauseTime);
  tiny.sendSerialMIDINote(midiChannel, 49, midiVelocity);
  delay(pauseTime);
  tiny.sendSerialMIDINote(midiChannel, 70, midiVelocity);
  delay(pauseTime);
}
