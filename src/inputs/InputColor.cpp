/// @file InputColor.cpp
/// @brief K-nearest neighbors algorithm + input color

// include header file
#include "InputColor.h"

// constructor
InputColor::InputColor() : _myKNN(3) {
  _labels[0] = "";
  _labels[1] = "";
  _labels[2] = "";
}

// // true: instrument outputs debugging messages over USB serial
// // false: standalone instrument, no debugging message
void InputColor::setupInstrument(bool serialDebugging) {

  tiny->_serialDebugging = serialDebugging;

  // if (tiny->_serialDebugging) {
  // Serial.begin(tiny->_baudRate);
  // while (!Serial) {
  //   ;
  // }
  // }

  tiny->setupLEDs();
  setupSensorAPDS9960();
}

// APDS9960 sensor for gestures, color, light intensity, proximity
void InputColor::setupSensorAPDS9960() {
  if (!APDS.begin()) {
    while (1)
      ;
    if (tiny->_serialDebugging) {
      // Serial.println("InputColor setupSensorAPDS9960");
    }
  }
}

// reads the color from the color sensor
// stores the rgb values in 'colorReading[]'
void InputColor::readColor(float colorReading[]) {

  // declare and initialize local variables for color
  int red, green, blue, colorTotal = 0;

  // wait for the object to move close enough
  while (!APDS.proximityAvailable() || APDS.readProximity() > 0) {
  }

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

// // uses the trained KNN algorithm to identify objects the user shows
void InputColor::identify() {

  // wait for the object to move away again
  // while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {
  // }

  if (APDS.proximityAvailable() && APDS.readProximity() != 0) {
    tiny->debugPrint("Let me guess your object");

    // wait for an object then read its color
    readColor(_colorReading);

    // classify the object
    int classification = _myKNN.classify(_colorReading, _k);

    tiny->debugPrint("You showed me: " + _labels[classification]);

    // turn on the corresponding light
    tiny->setStateLEDRGB(true, Colors(classification));

    tiny->playOutput(classification);

    // update previous classification
    _previousClassification = classification;
  }
}

// trains the KNN algorithm with examples provided by the user
// algorithm will use the 'k' nearest neighbors for classification
// 'examplesPerClass' examples that pass 'colorThreshold' are collected per
// class sets the labels of the objects for identification by the KNN algorithm
void InputColor::trainKNN(int k, int examplesPerClass, float colorThreshold,
                          String objects[3]) {

  _k = k;
  _colorThreshold = colorThreshold;

  _labels[0] = objects[0];
  _labels[1] = objects[1];
  _labels[2] = objects[2];

  String debugMessage =
      "Labels: " + _labels[0] + ", " + _labels[1] + ", " + _labels[2];
  tiny->debugPrint(debugMessage);

  for (int currentClass = 0; currentClass < 3; currentClass++) {

    // turn on the LED according to which class we are training
    tiny->setStateLEDRGB(true, Colors(currentClass));

    // ask the user to show examples of each object
    for (int currentExample = 0; currentExample < examplesPerClass;
         currentExample++) {

      tiny->debugPrint("Show me an example of: " + _labels[currentClass]);

      // wait for an object then read its color
      readColor(_colorReading);

      // add example color to the k-NN model
      _myKNN.addExample(_colorReading, currentClass);
    }

    // only show for objects 0 and 1
    if (currentClass < 2) {
      // TODO - maybe move to after LED change,
      // since Serial doesn't always work
      // and won't always be used
      tiny->debugPrint("Prepare next object");
    }
    // message to sginal that all objects are ready
    else {
      tiny->debugPrint("All objects ready");
    }

    // delay so the object readings don't overlap
    // TODO: maybe instead of hardcoded its a variable for advanced users
    delay(1000);

    // wait for the object to move away again
    while (!APDS.proximityAvailable() || APDS.readProximity() == 0) {
    }
  }
  tiny->debugPrint("Finished training");

  // blink twice
  tiny->blinkLEDBuiltIn(2);

  // turn off the LED built in
  tiny->setStateLEDBuiltIn(false);

  // turn off the LED RGB
  tiny->setStateLEDRGB(false, red);
}
