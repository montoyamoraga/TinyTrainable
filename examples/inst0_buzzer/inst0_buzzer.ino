// include library
#include <Inst0.h>

// declare instance of the instrument0
Inst0 tiny;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {

  tiny.setupLEDs();
  tiny.setupSensorAPDS9960();

    // setup instrument to output over midi, and printing debug statements
    tiny.setupInstrument(pinOut);

    // set pin for buzzer and note length
    tiny.setupPin(8, 1000);

    // set note frequencies for buzzer
    tiny.setFrequencies(1000, 1200, 1400);

    tiny.setLabels("Object 0", "Object 1", "Object 2");
    tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
    tiny.identify();
}
