#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define FOSC 16000000
#define BAUD 9600

void setup (void);
void init_USART (unsigned int);
static int uart_putchar(char c, FILE *stream);

void setup (void) {
	DDRD = 0b00010000; //initialisation des inputs et outputs sur D2
	PORTD = 0b00000000; //Initialisation du port D
	
}

void init_USART (unsigned int baud) {
	int UBRR = (int)((FOSC / 16 / baud) - 1); 
	/* Initialisation des registres UBRR0L et UBRRR0H */ 
	UBRR0L = (unsigned char) UBRR;
	UBRR0H = (unsigned char)(UBRR>>8);
	
	//Initialisation des registres UCSR0A, UCSR0B et UCSR0C, mode de com
	UCSR0B |= 0b00011000;
	UCSR0C |= 0b00000110;
   

	/* on relie printf au serial */
	static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);
	stdout = &mystdout;
} 

static int uart_putchar(char c, FILE *stream) { //envoie d'un caractère via un stream
  if (c == '\n')
    uart_putchar('\r', stream); //envoie de fin de chaine \n\r
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c; //envoir du char
  return 0;
}


int main (void) {
	setup();
	init_USART(9600); //init serial

    while(1) {
        PORTD |= 0b00000100; // ALllume la led
        printf ("Led est allumé \n"); //send serial message
        _delay_ms (1000);
        PORTD &= 0b11111011;// Eteins la led
        printf ("Led est éteinte\n");
        _delay_ms (750);
    }
	return 0;
}
