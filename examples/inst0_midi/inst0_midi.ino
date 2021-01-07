// include libraries
#include "TinyTrainable.h"
#include "Inst0.h"

int snare = 38;

int K = 5;
int EXAMPLES_PER_CLASS = 10;
float COLOR_THRESHOLD = 0.5;

TinyTrainable myTiny;

void setup() {

  Serial1.begin(9600);

  // desired baudrate
  uint32_t baudrate = 0x800000;

  // pointer to the memory address that stores the baudrate
  uint32_t *pointerBaudrate = ( uint32_t * )0x40002524;

  // replace the value at the pointer with the desired baudrate
  *pointerBaudrate = baudrate;
}

void loop() {

  // 153
  // note on channel 10
  // 143 + channel
  midiCommand(0x99, snare, 127);

  delay(5000);
}

// send 3 byte midi message
void midiCommand(byte cmd, byte data1, byte data2) {
  Serial1.write(cmd);
  Serial1.write(data1);
  Serial1.write(data2);
}
