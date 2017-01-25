/*
  DebouncedInput.cpp

  See .h file

  Created 2016-11-27
  By jabratn

  Modified:
  20161128 BvdM   Create docs and make library
  20170126 BvdM   Default is INPUT_PULLUP, so _stablevalue and _lastvalue should be HIGH

  https://github.com/jabratn/SimpleIo

*/

#include "stdint.h"

#include "Arduino.h"

#include "DebouncedInput.h"

DebouncedInput::DebouncedInput(void)
{
}

DebouncedInput::DebouncedInput(uint8_t arduinopin)
{
  _pin = arduinopin;
  _pintype = INPUT_PULLUP;
  _stablevalue = HIGH;
  _lastvalue = HIGH;
  _noisedelay = 50;   // default ~50ms
}

void DebouncedInput::begin(void)
{
  pinMode(_pin, _pintype);
  _millisPrev = millis();
}

void DebouncedInput::setpintype(uint8_t type)
{
  _pintype = type;
}

void DebouncedInput::setnoisedelay(uint16_t delay)
{
  _noisedelay = delay;
}

boolean DebouncedInput::changed(void)
{
  boolean changed = false;
  uint8_t newvalue = digitalRead(_pin);
  uint32_t millisNow = millis();

  if (newvalue != _lastvalue)
  {
    // not stable yet
    _millisPrev = millisNow;
  }

  if ((millisNow - _millisPrev) > _noisedelay)
  {
    if (newvalue != _stablevalue)
    {
      _stablevalue = newvalue;
      changed = true;
    }
  }

  _lastvalue = newvalue;

  return changed;
}

boolean DebouncedInput::ishigh(void)
{
  return (_stablevalue == HIGH) ? true : false;
}

boolean DebouncedInput::islow(void)
{
  return (_stablevalue == LOW) ? true : false;
}

