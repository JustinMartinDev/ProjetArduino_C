#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

void setup (void);

void setup (void)
{
	DDRB = 0b00100000; //Initialisation des broches input et output
	PORTB = 0b00000000; //Initialisation du port B � 0
}

int main (void)
{
	setup();
	while(1) //Boucle infinie pour faire clignoter la led
	{
		
		PORTB |= 0b00100000; //Allume la led
		_delay_ms (1000);
		PORTB &= 0b11011111; //Eteint la led
		_delay_ms (750);
	}
	
	return 0;
}
