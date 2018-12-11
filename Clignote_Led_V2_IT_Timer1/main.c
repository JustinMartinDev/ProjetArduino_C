#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void setup (void);
int first = 0;

void setup (void){

	DDRD = 0b00010000; //initialisation des inputs et outputs sur D2
	PORTD = 0b00000000; //Initialisation du port D
	
	SREG  = 0b10000000; //Permet les interruptions
	TCCR1A = 0b00000000;//Initialisation du mode de fonctionnement du timer
	TCCR1B = 0b00000101;//Initialisation de la frequence du registre
	TIMSK1 = 0b00000001;
	TCNT1 =  49910; //65535 -(1/64*10^6) : 1000ms	//compteur initialisé
}


/*function déclancher à chaque interruption */
ISR(TIMER1_OVF_vect){
	SREG &= 0b00000000;//Bloque les interruptions
	
	PORTD ^= 0b00000100; // Allume/Eteint la led en fonction de leur etat
	
	TIFR1 &= 0b00000000;
	
	if(first%2 == 0) TCNT1 = 49910;
	else TCNT1 = 60000; //on reduit le temps de la prochaine interruption 1 fois sur 2
	first++;
	
	TIMSK1 |= 0b00000001;
	SREG |= 0b10000000;//Autorise les interruptions
}

int main (void) {
	
	setup();

    while(1){
    }

	
	return 0;
}
