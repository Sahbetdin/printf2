#include "test_header.h"

t_long *create_DLNG_whole_pre(void)
{
	t_long *lng2;

	lng2 = (t_long *)malloc(sizeof(t_long));
	lng2->flag = 1UL << 62;
	lng2->whole = NULL;
	return (lng2);
}

uint *ft_temp_b_DLNG(uint exp, int n)
{
	uint *b;

	if (exp >= 16383)
	{
		exp = exp - 16383;
		b = power_of_2(exp, n); //malloc used

	}
	else
	{
		exp = 16383 - exp;
		b = divide_by_minus_2(NULL, n);
		while (exp > 1)
		{
			divide_by_minus_2(b, n);
			exp--;
		}
	}
	return (b);
}


void	create_DLNG_whole(t_long *lng2, u_long_dbl *num_DBL, uint *b)
{
	int exp;
	int n;

	if (num_DBL->parts.exponent >= 16383)
	{
		exp = num_DBL->parts.exponent - 16383;
		n = exp * 0.30103 + 4;
		b = ft_temp_b_DLNG(num_DBL->parts.exponent, n);
		lng2->whole = power_of_2(exp, n); //malloc used
		while (exp > 0)
		{
			divide_by_2(b);
			if (lng2->flag & num_DBL->parts.mantissa)
				add_arithmetics(lng2->whole, b);
			lng2->flag = lng2->flag >> 1;
			exp--;
		}
		free(b);
	}
	else
	{
		if (!(lng2->whole = (uint *)malloc(sizeof(uint) * 2)))
			return ;
		lng2->whole[0] = 1;
		lng2->whole[1] = 0;
	}
}



/*
void	create_DLNG_decimal(t_long *lng2, u_long_dbl *num_DBL, uint *b)
{
	int n;


	if (num_DBL->parts.exponent < 16383)
	{
		n = (16383 - num_DBL->parts.exponent) * 0.30103 + 70;
		b = divide_by_minus_2(NULL, n);
	}
	else
		n = (num_DBL->parts.exponent - 16383) * 0.30103 + 4;
print_memory(b);
	lng2->decimal = set_arithmetic_zeros(n);
	// ft_putnbr_positive(n);
	// write(1, "~~~~~~~~~\n", 10);
	// print_memory(b);
	// print_binary_ulong(num_DBL->parts.mantissa);
	// print_binary_ulong(lng2->flag);
	if (num_DBL->parts.exponent < 16383)
	{
		add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
	}
print_memory(b);
	// print_binary_uint(num_DBL->parts.sign);
	// print_binary_uint(num_DBL->parts.exponent);
	// print_binary_uint(num_DBL->parts.mantissa);

	// write(1, "~~~~~~~~~\n", 10);
	while (lng2->flag)
	{	
		if (lng2->flag & num_DBL->parts.mantissa)
			add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
		lng2->flag = lng2->flag >> 1;
	}
	free(b);
	b = NULL;
	print_memory(lng2->decimal); ???????
	// write(1, "~~~~~~~~~\n", 10);
	// print_memory(lng2->decimal);
}
*/
?????
void	create_DLNG_decimal(t_long *lng2, u_long_dbl *num_DBL, uint *b)
{
	int n;

	if (num_DBL->parts.exponent < 16383)
		n = (16383 - num_DBL->parts.exponent) * 0.30103 + 70;
	else
		n = (num_DBL->parts.exponent - 16383) * 0.30103 + 4;

	if (num_DBL->parts.exponent >= 16383)
		b = divide_by_minus_2(NULL, n);
	lng2->decimal = set_arithmetic_zeros(n);
	if (num_DBL->parts.exponent < 16383)
	{
		add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
	}
	while (lng2->flag)
	{
		if (lng2->flag & num_DBL->parts.mantissa)
			add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
		lng2->flag = lng2->flag >> 1;
	}
}


//made for decreasing line number for function ft_put_LONG_double
int ft_put_DLNG_minus_sign(long double x, int c)
{
	if (x < 0)
	{
		write(1, "-", 1);
		c++;
	}
	return (c);
}

t_long *ft_create_DLNG(int d, u_long_dbl *num_DBL)
{
	t_long *lng2;
	uint *b;

	
	// print_binary_uint(num_DBL->parts.sign);
	// print_binary_uint(num_DBL->parts.exponent);
	// print_binary_uint(num_DBL->parts.mantissa);
	// printf("exp- ... = %u", num_DBL->parts.exponent - 16383);
	// return ;


	lng2 = create_DLNG_whole_pre();
	
//	n = (d > 64) ? d + 4 : 64; //used for whole part
	// if (num_DBL->parts.exponent < 16383)
	// {
	// 	n = (16383 - num_DBL->parts.exponent) * 0.30103 + 4;
	// 	printf("n = %d\n", n);
	// }
	b = NULL;
	create_DLNG_whole(lng2, num_DBL, b);
//	print_memory(lng2->whole);
	// printf("n = %d\n", n);
	create_DLNG_decimal(lng2, num_DBL, b);
	
	// return (NULL);
	return (lng2);
}

int		ft_put_LONG_double(long double x, t_s *sp)
{
	u_long_dbl num;
	t_long *lng2;
	int n; //number of digits. thus this amount is allocated
	uint *b;
	int count;

	count = 0;
	num.l_dbl = x;


	if ((n = check_DLNG_inf(&num, sp)))
		return (n);

	if (!(lng2 = ft_create_DLNG(sp->decim, &num)))
		return (0);
	
	
	normalize(lng2->whole, lng2->decimal, sp->decim);
	ft_put_DLNG_minus_sign(x, count);
	count += print_double_whole_part(lng2->whole);
	if (!sp->hash && sp->decim == 0)
	{
		free_long_arithm(lng2);
		return (count); 
	}	
	write(1, ".", 1);
	count++;
	print_double_decimal_part(lng2->decimal, sp->decim);
	count += sp->decim;
	// free_long_arithm(lng2);
	return (count); 
}

