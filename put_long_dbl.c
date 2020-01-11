#include "test_header.h"
t_long	*ft_create_LONG_whole(long double x)
{
	u_long_dbl	num;
	double		log2;
	t_long		*lng2;
	uint		exp;
	int			n;
	uint *b;

	num.l_dbl = x;
	lng2 = (t_long *)malloc(sizeof(t_long));
	log2 = 0.30103;
	lng2->flag = 1UL << 62;
	if (num.parts.exponent >= 16383)
	{
		exp = num.parts.exponent - 16383;
		n = log2 * exp + 4; //4 for reliability
		lng2->whole = power_of_2(exp, n); //malloc used
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
		b = NULL;
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


int		ft_put_LONG_double(long double x, t_s *sp)
{
	u_long_dbl num;
	double log2;
	int n; //number of digits. thus this amount is allocated
	uint *a; //this will be n digit for 2^exp which is max exponent
	uint *b;
	uint *s;
	int count;
	int dig;
	t_long *lng2;

	uint	exp;
	ulong	flag;

	count = 0;

	num.l_dbl = x;
	b = NULL;
	s = NULL;
	lng2 = ft_create_LONG_whole(x);	
	a = lng2->whole;

	log2 = 0.30103;
	if (num.parts.exponent >= 16383)
	{
		n = (sp->decim > 64) ? sp->decim + 4 : 64;
		if (!s)
			s = set_arithmetic_zeros(n);
		b = divide_by_minus_2(NULL, n);
	}
	else
	{
		exp = 16383 - num.parts.exponent;
		n = 10 * (log2 * exp + 4); //4 for reliability
		b = divide_by_minus_2(NULL, n);	
		while (exp > 1)
		{
			divide_by_minus_2(b, n);
			exp--;
		}

	}

	if (num.parts.exponent < 16383)
	{
		s = set_arithmetic_zeros(n);
		add_arithmetics_minus(s, b);
		divide_by_minus_2(b, n);
	}
	while (lng2->flag)
	{
		if (lng2->flag & num.parts.mantissa)
			add_arithmetics_minus(s, b);
		divide_by_minus_2(b, n);
		lng2->flag = lng2->flag >> 1;
	}
	dig = (sp->point > 0) ? sp->decim : 6;
	normalize(a, s, sp->decim);
	count += print_double_whole_part(a);
	if (!sp->hash && sp->decim == 0)
	{
		free(a);
		free(b);
		free(s);
		return (count); 
	}	
	write(1, ".", 1);
	count++;
	print_double_decimal_part(s, sp->decim);
	count += sp->decim;
	free(a);
	free(b);
	free(s);

	return (count); 
}
