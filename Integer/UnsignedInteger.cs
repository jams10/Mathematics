using System;
using System.Runtime.Intrinsics.X86;

namespace UnsignedInteger
{
    public class AdditionOverflow
    {
        /*
          The value range of unsigned 8 bit intger is 0 ~ 255.

          C++    C#
          int8   sbyte
          uint8  byte
        */
        public static void Main(string[] args)
        {
            byte n1 = 255; // 2진수 : 1111 1111 / 16진수 : 0xFF
            byte n2 = 1;   // 2진수 : 0000 0001 / 16진수 : 0x01 
            byte result = (byte)(n1 + n2);
            Console.WriteLine($"uint8(byte in C#) : {n1} + {n2} = {result}\n"); // result : 0 -> OVERFLOW!!

            n1 = 255;
            n2 = 1;
            byte n3 = 9;

            result = (byte)(n1 + n2 + n3);
            Console.WriteLine($"unit8(byte in C#) : {n1} + {n2} + {n3} = {result}\n"); // result : 9

            n1 = 255;
            n2 = 10;

            Console.WriteLine($"uint8(byte in C#) : {n1} + {n2} = {(byte)(n1 + n2)}");
        }
    }
}

