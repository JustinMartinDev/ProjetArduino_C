/* Fichier noyau.h                                                                            */
/* Fichier d'en t�te                                                                          */
/* Contient la d�finition des constantes symboliques utilis�es                                */
/* Contient le prototypes des fonctions du fichier noyau.c                                    */


#include <stdlib.h>
#include <avr/interrupt.h>
#include <Arduino.h>


extern unsigned char _csreg;

inline void OSMakeAtomic(unsigned char *_csreg)
{
	*_csreg = SREG;
	cli();
}

inline void OSExitAtomic(unsigned char _csreg)
{
	SREG =_csreg;
}
