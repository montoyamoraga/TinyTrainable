// include library
#include <Inst0.h>

Inst0 tiny;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {
  tiny.setupLEDs();

  tiny.setSerialDebugging(true);

  tiny.setupSensorAPDS9960();

  tiny.setOutputMode(outputMIDI);

  tiny.setupSerialMIDI();

  tiny.setSerialMIDIChannel(10);

  tiny.setSerialMIDIVelocity(127);

  tiny.setSerialMIDINotes(37, 38, 39);

  tiny.setLabels("Object 0", "Object 1", "Object 2");

  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
  tiny.identify();
}
