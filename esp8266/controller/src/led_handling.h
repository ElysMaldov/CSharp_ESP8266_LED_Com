#include <Arduino.h>
#include <ArduinoJson.h>

#ifndef LED_HANDLING_H
#define LED_HANDLING_H

// Use extern to publish to entire app
extern char ledControllerDTOBuffer[43]; // total of our json is 41 + 1 for \n + 1 for null terminator
extern JsonDocument ledControllerDTOJsonDoc;

void handleJsonDeserialization();
void toggleLEDFromDTO(int pin, String key);

#endif