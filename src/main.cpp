#include <Arduino.h>

#include <WiFi.h>
#include <HTTPClient.h>

#include <shelly.h>
#include <buttons.h>

#include "debug.h"


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

  #ifndef DEBUG_NO_WIFI
  WiFi.begin(WIFI_SSID, WIFI_PASSWD);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  trace("connected to wifi: %s", WIFI_SSID);
  trace("ip address: %s", WiFi.localIP().toString().c_str());

  #ifdef DEBUG
  Serial.println("\n");
  WiFi.printDiag(Serial);
  Serial.println("\n");
  #endif

  #else // DEBUG_NO_WIFI
  Serial.println("skiping wifi configuration");
  #endif //DEBUG_NO_WIFI
  #ifndef DEBUG_NO_GET
  http = (HTTPClient*)calloc(1, sizeof(HTTPClient));
  http = new HTTPClient();
  http->setConnectTimeout(500);
  #endif // DEBUG_NO_GET
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
