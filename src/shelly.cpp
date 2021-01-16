#include <Arduino.h>
#include <HTTPClient.h>
//#include <WiFi.h>

#include <shelly.h>
#include <config.h>

int toggle_shelly(shelly_address_t shelly) {
    char buffer[SHELLY_URL_BUFFER];
    sprintf(buffer, SHELLY_URL, (int)shelly);

    http->begin(buffer);
    int code = http->GET();
    http->end();
    return code;
}
