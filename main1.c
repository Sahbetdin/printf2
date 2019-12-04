#include "test_header.h"

/*
make scientific notation
double enters and exponent and mantissa outputs. 
*/

#include "float.h"


int	main()
{
	int c1, c2;
	double a;
	int d;
	char *s;

	a = 0.95426;
	long double max = LDBL_MAX;
	   c1 = printf("%LfA\n", max);
	c2 = ft_printf("%fA\n", max);

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

