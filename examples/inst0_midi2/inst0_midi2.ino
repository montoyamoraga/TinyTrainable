#include <TinyTrainable.h>
#include <Inst0.h>

Inst0 myInst0;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {
    // setup instrument to output over midi, and printing debug statements
    myInst0.setupInstrument(midiOut, true);

    // midi channel is 153 in hex
    myInst0.setupMidi(0x99, 127);

    // midi note numbers
    myInst0.setNotes(37, 38, 39);

    myInst0.setLabels("Object 1", "Object 2", "Object 3");
    myInst0.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
    myInst0.identify();
}
