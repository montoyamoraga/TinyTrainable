/// @file InputGesture.cpp
/// @brief TensorFlow model + input gesture

// include header file
#include "InputGesture.h"

// include machine learning model
#include "../assets/modelGestureDefault.h"

// constructor
InputGesture::InputGesture() {
  _gestures[0] = "";
  _gestures[1] = "";
  _gestures[2] = "";
}

void InputGesture::setupInstrument(bool serialDebugging) {
  tiny->setupLEDs();
  setupGestureSensor();

  tiny->_serialDebugging = serialDebugging;

  if (tiny->_serialDebugging) {
    Serial.begin(tiny->_baudRate);
    while (!Serial)
      ;
  }
}

void InputGesture::setupGestureModel(String gestures[3],
                                  const unsigned char *model) {
  _gestures[0] = gestures[0];
  _gestures[1] = gestures[1];
  _gestures[2] = gestures[2];

  // load the default model or the custom model
  tflModel = tflite::GetModel((model == nullptr) ? modelGestureDefault : model);

  if (tflModel->version() != TFLITE_SCHEMA_VERSION) {
    Serial.println("Model schema mismatch!");
    while (1)
      ;
  }

  // create an interpreter to run the model
  tflInterpreter =
      new tflite::MicroInterpreter(tflModel, tflOpsResolver, tensorArena,
                                   tensorArenaSize, &tflErrorReporter);

  // allocate memory for the model's input and output tensors
  tflInterpreter->AllocateTensors();

  // get pointers for the model's input and output tensors
  tflInputTensor = tflInterpreter->input(0);
  tflOutputTensor = tflInterpreter->output(0);
}

void InputGesture::identify() {
  while (_samplesRead == _numSamples) {
    // wait for significant motion
    if (IMU.accelerationAvailable()) {

      // read the acceleration data
      IMU.readAcceleration(aX, aY, aZ);

      // sum up the absolutes
      float aSum = fabs(aX) + fabs(aY) + fabs(aZ);

      // check if it's above the threshold
      if (aSum >= _accelerationThreshold) {
        // reset the sample read count
        _samplesRead = 0;
        break;
      }
    }
  }

  // check if the all the required samples have been read since
  // the last time the significant motion was detected
  while (_samplesRead < _numSamples) {

    // check if new acceleration AND gyroscope data is available
    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {

      // read the acceleration and gyroscope data
      IMU.readAcceleration(aX, aY, aZ);
      IMU.readGyroscope(gX, gY, gZ);

      // normalize the IMU data between 0 to 1 and store in the model's
      // input tensor
      tflInputTensor->data.f[_samplesRead * 6 + 0] = (aX + 4.0) / 8.0;
      tflInputTensor->data.f[_samplesRead * 6 + 1] = (aY + 4.0) / 8.0;
      tflInputTensor->data.f[_samplesRead * 6 + 2] = (aZ + 4.0) / 8.0;
      tflInputTensor->data.f[_samplesRead * 6 + 3] = (gX + 2000.0) / 4000.0;
      tflInputTensor->data.f[_samplesRead * 6 + 4] = (gY + 2000.0) / 4000.0;
      tflInputTensor->data.f[_samplesRead * 6 + 5] = (gZ + 2000.0) / 4000.0;

      _samplesRead++;

      if (_samplesRead == _numSamples) {

        // Run inferencing
        TfLiteStatus invokeStatus = tflInterpreter->Invoke();
        if (invokeStatus != kTfLiteOk) {
          Serial.println("Invoke failed!");
          while (1)
            ;
          return;
        }

        int maxIndex = -1;
        float maxVal = -1;

        // loop through the output tensor values from the model
        for (int i = 0; i < NUM_GESTURES; i++) {
          if (tflOutputTensor->data.f[i] > maxVal) {
            maxIndex = i;
            maxVal = tflOutputTensor->data.f[i];
          }
          if (tiny->_serialDebugging) {

            //     Serial.print(_gestures[i]);
            //     Serial.print(": ");
            //     Serial.println(tflOutputTensor->data.f[i], 6);
          }
        }
        tiny->playOutput(maxIndex);
      }
    }
  }
}

void InputGesture::gesturePrintHeader() { Serial.println(_gestureHeader); }

void InputGesture::gestureReadData() {

  // while we have read as many samples as wanted for a certain motion
  // reset the IMU reader variables
  while (_samplesRead == _numSamples) {
    //    //
    //    // if there is acceleration data available from the sensor
    if (IMU.accelerationAvailable()) {

      // read it and store it on variables aX, aY, aZ
      IMU.readAcceleration(_aX, _aY, _aZ);

      // store the sum of their absolute values in variable aSum
      float aSum = fabs(_aX) + fabs(_aY) + fabs(_aZ);

      // check if aSum is above the threshold
      if (aSum >= _accelerationThreshold) {

        // reset the sample read count
        _samplesRead = 0;

        // exit the while loop
        break;
      }
    }
  }

  // check if the all the required samples have been read since
  // the last time the significant motion was detected
  while (_samplesRead < _numSamples) {

    // check if both new acceleration and gyroscope data is
    // available
    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {

      // read accelation data and store in variables aX, aY, aZ
      IMU.readAcceleration(_aX, _aY, _aZ);

      // read gyroscope data and store in variables gX, gY, gZ
      IMU.readGyroscope(_gX, _gY, _gZ);

      // signal one more sample read
      _samplesRead++;

      //      // print the data on the console in CSV format
      Serial.print(_aX, _floatDecimals);
      Serial.print(',');
      Serial.print(_aY, _floatDecimals);
      Serial.print(',');
      Serial.print(_aZ, _floatDecimals);
      Serial.print(',');
      Serial.print(_gX, _floatDecimals);
      Serial.print(',');
      Serial.print(_gY, _floatDecimals);
      Serial.print(',');
      Serial.print(_gZ, _floatDecimals);
      Serial.println();

      // check if it is the last sample
      if (_samplesRead == _numSamples) {

        // add an empty line
        Serial.println();
      }
    }
  }
}

void InputGesture::gestureSetAcceleration(float newVal) {
  _accelerationThreshold = newVal;
}

void InputGesture::gestureSetNumberSamples(int newVal) {
  _numSamples = newVal;
}

/// @brief function for setup of sensor LSM9DS1
// LSM9DS1 sensor for IMU (inertial measurement unit)
//  3-axis accelerometer, gyroscope, magnetometer
void InputGesture::setupGestureSensor() {
  if (!IMU.begin()) {
    while (1)
      ;
  }
}
