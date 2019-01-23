# Titre Sketch : Commande de LED via un potentiometre
# Description :

Contient le programme C permettant de faire d'allumer 3 LED en fonction le la valeur d'un potentiometre
La valeur permet de changer le nombre de led qui sont allumées
La definition de la valeur maximal renvoyé par potentiometre se fait en allant au moins une fois au maximum de celui-ci

![Schéma](https://raw.githubusercontent.com/JustinMartinDev/ProjetArduino_C/master/Lecture_Analogique_ADC0/schema_arduino.png)

# Utilisation :
Une fois téléversé, tournez le potentiomètre au maximum (une communication série vous permet d'observer l'évolution de la valeur), une fois au maximum vous pouvez diminuer progressivement la valeur du potentiomètre pour observer l'évolution des états des LEDs


## Note : 
Il est possible que vous trouviez cette méthode étrange mais elle avait été conçue pour permettre de régler la valeur de référence mais cette fonctionnalité n'a pas été abouti sur la version C. (disponible sur la version Arduino)

Matériel nécessaire:
LED sur D4
LED sur D5
LED sur D6
