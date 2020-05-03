using System;

namespace UnsignedInteger
{
  public class AdditionOverflow
  {
    public static void run() // static method. 
    {
      byte n1 = 255; // unsigned 8 bit integer 0xFF
      byte n2 = 1; // unsigned 8 bit integer 0x0
      byte result = (byte)(n1 + n2);
      Console.WriteLine(result); // result is '0'. Overflow
    }
  }
}

// C++    C#
// int8   sbyte
// uint8  byte

// Static method does not create object and call directly.
// ex) AdditionOverflow.run();