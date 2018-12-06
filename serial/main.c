#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define FOSC 16000000
#define BAUD 9600

void setup (void);
void init_USART (unsigned int);
static int uart_putchar(char c, FILE *stream);

void setup (void)
{
	DDRD = 0b00010000; //initialisation des inputs et outputs sur D2
	PORTD = 0b00000000; //Initialisation du port D
	
}

void init_USART (unsigned int baud) 
{ 
	int UBRR = (int)((FOSC / 16 / baud) - 1); 
	/* Initialisation des registres UBRR0L et UBRRR0H */ 
	UBRR0L = (unsigned char) UBRR;
	UBRR0H = (unsigned char)(UBRR>>8);
	
	//Initialisation des registres UCSR0A, UCSR0B et UCSR0C
	
	//UCSR0A |= 0b00100000;
	UCSR0B |= 0b00011000;
	UCSR0C |= 0b00000110;
   
   
	static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL,_FDEV_SETUP_WRITE);
	stdout = &mystdout;
   // Définir le format d’une trame : 8 bits, parité : aucune, 1 bit de stop 
   /* 
	Code à écrire 
	*/ 
} 

static int uart_putchar(char c, FILE *stream)
{
  if (c == '\n')
    uart_putchar('\r', stream);
  loop_until_bit_is_set(UCSR0A, UDRE0);
  UDR0 = c;
  return 0;
}


int main (void) 
{
	setup();
	init_USART(9600);

    while(1) // Exécution en continue du programme
    {
        PORTD |= 0b00000100; // ALllume la led
        printf (" ALLUMER LE FEU \n");
        _delay_ms (1000); //1000 ms allumé
        PORTD &= 0b11111011;// Eteins la led
        printf (" ET ON ETEINS TOUT \n");
        _delay_ms (750); //750 ms
    }

	
	return 0;
}
