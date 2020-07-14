#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch1_state_down,
  switch2_state_down,
  switch3_state_down,
  switch4_state_down,
  switch_state_changed; /* effectively boolean */

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  switch1_state_down = (p2val & SW1) ? 0 : 1;    /* 0 when switch is up */
  switch2_state_down = (p2val & SW2) ? 0 : 1;
  switch3_state_down = (p2val & SW3) ? 0 : 1;
  switch4_state_down = (p2val & SW4) ? 0 : 1;

  if(switch1_state_down){
    led_toggle();               /* alternate between turning on green or red led */
  }

  if(switch2_state_down){

    static char press = 0;

    switch(press){
      
    case 0:
      bothLedOn();
      press = 1;
      break;

    case 1:
      _enable_interrupts();    /* enable periodic interrupt */
      press = 2;
      break;

    case 2:
      WDTCTL = WDTPW + WDTHOLD; /* turn off watchdog timer */
      bothLedOff();
      press = 0;
      break;
    }
  }

  if(switch3_state_down){
    song();
  }

  if(switch4_state_down){
    tone();
  }
}
