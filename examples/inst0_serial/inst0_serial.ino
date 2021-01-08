// include libraries
#include <TinyTrainable.h>
#include <Inst0.h>

Inst0 myInst0;

// constants for the KNN algorithm
int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

void setup() {
  
    // setup instrument to output over USB serial, and printing debug statements
    myInst0.setupInstrument(usbOut, true);

    // set object labels for the KNN classification
    myInst0.setLabels("Object 1", "Object 2", "Object 3");

    // train the KNN algorithm with your objects
    myInst0.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

void loop() {
    // identify the item shown to the arduino
    myInst0.identify();
}
