using Microsoft.Extensions.Configuration;

namespace CSharp_ESP8266_LED_Com.CLI.Entities;

public record class ESP8266Config
{
  public string IPAddress { get; set; } = "";
  public int Port { get; set; }
}