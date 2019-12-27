#include "test_header.h"


/*
adds two numbers which are in long arithmetics
each of them has n digits (or elements)
returns first one
*/
uint *add_arithmetics(uint *a, uint *b)
{
	int i;

	i = 1;
	while (i < a[0])
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		i++;
	}
	return (a);
}



uint *set_arithmetic_zeros(int n)
{
	uint *s;
	int i;

	s = (uint *)malloc(sizeof(uint) * (n + 1));
	s[0] = n;
	i = 0;
	while (++i <= n)
		s[i] = 0;
	return (s);
}

/*
ATTENTION! used for negative orders of 2
number of digits is taken from a
*/
uint *add_arithmetics_minus(uint *a, uint *b)
{
	int i;

	i = b[0];
	while (i && b[i] == 0)  // we run through b because it has more digits
		i--;
	while (i > 0)
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i - 1] += a[i] / 10;
			a[i] %= 10;
		}
		i--;
	}
	return (a);
}
