#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <DHT.h>

#define DHT_PIN 5
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
float temp = 0;
float humid = 0;
void updateData();
String printData;
String tempSentence = "Temperatur saat ini: ";
String humidSentence = "Kelembaban saat ini: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateData();
  printData = tempSentence + String(temp) + String(" C");
  Serial.println(printData);
  printData = humidSentence + String(humid) + String(" %");
  Serial.println(printData);
  delay(5000);
}

void updateData(){
  temp = dht.readTemperature();
  humid = dht.readHumidity();
}