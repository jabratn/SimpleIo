#ifndef PULSEOUTPUT_H
#define PULSEOUTPUT_H

#include "stdint.h"

#include "Arduino.h"

class PulseOutput
{
  public:
    PulseOutput(void);
    PulseOutput(uint8_t arduinopin);
    void begin(void);
    void setinverted(void);
    void clearinverted(void);
    void on(void);
    void off(void);
    void trigger(uint16_t length);
    void update(void);
  protected:
    uint8_t _pin;
    boolean _inverted;
    uint32_t _millisPrev;
  private:
    uint16_t _pulselength;
};

#endif

