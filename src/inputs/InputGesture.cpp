// include header file
#include "InputGesture.h"

// constructor
InputGesture::InputGesture() {

}

// LSM9DS1 sensor for IMU (inertial measurement unit)
//  3-axis accelerometer, gyroscope, magnetometer
void InputGesture::setupSensorLSM9DS1() {
  if (!IMU.begin()) {
    while (1)
      ;
  }
}
