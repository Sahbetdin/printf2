#include "test_header.h"


void ft_put_sign(t_s *sp)
{
	if (sp->sign)
		write(1, "-", 1);
	else if (sp->plus)
		write(1, "+", 1);
}


void ft_put_exp(char ch, int dig)
{
	if (ch == 'e')
		write(1, "e", 1);
	else if (ch == 'E')
		write(1, "E", 1);
	if (dig < 0)
		write(1, "-", 1);
	else
		write(1, "+", 1);
}

int ft_put_exp_value(int exp_)
{
	if (exp_ < 0)
		exp_ = -exp_;
	else
		exp_ -= 1;
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
	}
	else
		ft_putnbr_positive(exp_ - 1);
	if (exp_ < 100)
		return (2);
	else if (exp_ < 1000)
		return (3);
	else if (exp_ < 10000)
		return (4);
	else
		return (5);
}


//s это не ДЕСЯТАЯ ЧАСТЬ, это элемент объединенного массива
void normalize_sci(uint *s, int d)
{
	int i;

	i = d;
	if (s[i + 1] > 4)
	{
		s[i]++;
		while (s[i] > 9 && i > 1)
		{
			s[i] -= 10;
			s[i - 1]++;
			i--;
		}
	}
}

int ft_put_sci(double x, t_s *sp)
{
	int k;
	int n;
	int i;
	int j; //кол-во записанных в "arr" целых чисел
	t_long *lng;
	uint *a;
	uint *s;
	uint *arr; //new array where whole and decimal parts stored
	int count;

	if (!(lng = create_long(x, sp)))
		return (0);
	print_memory(lng->whole);
	print_memory(lng->decimal);
	a = lng->whole;
	s = lng->decimal;

//initiate arr which is concatination of "a" and "s"
	arr = (uint *)malloc(sizeof(uint) * (lng->whole[0] + lng->decimal[0] + 1));
	arr[0] = lng->whole[0] + lng->decimal[0];
	i = 0;
	while (++i < arr[0])
		arr[i] = 0;

	i = lng->whole[0];
	while (i > 0 && lng->whole[i] == 0)
		i--;
	j = i;
	
	if (j > 0)
	{
		while (i > 0)
		{
			arr[a[0] - i - 1] = lng->whole[i];
			i--;
		}
		i = 1;
		while (i < s[0])
		{
			arr[j + i] = s[i];
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < s[0] && s[i] == 0)
			i++;
		j = -i;
		i = 1;
		while (i <= s[0] + j)
		{
			arr[i] = s[i - j - 1];
			i++;
		}
		//if (j == s[0] - 1) ?????
	}
	
	print_memory(arr);
	// printf("j = %d\n", j);

	i = 2;
	sp->decim++;	

	normalize_sci(arr, sp->decim);
	print_memory(arr);

	ft_putchar(arr[1] + '0');
	if (sp->decim > 0)
		write(1, ".", 1);

// if sp->decim > 0

	if (j >= 0)
	{
		while (i <= sp->decim)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
	}
	else
	{
		while (i <= sp->decim)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
	}
	sp->decim--;
	
	ft_put_exp(sp->s, j);

	// print_sp(sp);
//write down exponent value
	count = 1 + 2; //целая часть и e+
	// printf("\ncount = %d\n", count);
	// print_sp(sp);
	if (sp->decim > 0)
		count += sp->decim + 1; //
	// printf("count = %d\n", count);
	n = ft_put_exp_value(j);
	// printf("\nn = %d\n", n);
	
	return (count + n);
}
