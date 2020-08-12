using System;

namespace Floats
{
    public class ExponentBit
    {
        public static void Main(string[] args)
        {
            float denominator = 1.0f; // any number not 0
            float numerator = 0.0f;

            float result = denominator / numerator;

            // 1 Exponent Bit : 0xFF, Mantissa Bit : 0X00
            Console.WriteLine($"result : {result}"); // result : Infinity

            // 2 Exponent Bit : 0xFF, Mantissa Bit : not 0X00
            float result2 = result / result; // infinity / infinity
            Console.WriteLine($"result : {result2}"); // result : NaN(Not a Number)

            // 3 Exponent Bit : 0xFF, Mantissa Bit : not 0X00
            denominator = 0.0f;
            float result3 = denominator / numerator; // 0 / 0
            Console.WriteLine($"result : {result3}"); // result : NaN(Not a Number)
        }
    }
}
