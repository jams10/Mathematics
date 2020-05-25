using System;
using Unsigned_Integer;
using Signed_Integer;
using UTF8;

class MainClass {
  public static void Main (string[] args) {
    Addition_Overflow.test1();
    Addition_Overflow.test2();
    Addition_Overflow.test3();
    
    Two_Complement.Express_Negative_Intger();
    Two_Complement.Negative_Signed_Integer();
    Two_Complement.Signed_Integer_Addition_Overflow();

    Console.WriteLine(utf8.Utf16_To_Utf8("한글"));
  }
}