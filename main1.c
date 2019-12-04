#include "test_header.h"

/*
make scientific notation
double enters and exponent and mantissa outputs. 
*/




int	main()
{
	int c1, c2;
	double a;
	int d;
	char *s;

	a = 134300e-300;
	   c1 = printf("%5.5eA\n", a);
	c2 = ft_printf("%5.3eA\n", a);

//	printf("c1 = %d, c2 = %d", c1, c2);

	// c1 = ft_putnbr(-2147483648);
	// printf("int digits = %d", c1);
	// c1 = printf("%s\n", "goodie");
	// c2 = ft_printf("%s\n", "goodie");

//	clear_spec(ttt);
//	ttt->specif = '1';
//	printf("\n\norig: %d, my: %d\n", c1, c2);
	return (0);
}

