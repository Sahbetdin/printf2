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
	else if (sp->minus && sp->backsp && sp->sign == '+')
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