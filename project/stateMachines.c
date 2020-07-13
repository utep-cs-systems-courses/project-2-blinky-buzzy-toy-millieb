#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void state_advance(int state)
{
  switch(state)
    {
    case 1:
      led_dim();
      state = 0;
      break;

    case 2:
      song();
      state = 0;
      break;

    case 3:
      song2();
      state = 0;
      break;

    case 4:
      led_song2();
      state = 0;
      break;

    default:
      break;
    }
}
