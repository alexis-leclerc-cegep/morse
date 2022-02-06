#ifndef MORSE_H
#define MORSE_H 

#include <string>

class MyMorse
{
    private:
        // The letters A-Z in Morse code  
        /*
        */

        // The numbers 0-9 in Morse code  
        /*
        };
        */

        int pulseTime = 20; //pas été bon pour mettre en const 
        int ledPin = 5;
        void flash_dot_or_dash(char dot_or_dash);
        void flash_morse_code(char *morse_code);

    public:
        MyMorse(int myPulseTime, int myLedPin);
        void flash_string(String phrase_a_ecrire);
        static const char* letters[26]; 
        static const char* numbers[10]; 
        
};

#endif MORSE_H
