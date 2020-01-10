#include "test_header.h"

int ft_put_whole_double(double a, t_s *sp)
{
	int		k;
	int		l;
	int		n;
	int		dig;
	u_double num;

	if ((n = check_double_inf(a, sp))) //check if number is inf, -inf, nan
		return (n);
	if (a < 0)
	{
		sp->sign = 1;
		a = -a;
	}
	if (sp->s == 'e' || sp->s == 'E')
		return (ft_put_sci(a, sp));

	dig = digits_in_base((long)a, 10);
	if (!(sp->numb || sp->decim))
	{
		if (sp->plus && !sp->sign)
			write(1, "+", 1);
		else if (sp->backsp && !sp->sign)
			write(1, " ", 1);
		if (sp->sign)
			write(1, "-", 1);
		return ((sp->plus || sp->backsp || sp->sign) + ft_put_f_double(a, sp)); 
	}
	n = dig + (sp->plus || sp->backsp || sp->sign);
	if (sp->decim > 0)
		n += sp->decim + 1;
		// write(1, "WW", 2);
	if (sp->hash && sp->decim == 0)
		n += 1;
	k = (sp->numb > n) ? sp->numb - n : 0;
	if (sp->plus && sp->minus)
	{
		if (sp->sign)
			write(1, "-", 1);
		else
			write(1, "+", 1);
		ft_put_f_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (sp->plus && !sp->sign && sp->zero)
	{
		write(1, "+", 1);
		ft_put_n_chars(48, k);
		ft_put_f_double(a, sp);
	}
	else if (sp->plus && !sp->sign)
	{ //+6.5d, 232
		ft_put_n_chars(32, k);
		write(1, "+", 1);
		ft_put_f_double(a, sp);
	}
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
	{
		write(1, " ", 1);
		ft_put_f_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && sp->minus)
	{
		if (sp->sign)
			write(1, "-", 1);
		else if (sp->backsp)
			write(1, " ", 1);
		ft_put_f_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && sp->minus) //убрать в просто минус
	{
		if (sp->sign)
			write(1, "-", 1);
		ft_put_f_double(a, sp);
		ft_put_n_chars(32, k);
	}
	else if (!sp->plus && !sp->sign && sp->backsp)
	{
		write(1, " ", 1);
		if (sp->zero)
			ft_put_n_chars(48, k);
		else
			ft_put_n_chars(32, k);
		ft_put_f_double(a, sp);
	}
	else if (sp->sign && sp->zero) 
	{

		write(1, "-", 1);
		ft_put_n_chars(48, k);
		ft_put_f_double(a, sp);
	}
	else if (sp->sign && sp->backsp)
	{
		ft_put_n_chars(32, k);
		write(1, "-", 1);
		ft_put_f_double(a, sp);
	}
	else
	{
		if (sp->zero)
			ft_put_n_chars(48, k);
		else
			ft_put_n_chars(32, k);
		if (sp->sign)
			write(1, "-", 1);
		// write(1, "JJ", 2);
		ft_put_f_double(a, sp);
	}
	return (k + n);
}