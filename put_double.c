#include "test_header.h"

//dig is greater than number of processed digits
//нормализация: 1.99999, 1.48999999999, 199.99999
void normalize(uint *a, uint *s, int i)
{
	if (s[i + 1] > 4)
	{
		s[i]++;
		while (s[i] > 9 && i > 0)
		{
			s[i] -= 10;
			s[i - 1] += 1;
			i--;
		}
		if (i == 0)
		{
			a[1]++;
			i = 1;
			while (a[i] > 9)
			{
				a[i] -= 10;
				a[i + 1]++;
				i++;
			}
		}
	}
}



t_long *create_long_whole_pre(u_double *num_union_f)
{
	t_long *lng;
	uint	exp;
	int		n;

	lng = (t_long *)malloc(sizeof(t_long));
	lng->whole = NULL;
	lng->flag = 1UL << 51;
	if (num_union_f->parts.exponent >= 1023)
	{
		exp = num_union_f->parts.exponent - 1023;
		n = 0.30103 * exp + 3; //3 for reliability
		lng->whole = power_of_2(exp, n); //malloc used
	}
	else
	{
		exp = 1023 - num_union_f->parts.exponent;
		if (!(lng->whole = (uint *)malloc(sizeof(uint) * 2)))
			return (0);
		lng->whole[0] = 1;
		lng->whole[1] = 0;
	}
	return (lng);	
}

//for exp > 1023 creates only whole part.
//otherwise creates only lng
t_long *create_long_whole(u_double *num_union_f)
{
	t_long *lng;
	uint	*b;
	uint	exp;
	int		n;

	lng = create_long_whole_pre(num_union_f);
	b = NULL;
	if (num_union_f->parts.exponent >= 1023)
	{
		exp = num_union_f->parts.exponent - 1023;
		n = 0.30103 * exp + 3; //3 for reliability
		b = power_of_2(exp, n); //malloc used
		while (exp > 0)
		{
			divide_by_2(b);
			if (lng->flag & num_union_f->parts.mantissa)
				add_arithmetics(lng->whole, b);
			lng->flag = lng->flag >> 1;
			exp--;
		}
		free(b);
		b = NULL;
	}
	return (lng);
}

uint *ft_temp_b_floats(u_double *num_union_f, int n)
{
	uint	exp;
	uint	*b;

	b = NULL;
	if (num_union_f->parts.exponent < 1023)
	{
		exp = 1023 - num_union_f->parts.exponent;
		b = divide_by_minus_2(NULL, n);
		while (exp > 1)
		{
			divide_by_minus_2(b, n);
			exp--;
		}
	}
	else
		b = divide_by_minus_2(NULL, n);
	return (b);
}

// uint	*a; //this will be n digit for 2^exp which is max exponent
// uint	*s;
t_long *create_long(double x, t_s *sp)
{
	t_long *lng;
	u_double num;
	uint	*b;
	int		n;

	num.dbl = x;

	if (!(lng = create_long_whole(&num)))
		return (NULL);
	n = (sp->decim > 52) ? sp->decim + 600 : 52;
	lng->decimal = set_arithmetic_zeros(n);
	b = ft_temp_b_floats(&num, n);
	if (num.parts.exponent < 1023)
	{
		add_arithmetics_minus(lng->decimal, b);
		divide_by_minus_2(b, n);
	}
	while (lng->flag)
	{
		if (lng->flag & num.parts.mantissa)
			add_arithmetics_minus(lng->decimal, b);
		divide_by_minus_2(b, n);
		lng->flag = lng->flag >> 1;
	}
	free(b);
	return (lng);
}

void free_long_arithm(t_long *lng)
{
	free(lng->whole);
	free(lng->decimal);
	free(lng);
}

int		put_double_NEW(double x, t_s *sp)
{
	int n; //number of digits. thus this amount is allocated
	int count;
	int dig;
	t_long *lng;
	count = 0;


	if (!(lng = create_long(x, sp)))
		return (0);

	// print_sp(sp);
	// print_memory(lng->decimal);

	normalize(lng->whole, lng->decimal, sp->decim);

	// print_memory(lng->decimal);
	// write(1, "H", 1);
	// return (0);

	count += print_double_whole_part(lng->whole);
	if (!sp->hash && sp->decim == 0 && sp->point)
	{
		free_long_arithm(lng);
		return (count);
	}
	write(1, ".", 1);
	count++;
	print_double_decimal_part(lng->decimal, sp->decim);
	count += dig;
	free_long_arithm(lng);
	return (count);
}

//puts f, F,  Lf
int ft_put_f_double(double a, t_s *sp)
{

	if (sp->s == 'f' || sp->s == 'F' || (sp->s == 'l' && sp->s1 == 'f'))
		return (put_double_NEW(a, sp));
	else if (sp->s == 'L' && sp->s1 == 'f')
		return (ft_put_LONG_double(a, sp));
	else
		return (0);
}

int		ft_memory_float(double a, t_s *sp)
{
	u_double num;
	num.dbl = a;
	write(1, "sign:     ", 10);
	print_binary_uint(num.parts.sign, 0);
	write(1, "exponent: ", 10);
	print_binary_uint(num.parts.exponent, 10);
	write(1, "mantissa: ", 10);
	print_binary_ulong(num.parts.mantissa, 51);
	return (94);
}

int		ft_memory_LDBL(long double a, t_s *sp)
{
	u_long_dbl num;
	num.l_dbl = a;
	write(1, "sign:     ", 10);
	print_binary_uint(num.parts.sign, 0);
	write(1, "exponent: ", 10);
	print_binary_uint(num.parts.exponent, 10);
	write(1, "mantissa: ", 10);
	print_binary_ulong(num.parts.mantissa, 63);
	return (0);
}

