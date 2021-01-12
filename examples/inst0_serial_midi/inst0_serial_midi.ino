// include library
#include <Inst0.h>

Inst0 myInstrument;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {
  // setup instrument to output over midi, and printing debug statements
  myInstrument.setupInstrument(midiOut, true);

  // midi channel is 153 (0x99 in hex)
  // myInst0.setupMidi(153, 127);

  // setup global MIDI variables
  myInstrument.setSerialMIDIChannel(10);
  myInstrument.setSerialMIDIVelocity(127);

  // set MIDI note numbers
  myInstrument.setMIDINotes(37, 38, 39);

  myInstrument.setLabels("Object 0", "Object 1", "Object 2");
  myInstrument.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
  myInstrument.identify();
}
