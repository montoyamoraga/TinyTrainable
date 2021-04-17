// include header file
#include "InputGesture.h"

// constructor
InputGesture::InputGesture() {
  _gestures[0] = "";
  _gestures[1] = "";
  _gestures[2] = "";
}

void InputGesture::setupInstrument(bool serialDebugging) {
  tiny->setupLEDs();
  setupSensorLSM9DS1();

  tiny->_serialDebugging = serialDebugging;

  if (tiny->_serialDebugging) {
    Serial.begin(tiny->_baudRate);
    while (!Serial)
      ;
  }
}

void InputGesture::setupGestures(String gestures[3]) {
  _gestures[0] = gestures[0];
  _gestures[1] = gestures[1];
  _gestures[2] = gestures[2];
}

// TODO: copy pasted from Peter's fork
void InputGesture::setupTF(float accelerationThreshold, int numSamples) {
  // _accelerationThreshold = accelerationThreshold;
  // _numSamples = numSamples;
  // _samplesRead = numSamples;

  // // get the TFL representation of the model byte array
  // tflModel = tflite::GetModel(model);
  // if (tflModel->version() != TFLITE_SCHEMA_VERSION) {
  //   Serial.println("Model schema mismatch!");
  //   while (1)
  //     ;
  // }

  // // create an interpreter to run the model
  // tflInterpreter =
  //     new tflite::MicroInterpreter(tflModel, tflOpsResolver, tensorArena,
  //                                  tensorArenaSize, &tflErrorReporter);

  // // allocate memory for the model's input and output tensors
  // tflInterpreter->AllocateTensors();

  // // get pointers for the model's input and output tensors
  // tflInputTensor = tflInterpreter->input(0);
  // tflOutputTensor = tflInterpreter->output(0);
}

// TODO: copy pasted from Peter's fork
void InputGesture::classify() {
  //  while (_samplesRead == _numSamples) {
  //   // wait for significant motion
  //   if (IMU.accelerationAvailable()) {

  //     // read the acceleration data
  //     IMU.readAcceleration(aX, aY, aZ);

  //     // sum up the absolutes
  //     float aSum = fabs(aX) + fabs(aY) + fabs(aZ);

  //     // check if it's above the threshold
  //     if (aSum >= _accelerationThreshold) {
  //       // reset the sample read count
  //       _samplesRead = 0;
  //       break;
  //     }
  //   }
  // }

  // // check if the all the required samples have been read since
  // // the last time the significant motion was detected
  // while (_samplesRead < _numSamples) {

  //   // check if new acceleration AND gyroscope data is available
  //   if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {

  //     // read the acceleration and gyroscope data
  //     IMU.readAcceleration(aX, aY, aZ);
  //     IMU.readGyroscope(gX, gY, gZ);

  //     // normalize the IMU data between 0 to 1 and store in the model's
  //     // input tensor
  //     tflInputTensor->data.f[_samplesRead * 6 + 0] = (aX + 4.0) / 8.0;
  //     tflInputTensor->data.f[_samplesRead * 6 + 1] = (aY + 4.0) / 8.0;
  //     tflInputTensor->data.f[_samplesRead * 6 + 2] = (aZ + 4.0) / 8.0;
  //     tflInputTensor->data.f[_samplesRead * 6 + 3] = (gX + 2000.0) / 4000.0;
  //     tflInputTensor->data.f[_samplesRead * 6 + 4] = (gY + 2000.0) / 4000.0;
  //     tflInputTensor->data.f[_samplesRead * 6 + 5] = (gZ + 2000.0) / 4000.0;

  //     _samplesRead++;

  //     if (_samplesRead == _numSamples) {
  //       // Run inferencing
  //       TfLiteStatus invokeStatus = tflInterpreter->Invoke();
  //       if (invokeStatus != kTfLiteOk) {
  //         Serial.println("Invoke failed!");
  //         while (1)
  //           ;
  //         return;
  //       }

  //       // loop through the output tensor values from the model
  //       for (int i = 0; i < NUM_GESTURES; i++) {
  //         Serial.print(_gestures[i]);
  //         Serial.print(": ");
  //         Serial.println(tflOutputTensor->data.f[i], 6);
  //       }
  //       Serial.println();
  //     }
  //   }
  // }
}

// LSM9DS1 sensor for IMU (inertial measurement unit)
//  3-axis accelerometer, gyroscope, magnetometer
void InputGesture::setupSensorLSM9DS1() {
  if (!IMU.begin()) {
    while (1)
      ;
  }
}
