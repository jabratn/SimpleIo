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
  20170123 BvdM   Add test code for FlashOutput

  https://github.com/jabratn/SimpleIo

*/

#include <stdint.h>

#include "ButtonInput.h"
#include "FlashOutput.h"

#define LED_PIN (LED_BUILTIN)     // default LED w/ Arduino

#define BUTTON_PIN (2)

ButtonInput button = ButtonInput(BUTTON_PIN);

FlashOutput led = FlashOutput(LED_PIN);

void setup()
{
  // put your setup code here, to run once:

  button.begin();

  led.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:

  static int count = 0;

  if (button.pressed())
  {
    count++;

    switch (count)
    {
      case 1:
        led.trigger(2000, 10);
        break;
        
      case 2:
        led.trigger(2000, 90);
        break;
        
      case 3:
        led.trigger(2000, 50);
        break;
        
      case 4:
        led.trigger(1000, 50);
        break;
        
      case 5:
        led.trigger(100, 50);
        break;
        
      case 6:
        led.on();
        break;
        
      default:
        led.off();
        count = 0;
        break;
        
    }
  }
  
  led.update();
}

