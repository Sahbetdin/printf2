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

	while (m > 9 || m < -9)
	{
		m /= 10;
		c *= 10;
		i++;
	}
	if (num < 0)
		c = -c;
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


int ft_put_int_min(int num, t_s *sp)
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

int ft_put_d_withOUT_numb_point(long long num, t_s *sp)
{
	if (sp->plus && !sp->sign)
		write(1, "+", 1);
	else if (sp->backsp && !sp->sign)
		write(1, " ", 1);
	if (sp->sign)
		write(1, "-", 1);
	ft_put_long_long(num);
	return (sp->plus || sp->backsp || sp->sign);
}


int ft_put_d_with_numb_point(long long num, t_s *sp, int dig)
{
	int l;
	int k;

	if (sp->point && num == 0)
		dig = 0;
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;
	k -= sp->sign || sp->plus;
	if (k < 0)
		k = 0;
	if (sp->plus && !sp->sign && sp->minus)
	{
		write(1, "+", 1);
		ft_put_n_chars(48, l);
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
		ft_put_n_chars(32, k);
	}
	else if (sp->plus && !sp->sign && sp->zero)
	{
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
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
	}
	else if (sp->plus && !sp->sign)
	{ //+6.5d, 232
		ft_put_n_chars(32, k);
		write(1, "+", 1);
		ft_put_n_chars(48, l);
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
	}
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
	{
		k--;
		write(1, " ", 1);
		ft_put_n_chars(48, l);
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && !sp->sign && sp->zero && sp->backsp)
	{
		write(1, " ", 1);
		if (k > 0)
			k--;
		if (sp->point)
		{
			ft_put_n_chars(32, k);
			ft_put_n_chars(48, l);
		}
		else
		{
			ft_put_n_chars(48, k);
		}
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
	}
	else if (!sp->plus && !sp->sign && sp->minus)
	{
		ft_put_n_chars(48, l);
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && !sp->sign && sp->backsp)
	{ // % 5d
		if (k < 1)
			write(1, " ", 1);
		else
			ft_put_n_chars(32, k);
		k--;
		ft_put_n_chars(48, l);
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
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
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
	}
	else if (sp->sign && sp->minus)
	{
//		write(1, "EE\n", 3);
		write(1, "-", 1);
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
		ft_put_n_chars(32, k);
	}
	else if (sp->sign && sp->zero) 
	{
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
		ft_put_n_chars(48, l);
		ft_put_long_long(num);
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
	}
	else
	{
	// printf("l = %d, k = %d, dig = %d, sp->sign = %d\n", l, k, dig, sp->sign);
	//	write(1, "YY\n", 3);
		ft_put_n_chars(32, k);
		if (sp->sign)
			write(1, "-", 1);
		ft_put_n_chars(48, l);
		if (!(sp->point && num == 0))
			ft_put_long_long(num);
	}
	return (dig + (sp->sign || sp->plus || sp->backsp) + l + k);
}




int ft_put_d(long long num, t_s *sp)
{
	int dig;
	int l;
	int k;
	int n;

	if (sp->s == 'h')
	{
		if (sp->s1 == 'd' || sp->s1 == 'i')
			num = (short)num;
		else if (sp->s1 == 'h' && (sp->s2 == 'd' || sp->s2 == 'i'))
			num = (char)num;
	}
	else if (sp->s == 'l')
	{
		if (sp->s1 == 'd')
			num = (long)num;
	}
	else if (sp->s == 'd' || sp->s == 'i')
		num = (int)num;
	dig = digits_in_base(num, 10);
	if (num == -2147483648)
		return (ft_put_int_min(num, sp));	
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
