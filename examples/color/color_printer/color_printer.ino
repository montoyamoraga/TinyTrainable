// include library TinyTrainable
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(INPUT_COLOR, OUTPUT_PRINTER);

// constants for the KNN algorithm
const int K = 5;
const int EXAMPLES_PER_CLASS = 10;
const float COLOR_THRESHOLD = 0.5;

String myColors[3] = {"color0", "color1", "color2"};

// constants for the hardware
const int placeHolder0 = 10;
const int placeHolder1 = 10;
const int placeHolder2 = 10;

void setup() {

  // TODO: baudrate is 19200, or 9600 for some printers, confirm
  //  Serial1.begin(19200);

  // start printer
  //  printer.begin();

  // text justification
  // TODO: what is F()?
  //  printer.justify('R');
  //  printer.println(F("Right justified"));
  //  printer.justify('C');
  //  printer.println(F("Center justified"));
  //  printer.justify('L');
  //  printer.println(F("Left justified"));

  // make printer sleep for 5 seconds
  //  printer.sleep();
  // TODO: what is L?
  //  delay(5000L);
  // wake up the printer
  //  printer.wake();

  // restore printer to defaults
  //  printer.setDefault();
}

void loop() {}
