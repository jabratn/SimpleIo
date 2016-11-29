/*
  DebouncedInput.cpp

  See .h file

  Created 2016-11-27
  By jabratn

  Modified:
  20161128 BvdM   Create docs and make library

  https://github.com/jabratn/SimpleIo

*/

#include "stdint.h"

#include "Arduino.h"

#include "ButtonInput.h"

ButtonInput::ButtonInput(void)
{
}

ButtonInput::ButtonInput(uint8_t arduinopin)
{
  _input = DebouncedInput(arduinopin);
  _pin = arduinopin;
  _pressed = false;
  _repeatdelay = 500;   // default ~500ms
}

void ButtonInput::begin(void)
{
  _input.begin();
  _millisPrev = millis();
}

void ButtonInput::setrepeatdelay(uint16_t delay)
{
  _repeatdelay = delay;
}

boolean ButtonInput::pressed(void)
{
  if (_input.changed())
  {
    if (_input.islow())
    {
      _pressed = true;
    }
    else
    {
      _pressed = false;
    }
    _millisPrev = millis();
  }
  else
  {
    uint32_t millisNow = millis();

    if ((millisNow - _millisPrev) > _repeatdelay)
    {
      _pressed = _input.islow();
      _millisPrev = millisNow;
    }
    else
    {
      _pressed = false;
    }
  }

  return _pressed;
}

