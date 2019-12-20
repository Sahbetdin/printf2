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

void ft_put_long_long(long long num)
{
	long long c;
	long long m;
	int i;
	int dig;

	m = num;
	i = 0;
	c = 1;

	while (m > 9)
	{
		m /= 10;
		c *= 10;
		i++;
	}
	while (i >= 0)
	{
		dig = num / c;
		ft_putchar(dig + '0');
		num -= dig * c;
		c /= 10;
		i--;
	}
	return ;
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
			ft_put_n_chars(48, k);
			write(1, "2147483648", 10);
			dig += k;
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

int ft_put_d_withOUT_numb_point(int num, t_specif *sp)
{
	if (sp->plus && !sp->sign)
		write(1, "+", 1);
	else if (sp->backsp && !sp->sign)
		write(1, " ", 1);
	if (sp->sign)
		write(1, "-", 1);
	ft_put_long_long(num);
	return ((sp->plus || sp->backsp) + sp->sign);
}


int ft_put_d_with_numb_point(int num, t_specif *sp, int dig)
{
	int l;
	int k;

	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->decim > dig) ? sp->numb - sp->decim - (sp->sign || sp->plus): sp->numb - dig - (sp->sign || sp->plus);
	if (k < 0)
		k = 0;
//	write(1, "FF\n", 3);
	// if (sp->sign || sp->plus) // || sp->backsp
	// 	k--; убрал в выше
	if (sp->plus && !sp->sign && sp->minus)
	{
		write(1, "+", 1);
		ft_put_n_chars(48, l);
//		ft_putnbr_positive(num);
		ft_put_long_long(num);
		ft_put_n_chars(32, k);
	}
	else if (sp->plus && !sp->sign && sp->zero)
	{
		//write(1, "PP\n", 3);
		if (sp->point)
		{
			ft_put_n_chars(32, k);
			write(1, "+", 1);
		}
		else
		{
			write(1, "+", 1);
			ft_put_n_chars(48, k);
		}
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
		//ft_putnbr_positive(num);
	}
	else if (sp->plus && !sp->sign)
	{ //+6.5d, 232
		ft_put_n_chars(32, k);
		write(1, "+", 1);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
//		ft_putnbr_positive(num);
	}
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
	{
		k--;
		write(1, " ", 1);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
		//ft_putnbr_positive(num);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && !sp->sign && sp->zero && sp->backsp)
	{
		k--;
		write(1, " ", 1);
		ft_put_n_chars(32, k);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
//		ft_putnbr_positive(num);
	}
	else if (!sp->plus && !sp->sign && sp->minus)
	{
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
		//ft_putnbr_positive(num);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && !sp->sign && sp->backsp)
	{ // % 5d
	//		write(1, "CC\n", 3);
		if (k < 1)
			write(1, " ", 1);
		else
			ft_put_n_chars(32, k);
		k--;
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
//		ft_putnbr_positive(num);
	}
	else if (!sp->plus && !sp->sign && sp->zero)
	{
		// write(1, "JJ\n", 3);
	//printf("l = %d, k = %d, dig = %d, sp->sign = %d\n", l, k, dig, sp->sign);
		if (sp->point)
			ft_put_n_chars(32, k);		
		else
			ft_put_n_chars(48, k);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
//		ft_putnbr_positive(num);
	}
	else if (sp->sign && sp->minus)
	{
//		write(1, "EE\n", 3);
		write(1, "-", 1);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
//		ft_putnbr_positive(num);
		ft_put_n_chars(32, k);
	}
	else if (sp->sign && sp->zero) 
	{
//		write(1, "GG\n", 3);
		// if (sp->point)
		// 	ft_put_n_chars(32, k);
		// else
		// 	ft_put_n_chars(48, k);

		if (sp->point)
		{
			ft_put_n_chars(32, k);
			write(1, "-", 1);
		}
		else
		{
			write(1, "-", 1);
			ft_put_n_chars(48, k);
		}

		// write(1, "-", 1);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
//		ft_putnbr_positive(num);
	}
	else if (sp->sign && sp->backsp)
	{
//		write(1, "BB\n", 3);
//	printf("l = %d, k = %d, dig = %d, sp->sign = %d\n", l, k, dig, sp->sign);
		ft_put_n_chars(32, k);
		k--;
		write(1, "-", 1);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
//		ft_putnbr_positive(num);
	}
	else
	{
		ft_put_n_chars(32, k);
		if (sp->sign)
			write(1, "-", 1);
		ft_put_n_chars(48, l);
		if (!sp->numb && !sp->decim && num == 0)
			dig--;
		else
			ft_put_long_long(num);
			//ft_putnbr_positive(num);

	}
	return (dig + (sp->sign || sp->plus) + (sp->backsp) + l + k);
}

int ft_put_d(int num, t_specif *sp)
{
	int dig;
	int l;
	int k;
	int n;


	dig = digits_in_base(num, 10);
	if (num == -2147483648)
		return (ft_put_int_min(num, sp));
//	printf("dig = %d\n", dig);

	if (sp->specif == 'h' && sp->specif1 == 'd')
		write(1, "YES!\n", 5);

	if (num < 0)
	{
		num = -num; //!INT_MIN
		sp->sign = 1;
	}
	if (sp->numb || sp->point)
		return (ft_put_d_with_numb_point(num, sp, dig));
	else
		return (ft_put_d_withOUT_numb_point(num, sp) + dig);
	return (0);
}
