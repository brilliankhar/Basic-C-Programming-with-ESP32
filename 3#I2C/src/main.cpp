#include <Arduino.h>
#include <Wire.h>

#define BH1750_ADDRESS 0x23
#define BH1750_DATALEN 2 

byte buff[2];
unsigned short lux = 0;

void bh1750Request(int address){
  Wire.beginTransmission(address);
  Wire.write(0x10);
  Wire.endTransmission();
}

int bh1750Read(int address)
{
  int i = 0;

  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while (Wire.available())
  {
    buff[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();

  return i;
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bh1750Request(BH1750_ADDRESS);
  delay(200);

  if(bh1750Read(BH1750_ADDRESS) == BH1750_DATALEN) {
    lux = (((unsigned short)buff[0] << 8)|(unsigned short)buff[1]) / 1.2;
    Serial.print(lux);
    Serial.println("lux");
  }
  delay(1000);

}