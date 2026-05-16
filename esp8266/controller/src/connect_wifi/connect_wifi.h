#include <ESP8266WiFi.h>

#ifndef CONNECT_WIFI_H
#define CONNECT_WIFI_H

extern char *ssid;
extern char *psk;

void connectToWiFi();

#endif
