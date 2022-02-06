#include <Arduino.h>
#include <string>
#include "morse.h"

const int LED = 5;
char* serialString();
MyMorse morse(LED, 20);

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Morse2Led");
  Serial.println("Programmed by Addison Sears-Collins");
  Serial.println("Copied and adapted by Alexis Leclerc");
  Serial.println("");
  Serial.print("Enter you message : ");
}


void loop() {
  static boolean needPrompt=true;
    char* userInput;
    if (needPrompt)
    {
      Serial.println("Entrez la phrase : ");
      needPrompt=false;
    }
    userInput = serialString();
    if (userInput!=NULL)
    {
      morse.flash_string("..-");
      needPrompt=true;
    }
}


char* serialString()
{
  static char str[21]; // For strings of max length=20
  if (!Serial.available()) return NULL;
  delay(64); // wait for all characters to arrive
  memset(str,0,sizeof(str)); // clear str
  byte count=0;
  while (Serial.available())
  {
    char c=Serial.read();
    if (c>=32 && count<sizeof(str)-1)
    {
      str[count]=c;
      count++;
    }
  }
  str[count]='\0'; // make it a zero terminated string
  return str;
}