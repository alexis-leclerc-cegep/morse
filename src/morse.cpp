#include <Arduino.h>
#include "morse.h"
#include <string>

int pulseTime;
int ledPin; 


//MyMorse::MyMorse(const unsigned char letters[], const unsigned char numbers[]){
MyMorse::MyMorse(int MyPulseTime, int MyLedPin){
    pulseTime = MyPulseTime;
    ledPin = MyLedPin;
}

const char* MyMorse::letters[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    
        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  
        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." 
};
        
const char* MyMorse::numbers[]= {
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", 
        "--...", "---..", "----."
};

void flash_string(String phrase_a_ecrire){

}

void flash_morse_code(char *morse_code)
{
    unsigned int i = 0;

    while (morse_code[i] != NULL)
    {
      flash_dot_or_dash(morse_code[i]);
      i++;
    }
    
    delay(pulseTime * 3);
}

void flash_dot_or_dash(char dot_or_dash){

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