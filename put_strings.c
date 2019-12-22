#include "test_header.h"


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

//22Dec 2019
int ft_put_null(t_specif *sp)
{
	int k;
	int n;

	if(sp->point)
		k = sp->numb - sp->decim;
	else
		k = sp->numb - 6;
	if (sp->minus)
	{
		if (sp->point)
			write(1, "(null)", sp->decim);
		else
			write(1, "(null)", 6);
		ft_put_n_chars(32, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		if (sp->point)
			write(1, "(null)", sp->decim);
		else
			write(1, "(null)", 6);
	}
	return (0);
}


int		ft_put_string(char *str, t_specif *sp)
{
	int k;
	int n;
	int l;

	if (!str)
		return (ft_put_null(sp));
	if (sp->minus)
		return (ft_put_backsp_str_minus(str, sp));
	else
		return (ft_put_backsp_str(str, sp));
}