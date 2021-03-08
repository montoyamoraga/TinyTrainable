/// @file inst1_buzzer.ino
/// @brief Example: Instrument1 with output buzzer

// include library
#include <Inst1.h>

// include machine learning model
#include "../assets/modelInst1.h"
// or include your own
//#include "myModel.h"

// declare instance of the instrument0
Inst1 tiny;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// constants for the hardware
const int outputPin = 8;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = true;

// setup() runs once, at the beginning
void setup() {

  // configure all LEDs on the microcontroller
  tiny.setupLEDs();

  // set debugging over serial port
  tiny.setSerialDebugging(tinyDebugging);

  // turn on the sensor to measure
  // 3-axis accelerometer, gyroscope, magnetometer
  tiny.setupSensorLSM9DS1();

  // setup instrument to output over buzzer
  tiny.setOutputMode(outputBuzzer);

  // setup the hardware pin for the output
  tiny.setBuzzerPin(outputPin);

  // set frequencies for buzzer sounds
  tiny.setBuzzerFrequencies(1000, 1200, 1400);

  // set duration for buzzer soudns
  tiny.setBuzzerDurations(1000);

  // set labels for each of the three classes
  //  tiny.setLabels("Object 0", "Object 1", "Object 2");

  // train the KNN algorithm
  //  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  //  tiny.identify();
}
