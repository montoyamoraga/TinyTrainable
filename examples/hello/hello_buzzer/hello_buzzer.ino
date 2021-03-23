/// @file hello_buzzer.ino
/// @brief Example: Test output with buzzer

#include <TinyTrainable.h>

#define TINY_OUTPUT "BUZZER"

// declare instance of the instrument
// you can also do the same with Inst0, Inst1, or Inst2 instances
TinyTrainable tiny;

// constants for the hardware
const int outputPin = 2;

// arrays of frequencies
int freqArray0[] = {1200, 1400, 1600};
int freqArray1[] = {2100, 2200, 2300, 2400, 2500, 2600};
int freqArray2[] = {3100, 3200, 3300, 3400, 3500, 3600};

// length of above arrays (can be of varying lengths)
int shortParamArrayLength = 3;
int longParamArrayLength = 6;

int pauseTime = 2000;

// setup() runs once, at the beginning
void setup() {
  // initialize instrument
  tiny.setupOutputBuzzer(outputPin);

  // for buzzer output, there are 3 options:

  // 1. each classified item gets a single frequency (in Hz)

  tiny.setBuzzerFrequency(0, 1000);
  tiny.setBuzzerFrequency(1, 2000);
  tiny.setBuzzerFrequency(2, 3000);

  // 2. each classified item gets a random frequency within the given range
  // (the frequency will change each time the item is classified)

  // tiny.setBuzzerFrequency(0, 1000, 2000);
  // tiny.setBuzzerFrequency(1, 2000, 3000);
  // tiny.setBuzzerFrequency(2, 3000, 4000);

  // 3. each classified item gets a random frequency from a given array
  // (the frequency will change each time the item is classified)
  // NOTE: though you call these arrays in setup(), they need to be
  // declared in the global scope so they can be used after setup runs!

  // tiny.setBuzzerFrequency(0, freqArray0, shortParamArrayLength);
  // tiny.setBuzzerFrequency(1, freqArray1, longParamArrayLength);
  // tiny.setBuzzerFrequency(2, freqArray2, longParamArrayLength);

  // the same options also exist for buzzer durations (in milliseconds), in
  // the overloaded function setBuzzerDuration()

  // 1.

  tiny.setBuzzerDuration(0, 300);
  tiny.setBuzzerDuration(1, 600);
  tiny.setBuzzerDuration(2, 900);

  // 2.

  // tiny.setBuzzerDuration(0, 1000, 2000);
  // tiny.setBuzzerDuration(1, 2000, 3000);
  // tiny.setBuzzerDuration(2, 3000, 4000);

  // 3. (using the same arrays as above because the numbers also work in ms!)

  // tiny.setBuzzerDuration(0, freqArray0, shortParamArrayLength);
  // tiny.setBuzzerDuration(1, freqArray1, longParamArrayLength);
  // tiny.setBuzzerDuration(2, freqArray2, longParamArrayLength);

  // though the frequency and duration options can be different, you can't
  // do this:
  // tiny.setBuzzerFrequency(0, 1000);
  // tiny.setBuzzerFrequency(1, 2000, 3000);
  // tiny.setBuzzerFrequency(2, freqArray2, longParamArrayLength);
}

// loop() runs in a loop, after setup()
void loop() {
  // cycle through the three possible classification outputs

  // this will be taken care of by the instruments for base functionality!
  // it's demonstrated here in case to show what's possible

  // long because tone isn't blocking - calls will override!
  tiny.playOutput(0);
  delay(pauseTime);
  tiny.playOutput(1);
  delay(pauseTime);
  tiny.playOutput(2);
  delay(pauseTime);
}
