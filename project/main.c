/*Creating main file based on blink_demo*/
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

void main(void)
{
  configureClocks();
  led_init();
  enableWDTInterrupts();

  or_sr(0x18);
}