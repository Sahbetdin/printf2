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

//j is digit from which we will write.
//thus, if j is in "a"(whole part), we look the j - 1.
//otherwise, if j < 0 and it is in "s"(decimal part), we look the j + 1.
void normalize_sci(uint *a, uint *s, int j)
{
	uint y;
	int i;

	if (j < 0)
	{
		i = -j;
		if (s[i + 1] > 4)
		{
			s[i]++;
			while (s[i] > 9 && i > 1)
			{
				s[i] -= 10;
				s[i - 1]++;
				i--;
			}
			if (i == 1)
				j = 1;
		}
	}
	if (j == 1 && s[1] > 9)
	{
		s[1] -= 10;
		a[1]++;
	}
	else if (j == 1)
	{

		i = 1;
		y = s[1];
	}
	else if (j > 1)
	{
		i = j;
		y = a[i - 1];
	}
	if (y > 4)
	{
		a[i]++;
		while (a[i] > 9)
		{
			a[i] -= 10;
			a[i + 1]++;
			i++;
		}
	}	
}

int put_scientific_gr_1(uint *a, uint *s, t_s *sp)
{
	int m1;  //кол-во взятых чисел из целой части, если m1 >= 1, иначе в том числе и кол-во из s
	int i;
	int exp;

	i = a[0];
	while (i && a[i] == 0)
		i--;
	exp = i - 1;
	// printf("exp = %d\n", exp);
	m1 = (exp >= sp->decim) ? i - sp->decim : exp - sp->decim;
	// print_memory(a);
	// print_memory(s);
	// printf("m1 = %d\n", m1);

	normalize_sci(a, s, m1);
	// print_memory(a);
	// print_memory(s);

	if (a[i + 1] != 0)
	{
		exp++;
		i++;
		m1++;
	}
	ft_putchar(a[i] + '0');
	if (sp->decim > 0)
		write(1, ".", 1);
	i--;
	// printf("i = %d\n", i);
	while (i >= m1 && i > 0)
	{
		ft_putchar(a[i] + '0');
		i--;
	}
	i = 1;
	while (i <= -m1)
	{
		ft_putchar(s[i] + '0');
		i++;
	}
	if (sp->s == 'e')
		write(1, "e+", 2);
	else if (sp->s == 'E')
		write(1, "E+", 2);
	if (exp < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp + '0');
		m1++;		
	}
	else
		ft_putnbr_positive(exp);
	if (exp < 10)
		return (5 + sp->decim);
	else
		return (4 + digits_in_base(exp, 10) + sp->decim); //?? 
	// printf("m1 = %d\n", digits_in_base(exp, 10));
}


int put_scientific_less_1(uint *a, uint *s, t_s *sp)
{
	int i;

	i = s[0];
	print_memory(s);
	return(0);
}

t_long *create_long(double x, t_s *sp)
{
	t_long *lng;
	u_double num;
	double	log2;
	uint	*a; //this will be n digit for 2^exp which is max exponent
	uint	*b;
	uint	*s;
	uint	exp;
	int		n;

	lng = (t_long *)malloc(sizeof(t_long));

	num.dbl = x;
	log2 = 0.30103;
	lng->whole = NULL;
	b = NULL;
	lng->decimal = NULL;
	lng->flag = 1UL << 51;
	if (num.parts.exponent >= 1023)
	{
		exp = num.parts.exponent - 1023;
		n = log2 * exp + 3; //3 for reliability
		lng->whole = power_of_2(exp, n); //malloc used
		b = power_of_2(exp, n); //malloc used
		while (exp > 0)
		{
			divide_by_2(b);
			if (lng->flag & num.parts.mantissa)
				add_arithmetics(lng->whole, b);
			lng->flag = lng->flag >> 1;
			exp--;
		}
		free(b);
		b = NULL;
	}
	else
	{
		n = 52;
		exp = 1023 - num.parts.exponent;
		if (!(lng->whole = (uint *)malloc(sizeof(uint) * 2)))
			return (0);
		lng->whole[0] = 1;
		lng->whole[1] = 0;
		b = divide_by_minus_2(NULL, n);
		while (exp > 1)
		{
			divide_by_minus_2(b, n);
			exp--;
		}
		lng->decimal = set_arithmetic_zeros(n);
		add_arithmetics_minus(lng->decimal, b);
	}
	n = (sp->decim > 52) ? sp->decim + 4 : 52;
	if (!lng->decimal)
		lng->decimal = set_arithmetic_zeros(n);
	if (b)
		divide_by_minus_2(b, n);
	else
		b = divide_by_minus_2(NULL, n);
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

int		put_double_NEW(double x, t_s *sp)
{
	int n; //number of digits. thus this amount is allocated
	int count;
	int dig;
	t_long *lng;
	// uint	exp; //rid
	// ulong	flag; //rid

	count = 0;
//		return (0);

	lng = create_long(x, sp);

/*
	log2 = 0.30103;
	num.dbl = x;
	a = NULL;
	b = NULL;
	s = NULL;
	flag = 1UL << 51;
	if (num.parts.exponent >= 1023)
	{
		exp = num.parts.exponent - 1023;
		n = log2 * exp + 3; //3 for reliability
		a = power_of_2(exp, n); //malloc used
		b = power_of_2(exp, n); //malloc used
		while (exp > 0)
		{
			divide_by_2(b);
			if (flag & num.parts.mantissa)
				add_arithmetics(a, b);
			flag = flag >> 1;
			exp--;
		}
		free(b);
		b = NULL;
	}
	else
	{
		n = 52;
		exp = 1023 - num.parts.exponent;
		if (!(a = (uint *)malloc(sizeof(uint) * 2)))
			return (0);
		a[0] = 1;
		a[1] = 0;
		b = divide_by_minus_2(NULL, n);
		while (exp > 1)
		{
			divide_by_minus_2(b, n);
			exp--;
		}
		s = set_arithmetic_zeros(n);
		add_arithmetics_minus(s, b);
	}
	n = (sp->decim > 52) ? sp->decim + 4 : 52;
	if (!s)
		s = set_arithmetic_zeros(n);
	if (b)
		divide_by_minus_2(b, n);
	else
		b = divide_by_minus_2(NULL, n);
	while (flag)
	{
		if (flag & num.parts.mantissa)
			add_arithmetics_minus(s, b);
		divide_by_minus_2(b, n);
		flag = flag >> 1;
	}
*/

	// if ((sp->s == 'e' || sp->s == 'E') && x >= 1)
	// 	return (put_scientific_gr_1(a, s, sp));
	// else if (sp->s == 'e' || sp->s == 'E')
	// 	return (put_scientific_less_1(a, s, sp));
	if ((sp->s == 'e' || sp->s == 'E') && x >= 1)
		return (put_scientific_gr_1(lng->whole, lng->decimal, sp));
	else if (sp->s == 'e' || sp->s == 'E')
		return (put_scientific_less_1(lng->whole, lng->decimal, sp));


	// normalize(a, s, sp->decim);
	normalize(lng->whole, lng->decimal, sp->decim);


	// count += print_double_whole_part(a);
	count += print_double_whole_part(lng->whole);

	// if (!sp->hash && sp->decim == 0 && sp->point)
	// {
	// 	free(a);
	// 	free(b);
	// 	free(s);
	// 	return (count); 
	// }
	if (!sp->hash && sp->decim == 0 && sp->point)
	{
		free(lng->whole);
		// free(b); //rid
		free(lng->decimal);
		return (count); 
	}



	write(1, ".", 1);
	count++;
	
	// print_double_decimal_part(s, sp->decim);
	print_double_decimal_part(lng->decimal, sp->decim);


	count += dig;

	// free(a);
	free(lng->whole);
//	free(b); //rid
	// free(s);
	free(lng->decimal);
	free(lng);
	return (count); 
}

//writes "inf" or "INF" depending on %f or %F specifier
int put_inf(t_s *sp)
{
	if (sp->s == 'f')
		write(1, "inf", 3);
	else if (sp->s == 'F')
		write(1, "INF", 3);
	return (3);
}

//this function checks if the exponent is equal to 2047
//if yes then the number is candidate to NaN or inf
//if mantissa is 0 then it's inf. Otherwise, NaN.
int check_double_inf(double a, t_s *sp)
{
	u_double num;
	int i;

	num.dbl = a;
	if (num.parts.exponent == 2047)
	{
		i = 0;
		if (a < 0)
		{
			write(1, "-", 1);
			i++;
		}
		if (num.parts.mantissa == 0)
			return (put_inf(sp) + i);
		else
		{
			write (1, "nan", 3);
			return (3);
		}
	}
	else
		return (0);
}

//puts f, F, e, E, Lf
int ft_put_all_double(double a, t_s *sp)
{
	if (sp->s == 'f' || sp->s == 'F' || sp->s == 'e' || sp->s == 'E')
		return (put_double_NEW(a, sp));
	else if (sp->s == 'L' && sp->s1 == 'f')
		return (ft_put_LONG_double(a, sp));
	else
		return (0);
}


int ft_put_whole_double(double a, t_s *sp)
{
	int		k;
	int		l;
	int		n;
	int		dig;

	if ((n = check_double_inf(a, sp))) //check if number is inf, -inf, nan
		return (n);
	if (a < 0)
	{
		sp->sign = 1;
		a = -a;
	}

	// print_sp(sp);
	// if (sp->point)
	// 	dig = sp->decim;
	// else
	// 	dig = 6;
	// if (sp->s == 'e' || sp->s == 'E') //check if we need scientific notation
	// 	return (put_double_NEW(a, sp));
	dig = digits_in_base((long)a, 10);
	if (!(sp->numb || sp->decim))
	{
		if (sp->plus && !sp->sign)
			write(1, "+", 1);
		else if (sp->backsp && !sp->sign)
			write(1, " ", 1);
		if (sp->sign)
			write(1, "-", 1);
		return ((sp->plus || sp->backsp || sp->sign) + ft_put_all_double(a, sp)); 
	}
	n = dig + (sp->plus || sp->backsp || sp->sign);
	if (sp->decim > 0)
		n += sp->decim + 1;
		// write(1, "WW", 2);
	if (sp->hash && sp->decim == 0)
		n += 1;
	k = (sp->numb > n) ? sp->numb - n : 0;
	if (sp->plus && sp->minus)
	{
		if (sp->sign)
			write(1, "-", 1);
		else
			write(1, "+", 1);
		ft_put_all_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (sp->plus && !sp->sign && sp->zero)
	{
		write(1, "+", 1);
		ft_put_n_chars(48, k);
		ft_put_all_double(a, sp);
	}
	else if (sp->plus && !sp->sign)
	{ //+6.5d, 232
		ft_put_n_chars(32, k);
		write(1, "+", 1);
		ft_put_all_double(a, sp);
	}
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
	{
		write(1, " ", 1);
		ft_put_all_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && sp->minus)
	{
		if (sp->sign)
			write(1, "-", 1);
		else if (sp->backsp)
			write(1, " ", 1);
		ft_put_all_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && sp->minus) //убрать в просто минус
	{
		if (sp->sign)
			write(1, "-", 1);
		ft_put_all_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && !sp->sign && sp->backsp)
	{
		write(1, " ", 1);
		if (sp->zero)
			ft_put_n_chars(48, k);
		else
			ft_put_n_chars(32, k);
		ft_put_all_double(a, sp);
	}
	else if (sp->sign && sp->zero) 
	{

		write(1, "-", 1);
		ft_put_n_chars(48, k);
		ft_put_all_double(a, sp);
	}
	else if (sp->sign && sp->backsp)
	{
		ft_put_n_chars(32, k);
		write(1, "-", 1);
		ft_put_all_double(a, sp);
	}
	else
	{
		if (sp->zero)
			ft_put_n_chars(48, k);
		else
			ft_put_n_chars(32, k);
		if (sp->sign)
			write(1, "-", 1);
		ft_put_all_double(a, sp);
	}
	return (k + n);
}
