#include <Arduino.h>

const int in1 = 17;
const int in2 = 18;
const int pwmPin = 16;
const int stby = 19;
const int potPin = 34; //Pin untuk membaca potensiometer

void setup() {
  // Inisialisasi pin driver motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(stby, OUTPUT);
  // Aktifkan driver dan set arah putaran maju
  digitalWrite(stby, HIGH); 
  digitalWrite(in1, HIGH);  
  digitalWrite(in2, LOW);
  // Konfigurasi PWM ESP32
  ledcSetup(0, 5000, 8);
  ledcAttachPin(pwmPin, 0);
  // Mulai komunikasi serial untuk memantau nilai (opsional)
  Serial.begin(115200); 
}

void loop() {
  int potValue = analogRead(potPin); //Baca nilai dari potensiometer (hasil: 0 - 4095)
  int motorSpeed = map(potValue, 0, 4095, 0, 255); //Konversi nilai 0-4095 menjadi 0-255 untuk PWM motor

  ledcWrite(0, motorSpeed); //Tulis kecepatan ke pin PWM motor
  //Cetak nilai ke Serial Monitor untuk proses debugging
  Serial.print("Nilai Potensiometer: ");
  Serial.print(potValue);
  Serial.print(" | Kecepatan Motor (PWM): ");
  Serial.println(motorSpeed);
  
  delay(50); //Jeda singkat agar pembacaan stabil dan tidak membebani ESP32
}

