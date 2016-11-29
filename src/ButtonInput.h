#ifndef BUTTONINPUT_H
#define BUTTONINPUT_H

#include "stdint.h"

#include "Arduino.h"

#include "DebouncedInput.h"

class ButtonInput
{
  public:
    ButtonInput(void);
    ButtonInput(uint8_t arduinopin);
    void begin(void);
    void setrepeatdelay(uint16_t delay);
    boolean pressed(void);
  private:
    DebouncedInput _input;
    uint8_t _pin;
    boolean _pressed;
    uint16_t _repeatdelay;
    uint32_t _millisPrev;
};

#endif

