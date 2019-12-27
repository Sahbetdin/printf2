#include "test_header.h"


//dig is greater than number of processed digits
void normalize(uint *a, uint *s, int dig)
{
	int i;

	i = dig;
	// printf("s[i] = %d\n", s[i]);
	if (s[i + 1] > 4)
	{
		s[i]++;

	//нормализация
		while (s[i] > 9 && i > 0)
		{
			s[i] -= 10;
			// printf("s[i-1] = %d\n", s[i-1]);
			s[i - 1] += 1;
			
			// printf("s[i-1] = %d\n", s[i-1]);
			i--;
		}
		if (i == 0)
		{
//			write(1, "GT\n", 3);
			a[1]++;
			i = 1;
			while (a[i] > 9)
			{
				a[i] -= 10;
				a[i + 1]++;
			//	printf("a[1] = %d\n", a[i]);
				i++;
			}
		}
	}
}

int		put_double_NEW(double x, t_s *sp)
{
	u_double num;
	double log2;
	int n; //number of digits. thus this amount is allocated
	uint *a; //this will be n digit for 2^exp which is max exponent
	uint *b;
	uint *s;
	int count;
	int dig;

	uint	exp;
	ulong	flag;

	count = 0;
	log2 = 0.30103;

	num.dbl = x;
	a = NULL;
	b = NULL;
	s = NULL;
	flag = 1UL << 51;
	// print_binary_uint(num.parts.exponent);
	// print_binary_ulong(num.parts.mantissa);
	
	// printf("exp = %d\n", exp);
	// printf("parts.exp = %u\n", num.parts.exponent);
//	printf("mant = %lu\n", num.parts.mantissa);
//	printf("sign = %lu\n", num.parts.sign);


	if (num.parts.exponent >= 1023)
	{
		// write(1, "JJ\n", 3);
		exp = num.parts.exponent - 1023;
	//	printf("exp = %d\n", exp);
		n = log2 * exp + 3; //3 for reliability
		//	printf("n = %d\n", n);
		a = power_of_2(exp, n); //malloc used
		b = power_of_2(exp, n); //malloc used

	//	print_memory(a);

		while (exp > 0)
		{
			divide_by_2(b);
			if (flag & num.parts.mantissa)
				add_arithmetics(a, b);
			flag = flag >> 1;
			exp--;
		}

		// count += print_double_whole_part(a);
//		printf("count = %d\n", count);
		free(b);
		b = NULL;
	//	b = divide_by_minus_2(NULL, 52);
	// }
	}
	else //(num.parts.exponent == 1022)
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
	{
		divide_by_minus_2(b, n);
	}
	else
		b = divide_by_minus_2(NULL, n);
	// write(1, "FR\n", 3);
	// print_memory(b);

	while (flag)
	{
		// ft_putnbr_positive(i);
		// write(1, "\n", 1);
		// print_binary_uint(num.parts.mantissa);
		// print_binary_uint(flag);
		// print_binary_ulong(flag);
		// print_memory(s);
		if (flag & num.parts.mantissa)
			add_arithmetics_minus(s, b);
		divide_by_minus_2(b, n);
		flag = flag >> 1;
	}

	if (sp->point)
		dig = sp->decim;
	else
		dig = 6;

	normalize(a, s, dig);
	if (x < 0)
	{
		write(1, "-", 1);
		count++;
	}

	count += print_double_whole_part(a);

	if (!sp->hash && dig == 0)
	{
		free(a);
		free(b);
		free(s);
		return (count); 
	}	

	write(1, ".", 1);
	count++;

	print_double_decimal_part(s, dig);
	count += dig;

	free(a);
	free(b);
	free(s);

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



int ft_put_whole_double(double a, t_s *sp)
{
	int		k;
	int		l;
	int		n;
	int dig;

	if ((n = check_double_inf(a, sp)))
		return (n);
	if (a < 0)
	{
		sp->sign = 1;
		a = -a;
	}
	dig = digits_in_base((long)a, 10);
	if (!(sp->numb || sp->decim))
	{
		if (sp->plus && !sp->sign)
			write(1, "+", 1);
		else if (sp->backsp && !sp->sign)
			write(1, " ", 1);
		if (sp->sign)
			write(1, "-", 1);
	
		return ((sp->plus || sp->backsp || sp->sign) + put_double_NEW(a, sp));
	}
	// print_sp(sp);
	n = dig + (sp->plus || sp->backsp || sp->sign);
	if (sp->decim > 0)
		n += sp->decim + 1;
	if (sp->hash && sp->decim == 0)
		n += 1;
	k = (sp->numb > n) ? sp->numb - n : 0;
	// if (k > 0 && sp->hash && sp->decim > 0)
	// 	k--;
//	printf("k = %d, n = %d\n", k, n);

	if (sp->plus && sp->minus)
	{
		if (sp->sign)
			write(1, "-", 1);
		else
			write(1, "+", 1);
		put_double_NEW(a, sp);
		ft_put_n_chars(32, k);
	}

	else if (sp->plus && !sp->sign && sp->zero)
	{
		// 
		write(1, "+", 1);
		ft_put_n_chars(48, k);
		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);
	}

	else if (sp->plus && !sp->sign)
	{ //+6.5d, 232

		ft_put_n_chars(32, k);
		write(1, "+", 1);
		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);
	}
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
	{
		write(1, " ", 1);

		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && sp->minus)
	{
				// write(1, "EE\n", 3);
	//	printf("k = %d, dig = %d\n", k, dig);
		if (sp->sign)
			write(1, "-", 1);
		else if (sp->backsp)
			write(1, " ", 1);

		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);
		// put_double_NEW(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && sp->minus) //убрать в просто минус
	{
		// write(1, "EE\n", 3);

		if (sp->sign)
		{
			write(1, "-", 1);
		}

		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);

		// put_double_NEW(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && !sp->sign && sp->backsp)
	{
		// write(1, "EE\n", 3);
//	printf("k = %d\n", k);
		write(1, " ", 1);
		if (sp->zero)
			ft_put_n_chars(48, k);
		else
			ft_put_n_chars(32, k);
		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);

		// put_double_NEW(a, sp);
	}
	else if (sp->sign && sp->zero) 
	{
		// write(1, "EE\n", 3);
		write(1, "-", 1);
		ft_put_n_chars(48, k);
		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);
		// put_double_NEW(a, sp);
	}

	else if (sp->sign && sp->backsp)
	{
		// write(1, "BB\n", 3);
//	printf("l = %d, k = %d, dig = %d, sp->sign = %d\n", l, k, dig, sp->sign);
		ft_put_n_chars(32, k);
		write(1, "-", 1);

		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);

		// put_double_NEW(a, sp);
	}
	else // if (sp->sign == '+')
	{ //ПОДУМАТЬ: МОЖЕТ БЫТЬ УБРАТЬ НЖЕ УСЛОВИЕ, ПОПАДАЕМЛИ СЮДА ВООБЩЕ?
		if (sp->zero)
			ft_put_n_chars(48, k);
		else
		{
		// write(1, "EE\n", 3);
			ft_put_n_chars(32, k);
		}
		if (sp->sign)
			write(1, "-", 1);
		if (sp->s == 'f')
			put_double_NEW(a, sp);
		else if (sp->s == 'L' && sp->s1 == 'f')
			ft_put_LONG_double(a, sp);
		// put_double_NEW(a, sp);
//		return (put_double_NEW(a, sp) + k);
	}

	// if (sp->decim > 0)
	// 	k += sp->hash;
	return (k + n);
}
