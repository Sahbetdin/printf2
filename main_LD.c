#include "test_header.h"


void test_printf_Lf()
{
	int c1, c2;
	long double dl[2] = {364.8l, -364.8l};
	int i;


// 	for (i = 0; i < 2; i++)
// 	{
// //	%%Lf |\t
// 	   c1 = printf("%Lf ", dl[i]); c2 = ft_printf("%Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("% Lf ", dl[i]); c2 = ft_printf("% Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%+Lf ", dl[i]); c2 = ft_printf("%+Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	}

// 	for (i = 0; i < 2; i++)
// 	{
// 	printf("\n|----------i = %d-----------|\n", i);
// 	printf("|     TEST %%Lf with sp->numb  |\n");
// 	printf("|----------LONG DOUBLE---------|\n");
// /*1*/	c1 = printf("|%2Lf ", dl[i]); c2 = ft_printf("|%2Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*2*/	c1 = printf("|%6Lf ", dl[i]); c2 = ft_printf("|%6Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*3*/	c1 = printf("|% 2Lf ", dl[i]); c2 = ft_printf("|% 2Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*4*/	c1 = printf("|% 6Lf ", dl[i]); c2 = ft_printf("|% 6Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*5*/	c1 = printf("|%+2Lf ", dl[i]); c2 = ft_printf("|%+2Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*6*/	c1 = printf("|%+6Lf ", dl[i]); c2 = ft_printf("|%+6Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*7*/	c1 = printf("|%-2Lf ", dl[i]); c2 = ft_printf("|%-2Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*8*/	c1 = printf("|%-6Lf ", dl[i]); c2 = ft_printf("|%-6Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*9*/	c1 = printf("|%02Lf ", dl[i]); c2 = ft_printf("|%02Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*10*/	c1 = printf("|%06Lf ", dl[i]); c2 = ft_printf("|%06Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*11*/	c1 = printf("|% 02Lf ", dl[i]); c2 = ft_printf("|% 02Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*12*/	c1 = printf("|% 06Lf ", dl[i]); c2 = ft_printf("|% 06Lf ", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	printf("----------------------\n");
// 	}

// for (i = 0; i < 2; i++)
// 	{
// 	printf("\n|-----------i = %d------------|\n", i);
// 	printf("|     TEST %%Lf with  sp->numb  |\n");
// 	printf("|-------------------------------|\n");
// 	   c1 = printf("%8Lf \n", dl[i]); c2 = ft_printf("%8Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%15Lf \n", dl[i]); c2 = ft_printf("%15Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("% 8Lf \n", dl[i]); c2 = ft_printf("% 8Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("% 15Lf \n", dl[i]); c2 = ft_printf("% 15Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%+8Lf \n", dl[i]); c2 = ft_printf("%+8Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%+15Lf \n", dl[i]); c2 = ft_printf("%+15Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%-8Lf \n", dl[i]); c2 = ft_printf("%-8Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%-15Lf \n", dl[i]); c2 = ft_printf("%-15Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%08Lf \n", dl[i]); c2 = ft_printf("%08Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%015Lf \n", dl[i]); c2 = ft_printf("%015Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("% 08Lf \n", dl[i]); c2 = ft_printf("% 08Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	      c1 = printf("% 015Lf \n", dl[i]); 
// 	   c2 = ft_printf("% 015Lf \n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	}

	// for (i = 0; i < 2; i++)
	// {
	// printf("\n|-----------i = %d------------|\n", i);
	// printf("|      TEST %%NUMB && POINT     |\n");
	// printf("|-------------------------------|\n");
	//       c1 = printf("%.Lf\n", dl[i]); 
	//    c2 = ft_printf("%.Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.Lf\n", dl[i]); 
	//    c2 = ft_printf("%2.Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.2Lf\n", dl[i]); 
	//    c2 = ft_printf("%2.2Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.4Lf\n", dl[i]); 
	//    c2 = ft_printf("%2.4Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.8Lf\n", dl[i]); 
	//    c2 = ft_printf("%2.8Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.Lf\n", dl[i]); 
	//    c2 = ft_printf("%4.Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.2Lf\n", dl[i]); 
	//    c2 = ft_printf("%4.2Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.4Lf\n", dl[i]); 
	//    c2 = ft_printf("%4.4Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.8Lf\n", dl[i]); 
	//    c2 = ft_printf("%4.8Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.Lf\n", dl[i]); 
	//    c2 = ft_printf("%6.Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.2Lf\n", dl[i]); 
	//    c2 = ft_printf("%6.2Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.4Lf\n", dl[i]); 
	//    c2 = ft_printf("%6.4Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.8Lf\n", dl[i]); 
	//    c2 = ft_printf("%6.8Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.Lf\n", dl[i]); 
	//    c2 = ft_printf("%8.Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.2Lf\n", dl[i]); 
	//    c2 = ft_printf("%8.2Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.4Lf\n", dl[i]); 
	//    c2 = ft_printf("%8.4Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.6Lf\n", dl[i]); 
	//    c2 = ft_printf("%8.6Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.8Lf\n", dl[i]); 
	//    c2 = ft_printf("%8.8Lf\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	// printf("\n----------------------\n");
	// }

}


int main()
{
	int c1, c2;
	int i;
	long double dl[2] = {364.8l, -364.8l};

	i = 0;
	test_printf_Lf();
	//    c1 = printf("% 02Lf\n", dl[i]);
	// c2 = ft_printf("% 02Lf\n", dl[i]);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	return (0);
}