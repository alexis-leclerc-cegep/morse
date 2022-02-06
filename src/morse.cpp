#include <Arduino.h>
#include "morse.h"
#include <string>


void flash_string(String phrase_a_ecrire);
void flash_morse_code(char *morse_code);
void flash_dot_or_dash(char dot_or_dash);


MyMorse::MyMorse(int MyPulseTime, int MyLedPin){
    pulseTime = MyPulseTime;
    ledPin = MyLedPin;
}

char* MyMorse::letters[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};
        
char* MyMorse::numbers[]= {
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", 
        "--...", "---..", "----."
};

void MyMorse::flash_string(String phrase_a_ecrire){
  for(char const &c: phrase_a_ecrire)
  {
    if (c >= 'A' && c <= 'Z')
    {
      Serial.print(c);
      flash_morse_code(MyMorse::letters[c - 'A']);
    }
    else if (c >= 'a' && c <= 'z')
    {
      Serial.print(c);
      flash_morse_code(MyMorse::letters[c - 'a']);
    }
    else if (c >= '0' && c <= '9')
    {
      Serial.print(c);
      flash_morse_code(MyMorse::numbers[c - '0']);
    }

    else if (c == ' ')
    {
      delay(pulseTime * 5);
      Serial.print(" ");
    }
  }
}

void MyMorse::flash_morse_code(char *morse_code){
    unsigned int i = 0;

    while (morse_code[i] != NULL)
    {
      flash_dot_or_dash(morse_code[i]);
      i++;
    }
    
    delay(pulseTime * 3);
};

void MyMorse::flash_dot_or_dash(char dot_or_dash){

  digitalWrite(ledPin, HIGH);

  if (dot_or_dash == '.')
  {
    delay(pulseTime);
  }
  else {
    delay(pulseTime * 3);
  }

  digitalWrite(ledPin, LOW);
  delay(pulseTime);
}