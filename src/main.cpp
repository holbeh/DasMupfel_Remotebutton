#include <Arduino.h>

#include "WiFi.h"
#include <HTTPClient.h>
 

HTTPClient http;
int code;
// const char* ssid = "yourNetworkName";
// const char* password = "yourNetworkPassword";
 
void setup() {
 
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