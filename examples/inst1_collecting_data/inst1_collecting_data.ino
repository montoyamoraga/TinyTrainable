// this sketch is adapted from the GestureToEmoji example
// from the repository ArduinoTensorFlowLiteTutorials by Arduino
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials

// include library
#include <Inst1.h>

// instance of Inst1
Inst1 tiny;

// threshold of significant in G's
const float accelerationThreshold = 2.5;

// number of samples per motion
const int numSamples = 119;

// initialize as if sampling has already been done
int samplesRead = numSamples;

// number of decimals for floating point numbers
const int floatDecimals = 3;

// variables for reading
float aX, aY, aZ, gX, gY, gZ;

void setup() {

  tiny.setupInstrument();
  tiny.setupOutputSerialUSB();

  // print the header
  Serial.println("aX,aY,aZ,gX,gY,gZ");
}

void loop() {

  // while we have read as many samples as wanted for a certain motion
  // reset the IMU reader variables
  while (samplesRead == numSamples) {

    // if there is acceleration data available from the sensor
    if (IMU.accelerationAvailable()) {

      // read it and store it on variables aX, aY, aZ
      IMU.readAcceleration(aX, aY, aZ);

      // store the sum of their absolute values in variable aSum
      float aSum = fabs(aX) + fabs(aY) + fabs(aZ);

      // check if aSum is above the threshold
      if (aSum >= accelerationThreshold) {

        // reset the sample read count
        samplesRead = 0;

        Serial.println("aX,aY,aZ,gX,gY,gZ");
        // exit the while loop
        break;
      }
    }
  }

  // check if the all the required samples have been read since
  // the last time the significant motion was detected
  while (samplesRead < numSamples) {

    // check if both new acceleration and gyroscope data is
    // available
    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {

      // read accelation data and store in variables aX, aY, aZ
      IMU.readAcceleration(aX, aY, aZ);

      // read gyroscope data and store in variables gX, gY, gZ
      IMU.readGyroscope(gX, gY, gZ);

      // signal one more sample read
      samplesRead++;

      // print the data on the console in CSV format
      Serial.print(aX, floatDecimals);
      Serial.print(',');
      Serial.print(aY, floatDecimals);
      Serial.print(',');
      Serial.print(aZ, floatDecimals);
      Serial.print(',');
      Serial.print(gX, floatDecimals);
      Serial.print(',');
      Serial.print(gY, floatDecimals);
      Serial.print(',');
      Serial.print(gZ, floatDecimals);
      Serial.println();

      // check if it is the last sample
      if (samplesRead == numSamples) {

        // add an empty line
        Serial.println();
      }
    }
  }
}
