#include <Arduino.h>
#include <HTTPClient.h>
//#include <WiFi.h>

#include <shelly.h>
#include <debug.h>

int toggle_shelly(shelly_address_t shelly) {
    trace("toggle shelly %d", (int)shelly);
    char buffer[SHELLY_URL_BUFFER];
    sprintf(buffer, SHELLY_URL, (int)shelly);

    #ifndef DEBUG_NO_GET
    http->begin(buffer);
    int code = http->GET();
    trace("got http code: %d", code);
    http->end();
    #else
    int code = 200;
    Serial.printf("fake 200 for %s\n", buffer);
    #endif // DEBUG_NO_GET
    return code;
}
