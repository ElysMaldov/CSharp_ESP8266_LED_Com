#include <Arduino.h>
#include <ArduinoJson.h>
#include "led_handling.h"
#include "connect_wifi/connect_wifi.h"

WiFiServer server(8888);

// Pins
int RED_LED = 16;
int YELLOW_LED = 5;
int GREEN_LED = 4;

void setup()
{
  Serial.begin(115200);

  connectToWiFi();

  server.begin();
  Serial.print("Listening on: ");
  Serial.println(8888);

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

  // Its like express's req object, declare it here to make new object
  // on each loop if there is a connection happening
  WiFiClient client = server.available();

  if (!client.available())
    return;

  digitalWrite(LED_BUILTIN, LOW);

  handleJsonDeserialization(client);

  toggleLEDFromDTO(RED_LED, "red");
  toggleLEDFromDTO(YELLOW_LED, "yellow");
  toggleLEDFromDTO(GREEN_LED, "green");
}
