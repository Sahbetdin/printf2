#include "test_header.h"

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


// int	ft_putnbr(int n)
// {
// 	unsigned int	m;
// 	int i;
// 	char u;

// 	m = (n < 0) ? (unsigned int)-n : (unsigned int)n;
// 	i = (n < 0) ? 1 : 0;
// 	if (n < 0)
// 		write(1, "-", 1);
// 	if (m > 9)
// 	{
// 		i += ft_putnbr(m / 10);
// 	}
// 	u = (char )(m % 10 + 48);
// 	write(1, &u, 1);
// 	i++;
// 	return (i);
// }

/*works with negatives, too.*/
// int digits_in_base(int value, int base)
// {
// 	int i;

// 	i = 0;
// 	while (value)
// 	{
// 		value /= base;
// 		i++;
// 	}
// 	return (i);
// }

/*распечатывает память */
//void	print_arithmetic(uint *s, int n)
void	print_memory(uint *s, int n)
{
	int i;
	char u;

//	ft_putnbr(s[0]);
//	write(1, " ", 1);
	i = 0;
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


void print_binary_uint(uint num)
{
	uint flag;

	flag = 1 << 22;
	while (flag)
	{
		if (flag & num)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		flag = flag >> 1;
	}
	write(1, "\n", 1);
}

/*used for displaying all 'float'
flag == 0 -> whole part + float-pont. Here n is number of all digits.
flag == 1 -> decimal part. Here n is number if digits to display.
*/
void print_float(uint *s, int n, int flag)
{
	int i;
	char u;

	if (flag == 0)
	{
		i = n - 1;
		while (i && s[i] == 0)
			i--;
		while (i >= 0)
		{
			u = (char)s[i] + '0';
			write(1, &u, 1);
			i--;
		}
		write(1, ".", 1);
	}
	else if (flag == 1)
	{
		i = 0;
		while (i < n)
		{
			u = (char)s[i] + '0';
			write(1, &u, 1);
			i++;
		}
	}
}

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
adds two numbers which are in long arithmetics 
*/
uint *add_arithmetics(uint *a, uint *b, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i] -= 10;
			a[i + 1] += 1;
		}
		i++;
	}
	return (a);
}

/*
ATTENTION!
used for negative orders of 2
*/
uint *add_arithmetics_minus(uint *a, uint *b, int n)
{
	int i;

	i = n - 1;
	while (i && b[i] == 0)  // we run through b because it has more digits
		i--;
	while (i >= 0)
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i] -= 10;
			a[i - 1] += 1;
		}
		i--;
	}
	return (a);
}

/*
numb is number which is set
0th number is number of digits 
*/
// uint *set_arithmetic(int n, uint numb)
// {
// 	uint *s;
// 	int i;

// 	i = digits_in_base((int)numb, 10);
// 	s = (uint *)malloc(sizeof(uint) * n);
// 	s[0] = i;
// 	i = 0;
// 	while (++i < n)
// 		s[i] = 0;
// 	i = 1;
// 	while (numb)
// 	{
// 		s[i] = numb % 10;
// 		numb /= 10;
// 		i++;
// 	}
// 	return (s);
// }


/*ATTENTION!
0th is NOT the digit amount*/
uint *set_arithmetic_zeros(int n)
{
	uint *s;
	int i;

	s = (uint *)malloc(sizeof(uint) * n);
	i = -1;
	while (++i < n)
		s[i] = 0;
	return (s);
}

uint *power_of_2(uint v, int n)
{
    uint *dig;
	uint carry;
	int p;
	int i;

	dig = (uint *)malloc(sizeof(int) * n);
    i = 0;
	dig[i] = 1;
    while (++i < n)
		dig[i] = 0;
    p = 0;
    while (p < v)
    {
        carry = 0;
        i = 0;
        while (i < n)
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

uint *divide_by_2(uint *s, int n)
{
	int i;
	int carry;

	i = n - 1;
	while (i && s[i] == 0)
		i--;
	while (i > -1)
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

	i = 0;
	if (!s)
	{
		s = (uint *)malloc(sizeof(int) * n);
		s[0] = 5;
		while (++i < n)
			s[i] = 0;
//		printf("%u\n", s[1]);
		
	}
	else
	{
		while (i < n)
		{
			if (s[i] % 2 == 1)
				s[i + 1] += 10;
			s[i] /= 2;
			i++;
		}
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
	uint *a;
	uint *b;
	uint tmp;
	int i;
	int n;
	int x;
	uint flag;

//поработать с этим!!!
	d1.f = 0.201268;
	sign = d1.parts.sign;
	exp = d1.parts.exponent - 127;
	mant = d1.parts.mantissa;
	n = 100;


	ft_putnbr(exp);
	write(1, "\n", 1);
	flag = 1 << 22;
	if (d1.f >= 1)
	{
		a = power_of_2(exp, n);
		b = power_of_2(exp, n);

		
		while (exp) //exp shows "digits" before float-point
		{
			divide_by_2(b, n);
			if (flag & mant)
				add_arithmetics(a, b, n);
			flag = flag >> 1;
			exp--;
		}
		print_float(a, n, 0);
		free(a);
		free(b);
	}
	else
		write(1, "0.", 2);

	a = set_arithmetic_zeros(n);
	s = divide_by_minus_2(NULL, n);
	i = 0;
	while (flag)
	{
		if (flag & mant)
			add_arithmetics_minus(a, s, n);
		divide_by_minus_2(s, n);
		flag = flag >> 1;
		i++;
	}
	print_float(a, i, 1);


	// while (flag) // now we need to finish flag
	// {
	// 	if (flag & mant)
	// 		add_arithmetics(a, s, n);
	// 	s = divide_by_minus_2(s, n);
	// 	flag = flag >> 1;
	// }
//		divide_by_minus_2(s, n);



//print_binary_uint(mant);
	


	return (0);
}