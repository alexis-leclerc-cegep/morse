#ifndef MORSE_H
#define MORSE_H 

#include <string>

class MyMorse
{
    private:
        int pulseTime = 100; //pas été bon pour mettre en const 
        int ledPin = 2;
        void flash_dot_or_dash(char dot_or_dash);
        void flash_morse_code(char *morse_code);

    public:
        MyMorse(int myPulseTime, int myLedPin);
        void flash_string(String phrase_a_ecrire);
        static char* letters[26]; 
        static char* numbers[10]; 
        
};

#endif MORSE_H
