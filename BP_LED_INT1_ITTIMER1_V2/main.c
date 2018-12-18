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
	
	TCCR1A = 0b00000000;//Initialisation du mode de fonctionnement du timer
	TCCR1B = 0b00000101;//Initialisation de la fréquence du registre
	TIMSK1 = 0b00000001;
	TCNT1 =  49910; //65535 -(1/64*10^6) : 1000ms	
	
	
	
	
	EICRA = 0b00000100; //Déclenchement sur changement de niveau logique
	EIMSK = 0b00000010;
	
	
}


ISR(TIMER1_OVF_vect){
	SREG &= 0b00000000;//Bloque les interruptions
	
	PORTD ^= 0b00010000; // Allume/Eteint la led D4
	
	TIFR1 &= 0b00000000;
	/*
	if(first%2 == 0) TCNT1 = 49910;
	else TCNT1 = 60000;
	first++;
	*/
	TCNT1 = 49910;
	
	
	TIMSK1 |= 0b00000001;
	SREG |= 0b10000000;//Autorise les interruptions
}



ISR(INT1_vect){
	SREG &= 0b00000000;//Bloque les interruptions
	
	PORTD ^= 0b00100100; // Allume/Eteint la led (changement d'etat)
	

	
	
	EIFR &= 0b00000000;//INTF1 à 0

	
	SREG |= 0b10000000;//Autorise les interruptions
}

int main (void) 
{
	
	setup();
		
	
	

    while(1) // Exécution en continu du programme
    {
		/*
		PORTD |= 0b00010000; //allumer only D4
		_delay_ms (1000);
		PORTD &= 0b11101111; //eteindre D4
		_delay_ms (1000);
		*/
    }

	
	return 0;
}
