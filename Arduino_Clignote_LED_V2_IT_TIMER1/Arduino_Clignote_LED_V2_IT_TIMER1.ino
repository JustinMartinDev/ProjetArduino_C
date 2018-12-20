#include <avr/interrupt.h>
#define LED_D3 3 //Led sur le port D3
#define LED_D4 4 //Led sur le port D4


int first;

void setup() {
  first = 0;
  
  pinMode(LED_D3, OUTPUT);
  pinMode(LED_D4, OUTPUT);
  digitalWrite(LED_D3, LOW); //LED_D3 eteinte
  digitalWrite(LED_D4, HIGH); //LED_D4 allumée
  interrupts(); //Autorise les interruptions
  TCCR1A = 0b00000000;//Initialisation du mode de fonctionnement du timer
  TCCR1B = 0b00000101;//Initialisation de la fréquence du registre
  TIMSK1 = 0b00000001;
  TCNT1 =  49910; //65535 -(1/64*10^6) : 1000ms
}

ISR(TIMER1_OVF_vect){
  noInterrupts(); //Bloque les interruptions
 
  digitalWrite(LED_D3, !digitalRead(LED_D3)); //Change l'état de la LED_D3
  digitalWrite(LED_D4, !digitalRead(LED_D4)); //Change l'état de la LED_D4
  
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

}
