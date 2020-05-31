/* This code is not written by me. */

/*
<Reference>
code by Nishtha Thakur

https://www.tutorialspoint.com/how-do-i-convert-between-big-endian-and-little-endian-values-in-cplusplus
*/

#include <iostream>
#define SWAP_INT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24)) 
using namespace std;

void memory_represent(char *value, int n) {
   int i;
   for (i = 0; i < n; i++)
      printf(" %.2x", value[i]);
}
int main() {
   unsigned int x = 0x76543210;
   int y;
   cout << "The little endian value is: ";
   memory_represent((char*)&x, sizeof(x)); // (char*)&x의 경우 정수 x의 주소값을 가리킴.
   cout << endl;
   y = SWAP_INT32(x);
   cout << "The Big endian value after conversion is: ";
   memory_represent((char*)&y, sizeof(y));
   cout << endl;
}


/*
<Reference>

https://kldp.org/node/44712

*/

#include <stdio.h>
 
int main() 
{ 
     int i = 0x00000001; 
     if( ((char *)&i)[0] ) 
         printf( "Littile Endian\n" ); 
     else 
         printf( "Big Endian\n" ); 

     return 1;
}

int *형(int의 주소) -> char * 형으로 바꿔 참조한다는 것 -> char 형으로 바꾼다는 것

char 형(1바이트)로 바꾼다는 것 -> int(4바이트)를 4토막으로 나누는 것

Little Endian : 0x (01) 00 00 00

이므로 1이 되어 참입니다.

Big Endian이면 0x (00) 00 00 00

이므로 0으로 거짓입니다.

char *로 참조하는 이유 :
char 로 하면 무조건 Little Endian으로 나올겁니다.
왜냐면 윗부분을 잘라내기 때문이죠.
0x (00 00 00) 01
괄호 친 부분을 없애버리고 0x01 만 남겨서
무조건 참으로 만들어 버립니다..
