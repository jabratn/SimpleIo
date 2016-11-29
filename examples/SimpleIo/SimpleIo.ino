/*
  SimpleIo.ino

  Demonstrate usage of the SimpleIo modules:
  - ButtonInput
  - DebouncedInput
  - FlashOutput
  - PulseOutput

  The circuit:
  * list the components attached to each input
  * list the components attached to each output

  Created 2016-11-27
  By jabratn

  Modified:
  20161128 BvdM   Create docs and make library

  https://github.com/jabratn/SimpleIo

*/

#include <stdint.h>

#include "ButtonInput.h"
#include "FlashOutput.h"
#include "PulseOutput.h"

#define YELLOW_LED_PIN (13)           // default LED w/ Arduino
#define RED_LED_PIN (5)

#define SELECT_BUTTON_PIN (2)
#define CONFIRM_BUTTON_PIN (3)

ButtonInput selectButton = ButtonInput(SELECT_BUTTON_PIN);
ButtonInput confirmButton = ButtonInput(CONFIRM_BUTTON_PIN);

FlashOutput yellowLed = FlashOutput(YELLOW_LED_PIN);
PulseOutput redLed = PulseOutput(RED_LED_PIN);

void setup()
{
  // put your setup code here, to run once:

  selectButton.setrepeatdelay(1000);
  selectButton.begin();
  confirmButton.begin();

  yellowLed.begin();
  redLed.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:

  if (selectButton.pressed())
  {
    yellowLed.trigger(1000, 10);
    redLed.trigger(100);
  }
  
  if (confirmButton.pressed())
  {
    yellowLed.trigger(1000, 90);
    redLed.trigger(1000);
  }

  yellowLed.update();
  redLed.update();
}
