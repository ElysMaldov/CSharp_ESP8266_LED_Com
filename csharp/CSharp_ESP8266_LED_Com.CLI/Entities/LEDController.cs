using System.Net.Sockets;

namespace CSharp_ESP8266_LED_Com.CLI.Entities;

public class LEDController(string IPAddress, int Port)
{
  public void ConfigureLED(LEDControllerDTO dto)
  {
    try
    {
      // Create client here so we only connect to our MCU when needed and
      // instantly disconnect once done, saving our MCU's connections
      using TcpClient client = new(IPAddress, Port);
      client.SendTimeout = 5000;
      client.ReceiveTimeout = 5000;

      string payload = dto.ToJson() + "\n"; // add end terminator since we arent using Console.WriteLine anymore that automatically adds that

      Byte[] data = System.Text.Encoding.ASCII.GetBytes(payload);

      // C# will collate the data from the stream instead of sending data
      // bytes by bytes which would be very cumborsome due to having to handle
      // each TCP packet overhead of ACK-ing
      using NetworkStream stream = client.GetStream();

      stream.Write(data, 0, data.Length);
    }
    catch (SocketException)
    {
      Console.WriteLine("Failed to connect to server");
    }
    catch (IOException)
    {
      Console.WriteLine("Connection timed out while sending data");
    }
  }
}