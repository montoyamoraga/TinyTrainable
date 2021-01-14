// include library
#include <Inst0.h>

Inst0 tiny;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {

  tiny.setupLEDs();
  tiny.setupSensorAPDS9960();

  // setup instrument to output over midi
  // tiny.setupInstrument(midiOut);

  tiny.setLabels("Object 0", "Object 1", "Object 2");


  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
  tiny.identify();
}