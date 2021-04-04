// include header file
#include "OutputMIDI.h"

OutputMIDI::OutputMIDI() {}

// methods for TinyTrainable
void OutputMIDI::playOutput(int classification) {
    sendSerialMIDINote(_midiChannel, _midiNotes[classification],
    _midiVelocity);
}

void OutputMIDI::sendSerialMIDINote(byte channel, byte note, byte
velocity) {
  Serial1.write(143 + channel);
  Serial1.write(note);
  Serial1.write(velocity);
}
