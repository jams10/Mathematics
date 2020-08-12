using System;

// 부호 있는 정수
namespace SignedInteger
{
    public class TwoComplement
    {
        public static void Main(string[] args)
        {
            // 16진수(hexadecimal)로 음의 정수 출력.
            int n1 = -1;
            Console.WriteLine($"hexadecimal number {n1} is {n1:X} in hexadecimal.\n"); // 결과 : FFFFFFFF

            // 2진수(binary)로 양의 정수 출력.
            int n2 = 8;
            string binary1 = Convert.ToString(n2, 2);
            Console.WriteLine($"decimal number {n2} is {binary1} in binary.\n");

            // 2진수(binary)로 음의 정수 출력.
            int n3 = -8;
            string binary2 = Convert.ToString(n3, 2);
            Console.WriteLine($"decimal number {n3} is {binary2}(32bit) in binary.");

            // 음의 정수 끝 4비트만 추출할 경우
            string sub_binary = binary2.Substring(28, 4);
            Console.WriteLine($"but decimal number {n3} is {sub_binary} in binary so, it is same as {n2} in binary when compare only last 4 bits.\n");

            // 부호 있는 정수 덧셈 overflow
            sbyte sb1 = 1, sb2 = 127, result = (sbyte)(sb1 + sb2); // sbyte : 부호 있는 8비트(1byte) 정수 -128 ~ 127
            Console.WriteLine($"int8 {sb1} + {sb2} = {result}");

            sb1 = -1;
            sb2 = -128;
            result = (sbyte)(sb1 + sb2);
            Console.WriteLine($"int8 {sb1} + {sb2} = {result}");

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
  -1 is 1111 1111 1111 1111 1111 1111 1111 1110(2) + 1 (2의 보수 : 1의 보수 + 1)

  result : 1111 1111 1111 1111 1111 1111 1111 1111(2) = 0xFFFFFFFF
*/

/*
  8 = 1000(2)
  -8 is 0111(2) + 0001(2) = 1000(2) 
*/
