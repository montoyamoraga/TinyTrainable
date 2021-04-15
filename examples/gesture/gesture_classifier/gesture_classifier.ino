/// @file gesture_classifier.ino
/// @brief input gesture with output classifier?

// this sketch is adapted from the GestureToEmoji example
// from the repository ArduinoTensorFlowLiteTutorials by Arduino
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials

// TODO: rewrite this placeholder code
// at this stage, this code is a placeholder,
// copied from the following file
// https://github.com/arduino/ArduinoTensorFlowLiteTutorials/blob/master/GestureToEmoji/ArduinoSketches/IMU_Classifier/IMU_Classifier.ino
// with only little modifications
// and still without comments about what most lines mean
// and without optimization

#define INPUT_GESTURE
#define OUTPUT_SERIAL

// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of the TinyTrainable instrument
TinyTrainable myTiny(new InputGesture(), new Output());

// include machine learning model
#include "../assets/modelGesture.h"
// or include your own
//#include "myModel.h"

// instance of Inst1
Inst1 tiny;

// threshold of significant in G's
const float accelerationThreshold = 2.5;

// number of samples per gesture
const int numSamples = 119;

// initialize as if sampling has already been done
// int samplesRead = numSamples;

// global variables used for TensorFlow Lite Micro
// tflite::MicroErrorReporter tflErrorReporter;

// pull in all the TFLM ops, you can remove this line and
// only pull in the TFLM ops you need, if would like to reduce
// the compiled size of the sketch.
// tflite::AllOpsResolver tflOpsResolver;

// const tflite::Model *tflModel = nullptr;
// tflite::MicroInterpreter *tflInterpreter = nullptr;
// TfLiteTensor *tflInputTensor = nullptr;
// TfLiteTensor *tflOutputTensor = nullptr;

// Create a static memory buffer for TFLM, the size may need to
// be adjusted based on the model you are using
// constexpr int tensorArenaSize = 8 * 1024;
// byte tensorArena[tensorArenaSize];

// array to map gesture index to a name
String GESTURES[] = {"gesture0", "gesture1", "gesture2"};

// define constant for number of gestures
// #define NUM_GESTURES (sizeof(GESTURES) / sizeof(GESTURES[0]))

void setup() {

  // setup instrument
  tiny.setupInstrument(true, GESTURES);
  Serial.println("hello in setup");
  tiny.setupTF(accelerationThreshold, numSamples);

  // tiny.setupOutputSerialUSB();

  // get the TFL representation of the model byte array
  // tflModel = tflite::GetModel(model);
  // if (tflModel->version() != TFLITE_SCHEMA_VERSION) {
  //   Serial.println("Model schema mismatch!");
  //   while (1)
  //     ;
  // }

  // create an interpreter to run the model
  // tflInterpreter =
  //     new tflite::MicroInterpreter(tflModel, tflOpsResolver, tensorArena,
  //                                  tensorArenaSize, &tflErrorReporter);

  // // allocate memory for the model's input and output tensors
  // tflInterpreter->AllocateTensors();

  // get pointers for the model's input and output tensors
  // tflInputTensor = tflInterpreter->input(0);
  // tflOutputTensor = tflInterpreter->output(0);
}

void loop() {
  tiny.classify();

  // declare six variables
  // acceleration and gravity in x, y, z
  // float aX, aY, aZ, gX, gY, gZ;

  // while (samplesRead == numSamples) {
  //   // wait for significant motion
  //   if (IMU.accelerationAvailable()) {

  //     // read the acceleration data
  //     IMU.readAcceleration(aX, aY, aZ);

  //     // sum up the absolutes
  //     float aSum = fabs(aX) + fabs(aY) + fabs(aZ);

  //     // check if it's above the threshold
  //     if (aSum >= accelerationThreshold) {
  //       // reset the sample read count
  //       samplesRead = 0;
  //       break;
  //     }
  //   }
  // }

  // check if the all the required samples have been read since
  // the last time the significant motion was detected
  // while (samplesRead < numSamples) {

  //   // check if new acceleration AND gyroscope data is available
  //   if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {

  //     // read the acceleration and gyroscope data
  //     IMU.readAcceleration(aX, aY, aZ);
  //     IMU.readGyroscope(gX, gY, gZ);

  //     // normalize the IMU data between 0 to 1 and store in the model's
  //     // input tensor
  //     tflInputTensor->data.f[samplesRead * 6 + 0] = (aX + 4.0) / 8.0;
  //     tflInputTensor->data.f[samplesRead * 6 + 1] = (aY + 4.0) / 8.0;
  //     tflInputTensor->data.f[samplesRead * 6 + 2] = (aZ + 4.0) / 8.0;
  //     tflInputTensor->data.f[samplesRead * 6 + 3] = (gX + 2000.0) / 4000.0;
  //     tflInputTensor->data.f[samplesRead * 6 + 4] = (gY + 2000.0) / 4000.0;
  //     tflInputTensor->data.f[samplesRead * 6 + 5] = (gZ + 2000.0) / 4000.0;

  //     samplesRead++;

  //     if (samplesRead == numSamples) {
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
  //         Serial.print(GESTURES[i]);
  //         Serial.print(": ");
  //         Serial.println(tflOutputTensor->data.f[i], 6);
  //       }
  //       Serial.println();
  //     }
  //   }
  // }
}
