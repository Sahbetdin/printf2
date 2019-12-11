#include "test_header.h"





int main()
{
    char *tmp;
    int c1;
    int c2;
    uint p;

   // p = 1110000;
    p = 0;
//"%5d",0
//"%10xAA\n", 42
//"%#8xAA\n", 42

  	 c1 = printf("%#6oA\n", 2500);
  c2 = ft_printf("%#6oA\n", 2500);

 //  printf("c1 = %d", c1);
  printf("c1 = %d, c2 = %d", c1, c2);

//    printf("%7.-1f", 5.5657842);
//    printf("%  0 9.3f", 56.54562);
//    printf("%               0.50%");

  //  tmp = ft_strchr("diuoxXfFeEgGaAcspn%", 'd');
 
    return (0);
}