#ifndef led_included
#include <msp430.h>

#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

extern unsigned char red_led_state, green_led_state;
extern unsigned char leds_changed;

void led_init();
void led_update();
void led_dim();
void toggle_on();
void toggle_off();

#endif // included
