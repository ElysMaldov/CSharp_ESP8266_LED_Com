#include <Arduino.h>
#include <ArduinoJson.h>

char ledControllerDTOBuffer[42];
JsonDocument ledControllerDTOJsonDoc;

// Pins
int RED_LED = 16;
int YELLOW_LED = 5;
int GREEN_LED = 4;

void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(115200);

  Serial.println("Ready to get messages!");
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);

  if (!Serial.available())
    return;

  digitalWrite(LED_BUILTIN, LOW);

  // Process data
  int bytesRead = Serial.readBytesUntil('\n', ledControllerDTOBuffer, sizeof(ledControllerDTOBuffer) - 1);
  ledControllerDTOBuffer[bytesRead] = '\0'; // null terminator to stop reading the string

  deserializeJson(ledControllerDTOJsonDoc, ledControllerDTOBuffer);

  bool redControl = ledControllerDTOJsonDoc["red"];
  bool yellowControl = ledControllerDTOJsonDoc["yellow"];
  bool greenControl = ledControllerDTOJsonDoc["green"];

  // Use values to GPIO pins
  digitalWrite(RED_LED, redControl ? HIGH : LOW);
  digitalWrite(YELLOW_LED, yellowControl ? HIGH : LOW);
  digitalWrite(GREEN_LED, greenControl ? HIGH : LOW);
}
