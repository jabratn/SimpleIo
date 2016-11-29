/*
  ButtonLed.ino

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
#include "PulseOutput.h"

#define LED_PIN (LED_BUILTIN)     // default LED w/ Arduino

#define BUTTON_PIN (2)

ButtonInput button = ButtonInput(BUTTON_PIN);

PulseOutput led = PulseOutput(LED_PIN);

void setup()
{
  // put your setup code here, to run once:

  button.begin();

  led.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:

  if (button.pressed())
  {
    led.trigger(100);
  }
  
  led.update();
}
