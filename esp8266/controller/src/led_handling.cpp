#include "led_handling.h"

// Allocate actual memory for the extern variables
char ledControllerDTOBuffer[43];
JsonDocument ledControllerDTOJsonDoc;

void handleJsonDeserialization()
{
  // Process data
  int bytesRead = Serial.readBytesUntil('\n', ledControllerDTOBuffer, sizeof(ledControllerDTOBuffer) - 1);
  ledControllerDTOBuffer[bytesRead] = '\0'; // null terminator to stop reading the string

  deserializeJson(ledControllerDTOJsonDoc, ledControllerDTOBuffer);
}

void toggleLEDFromDTO(int pin, String key)
{
  bool control = ledControllerDTOJsonDoc[key];

  digitalWrite(pin, control ? HIGH : LOW);
}