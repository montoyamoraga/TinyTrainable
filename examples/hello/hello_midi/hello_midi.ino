/// @file hello_midi.ino
/// @brief Test output with MIDI

// define input and output
#define INPUT_NONE
#define OUTPUT_MIDI

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(new Input(), new OutputMIDI());

// MIDI note numbers
int myNotes[3] = {37, 38, 39};

// midi channel and velocity in decimal (not hex)
int myChannel = 10;
int myVelocity = 127;

int pauseTime = 1000;

void setup() {
  myTiny.setupOutputMIDI(myChannel);

  // set the MIDI note for each object
  myTiny.setMIDINote(0, myNotes[0]);
  myTiny.setMIDINote(1, myNotes[1]);
  myTiny.setMIDINote(2, myNotes[2]);
}

void loop() {
  // play the output associated with each object
  //  tiny.playOutput(0);
  //  delay(pauseTime);
  //  tiny.playOutput(1);
  //  delay(pauseTime);
  //  tiny.playOutput(2);
  //  delay(pauseTime);

  // or directly send a command to your MIDI device!
  // these parameters can be different from those above
  //  tiny.sendSerialMIDINote(midiChannel, 56, midiVelocity);
  //  delay(pauseTime);
  //  tiny.sendSerialMIDINote(midiChannel, 49, midiVelocity);
  //  delay(pauseTime);
  //  tiny.sendSerialMIDINote(midiChannel, 70, midiVelocity);
  //  delay(pauseTime);
}
