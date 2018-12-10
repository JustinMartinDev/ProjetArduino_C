#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define FOSC 16000000

void setup (void);
void init_USART(unsigned int baud);
void USART_SendByte(uint8_t u8Data);

FILE uart_str = FDEV_SETUP_STREAM(printCHAR, NULL, _FDEV_SETUP_RW);

void Serial_INIT (unsigned int baud) {
	BAUD_PRESCALE = (((FOSC / (baud * 16UL))) - 1)
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8); 

	UCSRB = ((1<<TXEN)|(1<<RXEN) | (1<<RXCIE));
}

/*
void blinkMyLed() {
	PORTD |= 0b00010000; //allumer only D4
	_delay_ms (250);
	PORTD &= 0b11101111; //eteindre D
	_delay_ms (250);
}*/


void USART_SendByte(uint8_t u8Data){

  // Wait until last byte has been transmitted
  while((UCSRA &(1<<UDRE)) == 0);

  // Transmit data
  UDR = u8Data;
}


void setup (void) {	
	init_USART(9600);
}

int main (void) {
	setup();
	while(1){	
		USART_SendByte(value);  // send value 
		_delay_ms(250);         
	}
	
	return 0;
}
