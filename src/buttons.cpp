#include <Arduino.h>
#include <HTTPClient.h>

#include <buttons.h>
#include <shelly.h>
#include "debug.h"

volatile unsigned long alteZeit=0;
unsigned long entprellZeit=500;

void deprell(button_t button){
    if((millis() - alteZeit) > entprellZeit) {
    alteZeit = millis(); // letzte Schaltzeit merken
    Serial.printf("%d wurde betaetigt \n", (int)button);
  }
}

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
