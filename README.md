# Projet Tuteuré C n°2

Partie1 : Ressources carte Arduino
Groupe : Barthélémy MARSAULT, Gaétan JAGOREL, Justin MARTIN

-------------------------------------------------------------------------------------------------------------------------------------

## Titre Sketch : Blink LED PWM
## Description : 

Permet de modifier l'intensité d'une LED en fonction d'un potentiomètre, une seconde LED commandée via un seuil sélectionné par l'utilisateur

## Schéma :

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Arduino_Blink_LED_PWM/schema_arduino.png)

## Utilisation :
Une fois le code téléversé, ouvrez un moniteur série sur le port de communication de votre carte. Cette phase permet d'initialiser votre valeur de seuil

![Serial com init](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Arduino_Blink_LED_PWM/Serial_com_init.PNG)

Matériel nécessaire:
* LED sur le port D5
* LED sur le port D6 
* Potentiometre sur le port A0
* Boutton sur le port D4

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Blink LED V1
## Description : 

Permet de faire clignoter une LED

## Schéma :

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Arduino_Blink_LED_V1/shema_arduino.png)

## Utilisation :
Pas de consigne particulière

Matériel nécessaire:
* LED sur le port D5

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Boutton Poussoir V1
## Description : 

Utilise une interruption materiel (bouton) pour changer l'état d'une LED (D5) et sinon fait clignoter une autre LED en continu (D4)

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Arduino_Bouton_Poussoir_V1/schema_arduino.png)

## Utilisation :
Appuyez sur le bouton pour commander le changement d'état de la LED D5

Materiel necessaire :
* LED sur le port D4
* LED sur le port D5
* Boutton poussoir sur le port D2

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Blink LED V2 IT_Timer1
## Description : 

Utilise une interruption logicielle pour faire clignoter 2 LED, la LED D4 s'allume quand la LED D5 s'éteint et vice versa. La période durant laquelle la LED D4 est allumée est différente de celle de D5

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Arduino_Clignote_LED_V2_IT_TIMER1/schema_arduino.png)

## Utilisation :
Pas de consigne particulière

Matériel nécessaire:
* LED sur le port D3
* LED sur le port D4

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : BP_LED_INT1_ITTIMER1
Clignotement de led via interruption materielle
## Description :

Permet de changer l'état d'une LED (sur D5) avec une interruption materielle (sur D3). Tout en faisant clignoter une autre LED (sur D4)

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/BP_LED_INT1_ITTIMER1/schema_arduino.png)

## Utilisation :
Une fois le code téléversé, vous pouvez changer l'etat d'une led via le bouton, tout en voyant clignoter la seconde

Matériel nécessaire:
* LED sur le port D5
* LED sur le port D4
* Bouton sur le port D3

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : BP_LED_INT1_ITTIMER1_V2
Clignotement de led via interruption timer et changement d'état d'une autre via interruption materielle
## Description : 

Permet de changer l'état d'une LED (sur D5) avec une interruption materielle (sur D3). Tout en faisant clignoter une autre LED (sur D4) à l'aide d'un Timer

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/BP_LED_INT1_ITTIMER1_V2/schema_arduino.png)

## Utilisation :

Une fois le code téléversé, vous pouvez changer l'etat de la LED (D5) via le bouton, tout en voyant clignoter la seconde LED (D4)

Matériel nécessaire:
* LED sur le port D5
* LED sur le port D4
* Bouton sur le port D3

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Clignote_Led_V1
Clignotement de la led interne (broche 5)
## Description :

Permet de faire clignoter la led interne de l'arduino uno 

## Schéma :

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Clignote_Led_V1/schema_arduino.png)

## Utilisation :
Pas de consigne particulière

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Clignote_Led_V1_USART
Clignotement de led et communication serie
## Description :

Permet de changer l'état d'une LED (sur D2) tout en envoyant un message via une liason serie (par USB)

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Clignote_Led_V1_USART/schema_arduino.png)

## Utilisation :
Une fois le code téléversé, ouvrez un moniteur serie sur le port de communcation ouvert avec votre carte. Quand la led change d'état vous recevez un message vous indiquant le nouvel état.

Matériel nécessaire:
* LED sur le port D2

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Clignote_Led_v2
Clignotement de 3 LEDs externes
## Description :

Permet de changer faire clignoter 3 LED en allumant et éteignant les un après les autres.

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Clignote_Led_V2/schema_arduino.png)

## Utilisation :
Pas de consigne particulière

Matériel nécessaire:
* LED sur le port D6
* LED sur le port D5
* LED sur le port D4

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Clignote_Led_V2_IT_Timer1
Clignotement de la led via interruption timer
## Description :

Contient le programme C permettant de faire clignoter la LED branchée sur le port D2 avec le Timer1,
la led est allumée plus longtemps qu'elle est éteinte

## Schéma :

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/BP_LED_INT1_ITTIMER1_V2/schema_arduino.png)

# Utilisation :
Pas de consigne particulière

Matériel nécessaire:
* LED sur D2

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Lecture_Analogique_ADC0
Commande de LED via un potentiometre
## Description :

Contient le programme C permettant de faire d'allumer 3 LED en fonction le la valeur d'un potentiometre
La valeur permet de changer le nombre de led qui sont allumées
La definition de la valeur maximal renvoyé par potentiometre se fait en allant au moins une fois au maximum de celui-ci

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Lecture_Analogique_ADC0/schema_arduino.png)

## Utilisation :
Une fois téléversé, tournez le potentiomètre au maximum (une communication série vous permet d'observer l'évolution de la valeur), une fois au maximum vous pouvez diminuer progressivement la valeur du potentiomètre pour observer l'évolution des états des LEDs

## Note : 
Il est possible que vous trouviez cette méthode étrange mais elle avait été conçue pour permettre de régler la valeur de référence mais cette fonctionnalité n'a pas été abouti sur la version C. (disponible sur la version Arduino)

Matériel nécessaire:
* LED sur D4
* LED sur D5
* LED sur D6

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Test_Arduino_CodeBlocks
## Description : 

Utilise une interruption materiel (bouton) pour changer l'état d'une LED (D5) et sinon fait clignoter une autre LED en continu (D4)

## Utilisation :
Appuyez sur le bouton pour commander le changement d'état de la LED D5

Materiel necessaire :
* LED sur le port D4
* LED sur le port D5
* Boutton poussoir sur le port D2

---------------------------------------------------------------------------------------------------------------------------------------
## Titre Sketch : Lecture_Humidité
Permet de lire l'humidité et la temperature via un capteur
## Description :

Contient le programme Arduino permettant de lire la temparature et l'humidité via le capteur grove (et avec l'aide de la librairy).
Ces valeurs sont ensuite transmises via liason serie

## Schéma : 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Lecture_humidite/schema_arduino.png)

## Utilisation :
Une fois téléversé, ouvrez un moniteur serie afin d'observé les valeurs transmises par le capteur

Matériel nécessaire:
* Capteur humidité sur D2

