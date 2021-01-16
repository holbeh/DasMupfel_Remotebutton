#include <Arduino.h>

#include <WiFi.h>
#include <HTTPClient.h>

#include <shelly.h>

#include "config.h"

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
  
  http->setConnectTimeout(500);
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
  toggle_shelly(SHELLY_U_HEATING_1);
  delay (2000);

  delay (8000);
}
