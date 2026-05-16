using Microsoft.Extensions.Configuration;

namespace CSharp_ESP8266_LED_Com.CLI.Entities;

public record class ESP8266Config
{
  public int BaudRate { get; set; }
  public int COMPort { get; set; }
}