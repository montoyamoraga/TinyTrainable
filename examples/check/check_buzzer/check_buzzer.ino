// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_NONE, OUTPUT_BUZZER);

// constants for the hardware
const int outputPin = 2;

// arrays of frequencies
int freqArray0[] = {1200, 1400, 1600};
int freqArray1[] = {2100, 2200, 2300, 2400, 2500, 2600};
int freqArray2[] = {3100, 3200, 3300, 3400, 3500, 3600};

// length of above arrays (can be of varying lengths)
int shortParamArrayLength = 3;
int longParamArrayLength = 6;

// time between sounds
int pauseTime = 2000;

void setup() {

  // initialize output
  myTiny.setupOutputBuzzer(outputPin);

  // for buzzer output, there are 3 options:

  // 0. each classified item gets a single frequency (in Hz)

  myTiny.setBuzzerFrequency(0, 1000);
  myTiny.setBuzzerFrequency(1, 2000);
  myTiny.setBuzzerFrequency(2, 3000);

  // 1. each classified item gets a random frequency within the given range
  // (the frequency will change each time the item is classified)

  // myTiny.setBuzzerFrequency(0, 1000, 2000);
  // myTiny.setBuzzerFrequency(1, 2000, 3000);
  // myTiny.setBuzzerFrequency(2, 3000, 4000);

  // 2. each classified item gets a random frequency from a given array
  // (the frequency will change each time the item is classified)
  // NOTE: though you call these arrays in setup(), they need to be
  // declared in the global scope so they can be used after setup runs!

  // myTiny.setBuzzerFrequency(0, freqArray0, shortParamArrayLength);
  // myTiny.setBuzzerFrequency(1, freqArray1, longParamArrayLength);
  // myTiny.setBuzzerFrequency(2, freqArray2, longParamArrayLength);

  // the same options also exist for buzzer durations (in milliseconds), in
  // the overloaded function setBuzzerDuration()

  // 0.

   myTiny.setBuzzerDuration(0, 300);
   myTiny.setBuzzerDuration(1, 600);
   myTiny.setBuzzerDuration(2, 900);

  // 1.

  //   myTiny.setBuzzerDuration(0, 1000, 2000);
  //   myTiny.setBuzzerDuration(1, 2000, 3000);
  //   myTiny.setBuzzerDuration(2, 3000, 4000);

  // 2. (using the same arrays as above because the numbers also work in ms!)

  // myTiny.setBuzzerDuration(0, freqArray0, shortParamArrayLength);
  // myTiny.setBuzzerDuration(1, freqArray1, longParamArrayLength);
  // myTiny.setBuzzerDuration(2, freqArray2, longParamArrayLength);

  // though the frequency and duration options can be different, you can't
  // do this:
  // myTiny.setBuzzerFrequency(0, 1000);
  // myTiny.setBuzzerFrequency(1, 2000, 3000);
  // myTiny.setBuzzerFrequency(2, freqArray2, longParamArrayLength);
}

// loop() runs in a loop, after setup()
void loop() {
  // cycle through the three possible classification outputs

  // this will be taken care of by the instruments for base functionality!
  // it's demonstrated here in case to show what's possible

  // long because tone isn't blocking - calls will override!
  myTiny.playOutput(0);
  delay(pauseTime);
  myTiny.playOutput(1);
  delay(pauseTime);
  myTiny.playOutput(2);
  delay(pauseTime);
}
