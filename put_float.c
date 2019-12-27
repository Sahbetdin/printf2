#include "test_header.h"


/*PUTS ONLY POSITIVE NUMBERS! */
int		ft_putdouble(double a, t_s *sp)
{
	long	d; //the same 'a' but rounded
	int		i;

	d = a;
//	printf("\n d is %lu \n", d);
	i = ft_putlong(d);
	ft_putchar('.');
	i++;
	// printf("i = %d\n", i);
//	ft_putchar('\n');
 	while (sp->decim > 0)
 	{
 		printf("bef %.10f ", a);
 		a = (a - d) * 10 + 1.0e-9;
 		printf(", %.10f, %ld, %f \n", a, (long)a, (a - (long)a) * 10);
		d = a;
 		if (sp->decim == 1)
 		{
			if ((a - (long)a) * 10 > 5)
				d += 1;
 		}
// 		write(1, "JJ\n", 3);
		ft_putchar(d + '0');
		i++;
 		sp->decim--;
 	}
	return (i);
}



int get_exp(double a, t_s *sp)
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
	//ft_putnbr_positive(i);
	ft_put_long_long(i);
	return (i);
}

int		ft_putscientific(double a, t_s *sp)
{
//	print_sp(sp);
	get_exp(a, sp);
//	ft_putstr("HERE");
	return (0);
}
