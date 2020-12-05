// TinyTrainable.h - a library for Tiny Trainable Instruments
// Written by aarón montoya-moraga
// MIT License

#ifndef TinyTrainable_h
#define TinyTrainable_h

#include "Arduino.h"

class TinyTrainable {
  public:
    TinyTrainable(int number);
    void setupBuiltInLED();
    void setColorBuiltInLED(int color);

  private:
    int _number;

};

#endif
