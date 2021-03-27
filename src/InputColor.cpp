// include header file
#include "InputColor.h"

// constructor
InputColor::InputColor() : _myKNN(3) {
  _labels[0] = "";
  _labels[1] = "";
  _labels[2] = "";
}

// true: instrument outputs debugging messages over USB serial
// false: standalone instrument, no debugging message
void InputColor::setupInstrument(bool serialDebugging) {
  setupLEDs();
  setupSensorAPDS9960();

  _serialDebugging = serialDebugging;

  if (_serialDebugging) {
    Serial.begin(9600);
    while (!Serial)
      ;
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