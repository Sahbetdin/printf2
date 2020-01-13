#include "test_header.h"


t_long	*ft_create_LONG_pre(long double x)
{
	u_long_dbl	num;
	double		log2;
	t_long		*lng2;
	uint exp;
	int n;

	num.l_dbl = x;
	log2 = 0.30103;
	lng2 = (t_long *)malloc(sizeof(t_long));
	lng2->flag = 1UL << 62;
	if (num.parts.exponent >= 16383)
	{
		exp = num.parts.exponent - 16383;
		n = log2 * exp + 4; //4 for reliability
		lng2->whole = power_of_2(exp, n); //malloc used
	}
	else
	{
		if (!(lng2->whole = (uint *)malloc(sizeof(uint) * 2)))
			return (0);
		lng2->whole[0] = 1;
		lng2->whole[1] = 0;
	}
	return (lng2);
}


t_long	*ft_create_LONG_whole(long double x)
{
	u_long_dbl	num;
	t_long		*lng2;
	uint		exp;
	int			n;
	uint *b;

	lng2 = ft_create_LONG_pre(x);
	num.l_dbl = x;
	if (num.parts.exponent >= 16383)
	{
		exp = num.parts.exponent - 16383;
		n = (int)(0.30103 * exp + 4.0); //could be problem.change back to log
		b = power_of_2(exp, n); //malloc used
		while (exp > 0)
		{
			divide_by_2(b);
			if (lng2->flag & num.parts.mantissa)
				add_arithmetics(lng2->whole, b);
			lng2->flag = lng2->flag >> 1;
			exp--;
		}
		free(b);
	}
	return (lng2);
}

int ft_create_n_temp(uint exp_, int d)
{
	int n;
	double log2;

	log2 = 0.30103;
	if (exp_ >= 16383)
		n = (d > 64) ? d + 4 : 64;
	else
	{
		exp_ = 16383 - exp_;
		n = (log2 * exp_ + 4) * 3; //4 for reliability
	}
	return (n);
}

uint *ft_create_b_temp(uint exp_, int d, int n)
{
	uint *b;
	double log2;

	if (exp_ >= 16383)
		b = divide_by_minus_2(NULL, n);
	else
	{
		exp_ = 16383 - exp_;
		b = divide_by_minus_2(NULL, n);	
		while (exp_ > 1)
		{
			divide_by_minus_2(b, n);
			exp_--;
		}
	}
	return (b);
}


void	ft_create_LONG_decimal(t_long *lng2, u_long_dbl *uDBL, int d)
{
	uint *b;
	int n;
	uint exp_;
	double log2;

	n = ft_create_n_temp(uDBL->parts.exponent, d);
	b = ft_create_b_temp(uDBL->parts.exponent, d, n);
	if (uDBL->parts.exponent >= 16383)
		lng2->decimal = set_arithmetic_zeros(n);
	else
	{
		lng2->decimal = set_arithmetic_zeros(n);
		add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
	}
	while (lng2->flag)
	{
		if (lng2->flag & uDBL->parts.mantissa)
			add_arithmetics_minus(lng2->decimal, b);
		divide_by_minus_2(b, n);
		lng2->flag = lng2->flag >> 1;
	}
	free(b);
}

int		ft_put_LONG_only(long double x, t_s *sp)
{
	u_long_dbl num;
	double log2;
	int count;
	int dig;
	t_long *lng2;

	count = 0;
	num.l_dbl = x;

	lng2 = ft_create_LONG_whole(x);	

	ft_create_LONG_decimal(lng2, &num, sp->decim);
	dig = (sp->point > 0) ? sp->decim : 6;
	// print_memory(lng2->decimal);
	normalize(lng2->whole, lng2->decimal, sp->decim);
//	print_memory(lng2->decimal);
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
	free_long_arithm(lng2);
	return (count); 
}

int ft_dig_LONG(long double a)
{
	int i;

	if (a < 1)
		return (1);
	i = 0;
	while (a >= 1)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int		ft_put_LONG_double(long double x, t_s *sp)
{
	int dig;
	int k;
	int count;

	if (x < 0)
	{
		sp->sign = 1;
		x = -x;
	}
	dig = ft_dig_LONG(x);
//	printf("dig = %d\n", dig);
	k = (sp->numb > dig) ? sp->numb - dig : 0;
	if (sp->decim > 0)
		k -= sp->decim + 1;
	k -= (sp->plus || sp->sign);
	if (k < 0)
		k = 0;
	if (k == 0 && sp->backsp && !sp->sign)
		k = 1;
//	printf("k = %d\n", k);
//узнаем что возвр
	count = dig + k + (sp->plus || sp->sign);
	// printf("count = %d\n", count);
	if (sp->decim > 0)
		count += sp->decim + 1;
//	printf("count = %d\n", count);

	if (sp->minus)
	{
			ft_put_sign(sp);
			ft_put_LONG_only(x, sp);
			ft_put_n_chars(32, k);
	}
	else
	{
		if (sp->zero && sp->backsp && !sp->plus && !sp->sign)
		{
			write(1, " ", 1);
			ft_put_n_chars(48, k - 1);
			ft_put_LONG_only(x, sp);
		}
		else if (sp->zero)
		{		
			ft_put_sign(sp);
			ft_put_n_chars(48, k);
			ft_put_LONG_only(x, sp);
		}
		else
		{
			ft_put_n_chars(32, k);
			ft_put_sign(sp);
			ft_put_LONG_only(x, sp);
		}
	}
	
	return (count);
}
