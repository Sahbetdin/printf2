#include "test_header.h"

void put_diff(int diff)
{
	if (diff == 0)
		printf("diff = %d\n", diff);
	else
		printf("\033[0;35mdiff = %d\033[0m\n", diff);
}

int main()
{
	int c1, c2;
	int i;

	// printf("\033[0;32m x \033[0m\n");
	//    c1 = printf("%x\n", 0);
	// c2 = ft_printf("%x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	printf("\033[0;32m 4x \033[0m\n");
	   c1 = printf("%4x\n", 0);
	c2 = ft_printf("%4x\n", 0);	
	printf("| c1 = %d, c2 = %d; ", c1, c2);
	put_diff(c1 - c2);

	// printf("\033[0;32m #x \033[0m\n");
	//    c1 = printf("%#x\n", 0);
	// c2 = ft_printf("%#x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);


	printf("\033[0;32m #4x \033[0m\n");
	   c1 = printf("%#4x\n", 0);
	c2 = ft_printf("%#4x\n", 0);	
	printf("| c1 = %d, c2 = %d; ", c1, c2);
	put_diff(c1 - c2);

	// printf("\033[0;32m .x \033[0m\n");
	//    c1 = printf("%.x\n", 0);
	// c2 = ft_printf("%.x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m .5x \033[0m\n");
	//    c1 = printf("%.5x\n", 0);
	// c2 = ft_printf("%.5x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m .x \033[0m\n");
	//    c1 = printf("%#.1x\n", 0);
	// c2 = ft_printf("%#.1x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m .5x \033[0m\n");
	//    c1 = printf("%#.5x\n", 0);
	// c2 = ft_printf("%#.5x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m 3.x \033[0m\n");
	//    c1 = printf("%3.x\n", 0);
	// c2 = ft_printf("%3.x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m 3.5x \033[0m\n");
	//    c1 = printf("%3.5x\n", 0);
	// c2 = ft_printf("%3.5x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m 5.3x \033[0m\n");
	//    c1 = printf("%5.3x\n", 0);
	// c2 = ft_printf("%5.3x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #3.x \033[0m\n");
	//    c1 = printf("%#3.x\n", 0);
	// c2 = ft_printf("%#3.x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #3.5x \033[0m\n");
	//    c1 = printf("%#3.5x\n", 0);
	// c2 = ft_printf("%#3.5x\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #5.3x \033[0m\n");
	//    c1 = printf("%#5.3x\n", 0);
	// c2 = ft_printf("%#5.3x\n", 0);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);


	return (0);
}