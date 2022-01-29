#include <Arduino.h>
#include <string>
const int LED = 5;

char *letters[] = {
  // The letters A-Z in Morse code  
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         
};

char *numbers[] = {
  // The numbers 0-9 in Morse code  
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", 
  "--...", "---..", "----."
};

unsigned int dot_duration = 50;
bool done = false;

void flash_dot_or_dash(char dot_or_dash);
void flash_morse_code(char *morse_code);

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
  char ch;

  std::string phrase = "";

    while(!done){
      if (Serial.available())
      {
        ch = Serial.read();

        if (ch == '\n')
        {
          unsigned int i = 0;

          for(char const &c: phrase)
          {
            Serial.println(c);
            if (c >= 'A' && c <= 'Z')
            {
              Serial.println(c);
              flash_morse_code(letters[c - 'A']);
            }
            else if (c >= 'a' && c <= 'z')
            {
              Serial.println(c);
              flash_morse_code(letters[c - 'a']);
            }
            else if (c >= '0' && c <= '9')
            {
              Serial.println(c);
              flash_morse_code(letters[c - '0']);
            }

            else if (c == ' ')
            {
              delay(dot_duration * 7);
              Serial.println(" ");
            }
            
            else if (c == '!')
            {
              done = true;
              Serial.println("bonne soirer");
            }
            else if (c == '&')
            {
              Serial.println("GROS CACA ");
            }
          }

          phrase = "";
          Serial.println("enter message : ");
        }
      }
    }

    while(true) {}
}



void flash_dot_or_dash(char dot_or_dash){

  digitalWrite(LED, HIGH);

  if (dot_or_dash == '.')
  {
    delay(dot_duration);
  }
  else {
    delay(dot_duration * 3);
  }

  digitalWrite(LED, LOW);
  delay(dot_duration);
}

void flash_morse_code(char *morse_code)
{
    unsigned int i = 0;

    while (morse_code[i] != NULL)
    {
      flash_dot_or_dash(morse_code[i]);
      i++;
    }
    
    delay(dot_duration * 3);
}