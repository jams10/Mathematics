using System;

namespace DegreeOfPrecision
{
  public class Precision
  {
    public static void PrecisionSix 
    {
      float n = 123.456f;
      Console.WriteLine($"{n}");
      
      float n2 = 123.4567f;
      Console.WriteLine($"{n2}");
      
      float n3 = 123.45678f;
      Console.WriteLine($"{n3}");
      
      float n4 = 123.456789f;
      Console.WriteLine($"{n4}");
      
      float n5 = 123.4567891f;
      Console.WriteLine($"{n5}");
      
      float n6 = 123456146689170f; 
      Console.WriteLine($"{n6}"); // result is 1.234562E+14
    }
  }
}