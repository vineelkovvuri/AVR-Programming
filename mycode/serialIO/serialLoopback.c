// ------- Preamble -------- //
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>


void USART_Init()
{
  /*Set baud rate */
  // By default, atmega328p runs at 1Mhz without external oscilator
  // So as per the data sheet the UBBR value should be 6 for 9600 baud rate
  UBRR0H = 0;
  UBRR0L = 6;

  UCSR0A &= ~(1 << U2X0);

  //Enable receiver and transmitter */
  UCSR0B = (1<<RXEN0)|(1<<TXEN0);
  /* Set frame format: 8data, 1stop bit */
  UCSR0C = (3<<UCSZ00);
}

void USART_Transmit(unsigned char data)
{
  /* Wait for empty transmit buffer */
  while (!(UCSR0A & (1<<UDRE0)))
  ;
  /* Put data into buffer, sends the data */
  UDR0 = data;
}

int main(void) {
  char outstr[50] = "Riya Nischala Vineel \n";

  // -------- Inits --------- //
  USART_Init();
  DDRB = 0xff;
  while (1) {
    for (int i = 0; i < strlen(outstr); i++) {
      PORTB = outstr[i];
      _delay_ms(10);
      USART_Transmit(outstr[i]);                          /* to test */
      PORTB = 0;
      _delay_ms(10);
    }
  }

  return 0;
}
