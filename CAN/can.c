#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#define FOSC 16000000
#define BAUD 9600

void setup (void);
int readPotValue(void);
void init_USART (unsigned int);
static int uart_putchar(char c, FILE *stream);

void setup (void)
{

	DDRD = 0b01110000; // broche D4, D5, D6
	PORTD = 0b00000000; //Port D
	
	DDRC = 0b00000000; //initialisation des inputs sur A0
	PORTC = 0b00000001; //Initialisation du port C
	
	ADCSRA = 0b10000010;//Initialisation du CAN
	ADCSRB = 0b00000000;//Mode de déclenchement CAN
	ADMUX = 0b01000000;	
	
}

int readPotValue(void){
	ADCSRA = 0b11000010;//Initialisation du CAN
	int value = ADCL + (ADCH<<8);	
	return value;					
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
	init_USART(BAUD);
	int value;
	int valueMaxRef = 0;
	
    while(1) // Exécution en continue du programme
    {
		PORTD = 0b00000000; 
		
		value = readPotValue();
		
		
		if(value > valueMaxRef) //Changement de max (si besoin)
			valueMaxRef = value;
			
			
		if(value > ((valueMaxRef/4)))
			PORTD |= 0b00010000; //allumer D4
		
		if(value > ((valueMaxRef/4)*2))
			PORTD |= 0b00100000; //allumer D5
			
		if(value > ((valueMaxRef/4)*3))
			PORTD |= 0b01000000; //allumer D6
		
		_delay_ms (250);
		printf("%d\n", readPotValue());
		printf("MAX : %d\n", valueMaxRef);
    }

	
	return 0;
}
