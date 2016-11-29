/*
  FlashOutput.cpp

  See .h file

  Created 2016-11-27
  By jabratn

  Modified:
  20161128 BvdM   Create docs and make library

  https://github.com/jabratn/SimpleIo

  TODO - inherit from PulseOutput

*/

#include "stdint.h"

#include "Arduino.h"

#include "FlashOutput.h"

FlashOutput::FlashOutput(void)
{
}

FlashOutput::FlashOutput(uint8_t arduinopin) : PulseOutput(arduinopin)
{
  _state = eIdle;
}

void FlashOutput::trigger(uint16_t period, uint8_t dutycycle)
{
  if (dutycycle == 0)
  {
    off();
    _state = eIdle;
  }
  else if (dutycycle >= 100)
  {
    on();
    _state = eIdle;
  }
  else
  {
    uint32_t temp;
    
    temp = dutycycle * (uint32_t)period;    
    _flashontime = (uint16_t)(temp / 100);
    temp = (100 - dutycycle) * (uint32_t)period;    
    _flashofftime = (uint16_t)(temp / 100);

    on();
    _state = eOn;
    _millisPrev = millis();
  }
}

void FlashOutput::update(void)
{
  uint32_t millisNow = millis();

  if ((_state == eOff) && ((millisNow - _millisPrev) > _flashofftime))
  {
    on();
    _state = eOn;
    _millisPrev = millisNow;
  }
  else if ((_state == eOn) && ((millisNow - _millisPrev) > _flashontime))
  {
    off();
    _state = eOff;
    _millisPrev = millisNow;
  }
  else
  {
    // nothing
  }
}

