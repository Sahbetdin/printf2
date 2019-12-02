#include "test_header.h"

void	ft_put_zeros(int n)
{
	if (n > 0)
	{
		while (n)
		{
			write(1, "0", 1);
			n--;
		}		
	}
}

void	ft_put_backspaces(int n)
{
	if (n > 0)
	{
		while (n)
		{
			write(1, " ", 1);
			n--;
		}		
	}
}

void	ft_put_sign(void)
{
	ft_putchar('-');
}

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
 		a = (a - d) * 10 + 0.000000001;
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
//	ft_putchar('\n'); //потом убрать!
	return (i);
}

int ft_put_whole_double(double a, t_specif *sp)
{
	int k;
	long	d; //the same 'a' but rounded

	if (a < 0)
	{
		sp->sign = 1;
		a = -a;
	}
	d = a;
	k = sp->numb - digits_in_base(d, 10) - 1 - sp->decim;
//	printf("k = %d\n", k);
//	printf("digits: %d\n", digits_in_base(d, 10));
	if (sp->backsp && a > 0)
	{
		ft_putchar(' ');
		k--;
	}
	else if (sp->minus && a < 0)
	{
		ft_putchar('-');
		k--;
	}
	if (sp->plus && a > 0)
		ft_putchar('+');
	if (sp->zero)
	{
		while (k)
		{
			ft_putchar('0');
			k--;
		}
	}

	ft_putdouble(a, sp);
//	if (sp->zero && !sp->plus)
	return (0);

}