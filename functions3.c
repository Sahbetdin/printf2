#include "test_header.h"

void	ft_put_n_chars(char c, int n)
{
	if (n > 0)
	{
		while (n)
		{
			write(1, &c, 1);
			n--;
		}
	}
}

int		ft_put_percentage(t_specif *sp)
{
	if (sp->minus)
	{
		ft_putchar('%');
		ft_put_n_chars(32, sp->numb - 1);
		return (sp->numb);
	}
	else if (sp->numb)
	{
		if (sp->zero)
			ft_put_n_chars(48, sp->numb - 1);
		else
			ft_put_n_chars(32, sp->numb - 1);
		ft_putchar('%');
		return (sp->numb);	
	}
	else
		ft_putchar('%');
	return (1);
}


/*PUTS ONLY POSITIVE NUMBERS! */
int		ft_putdouble(double a, t_specif *sp)
{
	long	d; //the same 'a' but rounded
	int		i;

	d = a;
//	printf("\n d is %lu \n", d);
	i = ft_putlong(d);
	ft_putchar('.');
	i++;
//	ft_putchar('\n');
 	while (sp->decim > 0)
 	{
 	//	printf("bef %9.5f ", a);
 		a = (a - d) * 10 + 1.0e-9;
 	//	printf(", aft %9.5f \n", a);
		d = a;
 		if (sp->decim == 1)
 		{
			if ((a - (long)a) * 10 > 4)
				d += 1;
 		}
		ft_putchar(d + '0');
		i++;
 		sp->decim--;
 	}
	return (i);
}

int ft_put_whole_double(double a, t_specif *sp)
{
	int		k;
	long	d; //the same 'a' but rounded
	int dig;

	if (a < 0)
	{
		sp->sign = '-';
		a = -a;
	}
	else
		sp->sign = '+';
	d = a;
	dig = digits_in_base(d, 10);
	k = sp->numb - dig - 1 - sp->decim;
	if (sp->plus)
		k--;
//	printf("k = %d\n", k);
//	printf("digits: %d\n", digits_in_base(d, 10));
	if (sp->plus && sp->minus)
	{
		ft_putchar(sp->sign);
		ft_putdouble(a, sp);
		ft_put_n_chars(' ', k);
		return (sp->numb);
	}
	else if (sp->plus && sp->zero)
	{
		ft_putchar(sp->sign);
		ft_put_n_chars('0', k);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else if (sp->plus)
	{
		ft_put_n_chars(' ', k);
		ft_putchar(sp->sign);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else if (sp->minus && sp->backsp && sp->sign == '+') //' ' is ignored when '+' is present
	{
		ft_putchar(' ');
		ft_putdouble(a, sp);
		ft_put_n_chars(' ', k - 1);
		return (sp->numb);
	}
	else if (sp->minus && sp->backsp && sp->sign == '-') 
	{
		ft_putchar('-');
		ft_putdouble(a, sp);
		ft_put_n_chars(' ', k - 1);
		return (sp->numb);
	}
	else if (sp->minus && sp->sign == '+')
	{	
		ft_putdouble(a, sp);
		ft_put_n_chars(' ', k);
		return (sp->numb);
	}
	else if (sp->minus && sp->sign == '-')
	{
		ft_putchar('-');
		ft_putdouble(a, sp);
		ft_put_n_chars(' ', k - 1);
		return (sp->numb);
}
	else if (sp->backsp && sp->zero && sp->sign == '-')
	{
		ft_putchar('-');
		ft_put_n_chars('0', k - 1);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else if (sp->backsp && sp->zero)
	{
		ft_putchar(' ');
		ft_put_n_chars('0', k - 1);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else if (sp->zero && sp->sign == '-')
	{
		ft_putchar('-');
		ft_put_n_chars('0', k - 1);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else if (sp->zero)
	{
		ft_put_n_chars('0', k);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else if (sp->backsp && sp->sign == '-')
	{
		ft_put_n_chars(' ', k - 1);
		ft_putchar('-');
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else if (sp->backsp && sp->sign == '+')
	{
		(k > 0) ? ft_put_n_chars(' ', k) : ft_put_n_chars(' ', 1);
		ft_putdouble(a, sp);
		return ((k > 0) ? sp->numb : sp->numb + 1);
	}
	else if (sp->sign == '-')
	{
		ft_put_n_chars(' ', k - 1);
		ft_putchar(sp->sign);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
	else // if (sp->sign == '+')
	{
		ft_put_n_chars(' ', k);
		ft_putdouble(a, sp);
		return (sp->numb);
	}
}


int get_exp(double a, t_specif *sp)
{
	int i;
	double b;

	i = 0;
	b = a;
	if (b > 10)
	{
		while (b >= 10) //проверить таки все здесь
		{
			b /= 10;
			i++;
		}
	}
	else if (b < 10)
	{
		while (b < 1)
		{
			b *= 10;
			i++;
		}
		i = -i;
	}
	else
		i = 0;
	ft_put_whole_double(b, sp);
	ft_putchar('e');
	if (i < 0)
		ft_putchar('-');
	else
		ft_putchar('+');
	i = abs_v(i);
	if (i < 10)
		ft_putchar('0');
	ft_putnbr(i);
	return (i);
}

int		ft_putscientific(double a, t_specif *sp)
{
//	print_sp(sp);
	get_exp(a, sp);
//	ft_putstr("HERE");
	return (0);
}


int ft_put_integer_u(uint u_value, t_specif *sp)
{
	int n;

	n = 0;
	// if (sp->hash)
	// {
	// 	if (sp->specif == 'o')
	// 		write(1, "0", 1);
	// 	else if (sp->specif == 'x')
	// 		write(1, "0x", 2);
	// 	else if (sp->specif == 'X')
	// 		write(1, "0X", 2);
	// 	if (sp->specif == 'o')
	// 		n = 1;
	// 	else if (sp->specif == 'x'|| sp->specif == 'X')
	// 		n = 2;
	// }
	if (sp->specif == 'u')
		n += ft_itoa_base_unsigned(u_value, 10, 0);
	else if (sp->specif == 'o')
		n += ft_itoa_base_unsigned(u_value, 8, 0);
	else if (sp->specif == 'x')
		n += ft_itoa_base_unsigned(u_value, 16, 0);
	else if (sp->specif == 'X')
		n += ft_itoa_base_unsigned(u_value, 16, 1);
	else if (sp->specif == 'd')
		n += ft_putnbr((int)u_value);
	return (n);
}

int		ft_put_parsed_integer_u(uint num, t_specif *sp)
{
	int		k;
	int		dig;
	int		n;

	if (sp->specif == 'u')
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->specif == 'o')
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->specif == 'x' || sp->specif == 'X')
		dig = digits_in_base_unsigned(num, 16);
	else if (sp->specif == 'd')
		dig = digits_in_base((int)num, 10);
	if (sp->hash)
	{
		if (sp->specif == 'x' || sp->specif == 'X')
			k = sp->numb - sp->decim - 2;
		if (k > 0 && sp->minus)
		{
			write(1, "0x", 2);
			ft_put_n_chars('0', sp->decim - dig);
			n = ft_put_integer_u(num, sp);
			ft_put_n_chars(32, k);
		}
		else if (k > 0 && !sp->minus)
		{
			ft_put_n_chars(32, k);	
			write(1, "0x", 2);
			n = ft_put_integer_u(num, sp);
		}
	return (sp->numb);
	}
	k = sp->numb - dig;
	// print_sp(sp);
//	printf(" sp->numb = %d. ", sp->numb);
//	printf(" k = %d. ", k);
	if (sp->minus)
	{
		n = ft_put_integer_u(num, sp);
		ft_put_n_chars(' ', k);
	}
	else if (sp->zero)
	{
		ft_put_n_chars('0', k);
		n = ft_put_integer_u(num, sp);
	}
	else
	{
//		printf("FFF\n");
//		if (k > 0)
		if (sp->hash)
		{
			if (sp->specif == 'o')
				k--;
			else if (sp->specif == 'x' || sp->specif == 'X')
				k -= 2;
		}
		ft_put_n_chars(' ', k);
//		else
//			ft_put_n_chars(' ', 1);
		n = ft_put_integer_u(num, sp);
//		return ((k > 0) ? n + k : n + 1);
	}
	if (k > 0)
		n += k;
//	printf(" n = %d\n", n);
//	printf("%d --\n", sp->numb);
//	return ((sp->numb) ? sp->numb : dig);
	return (n);
}

int		ft_put_string(char *str, t_specif *sp)
{
	int k;
	int n;


	if (!str)
		return (0);
	n = (int)ft_strlen(str);
	if (sp->point)
		n = sp->decim;
	k = sp->numb - n;
	if (k > 0)
	{
		if (sp->minus)
		{
			write(1, str, n);
			ft_put_n_chars(' ', k);
		}
		else
		{
			ft_put_n_chars(' ', k);
			write(1, str, n);
		}
		return (sp->numb);
	}
	else
		write(1, str, n);
	return (n);
}
