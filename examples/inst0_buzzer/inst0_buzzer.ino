// include libraries
#include "TinyTrainable.h"
#include "Inst0.h"

//const int INPUTS = 3; // Classifier input is color sensor data; red, green and blue levels
//const int CLASSES = 3; // Number of objects we will classify (e.g. Apple, Banana, Orange)
//const int EXAMPLES_PER_CLASS = 10; // Number of times user needs to show examples for each object
//
//const int K = 5;
//
//boolean isPrintingConsole = true;
//
//int previousClassification = -1;
//
//// Create a new KNNClassifier
//KNNClassifier myKNN(INPUTS);
//
//// Names for each class (object type)
//String label[CLASSES] = {"Up", "Down", "Sideways"};
//
//// Array to store data to pass to the KNN library
//float color[INPUTS];
//
//// Threshold for color brightness
//const float THRESHOLD = 0.5;
//
//// frequencies for buzzer
//int drumNotes[3] = {100, 250, 450};
//
//const int buzzerPin = 9;

void setup() {

  //  pinMode(buzzerPin, OUTPUT);
  //
  //  setupSerial1();
  //
  //  setupBuiltInLED();
  //
  //  // Ask user for the name of each object
  //  for (int currentClass = 0; currentClass < CLASSES; currentClass++) {
  //
  //    setColorBuiltInLED(currentClass);
  //
  //    // Ask user to show examples of each object
  //    for (int currentExample = 0; currentExample < EXAMPLES_PER_CLASS; currentExample++) {
  //
  //      if (isPrintingConsole) {
  //        Serial.print("Show me an example ");
  //        Serial.println(label[currentClass]);
  //      }
  //
  //      // Wait for an object then read its color
  //      readColor(color);
  //
  //      // Add example color to the k-NN model
  //      myKNN.addExample(color, currentClass);
  //    }
  //    // Wait for the object to move away again
  //    while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
  //  }



}

void loop() {

  //  int classification;
  //
  //  // Wait for the object to move away again
  //  while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
  //
  //  if (isPrintingConsole) {
  //    Serial.println("Let me guess your object");
  //  }
  //
  //  // Wait for an object then read its color
  //  readColor(color);
  //
  //  // Classify the object
  //  classification = myKNN.classify(color, K);
  //
  //  // Print the classification
  //  if (isPrintingConsole) {
  //    Serial.print("You showed me ");
  //    Serial.println(label[classification]);
  //  }
  //
  //  setColorBuiltInLED(classification);
  //
  //  if (classification != previousClassification) {
  //    tone(buzzerPin, drumNotes[classification], 100);
  //    //    midiCommand(0x99, drumNotes[classification], 127);
  //    previousClassification = classification;
  //  }

}

//void readColor(float color[]) {
//  //  int red, green, blue, proximity, colorTotal = 0;
//  float red, green, blue, proximity, colorTotal = 0.0;
//
//  // Wait for the object to move close
//  while (!APDS.proximityAvailable() || APDS.readProximity() > 0) {}
//
//  // Wait until we have a color bright enough
//  //  while (colorTotal < THRESHOLD) {
//
//  // Sample if color is available and object is close
//  //    if (APDS.colorAvailable()) {
//  while (!IMU.accelerationAvailable());
//  //    if (IMU.accelerationAvailable()) {
//
//  // Read color and proximity
//  IMU.readAcceleration(red, green, blue);
//  //      APDS.readColor(red, green, blue);
//  colorTotal = (red + green + blue);
//
//  color[0] = red;
//  color[1] = green;
//  color[2] = blue;
//
//
//  if (isPrintingConsole) {
//    Serial.println(colorTotal);
//    // Print the red, green and blue percentage values
//    Serial.print(color[0]);
//    Serial.print(",");
//    Serial.print(color[1]);
//    Serial.print(",");
//    Serial.println(color[2]);
//  }
//
//}
