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
////1
	// printf("\033[0;32m o \033[0m\n");
	//    c1 = printf("%o\n", 0);
	// c2 = ft_printf("%o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m 4o \033[0m\n");
	//    c1 = printf("%4o\n", 0);
	// c2 = ft_printf("%4o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #o \033[0m\n");
	//    c1 = printf("%#o\n", 0);
	// c2 = ft_printf("%#o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #4o \033[0m\n");
	//    c1 = printf("%#4o\n", 0);
	// c2 = ft_printf("%#4o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);
///////2
	// printf("\033[0;32m .o \033[0m\n");
	//    c1 = printf("%.o\n", 0);
	// c2 = ft_printf("%.o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m .5o \033[0m\n");
	//    c1 = printf("%.5o\n", 0);
	// c2 = ft_printf("%.5o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #.o \033[0m\n");
	//    c1 = printf("%#.o\n", 0);
	// c2 = ft_printf("%#.o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #.5o \033[0m\n");
	//    c1 = printf("%#.5o\n", 0);
	// c2 = ft_printf("%#.5o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);
//////////////3
	// printf("\033[0;32m 3.o \033[0m\n");
	//    c1 = printf("%3.o\n", 0);
	// c2 = ft_printf("%3.o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m 3.5o \033[0m\n");
	//    c1 = printf("%3.5o\n", 0);
	// c2 = ft_printf("%3.5o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m 5.3o \033[0m\n");
	//    c1 = printf("%5.3o\n", 0);
	// c2 = ft_printf("%5.3o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #3.o \033[0m\n");
	//    c1 = printf("%#3.o\n", 0);
	// c2 = ft_printf("%#3.o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

///////4
	// printf("\033[0;32m #3.5o \033[0m\n");
	//    c1 = printf("%#3.5o\n", 0);
	// c2 = ft_printf("%#3.5o\n", 0);	
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m #5.3o \033[0m\n");
	//    c1 = printf("%#5.3o\n", 0);
	// c2 = ft_printf("%#5.3o\n", 0);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);


////5
	// printf("\033[0;32m \"#7o, 50\" \033[0m\n");
	//    c1 = printf("%#7o\n", 50);
	// c2 = ft_printf("%#7o\n", 50);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m \"#7.4o, 50\" \033[0m\n");
	//    c1 = printf("%#7.4o\n", 50);
	// c2 = ft_printf("%#7.4o\n", 50);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m \"#3.7o, 50\" \033[0m\n");
	//    c1 = printf("%#3.7o\n", 50);
	// c2 = ft_printf("%#3.7o\n", 50);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m \"3.7o, 50\" \033[0m\n");
	//    c1 = printf("%3.7o\n", 50);
	// c2 = ft_printf("%3.7o\n", 50);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);


//// 6
	// printf("\033[0;32m \"#-3.7o, 50\" \033[0m\n");
	//    c1 = printf("%#-3.7o\n", 50);
	// c2 = ft_printf("%#-3.7o\n", 50);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m \"-3.7o, 50\" \033[0m\n");
	//    c1 = printf("%-3.7o\n", 50);
	// c2 = ft_printf("%-3.7o\n", 50);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m \"-3o, 50\" \033[0m\n");
	//    c1 = printf("%-3oA\n", 50);
	// c2 = ft_printf("%-3oA\n", 50);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);

	// printf("\033[0;32m \"%%-5.10o\", 2500 \033[0m\n");
	//    c1 = printf("%-5.10oA\n", 2500);
	// c2 = ft_printf("%-5.10oA\n", 2500);
	// printf("| c1 = %d, c2 = %d; ", c1, c2);
	// put_diff(c1 - c2);





	return (0);
}