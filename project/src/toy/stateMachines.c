#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

void redLedOn()
{
  red_on = 1;
  green_on = 0;
  leds_changed = 1;
  led_update();
}

void greenLedOn()
{
  green_on = 1;
  red_on = 0;
  leds_changed = 1;
  led_update();
}

void led_toggle()
{
  static char state = 0;

  switch(state)
    {
    case 0:
      redLedOn();
      state = 1;
      break;

    case 1:
      greenLedOn();
      state = 0;
      break;
    }
}

void bothLedOn()
{
  red_on = 1;
  green_on = 1;
  leds_changed = 1;
  led_update();
}

void bothLedOff()
{
  red_on = 0;
  green_on = 0;
  leds_changed = 0;
  led_update();
}

void led_dim()
{
  static char state2 = 0;

  switch(state2)
    {
    case 0:
      bothLedOn();
      state2 = 1;
      break;

    case 1:
      bothLedOff();
      state2 = 0;
      break;
    }
}

void song()
{
  int notes[5] = {698, 523, 0, 880, 1047};

  for(int i = 0; i < 6; i++)
    {
      buzzer_set_period(notes[i]);
      __delay_cycles(2500000);
    }
  buzzer_set_period(0);
}

void tone()
{
  static char tone = 0;

  switch(tone)
    {
    case 0:
      buzzer_set_period(523);
      tone = 1;
      break;

    case 1:
      buzzer_set_period(1047);
      tone = 2;
      break;

    case 2:
      buzzer_set_period(988);
      tone = 3;
      break;

    case 3:
      buzzer_set_period(0);
      tone = 0;
      break;
    }
}


















