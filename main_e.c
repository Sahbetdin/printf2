#include "test_header.h"


void test_printf_d()
{
	int c1, c2;
	double a[5] = {3648.987656734853121, -3648.987656734853121, 0.000002342, -0.000002342, 0.0};
	int i;


	printf("\n|-----------i = %d------------|\n", i);
	printf("|            TEST %%e           |\n");
	printf("|-------------------------------|\n");
	for (i = 0; i < 5; i++)
	{
	   c1 = printf("%e ", a[i]); c2 = ft_printf("%e ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	}


	printf("\n|-----------i = %d------------|\n", i);
	printf("|            TEST %%.e           |\n");
	printf("|-------------------------------|\n");
	for (i = 0; i < 5; i++)
	{
	   c1 = printf("%.8e ", a[i]); c2 = ft_printf("%.8e ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	}

}


int main()
{
    char *tmp;
    int c1;
    int c2;
    uint p;
    int a;
    int i;

   // p = 1110000;
//"%5d",0
//"%10xAA\n", 42
//"%#8xAA\n", 42
 

    p = 0;
	a = 0;
	if (p == 0)
		test_printf_d();
	else
	{
    	   c1 = printf("%xA\n", -42); 
		c2 = ft_printf("%xA\n", -42);
    	



		printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	}

	//c1 = digits_in_base_unsigned(4294967296, 16);

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