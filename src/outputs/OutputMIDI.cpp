// include header file
#include "OutputMIDI.h"

OutputMIDI::OutputMIDI() {}

// methods for TinyTrainable
void OutputMIDI::playOutput(int classification) {
  // sendSerialMIDINote(_midiChannel, _midiNotes[classification], _midiVelocity);
}

// void OutputMIDI::sendSerialMIDINote(byte channel, byte note, byte velocity) {
//   Serial1.write(143 + channel);
//   Serial1.write(note);
//   Serial1.write(velocity);
// }

void OutputMIDI::setupOutputMIDI(byte midiChannel, byte midiVelocity) {
  _midiChannel = midiChannel;
  _midiVelocity = midiVelocity;

  setupSerialMIDI();
}

void OutputMIDI::setMIDINote(int object, int note) {
  _midiNotes[object] = note;
}

// sets up Serial MIDI output on TX pin
void OutputMIDI::setupSerialMIDI() {

  // open serial tranmission on TX pin
  Serial1.begin(tiny->_baudRate);

  // desired baudrate for MIDI
  uint32_t baudrate = 0x800000;

  // declare pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = (uint32_t *)0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}
