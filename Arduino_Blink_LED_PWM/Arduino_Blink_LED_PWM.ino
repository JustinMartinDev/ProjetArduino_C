/* 
 * La LED D6 est tout le temps allumé et son intensité est contrôlée via le potentiomètre
 * Le BUTTON D4 permet à l'utilisateur de sélectionner la valeur de référence (afficher via le port de communication série)
 * La LED D5 est commandée en fonction de la valeur de référence, allumée si valeur du potentiomètre > seuil
 */

#define LED_D5 5 //LED sur port D5
#define LED_D6 6 //LED sur port D6
#define POT_A0 A0 //Potentiometre sur port A0 
#define BUTTON_D4 4 //Bouton sur D4

bool hasBeenInit;
int valueRef;

void setup() {
  // put your setup code here, to run once:  
  pinMode(LED_D5, OUTPUT);
  pinMode(POT_A0, INPUT);
  pinMode(BUTTON_D4, INPUT);
  hasBeenInit = false;
  valueRef = 0;
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  int valuePot = analogRead(POT_A0);//Lecture de la valeur du potentiometre
  if(!hasBeenInit){
    InitFunctionRef(valuePot);
    delay(1000);
  }else {
    digitalWrite(LED_D6, LOW); //reinitialisation de LED 6 à l'état bas
    if(valuePot > valueRef){
      digitalWrite(LED_D6, HIGH); //activiation ssi le seuil est dépassé
    }
    analogWrite(LED_D5, valuePot/4); //controle de la LED 5 en PWM (intensité lumineuse)
  }
}

//Demande à l'utilisateur de valider le seuil en fonction de la valeur du potentiometre
void InitFunctionRef(int valuePot){
  Serial.print("Actual value : ");
  Serial.println(valuePot);
  Serial.println("Press button to set as value Ref");//Envoi en com serie la valeur actuelle du potentiometre
  
  /*Si le bouton est pressé on initialise le seuil avec la valeur actuelle du potentiometre*/
  if(digitalRead(BUTTON_D4) == HIGH){
    hasBeenInit = true;
    valueRef = valuePot;
    Serial.print("Saved value ref :");
    Serial.println(valueRef);
  }
}
