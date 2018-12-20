
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include <rgb_lcd.h>
#include "DHT.h"
#include <Wire.h>

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);

rgb_lcd lcd;

int colorR = 0;
int colorG = 0;
int colorB = 0;

void setup() {
  Serial.begin(9600); 
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);  
  dht.begin();
}

void loop() {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // check if returns are valid, if they are NaN (not a number) then something went wrong!
    if (isnan(t) || isnan(h)){
        displayIntoLCDString("Failed to read from DHT");
    } else {
        displayIntoLCDData(h, t);
    }
}

void displayIntoLCDData(float h, float t){
  colorB = 255;
  colorR = (t > 25 ? 255 : 0);
  
  lcd.setRGB(colorR, colorG, colorB);

  Serial.println(colorB);
  Serial.println(colorR);
  
  lcd.print("Humidity: ");
  lcd.setCursor(11,0);
  lcd.print(h);
  
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.setCursor(13,1);
  lcd.print(t);
  
}

void displayIntoLCDString(String text){
   lcd.setCursor(0,0);
   lcd.print(text);
}
