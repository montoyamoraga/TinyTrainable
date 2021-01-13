// include libraries
#include <TinyTrainable.h>
#include <Inst0.h>

Inst0 tiny;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {
  
    // setup instrument to output over USB serial, and printing debug statements
    tiny.setupInstrument(usbOut, true);

    // set object labels for the KNN classification
    tiny.setLabels("Object 0", "Object 1", "Object 2");

    // train the KNN algorithm with your objects
    tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
    // identify the item shown to the arduino
    tiny.identify();
}
