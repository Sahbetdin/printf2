#include "test_header.h"


void test_printf_d()
{
	int c1, c2;
	int a[3] = {3648, -3648, 0};
	int b[2] = {-2147483648, 2147483647};
	int i;


	for (i = 0; i < 3; i++)
	{
	printf("\n|-----------i = %d------------|\n", i);
	printf("|    TEST %%d, %% d, %%+d     |\n");
	printf("|-------4 digit number--------|\n");
//	%%d |\t
	   c1 = printf("%d ", a[i]); c2 = ft_printf("%d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("% d ", a[i]); c2 = ft_printf("% d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%+d ", a[i]); c2 = ft_printf("%+d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	}

	for (i = 0; i < 3; i++)
	{
	printf("\n|-----------i = %d------------|\n", i);
	printf("|     TEST %%d with sp->numb  |\n");
	printf("|-------4 digit number--------|\n");
/*1*/	c1 = printf("%2d ", a[i]); c2 = ft_printf("%2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*2*/	c1 = printf("%6d ", a[i]); c2 = ft_printf("%6d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*3*/	c1 = printf("% 2d ", a[i]); c2 = ft_printf("% 2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*4*/	c1 = printf("% 6d ", a[i]); c2 = ft_printf("% 6d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*5*/	c1 = printf("%+2d ", a[i]); c2 = ft_printf("%+2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*6*/	c1 = printf("%+6d ", a[i]); c2 = ft_printf("%+6d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*7*/	c1 = printf("%-2d ", a[i]); c2 = ft_printf("%-2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*8*/	c1 = printf("%-6d ", a[i]); c2 = ft_printf("%-6d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*9*/	c1 = printf("%02d ", a[i]); c2 = ft_printf("%02d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*10*/	c1 = printf("%06d ", a[i]); c2 = ft_printf("%06d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*11*/	c1 = printf("% 02d ", a[i]); c2 = ft_printf("% 02d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
/*12*/	c1 = printf("% 06d ", a[i]); c2 = ft_printf("% 06d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	printf("----------------------\n");
	}

for (i = 0; i < 3; i++)
	{
	printf("\n|-----------i = %d------------|\n", i);
	printf("|     TEST %%d with sp->numb  |\n");
	printf("|-------MIN_INT, MAX_INT------|\n");
	   c1 = printf("%8d ", b[i]); c2 = ft_printf("%8d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%15d ", b[i]); c2 = ft_printf("%15d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("% 8d ", b[i]); c2 = ft_printf("% 8d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("% 15d ", b[i]); c2 = ft_printf("% 15d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%+8d ", b[i]); c2 = ft_printf("%+8d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%+15d ", b[i]); c2 = ft_printf("%+15d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%-8d ", b[i]); c2 = ft_printf("%-8d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%-15d ", b[i]); c2 = ft_printf("%-15d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%08d ", b[i]); c2 = ft_printf("%08d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("%015d ", b[i]); c2 = ft_printf("%015d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("% 08d ", b[i]); c2 = ft_printf("% 08d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	   c1 = printf("% 015d ", b[i]); c2 = ft_printf("% 015d ", b[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	}

	for (i = 0; i < 3; i++)
	{
	printf("\n|-----------i = %d------------|\n", i);
	printf("|      TEST %%NUMB && POINT     |\n");
	printf("|-------4 digit number--------|\n");
	      c1 = printf("%%.d  | %.d ", a[i]); 
	   c2 = ft_printf("%.d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%2.d ", a[i]); 
	   c2 = ft_printf("%2.d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%2.2d ", a[i]); 
	   c2 = ft_printf("%2.2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%2.4d ", a[i]); 
	   c2 = ft_printf("%2.4d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%2.8d ", a[i]); 
	   c2 = ft_printf("%2.8d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%4.d ", a[i]); 
	   c2 = ft_printf("%4.d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%4.2d ", a[i]); 
	   c2 = ft_printf("%4.2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%4.4d ", a[i]); 
	   c2 = ft_printf("%4.4d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%4.8d ", a[i]); 
	   c2 = ft_printf("%4.8d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%6.d ", a[i]); 
	   c2 = ft_printf("%6.d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%6.2d ", a[i]); 
	   c2 = ft_printf("%6.2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%6.4d ", a[i]); 
	   c2 = ft_printf("%6.4d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%6.8d ", a[i]); 
	   c2 = ft_printf("%6.8d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%8.d ", a[i]); 
	   c2 = ft_printf("%8.d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%8.2d ", a[i]); 
	   c2 = ft_printf("%8.2d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%8.4d ", a[i]); 
	   c2 = ft_printf("%8.4d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%8.6d ", a[i]); 
	   c2 = ft_printf("%8.6d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	      c1 = printf("%8.8d ", a[i]); 
	   c2 = ft_printf("%8.8d ", a[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	printf("----------------------\n");
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
	a = 2147;
	if (p == 0)
		test_printf_d();
	else
	{
    	   c1 = printf("%2d\n", a); 
		c2 = ft_printf("%2d\n", a);
		printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	}

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