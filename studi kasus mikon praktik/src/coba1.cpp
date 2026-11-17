#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

const int potPin = 34;
Adafruit_INA219 ina219;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);

  if (!ina219.begin()) {
    Serial.println("INA219 tidak terdeteksi!");
  }
}

void loop() {
    int potValue = analogRead(potPin);
    int persen = map(potValue, 0, 4095, 0, 100);
    persen = constrain(persen, 0, 100);

    float arus = ina219.getCurrent_mA();
    float tegangan_V = ina219.getBusVoltage_V();
    float daya_mW = ina219.getPower_mW();

    Serial.print("ADC: ");
    Serial.print(potValue);
    Serial.print(" , Tegangan: ");
    Serial.print(tegangan_V);
    Serial.print(" V , Arus: ");
    Serial.print(arus);
    Serial.println(" mA");
    
    delay(1000);
}