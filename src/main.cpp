#include <Arduino.h>

#include <WiFi.h>
#include <HTTPClient.h>
#include <shelly.h>
#include "config.h"

volatile unsigned long alteZeit=0, entprellZeit=300;

void deprell(button_t button){
    if((millis() - alteZeit) > entprellZeit) { 
    alteZeit = millis(); // letzte Schaltzeit merken     
    Serial.printf("%d wurde betaetigt \n", (int)button); 
  }
}

void detachAllInterupts();
void attachAllInterupts();

void interruptRoutine_LED_BAR_RIGHT() {
  detachAllInterupts();
  deprell(BUTTON_LED_BAR_RIGHT);
  attachAllInterupts();
}
void interruptRoutine_LED_BAR_BACK() {
  detachAllInterupts();
  deprell(BUTTON_LED_BAR_BACK);
  attachAllInterupts();
}
void interruptRoutine_CEILING_LED() {
  detachAllInterupts();
  deprell(BUTTON_CEILING_LED_1);
  attachAllInterupts();
}
void interruptRoutine_HEATER_START() {
  detachAllInterupts();
  deprell(BUTTON_HEATER_START);
  attachAllInterupts();
}

void attachAllInterupts(){
  attachInterrupt((int)BUTTON_LED_BAR_RIGHT, interruptRoutine_LED_BAR_RIGHT, FALLING);
  attachInterrupt((int)BUTTON_LED_BAR_BACK, interruptRoutine_LED_BAR_BACK, FALLING);
  attachInterrupt((int)BUTTON_CEILING_LED_1, interruptRoutine_CEILING_LED, FALLING);
  attachInterrupt((int)BUTTON_HEATER_START, interruptRoutine_HEATER_START, FALLING);
}

void detachAllInterupts(){
  detachInterrupt((int)BUTTON_LED_BAR_RIGHT);
  detachInterrupt((int)BUTTON_LED_BAR_BACK);
  detachInterrupt((int)BUTTON_CEILING_LED_1);
  detachInterrupt((int)BUTTON_HEATER_START);
}

//HTTPClient http;
HTTPClient* http;
int code;
void setup() {
  
  pinMode((int)BUTTON_LED_BAR_RIGHT, INPUT_PULLUP);
  pinMode((int)BUTTON_LED_BAR_BACK, INPUT_PULLUP);
  pinMode((int)BUTTON_CEILING_LED_1, INPUT_PULLUP);
  pinMode((int)BUTTON_HEATER_START, INPUT_PULLUP);
  digitalWrite((int)BUTTON_LED_BAR_RIGHT, HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  digitalWrite((int)BUTTON_LED_BAR_BACK , HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  digitalWrite((int)BUTTON_CEILING_LED_1, HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  digitalWrite((int)BUTTON_HEATER_START, HIGH);  //eigentlich nicht notwendig - aber funktioniert deutlich besser
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWD);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  http = new HTTPClient();
  http->setConnectTimeout(500);
  Serial.println("Setup done");

  attachAllInterupts();

}
 
void loop() {

  Serial.println(button_find_shelly(BUTTON_LED_BAR_RIGHT));
  //Serial.println((int)BUTTON_LED_BAR_RIGHT);

  /*http->begin("http://192.168.178.138/relay/0?turn=toggle");
  code = http->GET();
  if (code!=200){
    Serial.println("Nicht übermittlet");
  }
  else Serial.println("Relais Umgeschaltet");
  http->end();*/
  //toggle_shelly(SHELLY_U_HEATING_1);
  delay (2000);

  delay (8000);
}
