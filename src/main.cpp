#include <Arduino.h>
#include <string>
#include "morse.h"

const int LED_PIN = 23;
const int PULSE_LENGTH = 20;
char* serialString();
MyMorse morse(PULSE_LENGTH, LED_PIN);
String readString;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Morse2Led");
  Serial.println("Programmed by Addison Sears-Collins");
  Serial.println("Copied and adapted to OOP by Alexis Leclerc");
  Serial.println("");
  Serial.print("Enter you message : ");
}


void loop() {

  char ch;
  if (Serial.available())
  {
    ch = Serial.read();
    if (ch == '\n'){
      Serial.print("\n");
      morse.flash_string(readString);
      Serial.print("\nEnter your message : ");
      readString = "";
    }
    else{
      Serial.print(ch);
      readString += ch;   
    }
  }
}