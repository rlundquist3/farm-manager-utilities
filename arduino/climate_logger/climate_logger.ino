#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN1 (2)
#define DHTTYPE DHT22
DHT dht (DHTPIN1, DHTTYPE);


void setup() {
  Serial.begin(9600);
  dht.begin();
  
 }

void loop() {
  float h1 = dht.readHumidity();
  float t1 = dht.readTemperature(true);
  if (isnan(h1) || isnan(t1)) {
      Serial.println("Failed to read from DHT sensor #1!");
      return;
  }
      
  Serial.print(h1); Serial.print(","); Serial.println(t1);

  delay(5000);

}
