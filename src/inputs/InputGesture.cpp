// include header file
#include "InputGesture.h"

// constructor
InputGesture::InputGesture() {

}

void InputGesture::setupInstrument(bool serialDebugging) {
  tiny->setupLEDs();
  setupSensorLSM9DS1();

  tiny->_serialDebugging = serialDebugging;

  if (tiny->_serialDebugging) {
    Serial.begin(9600);
    while (!Serial)
      ;
  }
}

// LSM9DS1 sensor for IMU (inertial measurement unit)
//  3-axis accelerometer, gyroscope, magnetometer
void InputGesture::setupSensorLSM9DS1() {
  if (!IMU.begin()) {
    while (1)
      ;
  }
}
