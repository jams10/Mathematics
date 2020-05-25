using System;
using System.Text;

namespace UTF8
{
  public class utf8
  {
    public static string Utf16_To_Utf8(string utf16_String)
    {
      byte[] utf16_Bytes = Encoding.Unicode.GetBytes(utf16_String);
      byte[] utf8_Bytes = Encoding.Convert(Encoding.Unicode, Encoding.UTF8, utf16_Bytes);

      return Encoding.Default.GetString(utf8_Bytes);
    }
  }
}