using System;

namespace SignedInteger
{
  public class TwoComplement
  {
    /*
      Print number by hexadecimal.
    */
    public static void ExpressNegativeIntger()
    {
      int n = -1;
      Console.WriteLine($"{n:X}"); // result is FFFFFFFF
    }
    /*
      Print number by binary.
    */
    public static void PositiveSignedInteger()
    {
      int n = 8;
      string binary = Convert.ToString(n, 2);
      Console.WriteLine($"decimal number {n} is {binary} in binary.");
    }
    public static void NegativeSignedInteger()
    {
      int n = -8;
      string binary = Convert.ToString(n, 2);

      int length = 31 - 28 + 1;
      string result_binary = binary.Substring(28, length);
      Console.WriteLine($"decimal number {n} is {result_binary} in binary.");
    }
    /*
      Signed integer overflow example
    */
    public static void SignedIntegerAdditionOverflow()
    {
      sbyte n1 = 1;
      sbyte n2 = 127;
      sbyte result1 = (sbyte)(n1 + n2);
      Console.WriteLine($"int8 {n1} + {n2} = {result1}");

      sbyte n3 = -1;
      sbyte n4 = -128;
      sbyte result2 = (sbyte)(n3 + n4);
      Console.WriteLine($"int8 {n3} + {n4} = {result2}");
    }
  }
}

/*
  Hexadecimal print example from MS.

  https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/types/how-to-convert-between-hexadecimal-strings-and-numeric-types
*/

/*
  int is 4 byte in C#.
  4 byte = 32 bit
  0000 0000 0000 0000 0000 0000 0000 0000(2)

  So, decimal number 1 is 0000 0000 0000 0000 0000 0000 0000 0001(2)
  -1 is 1111 1111 1111 1111 1111 1111 1111 1110(2) + 1

  result : 1111 1111 1111 1111 1111 1111 1111 1111(2) = 0xFFFFFFFF
*/

/*
  8 = 1000(2)
  -8 is 0111(2) + 0001(2) = 1000(2) 
*/
