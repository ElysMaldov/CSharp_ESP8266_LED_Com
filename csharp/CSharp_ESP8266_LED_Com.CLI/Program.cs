using System.IO.Ports;
using CSharp_ESP8266_LED_Com.CLI.Entities;
using Microsoft.Extensions.Configuration;

class Program
{
  static Random rand = new();

  public static void Main(string[] args)
  {
    // Setup appsettings
    var builder = new ConfigurationBuilder().AddJsonFile("appsettings.json", optional: false, reloadOnChange: true);
    IConfiguration configuration = builder.Build();

    var esp8266Config = configuration.GetSection("ESP8266Config").Get<ESP8266Config>()
      ?? throw new InvalidOperationException("ESP8266Config section is not initialized correctly."); ;

    LEDController ledController = new(esp8266Config.IPAddress, esp8266Config.Port);


    ledController.ConfigureLED(new()
    {
      Green = rand.Next(2) == 1,
      Yellow = rand.Next(2) == 1,
      Red = rand.Next(2) == 1,
    });

    Console.WriteLine("Sent!");
  }
}