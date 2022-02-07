#include <Arduino.h>
#include <string>
#include "morse.h"

const int LED_PIN = 23;
const int PULSE_LENGTH = 50;
char* serialString();
MyMorse morse(50, LED_PIN);
String readString;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Morse2Led");
  Serial.println("Programmed by Addison Sears-Collins");
  Serial.println("Copied and adapted by Alexis Leclerc");
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






  /*
  while(Serial.available()){
    delay(1);
    char c = Serial.read();
    if (c == 'a'){break;}
    Serial.print(c);
    readString += c;
  }
  if (readString.length() > 0)
  {
      Serial.println(readString);
      Serial.println("yo");
      readString = "";
  }
  
  
}
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
*/