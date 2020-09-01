#include <Arduino.h>

int temp[5];
int tempLen;
int tempAverage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tempLen = sizeof(temp) / sizeof(temp[0]);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x = 0; x < tempLen; x++) {
    temp[x] = random(10,20);
  }

  tempAverage = (temp[0] + temp[1] + temp[2])/tempLen;
  Serial.println(tempAverage);
  delay(5000);
}