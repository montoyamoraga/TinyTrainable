// include library
#include <Inst0.h>

// declare instance of the instrument0
Inst0 myInst0;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {
    // setup instrument to output over midi, and printing debug statements
    myInst0.setupInstrument(pinOut, true);

    // set pin for buzzer and note length
    myInst0.setupPin(8, 1000);

    // set note frequencies for buzzer
    myInst0.setNotes(1000, 1200, 1400);

    myInst0.setLabels("Object 1", "Object 2", "Object 3");
    myInst0.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
    myInst0.identify();
}
