#include <avr/interrupt.h>


#define LED_D4 4 //Led sur le port D4
#define LED_D5 5 //Led sur le port D5
#define BUTTON_D2 2 //Bouton sur le port D2
#define NOT_AN_INTERRUPT -1
int compteur;
volatile byte state = LOW;

void setup() {
  compteur = 0;
  pinMode(LED_D4, OUTPUT);
  pinMode(LED_D5, OUTPUT);
  pinMode(BUTTON_D2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_D2), blink , RISING); //Execute la fonction blink() lors de l'appui sur le bouton

  interrupts();
  TCCR2A = 0b00000000;//Initialisation du mode de fonctionnement du timer
  TCCR2B = 0b00000101;//Initialisation de la frequence du registre
  TIMSK2 = 0b00000001;
  TCNT2 =  255; 



}


/*function déclancher à chaque interruption */
ISR(TIMER2_OVF_vect) {
  noInterrupts();//Bloque les interruptions
  compteur++;
  if(compteur == 500){
    compteur = 0;
    digitalWrite(LED_D4, !digitalRead(LED_D4)); //Change l'état de la LED
  
    TIFR2 &= 0b00000000;
  
    TCNT2 = 255;
  
    TIMSK2 |= 0b00000001;
  }
  interrupts();//Autorise les interruptions
}



void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_D5, state); //Change l'état de la LED_D5 selon la variable state
}

void blink() {
  state = !state; //Change l'état de state (HIGH/LOW)
}
