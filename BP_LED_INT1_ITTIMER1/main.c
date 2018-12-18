#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void setup (void);
void setup (void)
{

	DDRD = 0b00110100; //initialisation des inputs et outputs sur D
	PORTD = 0b00100000; //Initialisation du port D (D5 sous tension)
	
	SREG  = 0b10000000; //Permet les interruptions

	EICRA = 0b00000100; //Déclenchement sur changement de niveau logique
 	EIMSK = 0b00000010; //INTF1 à 1 pour interrupt sur INT1
}



ISR(INT1_vect){
	SREG &= 0b00000000;//Bloque les interruptions
	
	PORTD ^= 0b00100100; // Allume/Eteint la led (changement d'etat)

	EIFR &= 0b00000000;//INTF1 à 0

	SREG |= 0b10000000;//Autorise les interruptions
}

int main (void) {
	setup();

    while(1){
		PORTD |= 0b00010000; //allumer only D4
		_delay_ms (1000);
		PORTD &= 0b11101111; //eteindre D4
		_delay_ms (1000);
    }
	return 0;
}
