/* Fichier noyau.c                                                                            */
/* Contient les routines de base de l'OS                                                      */

#include "../includes/Noyau.h"


// Pour sauvegarder le contenu du registre SREG
unsigned char _csreg;

// pointeur sur la pile du processus
unsigned long pxCurrentTCB;

// Pointeurs sur le processus et sa liste d'arguments
unsigned long pxFuncPtr, pxFuncArg;

// Macros pour sauver et restaurer le contexte
#define portSAVE_CONTEXT()\
asm volatile (\
"push r0	\n\t"\
"in r0, __SREG__	\n\t"\
"cli	\n\t"\
"push r0	\n\t"\
"push r1	\n\t"\
"clr r1	\n\t"\
"push r2	\n\t"\
"push r3	\n\t"\
"push r4	\n\t"\
"push r5	\n\t"\
"push r6	\n\t"\
"push r7	\n\t"\
"push r8	\n\t"\
"push r9	\n\t"\
"push r10	\n\t"\
"push r11	\n\t"\
"push r12	\n\t"\
"push r13	\n\t"\
"push r14	\n\t"\
"push r15	\n\t"\
"push r16	\n\t"\
"push r17	\n\t"\
"push r18	\n\t"\
"push r19	\n\t"\
"push r20	\n\t"\
"push r21	\n\t"\
"push r22	\n\t"\
"push r23	\n\t"\
"push r24	\n\t"\
"push r25	\n\t"\
"push r26	\n\t"\
"push r27	\n\t"\
"push r28	\n\t"\
"push r29	\n\t"\
"push r30	\n\t"\
"push r31	\n\t"\
"in r26, __SP_L__	\n\t"\
"in r27, __SP_H__	\n\t"\
"sts pxCurrentTCB+1, r27	\n\t"\
"sts pxCurrentTCB, r26	\n\t"\
"sei	\n\t" : :);

#define portRESTORE_CONTEXT()\
asm volatile (\
"cli	\n\t"\
"out __SP_L__, %A0	\n\t"\
"out __SP_H__, %B0	\n\t"\
"pop r31	\n\t"\
"pop r30	\n\t"\
"pop r29	\n\t"\
"pop r28	\n\t"\
"pop r27	\n\t"\
"pop r26	\n\t"\
"pop r25	\n\t"\
"pop r24	\n\t"\
"pop r23	\n\t"\
"pop r22	\n\t"\
"pop r21	\n\t"\
"pop r20	\n\t"\
"pop r19	\n\t"\
"pop r18	\n\t"\
"pop r17	\n\t"\
"pop r16	\n\t"\
"pop r15	\n\t"\
"pop r14	\n\t"\
"pop r13	\n\t"\
"pop r12	\n\t"\
"pop r11	\n\t"\
"pop r10	\n\t"\
"pop r9	\n\t"\
"pop r8	\n\t"\
"pop r7	\n\t"\
"pop r6	\n\t"\
"pop r5	\n\t"\
"pop r4	\n\t"\
"pop r3	\n\t"\
"pop r2	\n\t"\
"pop r1	\n\t"\
"pop r0	\n\t"\
"sei	\n\t"\
"out __SREG__, r0\n\t"\
"pop r0	\n\t": : "r" (pxCurrentTCB));

// Sets up SP to point to the thread stack
#define portSetStack()\
asm volatile(\
	"OUT __SP_L__, %A0	\n\t"\
	"OUT __SP_H__, %B0	\n\t": : "r" (pxCurrentTCB))

// Loads the starting address of the thread function onto the stack and
// puts in the passed parameter into R25 and R24 as expected by the function.

#if OSCPU_TYPE==AT168 || OSCPU_TYPE==AT328
	#define portPushRetAddress()\
	asm volatile(\
		"mov r0, %A0	\n\t"\
		"push r0	\n\t"\
		"mov r0, %B0	\n\t"\
		"push r0	\n\t"\
		"mov R25, %B1	\n\t"\
		"mov R24, %A1	\n\t": : "r" (pxFuncPtr), "r" (pxFuncArg))
#elif OSCPU_TYPE==AT1280 || OSCPU_TYPE==AT2560
	#define portPushRetAddress()\
	asm volatile(\
		"mov r0, %A0	\n\t"\
		"push r0	\n\t"\
		"mov r0, %B0	\n\t"\
		"push r0	\n\t"\
		"mov r0, %C0	\n\t"\
		"push r0	\n\t"\
		"mov R25, %B1	\n\t"\
		"mov R24, %A1	\n\t": : "r" (pxFuncPtr), "r" (pxFuncArg))
#endif


inline void runTask() // allouer le processus activable au processeur
{
	unsigned char sreg;

	OSMakeAtomic(&sreg);
	// V�rifier si le processus est activable
	//if(Condition � �crire)
	if(false)
	{
		// Mettre � jour le statut du processus
		//Code � �crire
		portSetStack();
		// Lancer le processus : M�J des registres (R25,R24)
		// (R25,R24) = argument du processus et passer l'adresse de d�part du processu dans la pile

		// pxFuncPtr= � compl�ter
		// pxFuncArg= � compl�ter
		portPushRetAddress();
		OSExitAtomic(sreg);
	}
	else
	{
		OSExitAtomic(sreg);
		portRESTORE_CONTEXT();
	}
}
