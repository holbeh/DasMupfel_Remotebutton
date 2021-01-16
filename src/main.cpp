#include <Arduino.h>
#include "WiFi.h"
#include <HTTPClient.h>

#define button1 17
#define button2 23
#define button3 34
#define button4 35
 

HTTPClient http;
int code;
const char* ssid = "yourNetworkName";
const char* password = "yourNetworkPassword";
 
void setup() {
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  digitalWrite(button1, HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  digitalWrite(button2, HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  digitalWrite(button3, HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  digitalWrite(button4, HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  
  http.setConnectTimeout(500);
}
 
void loop() {

  http.begin("http://192.168.178.138/relay/0?turn=toggle");
  code = http.GET();  
  if (code!=200){
    Serial.println("Nicht übermittlet");
  }
  else Serial.println("Relais Umgeschaltet");
  http.end();
  delay (2000);

  // http.begin("http://192.168.178.138/relay/0?turn=on");
  // code = http.GET(); 
  // if (code!=200){
  //   Serial.println("Nicht übermittlet");
  // }
  // else Serial.println("Relais ANgeschaltet");
  // http.end();
  delay (8000);
}