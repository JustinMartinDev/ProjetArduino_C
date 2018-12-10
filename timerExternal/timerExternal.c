#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void setup (void);
void setup (void)
{

	DDRD = 0b00010000; //initialisation des inputs et outputs sur D2
	PORTD = 0b00000000; //Initialisation du port D
	
	SREG  = 0b10000000; //Permet les interruptions

	
	EICRA = 0b00001100;
	EIMSK = 0b00000010;
	
	
}



ISR(INT1_vect){
	SREG &= 0b00000000;//Bloque les interruptions
	
	PORTD ^= 0b00000100; // Allume/Eteint la led

	EIFR &= 0b00000000;//INTF1 à 0

	
	SREG |= 0b10000000;//Autorise les interruptions
}

int main (void) 
{
	
	setup();
		
	
	

    while(1) // Exécution en continue du programme
    {
		
    }

	
	return 0;
}
