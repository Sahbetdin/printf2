#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef unsigned long ulong;

int digits_in_base(long long value, int base);
int digits_in_base_unsigned(ulong u_value, int base);
int	ft_putnbr_positive(int n);


typedef union
{
	float f;
	struct {
		uint mantissa: 23;
		uint exponent: 8;
		uint sign: 1; 
	} parts;
} u_float;

// s has (n + 1) elements.
// where n = s[0].
// thus the cycle is: i = 1;... i <= s[0]
void	print_memory(uint *s)
{
	int i;
	char u;

	ft_putnbr_positive(s[0]);
	write(1, " ", 1);
	i = 1;
	while (i <= s[0])
	{
		u = (char )(s[i] + 48);
		write(1, &u, 1);
		i++;
		if (i % 4 == 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int print_float_whole_part(uint *s)
{
	int i;
	int count;
	char u;

	i = s[0];
	count = 0;
	while (i && s[i] == 0)
		i--;
	while (i > 0)
	{
		u = (char)s[i] + '0';
		write(1, &u, 1);
		count++;
		i--;
	}
	write(1, ".", 1);
	return (count + 1);
}

int print_float_decimal_part(uint *s, int n)
{
	unsigned char u;
	int i;

	i = 1;
	while (i <= n)
	{
		u = (unsigned char)s[i] + '0';
		write(1, &u, 1);
		i++;
	}
	return (n);
}
//allocates (n + 1) uints
//
uint *power_of_2(uint pow, int n)
{
	uint *dig;
	uint carry;
	int p;
	int i;

//	printf("n = %d\n", n);
	dig = (uint *)malloc(sizeof(int) * (n + 1));
	dig[0] = n;
	dig[1] = 1;
	i = 1;
	while (++i <= n)
		dig[i] = 0;
//	print_memory(dig);
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

//returns array int *a
//which has n digits
uint *set_whole_part(u_float *N)
{
	// uint sign;
	// uint mant;
	uint exp;
	float log2;
	// int pow_neg; //negative power of 2
	int n;
	uint *a;
	uint *b;
	uint flag;


	log2 = 0.30103;
	// sign = N->parts.sign;
	// mant = N->parts.mantissa;
	exp = N->parts.exponent - 127;
	// pow_neg = 23 - exp;
	n = log2 * exp + 6; //6 for reliability
	a = power_of_2(exp, n); //malloc used
	flag = 1 << 22;
	b = power_of_2(exp, n);
	while(exp)
	{
		divide_by_2(b);
		if (flag & N->parts.mantissa)
			add_arithmetics(a, b);
		flag = flag >> 1;
		exp--;
	}
	free(b);
	return (a);
}


int put_double_NEW(float x)
{
	u_float num;
	float log2;
	uint exp;
	int n; //number of digits. thus this amount is allocated
	uint *a; //this will be n digit for 2^exp which is max exponent
	uint *b;
	int i;
	uint flag;

	if (x < 0)
		write(1, "-", 1);
	num.f = x;
	log2 = 0.30103;
	exp = num.parts.exponent - 127;
	n = log2 * exp + 6; //6 for reliability
	a = power_of_2(exp, n); //malloc used
	flag = 1 << 22;
	b = power_of_2(exp, n);
	while(exp)
	{
		divide_by_2(b);
		if (flag & num.parts.mantissa)
			add_arithmetics(a, b);
		flag = flag >> 1;
		exp--;
	}
	print_float_whole_part(a);

	free(b);
	free(a);

//now a and b work for decimal part
	n = 23 - (num.parts.exponent - 127) + 10;
	//пото м упростим
	a = set_arithmetic_zeros(n);
	b = divide_by_minus_2(NULL, n);

	i = 0;
	while (flag)
	{
		if (flag & num.parts.mantissa)
			add_arithmetics_minus(a, b);
		divide_by_minus_2(b, n);
		flag = flag >> 1;
		i++;
	}
	print_float_decimal_part(a, n - 10);

	free(a);
	free(b);
	return (0);
}
	


int main()
{
	int n; //number of digits. thus this amount is allocated
	int i;

	put_double_NEW((double)43.4399999);
	write(1, "\n", 1);

	return (0);
}

//---------------------------------
//---------------------------------
//---------------------------------
//---------------------------------
//---------------------------------


int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int digits_in_base(long long value, int base)
{
	int i;
	i = 0;

	if (value == 0)
		return (1);
//	write(1, "HERE\n", 5);
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

int digits_in_base_unsigned(ulong u_value, int base)
{
	int i;

	i = 0;
	if (u_value == 0)
		return (1);
	while (u_value)
	{
		u_value /= base;
		i++;
	}
	return (i);
}

/*ONLY Positives and zero*/
int	ft_putnbr_positive(int n)
{
	int i;

	i = (n < 0) ? 1 : 0;
	if (n > 9)
		i += ft_putnbr_positive(n / 10);
	ft_putchar(n % 10 + '0');
	i++;
	return (i);
}


// int ft_put_(long long num, t_s *sp)
// {
// 	long long a1;

// 	if (sp->s == 'h')
// 	{
// 		if (sp->s1 == 'd' || sp->s1 == 'i')
// 			a1 = (short)num;
// 		else if (sp->s1 == 'h' && (sp->s2 == 'd' || sp->s2 == 'i'))
// 			a1 = (char)num;
// 	}
// 	else if (sp->s == 'l')
// 	{
// 		if (sp->s1 == 'd')
// 			a1 = (long)num;
// 	}
// 	else if (sp->s == 'd' || sp->s == 'i')
// 		a1 = (int)num;
// 	return (a1);
// }

