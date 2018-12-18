#include <avr/interrupt.h>
#define LED_D3 3 //Led sur le port D3
#define LED_D4 4 //Led sur le port D4
#define BUTTON_D2 2 //Bouton sur le port D2

volatile byte state = LOW;
int first;

void setup() {
  first = 0;
  
  pinMode(LED_D3, OUTPUT);
  pinMode(LED_D4, OUTPUT);
  pinMode(BUTTON_D2, INPUT_PULLUP);
  interrupts(); //Autorise les interruptions
  digitalWrite(LED_D4, LOW);
  attachInterrupt(digitalPinToInterrupt(BUTTON_D2), blink ,RISING); //Execute la fonction blink() lors de l'appui sur le bouton


  TCCR1A = 0b00000000;//Initialisation du mode de fonctionnement du timer
  TCCR1B = 0b00000101;//Initialisation de la fréquence du registre
  TIMSK1 = 0b00000001;
  TCNT1 =  49910; //65535 -(1/64*10^6) : 1000ms
 
}

ISR(TIMER1_OVF_vect){
  noInterrupts(); //Bloque les interruptions
  digitalWrite(LED_D3, !digitalRead(LED_D3)); //Change l'état de la LED_D3
  
  TIFR1 &= 0b00000000;

  //Modification de la valeur de registre de comptage 
  //Afin de modifier le temps des cycles de clignotement
  if(first%2 == 0) TCNT1 = 49910;
  else TCNT1 = 60000;
  first++;
  
  TIMSK1 |= 0b00000001;
  interrupts(); //Autorise les interruptions
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_D4, state);
}

void blink(){
    //noInterrupts();
    state = !state;
    //digitalWrite(LED_D4, !digitalRead(LED_D4)); //Change l'état de la LED_D4
    //interrupts();
}
