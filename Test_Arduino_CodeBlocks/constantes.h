#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#define LED_D4 4 //Led sur le port D4
#define LED_D5 5 //Led sur le port D5
#define BUTTON_D2 2 //Bouton sur le port D2

#define NOT_AN_INTERRUPT 1
#define digitalPinToInterrupt(p) ((p) == 0 ? 2 : ((p) == 1 ? 3 : ((p) == 2 ? 1 : ((p) == 3 ? 0 : ((p) == 7 ? 4 : NOT_AN_INTERRUPT)))))

#endif // CONSTANTES_H_INCLUDED
