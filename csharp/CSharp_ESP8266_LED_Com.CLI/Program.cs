using System.IO.Ports;
using CSharp_ESP8266_LED_Com.CLI.Entities;
using Microsoft.Extensions.Configuration;

class Program
{
  public static void Main(string[] args)
  {
    // Setup appsettings
    var builder = new ConfigurationBuilder().AddJsonFile("appsettings.json", optional: false, reloadOnChange: true);
    IConfiguration configuration = builder.Build();

    var esp8266Config = configuration.GetSection("ESP8266Config").Get<ESP8266Config>()
      ?? throw new InvalidOperationException("ESP8266Config section is not initialized correctly."); ;

    LEDController ledController = new(esp8266Config.COMPort, esp8266Config.BaudRate);
    var canConnect = ledController.Connect();

    if (!canConnect) return;

    // TODO parse args from user input when running CLI
    ledController.ConfigureLED(new()
    {
      Green = false,
      Yellow = true,
      Red = false
    });

    Console.WriteLine("Sent!");
  }
}