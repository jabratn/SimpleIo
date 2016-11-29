#ifndef DEBOUNCEDINPUT_H
#define DEBOUNCEDINPUT_H

#include "stdint.h"

#include "Arduino.h"

class DebouncedInput
{
  public:
    DebouncedInput(void);
    DebouncedInput(uint8_t arduinopin);
    void begin(void);
    void setpintype(uint8_t type);
    void setnoisedelay(uint16_t delay);
    boolean changed(void);
    boolean ishigh(void);
    boolean islow(void);
  private:
    uint8_t _pin;
    uint8_t _pintype;
    uint8_t _stablevalue;
    uint8_t _lastvalue;
    uint16_t _noisedelay;
    uint32_t _millisPrev;
};

#endif

