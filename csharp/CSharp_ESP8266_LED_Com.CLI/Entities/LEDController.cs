using System.IO.Ports;

namespace CSharp_ESP8266_LED_Com.CLI.Entities;

public class LEDController(int Port, int BaudRate)
{
  private SerialPort _serialPort = new($"COM{Port}", BaudRate);


  public bool Connect()
  {
    try
    {
      _serialPort.Open();
    }
    catch (UnauthorizedAccessException)
    {
      Console.WriteLine("Connection is being used by another process.");
      return false;
    }

    return true;
  }

  public void ConfigureLED(LEDControllerDTO dto)
  {
    string payload = dto.ToJson();

    _serialPort.WriteLine(payload);
  }
}