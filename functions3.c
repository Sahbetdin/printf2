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
	ft_putnbr_positive(i);
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
	if (sp->specif == 'u')
		n += ft_itoa_base_unsigned(u_value, 10, 0);
	else if (sp->specif == 'o')
		n += ft_itoa_base_unsigned(u_value, 8, 0);
	else if (sp->specif == 'x')
		n += ft_itoa_base_unsigned(u_value, 16, 0);
	else if (sp->specif == 'X')
		n += ft_itoa_base_unsigned(u_value, 16, 1);
	return (n);
}

int		ft_put_prelimenaries(uint num, t_specif *sp)
{
	if (sp->hash && num)
	{
		if (sp->specif == 'o')
		{
			write(1, "0", 1);
			return (1);
		}
		else if (sp->specif == 'x')
			write(1, "0x", 2);
		else if (sp->specif == 'X')
			write(1, "0X", 2);
		if (sp->specif == 'x' || sp->specif == 'X')
			return (2);
		else
			return (0);
	}
	else
		return (0);
}

int ft_put_int_min(int num, t_specif *sp)
{
	int l;
	int k;
	int dig;

	dig = 11;
	if (!sp->numb && !sp->point) //просто %d, % d
		write(1, "-2147483648", 11);
	else if (!sp->point)
	{
		k = (sp->numb > dig) ? sp->numb - dig : 0; //кол-во нулей либо пробелов
		if (sp->zero && !sp->minus) //нет '-' и есть '0'
		{
			write(1, "-", 1);
			ft_put_n_chars(48, k - 1);
			write(1, "2147483648", 10);
		}
		else if (!sp->minus)
		{
			ft_put_n_chars(32, k);
			write(1, "-2147483648", 11);
			dig += k;
		}
		else if (sp->minus)
		{
			k = (k > 1) ? k - 1 : 0;
			write(1, "-2147483648", 11);
			ft_put_n_chars(32, k);
			dig += (sp->numb > 11) ? k + 1 : k;
		}			
	}
	return(dig);
}

void ft_put_sign(int num)
{
	if (num == 1)
		write(1, "-", 1);
	else
		write(1, "+", 1);
}

int ft_put_d(int num, t_specif *sp)
{
	int dig;
	int l;
	int k;
	int n;
	
	dig = digits_in_base(num, 10);
//	 printf("dig = %d\n", dig);

//	print_sp(sp);
	// l = (sp->decim > dig) ? sp->decim - dig : 0;
	// k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;

	if (num == -2147483648)
		return (ft_put_int_min(num, sp));
	if (num < 0)
	{
		num = -num; //!INT_MIN
		sp->sign = 1;
	}
	if (!sp->numb && !sp->point) //просто %d, % d для пол/отр чисел
	{
		if ((sp->plus && num >= 0) || sp->sign)
			ft_put_sign(sp->sign);
		else if (sp->backsp && !sp->sign)
			write(1, " ", 1);
		if (sp->backsp || (sp->plus && num >= 0) || sp->sign)
			dig++;
		ft_putnbr_positive(num);
		return (dig);
	}
	else if (!sp->point) //!sp->sign means num > 0
	// %6d, %10d, %06d, %010d для полож чисел
	{
		k = (sp->numb > dig) ? sp->numb - dig : 0; //кол-во нулей либо пробелов
		if (sp->zero && !sp->minus) //нет '-' и есть '0'
		{
			if (sp->plus || sp->sign) //есть '+' либо число отриц
			{// %0+8d
				ft_put_sign(sp->sign);
				ft_put_n_chars(48, k - 1);
			}
			else if (!sp->sign && !sp->backsp) //полож 
				ft_put_n_chars(48, k);
			else if (!sp->sign && sp->backsp)
			{
				write(1, " ", 1);
				ft_put_n_chars(48, k - 1);	
			}
			ft_putnbr_positive(num);
		}
		else if (sp->backsp && !sp->minus) //есть ' ' и нет '-'
		{
			if (sp->plus || sp->sign)
			{
				ft_put_sign(num);
				ft_put_n_chars(32, k - 1);
			}
			else if (!sp->sign)
				ft_put_n_chars(32, k);
			ft_putnbr_positive(num);
		}
		else if (!sp->minus)
		{
			if (sp->sign || sp->plus)
				k--;
			ft_put_n_chars(32, k);
			if (sp->sign || sp->plus)
				ft_put_sign(sp->sign);
			ft_putnbr_positive(num);
		}
		else if (sp->minus)
		{
			if ((sp->backsp && !sp->sign) || sp->sign || (sp->plus && !sp->sign))
				k = (k > 1) ? k - 1 : 0;
			if (sp->backsp && !sp->sign)
				write(1, " ", 1);
			else if (sp->plus || sp->sign)
				ft_put_sign(sp->sign);
			ft_putnbr_positive(num);
			ft_put_n_chars(32, k);
		}			
		return (sp->numb);
	}


	return (0);
}

int		ft_put_parsed_integer_u(uint num, t_specif *sp)
{
	int		k;
	int		l;
	int		dig;
	int		n;

	if (sp->specif == 'u')
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->specif == 'o')
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->specif == 'x' || sp->specif == 'X')
		dig = digits_in_base_unsigned(num, 16);
	else if (sp->specif == 'd' || sp->specif == 'i')
	{
		return (ft_put_d((int)num, sp));
	}

//dig is number of digits. Afterthat, it's number of printed characters
//we compare it with sp->decim if it exists or with sp->numb otherwise
	if (sp->hash && sp->specif == 'o')
		dig = dig + 1;
	else if (sp->hash && (sp->specif == 'x' || sp->specif == 'X'))
		dig = dig + 2;
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;
	if (k < 0)
		k = 0;
	if (sp->zero && !sp->minus)
	{
		l += k;
		k = 0;
	}
	n = 0;
	if (sp->point && num == 0)
	{
		if (sp->specif == 'o' && sp->hash)
		{
			ft_put_n_chars(32, sp->numb - 1);
			write(1, "0", 1);
			return ((sp->numb > 0) ? sp->numb : 1);
		}
		else if (sp->specif == 'x' || sp->specif == 'X')
		{
			ft_put_n_chars(32, sp->numb - sp->decim);
			ft_put_n_chars(48, sp->decim);
			return ((sp->numb > sp->decim) ? sp->numb : sp->decim);
		}
		ft_put_n_chars(32, sp->numb);
		return (sp->numb);
	}
	if (!sp->minus)
	{
		ft_put_n_chars(32, k);
		n += ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
		n += ft_put_integer_u(num, sp);
	}
	else
	{
		n += ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
		n += ft_put_integer_u(num, sp);
		ft_put_n_chars(32, k);		
	}
//	print_sp(sp);
	return (n + k + l);
}

int		ft_put_backsp_str_minus(char *str, t_specif *sp)
{
	int n;
	int l;

	n = (int)ft_strlen(str);
	if (sp->point && sp->decim < n)
		l = sp->numb - sp->decim;
	else
		l = sp->numb - n;
	if (l < 0)
		l = 0;

	if (sp->point && sp->decim < n)
	{
		write(1, str, sp->decim);
		ft_put_n_chars(32, l);
		return (l + sp->decim);
	}
	else
	{
		write(1, str, n);
		ft_put_n_chars(32, l);
		return (l + n);
	}
}

int		ft_put_backsp_str(char *str, t_specif *sp)
{
	int n;
	int l;

	n = (int)ft_strlen(str);
	if (sp->point && sp->decim < n)
		l = sp->numb - sp->decim;
	else
		l = sp->numb - n;
	if (l < 0)
		l = 0;
	ft_put_n_chars(32, l);
	if (sp->point && sp->decim < n) //there is decimal point
	{
		write(1, str, sp->decim);
		return (l + sp->decim);
	} 	
	else
	{
		write(1, str, n);
		return (l + n);
	}
}

int		ft_put_string(char *str, t_specif *sp)
{
	int k;
	int n;
	int l;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (sp->minus)
		return (ft_put_backsp_str_minus(str, sp));
	else
		return (ft_put_backsp_str(str, sp));
}
