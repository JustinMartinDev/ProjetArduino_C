# ProjetArduino_C Clignote_Led_V1

Contient le programme C permettant de faire clignoter la LED de la broche 2 et d'envoyer un message
via le port serie en même temps

# Titre Sketch : Clignotement de led et communication serie
# Description :

Permet de changer l'état d'une LED (sur D2) tout en envoyant un message via une liason serie (par USB)

# Schéma: 

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Clignotement_Led_V1_USART/schema_arduino.png)

# Utilisation :

Une fois le code téléversé, ouvrez un moniteur serie sur le port de communcation ouvert avec votre carte. Quand la led change d'état vous recevez un message vous indiquant le nouvel état.

Matériel nécessaire:
LED sur le port D2
