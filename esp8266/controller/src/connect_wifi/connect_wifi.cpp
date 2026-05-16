#include "connect_wifi.h"

char *ssid = STASSID;
char *psk = STAPSK;

void connectToWiFi()
{
  // Connect wifi
  WiFi.begin(STASSID, STAPSK);
  Serial.println("Connecting to ");
  Serial.println(STASSID);
  Serial.println("...");

  // Wait for wifi
  int i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(++i);
    Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connected to network!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}