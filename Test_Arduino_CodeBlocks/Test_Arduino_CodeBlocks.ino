#include <Arduino.h>
#include <avr/interrupt.h>
#include "constantes.h"

volatile byte state = LOW;
int compteur = 0;
void blink();

void setup() {
  pinMode(LED_D4, OUTPUT);
  pinMode(LED_D5, OUTPUT);
  pinMode(BUTTON_D2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_D2), blink ,RISING); //Execute la fonction blink() lors de l'appui sur le bouton

  interrupts();

  TCCR2A = 0b00000000;//Initialisation du mode de fonctionnement du timer
  TCCR2B = 0b00000101;//Initialisation de la frequence du registre
  TIMSK2 = 0b00000001;
  TCNT2 =  255;



}


/*function déclancher à chaque interruption */
ISR(TIMER2_OVF_vect){
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

void blink(){
    state = !state; //Change l'état de state (HIGH/LOW)
}
