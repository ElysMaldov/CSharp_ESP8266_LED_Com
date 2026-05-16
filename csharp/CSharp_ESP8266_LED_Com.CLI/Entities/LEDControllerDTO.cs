using System.Text.Json;

namespace CSharp_ESP8266_LED_Com.CLI.Entities;

public record struct LEDControllerDTO(bool Red, bool Yellow, bool Green)
{
  public string ToJson()
  {
    string jsonOutput = JsonSerializer.Serialize(this, new JsonSerializerOptions()
    {
      PropertyNamingPolicy = JsonNamingPolicy.CamelCase
    });

    return jsonOutput;
  }
};