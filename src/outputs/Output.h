#ifndef OUTPUT_H
#define OUTPUT_H

// include Arduino library
#include <Arduino.h>

// this is to guard against circular include
// TODO: research the name of this
class TinyTrainable;

class Output {

  friend class TinyTrainable;

  protected:
  TinyTrainable* tiny = nullptr;

public:
  // constructor
  Output();
};

#endif
