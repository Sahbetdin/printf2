#include "test_header.h"


void test_printf_Lf()
{
	int c1, c2;
	double dl[2] = {364.8, -364.8};
	int i;


	for (i = 0; i < 2; i++)
	{
//	%%Lf |\t
	   c1 = printf("%e\n", dl[i]); c2 = ft_printf("%e\n", dl[i]);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//    c1 = printf("% e\n", dl[i]); c2 = ft_printf("% e\n", dl[i]);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//    c1 = printf("%+e\n", dl[i]); c2 = ft_printf("%+e\n", dl[i]);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	}

// 	for (i = 0; i < 2; i++)
// 	{
// 	printf("\n|----------i = %d-----------|\n", i);
// 	printf("|     TEST %%e  with sp->numb  |\n");
// 	printf("|----------LONG DOUBLE---------|\n");
// /*1*/	c1 = printf("|%2e\n", dl[i]); c2 = ft_printf("|%2e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*2*/	c1 = printf("|%6e\n", dl[i]); c2 = ft_printf("|%6e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*3*/	c1 = printf("|% 2e\n", dl[i]); c2 = ft_printf("|% 2e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*4*/	c1 = printf("|% 6e\n", dl[i]); c2 = ft_printf("|% 6e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*5*/	c1 = printf("|%+2e\n", dl[i]); c2 = ft_printf("|%+2e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*6*/	c1 = printf("|%+6e\n", dl[i]); c2 = ft_printf("|%+6e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*7*/	c1 = printf("|%-2e\n", dl[i]); c2 = ft_printf("|%-2e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*8*/	c1 = printf("|%-6e\n", dl[i]); c2 = ft_printf("|%-6e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*9*/	c1 = printf("|%02e\n", dl[i]); c2 = ft_printf("|%02e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*10*/	c1 = printf("|%06e\n", dl[i]); c2 = ft_printf("|%06e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*11*/	c1 = printf("|% 02e\n", dl[i]); c2 = ft_printf("|% 02e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// /*12*/	c1 = printf("|% 06e\n", dl[i]); c2 = ft_printf("|% 06e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	printf("----------------------\n");
// 	}

// for (i = 0; i < 2; i++)
// 	{
// 	printf("\n|-----------i = %d------------|\n", i);
// 	printf("|     TEST %%e\nwith  sp->numb  |\n");
// 	printf("|-------------------------------|\n");
// 	   c1 = printf("%8e\n", dl[i]); c2 = ft_printf("%8e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%15e\n", dl[i]); c2 = ft_printf("%15e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("% 8e\n", dl[i]); c2 = ft_printf("% 8e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("% 15e\n", dl[i]); c2 = ft_printf("% 15e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%+8e\n", dl[i]); c2 = ft_printf("%+8e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%+15e\n", dl[i]); c2 = ft_printf("%+15e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%-8e\n", dl[i]); c2 = ft_printf("%-8e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%-15e\n", dl[i]); c2 = ft_printf("%-15e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%08e\n", dl[i]); c2 = ft_printf("%08e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("%015e\n", dl[i]); c2 = ft_printf("%015e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	   c1 = printf("% 08e\n", dl[i]); c2 = ft_printf("% 08e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	      c1 = printf("% 015e\n", dl[i]); 
// 	   c2 = ft_printf("% 015e\n", dl[i]);
// 	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// 	}

	// for (i = 0; i < 2; i++)
	// {
	// printf("\n|-----------i = %d------------|\n", i);
	// printf("|      TEST %%NUMB && POINT     |\n");
	// printf("|-------------------------------|\n");
	//       c1 = printf("%.e\n", dl[i]); 
	//    c2 = ft_printf("%.e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.e\n", dl[i]); 
	//    c2 = ft_printf("%2.e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.2e\n", dl[i]); 
	//    c2 = ft_printf("%2.2e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.4e\n", dl[i]); 
	//    c2 = ft_printf("%2.4e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%2.8e\n", dl[i]); 
	//    c2 = ft_printf("%2.8e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.e\n", dl[i]); 
	//    c2 = ft_printf("%4.e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.2e\n", dl[i]); 
	//    c2 = ft_printf("%4.2e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.4e\n", dl[i]); 
	//    c2 = ft_printf("%4.4e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%4.8e\n", dl[i]); 
	//    c2 = ft_printf("%4.8e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.e\n", dl[i]); 
	//    c2 = ft_printf("%6.e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.2e\n", dl[i]); 
	//    c2 = ft_printf("%6.2e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.4e\n", dl[i]); 
	//    c2 = ft_printf("%6.4e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%6.8e\n", dl[i]); 
	//    c2 = ft_printf("%6.8e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.e\n", dl[i]); 
	//    c2 = ft_printf("%8.e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.2e\n", dl[i]); 
	//    c2 = ft_printf("%8.2e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.4e\n", dl[i]); 
	//    c2 = ft_printf("%8.4e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.6e\n", dl[i]); 
	//    c2 = ft_printf("%8.6e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	//       c1 = printf("%8.8e\n", dl[i]); 
	//    c2 = ft_printf("%8.8e\n", dl[i]);
	// printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
	// printf("\n----------------------\n");
	// }

}


int main()
{
	int c1, c2;
	int i;


	// // test_printf_Lf();
	//    c1 = printf("% 12.3Le\n", 1.0l/3120.0);
	// c2 = ft_printf("% 12.3Le\n", 1.0l/3120.0);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

	//    c1 = printf("%23.46Le\n", 1.0l/3120.0);
	// c2 = ft_printf("%23.46Le\n", 1.0l/3120.0);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

	//    c1 = printf("%.3e\n", 0.0078454);
	// c2 = ft_printf("%.3e\n", 0.0078454);	
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

	   c1 = printf("%LfA\n", 0.0l);
	c2 = ft_printf("%LfA\n", 0.0l);
	printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

//узнать, сколько n достаточно
	//    c1 = printf("%e\n", DBL_MAX);
	// c2 = ft_printf("%e\n", DBL_MAX);

	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

	//    c1 = printf("%10e\n", 1.0/0.0);
	// c2 = ft_printf("%10e\n", 1.0/0.0);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

//Lf
	//    c1 = printf("%Lf\n", -0.999999l);
	// c2 = ft_printf("%Lf\n", -0.999999l);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

	//    c1 = printf("%.5000LfAA\n", LDBL_MIN);
	// c2 = ft_printf("%.5000LfAA\n", LDBL_MIN);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);

	//    c1 = printf("%.8e\n", 0.0);
	// c2 = ft_printf("%.8e\n", 0.0);
	// printf("| c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);



	return (0);
}