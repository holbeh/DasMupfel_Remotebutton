#ifndef __DEBUG_H_
#define __DEBUG_H_

#include "config.h"

#ifdef DEBUG
#define trace(fmt...) Serial.printf(fmt); Serial.println()
#else
#define trace(fmt...)
#endif // DEBUG

#ifdef DEBUG_NO_WIFI
#ifndef DEBUG_NO_GET
#error You have to set DEBUG_NO_GET to use DEBUG_NO_WIFI
#endif // DEBUG_NO_GET
#endif // DEBUG_NO_WIFI

#endif // __DEBUG_H_
