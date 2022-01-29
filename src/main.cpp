#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <WiFiConfig.h> //wifi settings
#include <string>
#include <cstring>
#include <ESPAsyncWebServer.h>
using namespace std;


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

void ConnectToWifi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
    /* code */
  Serial.print("Connecting to "); Serial.println(SSID);

  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);

    if ((++i % 16) == 0)
    {
      Serial.println(F(" still trying to connect"));
    }
  }

  Serial.print(F("Connected. My IP address is: "));
  Serial.println(WiFi.localIP());
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>HTML Form to Input Data</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootswatch@4.5.2/dist/cyborg/bootstrap.min.css">
  </head><body class="bootstrap-dark m-1">
  <h2>HTML Form to Input Data</h2> 
  <form method="post">
    Enter a string: <input type="text" name="input_string">
    <input type="submit" value="Submit">
  </form><br>
  </body></html>
)rawliteral";


AsyncWebServer server(80);


unsigned int dot_duration = 25;
bool done = false;
const char* string_to_convert;

void flash_dot_or_dash(char dot_or_dash);
void flash_morse_code(char *morse_code);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("begin");
  ConnectToWifi();
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
    Serial.println("connecter qqn");
  });
  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request){
    if (request->hasParam("input_string"))
    {
      const char* input_message = request->getParam("input_string")->value().c_str();
      Serial.println(input_message);
    }
    request->send_P(200, "text/html", index_html);
  });
  server.begin();
  Serial.println("Morse2Led");
  Serial.println("Programmed by Addison Sears-Collins");
  Serial.println("Copied and adapted by Alexis Leclerc");
  Serial.println("");
  Serial.print("Enter you message : ");
}


void loop() {

  string phrase = "";


          for(char const &c: phrase)
          {
            if (c >= 'A' && c <= 'Z')
            {
              Serial.print(c);
              flash_morse_code(letters[c - 'A']);
            }
            else if (c >= 'a' && c <= 'z')
            {
              Serial.print(c);
              flash_morse_code(letters[c - 'a']);
            }
            else if (c >= '0' && c <= '9')
            {
              Serial.print(c);
              flash_morse_code(letters[c - '0']);
            }

            else if (c == ' ')
            {
              delay(dot_duration * 5);
              Serial.print(" ");
            }
            
            else if (c == '!')
            {
              done = true;
              Serial.print("bonne soirer");
            }
            else if (c == '&')
            {
              Serial.print("\nEnter your message : ");
              phrase = "";
              break;
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