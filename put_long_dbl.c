#include "test_header.h"


t_long	*ft_create_LONG_pre(u_long_dbl *num_DBL)
{
	// u_long_dbl	num;
	double		log2;
	t_long		*lng2;
	uint exp;
	int n;

	// num.l_dbl = x;
	log2 = 0.30103;
	lng2 = (t_long *)malloc(sizeof(t_long));
	lng2->flag = 1UL << 62;
	if (num_DBL->parts.exponent >= 16383)
	{
		exp = num_DBL->parts.exponent - 16383;
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


t_long	*ft_create_LONG_whole(u_long_dbl *num_DBL)
{
	// u_long_dbl	num;
	t_long		*lng2;
	uint		exp;
	int			n;
	uint *b;

	lng2 = ft_create_LONG_pre(num_DBL);
	if (num_DBL->parts.exponent >= 16383)
	{
		exp = num_DBL->parts.exponent - 16383;
		n = (int)(0.30103 * exp + 4.0); //could be problem.change back to log
		b = power_of_2(exp, n); //malloc used
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
		n = (log2 * exp_ + 780); //4 for reliability
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


void	ft_create_LONG_decimal(t_long *lng2, u_long_dbl *num_DBL, int d)
{
	uint *b;
	int n;
	uint exp_;
	double log2;

	n = ft_create_n_temp(num_DBL->parts.exponent, d);
	// printf("n = %d\n", n);
	b = ft_create_b_temp(num_DBL->parts.exponent, d, n);
	// print_memory(b);
	if (num_DBL->parts.exponent >= 16383)
		lng2->decimal = set_arithmetic_zeros(n);
	else
	{
		lng2->decimal = set_arithmetic_zeros(n);
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
	free(b);
}

int		ft_put_LONG_only(u_long_dbl *num_DBL, t_s *sp)
{
	double log2;
	int count;
	int dig;
	t_long *lng2;

	count = 0;
	lng2 = ft_create_LONG_whole(num_DBL);
	ft_create_LONG_decimal(lng2, num_DBL, sp->decim);

	//   print_memory(lng2->decimal);
	dig = (sp->point > 0) ? sp->decim : 6;
	normalize(lng2->whole, lng2->decimal, sp->decim);
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

int ft_dig_LDBL(long double a)
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

void	ft_put_from_specif_LDBL_minus(u_long_dbl *num_DBL, t_s *sp, int k)
{
	ft_put_sign(sp);
	ft_put_LONG_only(num_DBL, sp);
	ft_put_n_chars(32, k);	
}

void	ft_put_from_specif_LDBL(u_long_dbl *num_DBL, t_s *sp, int k)
{
	if (sp->minus)
		ft_put_from_specif_LDBL_minus(num_DBL, sp, k);		
	else
	{
		if (sp->zero && sp->backsp && !sp->plus && !sp->sign)
		{
			write(1, " ", 1);
			ft_put_n_chars(48, k - 1);
			ft_put_LONG_only(num_DBL, sp);
		}
		else if (sp->zero)
		{		
			ft_put_sign(sp);
			ft_put_n_chars(48, k);
			ft_put_LONG_only(num_DBL, sp);
		}
		else
		{
			// ft_putnbr_positive(k);
			// write(1,"J\n", 2);
			// ft_put_n_chars(32, k);
			ft_put_sign(sp);
			ft_put_LONG_only(num_DBL, sp);
		}
	}
}

int		ft_put_LONG_double(long double x, t_s *sp)
{
	int dig;
	int k;
	int count;
	u_long_dbl num;


	if (x < 0)
	{
		sp->sign = 1;
		x = -x;
	}
	num.l_dbl = x;
	if ((k = check_DLNG_inf(&num, sp)))
		return (k);
	if (sp->s1 == 'e' || sp->s1 == 'E')
		return (ft_put_whole_sci_LDBL(x, sp));
	dig = ft_dig_LDBL(x);
	// printf("dig = %d\n", dig);
	k = (sp->numb > dig) ? sp->numb - dig : 0;

	if (sp->decim > 0)
		k -= sp->decim + 1;
	k -= (sp->plus || sp->sign);
	if (k < 0)
		k = 0;
	if (k == 0 && sp->backsp && !sp->sign)
		k = 1;
//узнаем что возвр
	count = dig + k + (sp->plus || sp->sign);
	// printf("count = %d\n", count);
	if (sp->decim > 0)
		count += sp->decim + 1;
	ft_put_from_specif_LDBL(&num, sp, k);	
	return (count);
}

/////////////////////////////////////

// t_long	*ft_create_LONG_pre(u_long_dbl *num_DBL);
// t_long	*ft_create_LONG_whole(u_long_dbl *num_DBL);
// int ft_create_n_temp(uint exp_, int d);
// uint *ft_create_b_temp(uint exp_, int d, int n);
// void	ft_create_LONG_decimal(t_long *lng2, u_long_dbl *num_DBL, int d);
// int		ft_put_LONG_only(u_long_dbl *num_DBL, t_s *sp);
// int ft_dig_LDBL(long double a);
// void	ft_put_from_specif_LDBL_minus(u_long_dbl *num_DBL, t_s *sp, int k);
// void	ft_put_from_specif_LDBL(u_long_dbl *num_DBL, t_s *sp, int k);
// int		ft_put_LONG_double(long double x, t_s *sp);
