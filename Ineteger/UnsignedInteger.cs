using System;

namespace UnsignedInteger
{
  public class AdditionOverflow
  {
    /*
      The value range of unsigned 8 bit intger is 0 ~ 255.
    */
    public static void test1() // static method. 
    {
      byte n1 = 255; // unsigned 8 bit integer 0xFF
      byte n2 = 1; // unsigned 8 bit integer 0x0
      byte result = (byte)(n1 + n2);
      Console.WriteLine($"unit8 {n1} + {n2} = {result}"); 
      // result is '0'. Overflow
    }
    /*
      Test 1 and Test 2 have same result.
    */
    public static void test2()
    {
      byte n1 = 255;
      byte n2 = 1;
      byte n3 = 9;
      byte result = (byte)(n1 + n2 + n3);
      Console.WriteLine($"uint8 {n1} + {n2} + {n3} = {result}");
    }
    public static void test3()
    {
      byte n1 = 255;
      byte n2 = 10;
      Console.WriteLine($"unit8 {n1} + {n2} = {(byte)(n1 + n2)}");
    }
  }
}

// C++    C#
// int8   sbyte
// uint8  byte

// Static method does not create object and call directly.
// ex) AdditionOverflow.test1();