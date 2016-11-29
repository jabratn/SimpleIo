#ifndef FLASHOUTPUT_H
#define FLASHOUTPUT_H

#include "stdint.h"

#include "Arduino.h"

#include "PulseOutput.h"

class FlashOutput: public PulseOutput
{
  public:
    FlashOutput(void);
    FlashOutput(uint8_t arduinopin);
    void trigger(uint16_t period, uint8_t dutycycle);
    void update(void);
  private:
    enum eState_t { eIdle, eOff, eOn } _state;
    uint16_t _flashontime;
    uint16_t _flashofftime;
};

#endif

