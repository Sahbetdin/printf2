#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned int uint;

typedef union
{
	float f;
	struct {
		uint mantissa: 23;
		uint exponent: 8;
		uint sign: 1; 
	} parts;
} float_cast;


int	ft_putnbr(int n)
{
	unsigned int	m;
	int i;
	char u;

	m = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	i = (n < 0) ? 1 : 0;
	if (n < 0)
		write(1, "-", 1);
	if (m > 9)
	{
		i += ft_putnbr(m / 10);
	}
	u = (char )(m % 10 + 48);
	write(1, &u, 1);
	i++;
	return (i);
}

/*works with negatives, too.*/
int digits_in_base(int value, int base)
{
	int i;

	i = 0;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

/*распечатвывает память */
void	print_arithmetic(uint *s, int n)
{
	int i;
	char u;

	ft_putnbr(s[0]);
	write(1, " ", 1);
	i = 1;
	while (i < n)
	{
		u = (char )(s[i] + 48);
		write(1, &u, 1);
		i++;
		if (i % 4 == 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

// void print_right_order(uint *s, int n)
// {
// //	нужно хранить максимально заполненный бит
// //	и update его по хожу опеоаций
// }

//function adds b > 0 to s of length n
/*we start 1st digit, because in 0th
we have the digit number
*/
uint *multiply_arithmetic(uint *s, int n, uint b)
{
	int i;
	int j;
	int dig;
	
	i = s[0];

	while (i >= 1)
	{
		s[i] *= b;
		j = i;
		while (s[j] > 9)
		{
			dig = s[j] / 10;
			s[j] -= 10 * dig;
			s[j + 1] += dig;
			j++;
		}
		i--;		
	}


	// j = i;
	// while (s[j] > 9)
	// {
	// 	dig = s[j] / 10;
	// 	s[j] -= 10 * dig;
	// 	s[j + 1] += dig;
	// 	j++;
	// }

	// while (i <= s[0])
	// {
	// 	s[i] *= b;
	// 	dig = s[i] / 10;
	// 	j = i;
	// 	while (s[j] > 9)
	// 	{
	// 		s[j] -= 10 * dig;
	// 		s[j + 1] += dig;
	// 		j++;
	// 	}
	// 	i++;
	// }
	return (s);
}

/*
we use i for determining digits number first, and
then for cycling
*/
uint *add_to_arithmetic(uint *s, int n, uint b)
{
	int i;

	i = digits_in_base((int)b, 10);
	if (i > s[0])
		s[0] = 0;
	i = 1;
	while (b)
	{
		s[i] += b % 10;
		if (s[i] > 9)
		{
			s[i] -= 10;
			s[i + 1] += 1;
		}
		b /= 10;
		i++;
	}
	return (s);
}

/*
numb is number which is set
0th number is number of digits 
*/
uint *set_arithmetic(int n, uint numb)
{
	uint *s;
	int i;

	i = digits_in_base((int)numb, 10);
	s = (uint *)malloc(sizeof(uint) * n);
	s[0] = i;
	i = 0;
	while (++i < n)
		s[i] = 0;
	i = 1;
	while (numb)
	{
		s[i] = numb % 10;
		numb /= 10;
		i++;
	}
	return (s);
}

int main(void)
{
	float numb;
	float_cast d1;
	uint mant;
	uint exp;
	uint exp_2; //2 ^ exp;
	uint sign;
	uint *s;
	int i;
	int n;
	int x;


	d1.f = 263.3;
	sign = d1.parts.sign;
	exp = d1.parts.exponent - 127;
	mant = d1.parts.mantissa;
	n = 100;
	s = set_arithmetic(n, 214748364);
	print_arithmetic(s, n);
	multiply_arithmetic(s, n, 214748364);
	print_arithmetic(s, n);
	// add_to_arithmetic(s, n, 1111111111);
	
//научиться складывать число в длинную арифметику
//научиться умножать число в длинную арифметику

	// exp_2 = (1 << 28) * 9;
	// printf("%u\n", exp_2);
	// printf("%u\n", mant);

	free(s);
	return (0);
}