#include <Arduino.h>
#include <ArduinoJson.h>
#include "led_handling.h"
#include "connect_wifi/connect_wifi.h"

// Pins
int RED_LED = 16;
int YELLOW_LED = 5;
int GREEN_LED = 4;

void setup()
{
  Serial.begin(115200);

  connectToWiFi();

  // Setup pins
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.println("Ready to get messages!");
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);

  if (!Serial.available())
    return;

  digitalWrite(LED_BUILTIN, LOW);

  handleJsonDeserialization();

  toggleLEDFromDTO(RED_LED, "red");
  toggleLEDFromDTO(YELLOW_LED, "yellow");
  toggleLEDFromDTO(GREEN_LED, "green");
}
