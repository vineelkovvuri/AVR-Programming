                                                         /* Cylon Eyes */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */

#define DELAYTIME 100                                   /* milliseconds */

int main(void) {

  DDRD = 0x0;
  PORTD = 0;//0xFF;

  DDRB = 0xFF;

  // ------ Event loop ------ //
  while (1) {
    if (PIND & 0x2) {
      PORTB = 0xFF; // turn on led
    } else {
      PORTB = 0; // turn off led
    }
    //_delay_us(200);
  }                        
  return 0;
}
