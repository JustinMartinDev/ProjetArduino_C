#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void setup (void);
int first = 0;
void setup (void)
{

	DDRD = 0b00010000; //initialisation des inputs et outputs sur D2
	PORTD = 0b00000000; //Initialisation du port D
	
	SREG  = 0b10000000; //Permet les interruptions
	TCCR1A = 0b00000000;//Initialisation du mode de fonctionnement du timer
	TCCR1B = 0b00000101;//Initialisation de la fréquence du registre
	TIMSK1 = 0b00000001;
	TCNT1 =  49910; //65535 -(1/64*10^6) : 1000ms	
}



ISR(TIMER1_OVF_vect){
	SREG &= 0b00000000;//Bloque les interruptions
	
	PORTD ^= 0b00000100; // Allume/Eteint la led
	
	TIFR1 &= 0b00000000;
	
	if(first%2 == 0) TCNT1 = 49910;
	else TCNT1 = 60000;
	first++;
	
	TIMSK1 |= 0b00000001;
	SREG |= 0b10000000;//Autorise les interruptions
}

int main (void) 
{
	
	setup();
		
	
	

    while(1) // Exécution en continue du programme
    {
		/*
        PORTD |= 0b00000100; // ALllume la led
        _delay_ms (1000); //1000 ms allumé
        PORTD &= 0b11111011;// Eteint la led
        _delay_ms (750); //750 ms
		*/
    }

	
	return 0;
}
