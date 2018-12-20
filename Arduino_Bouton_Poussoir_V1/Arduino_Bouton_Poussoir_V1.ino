#include <avr/interrupt.h>

#define LED_D4 4 //Led sur le port D4
#define LED_D5 5 //Led sur le port D5
#define BUTTON_D2 2 //Bouton sur le port D2

volatile byte state = LOW;

void setup() {
  
  pinMode(LED_D4, OUTPUT);
  pinMode(LED_D5, OUTPUT);
  pinMode(BUTTON_D2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON_D2), blink ,RISING); //Execute la fonction blink() lors de l'appui sur le bouton

  interrupts();
  TCCR1A = 0b00000000;//Initialisation du mode de fonctionnement du timer
  TCCR1B = 0b00000101;//Initialisation de la frequence du registre
  TIMSK1 = 0b00000001;
  TCNT1 =  49910; //65535 -(1/64*10^6) : 1000ms //compteur initialisé
  


}


/*function déclancher à chaque interruption */
ISR(TIMER1_OVF_vect){
  noInterrupts();//Bloque les interruptions
  
  digitalWrite(LED_D4, !digitalRead(LED_D4)); //Change l'état de la LED
  
  TIFR1 &= 0b00000000;

  TCNT1 = 49910;
  
  TIMSK1 |= 0b00000001;
  
  interrupts();//Autorise les interruptions
}



void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_D5, state); //Change l'état de la LED_D5 selon la variable state
}

void blink(){
    state = !state; //Change l'état de state (HIGH/LOW)
}
