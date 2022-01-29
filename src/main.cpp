#include <Arduino.h>

const int LED = 5;

void flash(int duration);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void flash(int duration){
  digitalWrite(LED, LOW);
  Serial.println("low");
  delay(duration);
  digitalWrite(LED, HIGH);
  Serial.println("high");
  delay(duration);
}

void loop() {
  // put your main code here, to run repeatedly:
  flash(200); flash(200); flash(200);

  delay(300);

  flash(500); flash(500); flash(500);

  flash(200); flash(200); flash(200);

  delay(1000);
}
