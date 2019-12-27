#include "test_header.h"


//allocates (n + 1) uints
uint *power_of_2(uint pow, int n)
{
	uint *dig;
	uint carry;
	int p;
	int i;

	// printf("n = %d\n", n);
	if (!(dig = (uint *)malloc(sizeof(uint) * (n + 1))))
		return (NULL);
	dig[0] = n;
	dig[1] = 1;
	i = 1;
	while (++i <= n)
		dig[i] = 0;
//	print_memory(dig);
	// write(1, "HERE\n", 5);
	p = 0;
	while (p < pow)
	{
		carry = 0;
		i = 1;
		while (i <= n)
		{
			carry = carry + dig[i] * 2;
			dig[i] = carry % 10;
			carry /= 10;
			i++;
		}
		p++;
	}
	return (dig);
}

//takes *s and divides by 2.
//returns the same array.
//make function skip_zeros
uint *divide_by_2(uint *s)
{
	int i;
	int carry;

	i = s[0];
	while (i && s[i] == 0)
		i--;
	while (i > 0)
	{
		if (s[i] >= 2)
		{
			carry = s[i] % 2;
			s[i] /= 2;
			if (carry != 0)
			{
				s[i - 1] = s[i - 1] + carry * 10;
				carry = 0;
			}
		}
		else
		{
			s[i - 1] = s[i - 1] + 10 * s[i];
			s[i] = 0;
		}
		i--;
	}
	return (s);
}

uint *divide_by_minus_2(uint *s, int n)
{
	int i;
	char u;

	i = 1;
	if (!s)
	{
		// write(1, "k\n", 2);
		s = (uint *)malloc(sizeof(int) * (n + 1));
		s[0] = n;
		s[1] = 5;
		while (++i <= n)
			s[i] = 0;
	}
	else
	{
		// write(1, "H\n", 2);
		while (i <= s[0])
		{
			if (s[i] % 2 == 1)
				s[i + 1] += 10;
			s[i] /= 2;
			i++;
		}
	}
	return (s);
}
