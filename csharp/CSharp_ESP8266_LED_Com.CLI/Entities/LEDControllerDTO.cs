using System.Text.Json;

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