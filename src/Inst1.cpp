/// @file Inst1.cpp
/// @brief gesture recognition using TensorFlow

/// include library
#include "Inst1.h"

// include your model file
#include "../assets/modelInst1.h"

// constructor method
Inst1::Inst1() {
  _gestures[0] = "";
  _gestures[1] = "";
  _gestures[2] = "";
}

// TODO - add some sort of led indication that it's working on setup?
void Inst1::setupInstrument(bool serialDebugging, String gestures[3]) {
  // setup LEDs
  setupLEDs();
  // turn on sensor
  setupSensorLSM9DS1();

  _gestures[0] = gestures[0];
  _gestures[1] = gestures[1];
  _gestures[2] = gestures[2];

  _serialDebugging = serialDebugging;

  if (_serialDebugging) {
    Serial.begin(9600);
    while (!Serial)
      ;
  }
}

void Inst1::setupTF(float accelerationThreshold, int numSamples) {
  _accelerationThreshold = accelerationThreshold;
  _numSamples = numSamples;
  _samplesRead = numSamples;

  // get the TFL representation of the model byte array
  tflModel = tflite::GetModel(model);
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

  Serial.println("successful tf setup");
}

void Inst1::classify() {
  Serial.println("got to classify");
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
        Serial.println("all samples read");
        // Run inferencing
        TfLiteStatus invokeStatus = tflInterpreter->Invoke();
        if (invokeStatus != kTfLiteOk) {
          Serial.println("Invoke failed!");
          while (1)
            ;
          return;
        }

        Serial.println("finished running inference");

        // loop through the output tensor values from the model
        for (int i = 0; i < NUM_GESTURES; i++) {
          Serial.print(_gestures[i]);
          Serial.print(": ");
          Serial.println(tflOutputTensor->data.f[i], 6);
        }
        Serial.println();
      }
    }
  }
}
