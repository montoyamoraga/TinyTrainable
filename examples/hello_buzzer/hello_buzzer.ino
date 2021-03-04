/// @file hello_buzzer.ino
/// @brief Example: Test output with buzzer
/// @author montoyamoraga, peter-parque, maxzwang
/// @date March 2021


// include all libraries
#include <Inst0.h>
#include <Inst1.h>
#include <Inst2.h>

// declare instance of the instrument
// default is Inst0, change Inst0 to Inst1 or Inst2 if necessary
Inst0 tiny;

// constant for debugging
// true: the instrument needs to be connected to serial port
// false: the instrument is standalone
const bool tinyDebugging = false;

// constants for the hardware
const int outputPin = 8;

// arrays of frequencies
int freqArray0[] = {1100, 1200, 1300, 1400, 1500, 1600};
int freqArray1[] = {2100, 2200, 2300, 2400, 2500, 2600};
int freqArray2[] = {3100, 3200, 3300, 3400, 3500, 3600};

// setup() runs once, at the beginning
void setup() {
  // initialize instrument
  tiny.setupInstrument(tinyDebugging);

  tiny.setBuzzerFrequency(0, freqArray0, paramArrayLength);
  tiny.setBuzzerFrequency(1, freqArray1, paramArrayLength);
  tiny.setBuzzerFrequency(2, freqArray2, paramArrayLength);

  // set durations, in milliseconds
  tiny.setBuzzerDuration(0, 300);
  tiny.setBuzzerDuration(1, 600);
  tiny.setBuzzerDuration(2, 900);
}

// loop() runs in a loop, after setup()
void loop() {

  // TODO: add functions for testing buzzer
}
