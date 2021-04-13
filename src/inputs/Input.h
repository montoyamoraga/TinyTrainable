#ifndef INPUT_H
#define INPUT_H

// include Arduino library
#include <Arduino.h>

// declare class
class TinyTrainable;

class Input {

  // friend classes can access protected and private members
  friend class TinyTrainable;

  virtual void setupInstrument(bool serialDebugging){}

protected:
  TinyTrainable *tiny = nullptr;

public:
  Input();
};

#endif
