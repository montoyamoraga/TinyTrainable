// include header file
#include "Inst0.h"

// constructor for the Inst0 class
Inst0::Inst0() : _myKNN(3) {
  _previousClassification = -1;

}

// sets up Serial, Serial1, proximity/color sensor, and LEDs based on 'mode'
// if 'serialDebugging' is true, debugPrint() statements will be printed over Serial
void Inst0::setupInstrument(OutputMode mode) {
  _outputMode = mode;

  if (_outputMode == usbOut) {
    Serial.begin(9600);
    while (!Serial);
  }

  if (_outputMode == midiOut) {
    setupSerialMIDI();
  }

    // TODO: i tried to move these lines to the constructor and it broke
    // if we can move things to the constructor
    // this function setupInstrument can be renamed to setupOutput or similar
    // setupSensorAPDS9960();
    // setupLEDs();
}

void Inst0::setupPin(int outputPin, long noteDuration) {
  _outputPin = outputPin;
  _noteDuration = noteDuration;
  pinMode(_outputPin, OUTPUT);
}

// set note frequencies for pin/buzzer output, or note numbers for midi output 
void Inst0::setFrequencies(int note0, int note1, int note2) {
  _notes[0] = note0;
  _notes[1] = note1;
  _notes[2] = note2;
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

      debugPrint("Show me an example of:");
      debugPrint(_labels[currentClass]);

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

  debugPrint("You showed me:");
  debugPrint(_labels[classification]);

  // turn on the corresponding light
  turnOnLEDRGB(Colors(classification));

  switch (_outputMode) {
    case usbOut:
      Serial.println(classification);
      break;
    case midiOut:
      sendSerialMIDINote(_midiChannel, _notes[classification], _midiVelocity);
      break;
    case pinOut:
      tone(_outputPin, _notes[classification], _noteDuration);
      break;
  }

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
