#include "test_header.h"

int set_k_for_pointers(long num, t_s *sp)
{
	int k;
	int dig;
	
	if (num == 0)
	{
		if (sp->point)
			k = (sp->numb - 2 > sp->decim) ? sp->numb - sp->decim - 2 : 0;
		else
			k = (sp->numb > 3) ? sp->numb - 3 : 0;
	}
	else
	{
		dig = digits_in_base(num, 16) + 2;
		if (sp->point)
			k = (sp->decim > dig - 2) ? sp->numb - sp->decim - 2 : sp->numb - dig;
			// k = (sp->numb - 14 > sp->decim) ? sp->numb - sp->decim - 14 : 0;
		else
			k = (sp->numb > dig) ? sp->numb - dig : 0;
	}
	return (k);
}

int ft_put_p(long num, t_s *sp)
{
	int k;
	int l;
	int k1;

	k = set_k_for_pointers(num, sp);
	l = 0;
	if (sp->point)
		l = (sp->decim > 12) ? sp->decim - 12 : 0;
	if (sp->minus)
	{
		write(1, "0x", 2);
		k1 = ft_itoa_base_unsigned(num, 16, 0) + 2;
		ft_put_n_chars(48, l);		
		ft_put_n_chars(32, k);
		k += k1;
	}
	else
	{
		ft_put_n_chars(32, k);
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
		k += ft_itoa_base_unsigned(num, 16, 0) + 2;
	}
	return (k + l);
}
