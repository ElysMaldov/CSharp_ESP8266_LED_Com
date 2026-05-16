#include <Arduino.h>
#include <ArduinoJson.h>

char ledControllerDTOBuffer[43]; // total of our json is 41 + 1 for \n + 1 for null terminator
JsonDocument ledControllerDTOJsonDoc;

// Pins
int RED_LED = 16;
int YELLOW_LED = 5;
int GREEN_LED = 4;

void handleJsonDeserialization();
void toggleLEDFromDTO(int pin, String key);

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

  handleJsonDeserialization();

  toggleLEDFromDTO(RED_LED, "red");
  toggleLEDFromDTO(YELLOW_LED, "yellow");
  toggleLEDFromDTO(GREEN_LED, "green");
}

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