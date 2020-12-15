#include "Arduino.h"
#include "TinyTrainable.h"

TinyTrainable myInst(true);


void setup() {
  // put your setup code here, to run once:
  myInst.debugPrint("Arduino k-NN color classifier");
  myInst.setLabels("Object 0", "Object 1", "Object 2");
  myInst.trainKNN(5, 10, 0.5);
}

void loop() {
  // put your main code here, to run repeatedly:
  myInst.identify();
}
