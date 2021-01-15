// include header file
#include "Inst0.h"

// constructor for the Inst0 class
Inst0::Inst0() : _myKNN(3) {
  // default, no classification
  _previousClassification = -1;
  // default built in LED is on
}

// sets the labels of the objects for identification by the KNN algorithm
void Inst0::setLabels(String object0, String object1, String object2) {
  _labels[0] = object0;
  _labels[1] = object1;
  _labels[2] = object2;
  debugPrint("Labels for Inst0:");
  debugPrint(_labels[0]);
  debugPrint(_labels[1]);
  debugPrint(_labels[2]);
}

// trains the KNN algorithm with examples provided by the user
// algorithm will use the 'k' nearest neighbors for classification
// 'examplesPerClass' examples that pass 'colorThreshold' are collected per class
void Inst0::trainKNN(int k, int examplesPerClass, float colorThreshold) {
  _k = k;
  _colorThreshold = colorThreshold;

  for (int currentClass = 0; currentClass < 3; currentClass++) {

    turnOnLEDRGB(Colors(currentClass));

    // ask the user to show examples of each object
    for (int currentExample = 0; currentExample < examplesPerClass; currentExample++) {

      debugPrint("Show me an example of: " + _labels[currentClass]);

      // wait for an object then read its color
      readColor(_colorReading);

      // add example color to the k-NN model
      _myKNN.addExample(_colorReading, currentClass);
    }

    // TODO - maybe move to after LED change, since Serial doesn't always work 
    // and won't always be used
    debugPrint("Prepare next object");
    delay(1000);  // so the object readings don't overlap

    // wait for the object to move away again
    while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}
  }
  debugPrint("Finished training");

  // blink twice
  blinkLEDBuiltIn(2);

  // turn off the LED built in
  turnOffLEDBuiltIn();

  // turn off the LED RGB
  turnOffLEDRGB();

}

// uses the trained KNN algorithm to identify objects the user shows
void Inst0::identify() {
  // wait for the object to move away again
  while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {}

  debugPrint("Let me guess your object");

  // wait for an object then read its color
  readColor(_colorReading);

  // classify the object
  int classification = _myKNN.classify(_colorReading, _k);

  debugPrint("You showed me: " + _labels[classification]);

  // turn on the corresponding light
  turnOnLEDRGB(Colors(classification));

  // TODO: add the corresponding calls to functions
  switch (_outputMode) {
    case outputBuzzer:
      tone(_outputPin, _buzzerFrequencies[classification], _buzzerDuration);
      break;
    case outputLCD:
      break;
    case outputLED:
      break;
    case outputMIDI:
      break;
    case outputPrinter:
      break;
    case outputSerialUSB:
      break;
    case outputServo:
      break;
  }

  // TODO: delete this legacy code,
  // it is here as reference for now
  //   case usbOut:
  //     Serial.println(classification);
  //     break;
  //   case midiOut:
  //     sendSerialMIDINote(_midiChannel, _notes[classification], _midiVelocity);
  //     break;
  // }

  _previousClassification = classification;
}

// reads the color from the color sensor
// stores the rgb values in 'colorReading[]'
void Inst0::readColor(float colorReading[]) {

  // declare and initialize local variables for color
  int red, green, blue, colorTotal = 0;

  // wait for the object to move close enough
  while (!APDS.proximityAvailable() || APDS.readProximity() > 0) {}

  // wait until the color is bright enough
  while (colorTotal < _colorThreshold) {

    // sample if the color is available and the object is close
    if (APDS.colorAvailable()) {

      // read color and proximity
      APDS.readColor(red, green, blue);
      colorTotal = (red + green + blue);

      // update readings
      _colorReading[0] = red;
      _colorReading[1] = green;
      _colorReading[2] = blue;
    }
  }
}
