#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define FOSC 16000000

void setup (void);
void blinkMyLed();
void init_USART(unsigned int baud);
int printCHAR(char character, FILE *stream);

int printCHAR(char character, FILE *stream)
{
	while ((UCSRA & (1 << UDRE)) == 0) {};

	UDR = character;

	return 0;
}

FILE uart_str = FDEV_SETUP_STREAM(printCHAR, NULL, _FDEV_SETUP_RW);

void init_USART (unsigned int baud) {
	int UBRR;
	UBRR = (int) ((FOSC / 16 / baud) - 1);
	
	UBRR0H = (unsigned char)(UBRR>>8);
	UBRR0L = (unsigned char)UBRR;
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 8data, 1stop bit */
	UCSR0C = (1<<USBS0)|(2<<UCSZ00);
	
	fprintf(&uart_str, "Hello World\n\r");
	stdout = &uart_str;
	printf("I'm init\n\r");

}


void blinkMyLed() {
		PORTD |= 0b00010000; //allumer only D4
		_delay_ms (250);
		
		
		
		PORTD &= 0b11101111; //eteindre D
		_delay_ms (250);
}




void setup (void)
{	
	DDRD = 0b01110000; // broche D4
	PORTD = 0b00000000; //Port D for D4 
	init_USART(9600);
}

int main (void)
{
	setup();
	while(1){	
		blinkMyLed();
	}
	
	return 0;
}
