/// @file hello_printer.ino
/// @brief Example: Test output with thermal printer

// define input and output
#define INPUT_NONE
#define OUTPUT_PRINTER

// include TinyTrainable library
#include <TinyTrainable.h>

// declare instance of a TinyTrainable instrument
TinyTrainable myTiny(new Input(), new OutputPrinter());

// for wiring instructions, refer to docs/

// constants for the hardware
const int placeHolder0 = 10;
const int placeHolder1 = 10;
const int placeHolder2 = 10;

// TODO: move this to library
// instance of Adafruit Thermal Printer, connected to Serial1
//Adafruit_Thermal printer(&Serial1);

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
