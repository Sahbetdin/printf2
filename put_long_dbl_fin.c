#include "test_header.h"

int		ft_put_LONG_double(long double x, t_s *sp)
{
	//

	u_long_dbl num;
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

	num.l_dbl = x;
	a = NULL;
	b = NULL;
	s = NULL;
	flag = 1UL << 62;
	// print_binary_uint(num.parts.exponent);
	// print_binary_ulong(num.parts.mantissa);
	// printf("mant = %lu\n", num.parts.mantissa);

	// printf("exp = %d\n", exp);
	// printf("parts.exp = %u\n", num.parts.exponent);
//	printf("sign = %lu\n", num.parts.sign);


	if (num.parts.exponent >= 16383)
	{
		// write(1, "JJ\n", 3);
		exp = num.parts.exponent - 16383;
		// printf("exp = %d\n", exp);
		n = log2 * exp + 4; //4 for reliability
		//	printf("n = %d\n", n);
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

		// count += print_double_whole_part(a);
//		printf("count = %d\n", count);
		free(b);
		b = NULL;
		n = (sp->decim > 64) ? sp->decim + 4 : 64;
		if (!s)
			s = set_arithmetic_zeros(n);
		b = divide_by_minus_2(NULL, n);
	//	b = divide_by_minus_2(NULL, 52);
	// }
	}
	else //(num.parts.exponent == 1022)
	{
		if (!(a = (uint *)malloc(sizeof(uint) * 2)))
			return (0);
		a[0] = 1;
		a[1] = 0;
		exp = 16383 - num.parts.exponent;
		n = 3.4 * (log2 * exp + 4); //4 for reliability
		// printf("exp = %d\n", exp);
		// printf("n = %d\n", n);
		b = divide_by_minus_2(NULL, n);
	
		while (exp > 1)
		{
			divide_by_minus_2(b, n);
			exp--;
		}
		// print_memory(b);
		s = set_arithmetic_zeros(n);
		add_arithmetics_minus(s, b);
		divide_by_minus_2(b, n);
	}
		
	// write(1, "FR\n", 3);
	// print_memory(b);
	// flag = flag >> 1;
	while (flag)
	{
		// ft_putnbr_positive(i);
		// write(1, "\n", 1);
		// print_binary_ulong(flag);
		// print_binary_ulong(num.parts.mantissa);
		// print_memory(s);
		// print_memory(s);
		if (flag & num.parts.mantissa)
			add_arithmetics_minus(s, b);
		// write(1, "\n", 1);
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
