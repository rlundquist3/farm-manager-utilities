#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN1 (2)
#define DHTTYPE DHT22
DHT dht (DHTPIN1, DHTTYPE);
int Humidify = 3;
int Heating = 4;
int Meal1HeatHigh =75;
int Meal1HeatLow =65;
int Meal1HumidHigh =85;
int Meal1HumidLow =70;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(Humidify, OUTPUT);
  pinMode(Heating, OUTPUT);
  
  
 }

void loop() {
  float h1 = dht.readHumidity();
  float t1 = dht.readTemperature(true);
  if (isnan(h1) || isnan(t1)) {
      Serial.println("Failed to read from DHT sensor #1!");
      delay(1000);
      return;
  }
      
  Serial.print(h1); Serial.print(","); Serial.println(t1);

  if (h1 < Meal1HumidLow) {
    digitalWrite(Humidify, HIGH);}
  if (h1 > Meal1HumidHigh) {  
      digitalWrite(Humidify, LOW);}
  if (t1 < Meal1HeatLow){
    digitalWrite(Heating, HIGH);}
  if(t1 > Meal1HeatHigh) {
      digitalWrite(Heating, LOW);}
  delay(5000);

}
