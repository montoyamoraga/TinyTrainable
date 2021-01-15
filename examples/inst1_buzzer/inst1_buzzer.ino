// include library
#include <Inst1.h>

// declare instance of the instrument0
Inst1 tiny;

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

// setup() runs once, at the beginning
void setup() {

  // configure all LEDs on the microcontroller
  tiny.setupLEDs();

  // turn on the sensor to measure
  // 3-axis accelerometer, gyroscope, magnetometer
  tiny.setupSensorLSM9DS1();

  // setup instrument to output over midi
  tiny.setupInstrument(pinOut);

  // set pin for buzzer and note length
  tiny.setupPin(8, 1000);

  // set note frequencies for buzzer
  tiny.setFrequencies(1000, 1200, 1400);

  // set labels for each of the three classes
  tiny.setLabels("Object 0", "Object 1", "Object 2");

  // train the KNN algorithm
  tiny.trainKNN(K, EXAMPLES_PER_CLASS, COLOR_THRESHOLD);
}

// loop() runs after setup(), on a loop
void loop() {

  // identify the input and respond
  tiny.identify();
}
