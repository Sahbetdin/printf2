#include "test_header.h"





int main()
{
    char *tmp;
    int c1;
    int c2;
    uint p;
    int a;

   // p = 1110000;
    p = 0;
//"%5d",0
//"%10xAA\n", 42
//"%#8xAA\n", 42

  a =  2147483647;

//  a = 83648;
  
 	   c1 = printf("%#llx", 9223372036854775807);
  c2 = ft_printf("%6d\n", a);
  printf("c1 = %d, c2 = %d\n", c1, c2);
  // printf("char is %ld byte\n", sizeof(char));
  // printf("short is %ld byte\n", sizeof(short));
  // printf("uint is %ld byte\n", sizeof(uint));
  // printf("long is %ld byte\n", sizeof(long));
  // printf("long long is %ld byte\n", sizeof(long long));
  // printf("long long int is %ld byte\n", sizeof(long long int));

//    printf("%7.-1f", 5.5657842);
//    printf("%  0 9.3f", 56.54562);
//    printf("%               0.50%");

  //  tmp = ft_strchr("diuoxXfFeEgGaAcspn%", 'd');
 
    return (0);
}