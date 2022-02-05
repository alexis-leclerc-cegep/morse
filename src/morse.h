#ifndef MORSE_H
#define MORSE_H 

#include <string>

class MyMorse
{
    private:
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

        int pulse_time = 20;
        void flash_dot_or_dash(char dot_or_dash);
        void flash_morse_code(char *morse_code);

    public:
        MyCalc(char *letters[], char *numbers[], int pulse_time);
        void flash_string(String string_to_flash);
        
};

#endif MORSE_H
