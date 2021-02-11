// include library
#include <Inst0.h>

Inst0 tiny;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {
  tiny.setupInstrument(true);

  tiny.setupOutputSerialUSB();

  String objectNames[3] = {"Object 0", "Object 1", "Object 2"};
  // train the KNN algorithm with your objects
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD, objectNames);
}

void loop() {
  // identify the item shown to the arduino
  tiny.identify();
}
