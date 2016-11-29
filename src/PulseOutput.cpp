/*
  PulseOutput.cpp

  See .h file

  Created 2016-11-27
  By jabratn

  Modified:
  20161128 BvdM   Create docs and make library

  https://github.com/jabratn/SimpleIo

*/

#include "stdint.h"

#include "Arduino.h"

#include "PulseOutput.h"

PulseOutput::PulseOutput(void)
{
}

PulseOutput::PulseOutput(uint8_t arduinopin)
{
  _pin = arduinopin;
  _inverted = false;
}

void PulseOutput::begin(void)
{
  pinMode(_pin, OUTPUT);
  off();
}

void PulseOutput::setinverted(void)
{
  _inverted = true;
}

void PulseOutput::clearinverted(void)
{
  _inverted = false;
}

void PulseOutput::on(void)
{
  digitalWrite(_pin, (_inverted ? LOW : HIGH));
  _pulselength = 0;
}

void PulseOutput::off(void)
{
  digitalWrite(_pin, (_inverted ? HIGH : LOW));
  _pulselength = 0;
}

void PulseOutput::trigger(uint16_t length)
{
  digitalWrite(_pin, (_inverted ? LOW : HIGH));
  _pulselength = length;
  _millisPrev = millis();
}

void PulseOutput::update(void)
{
  if (_pulselength)
  {
    uint32_t millisNow = millis();

    if ((millisNow - _millisPrev) > _pulselength)
    {
      off();
    }
  }
}

