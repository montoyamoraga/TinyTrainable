// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_MIDI);

// MIDI note numbers
int myNotes[3] = {37, 38, 39};

// channel and velocity in decimal (not hex)
int myChannel = 10;
int myVelocity = 127;

int pauseTime = 1000;

void setup() {
  myTiny.setupOutputMIDI(myChannel);

  // set the MIDI note for each object
  //  myTiny.setMIDINote(0, myTiny.noteBassDrum);
  myTiny.setMIDINote(0, myNotes[0]);
  myTiny.setMIDINote(1, myNotes[1]);
  myTiny.setMIDINote(2, myNotes[2]);
}

void loop() {
  // play the output associated with each object
  myTiny.playOutput(0);
  delay(pauseTime);
  myTiny.playOutput(1);
  delay(pauseTime);
  myTiny.playOutput(2);
  delay(pauseTime);

  // or directly send a command to your MIDI device!
  // these parameters can be different from those above
  myTiny.sendMIDINoteOn(myChannel, 56, myVelocity);
}
