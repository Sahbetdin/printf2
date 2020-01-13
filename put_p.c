#include "test_header.h"

int set_k_for_pointers(long num, t_s *sp, int dig)
{
	int k;
	
		// if (sp->point)
		// 	k = (sp->numb > dig + 2) ? sp->numb - dig - 2 : 0;
		// 	// k = (sp->numb - 14 > sp->decim) ? sp->numb - sp->decim - 14 : 0;
		// else
		// 	k = (sp->numb > dig + 2) ? sp->numb - dig - 2 : 0;
			k = (sp->numb > dig + 2) ? sp->numb - dig - 2 : 0;
	return (k);
}

int ft_put_p_zero(t_s *sp)
{
	int k;
	int l;

	l = (sp->point > 0) ? sp->decim : 1;
	if (sp->point)
		k = (sp->numb > sp->decim + 2 + l) ? sp->numb - sp->decim - 2 - l : 0;
	else
		k = (sp->numb > 2 + l) ? sp->numb - 2 - l : 0;
	// printf("k = %d, l = %d\n", k, l);
	if (sp->minus)
	{
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
		ft_put_n_chars(32, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
	}
	return (k + l + 2);
}

int ft_put_p(long num, t_s *sp)
{
	int k;
	int l;
	int k1;
	int dig;

	if (num == 0)
		return (ft_put_p_zero(sp));
	dig = digits_in_base(num, 16);
	// printf("dig = %d\n", dig);

	// k = set_k_for_pointers(num, sp, dig);
	// // printf("k! = %d\n", k);

	// if (sp->point)
	// 	// l = (sp->decim > dig + 1) ? sp->decim - dig - 1: 0;
	// 	l = (k > 0 && sp->decim > dig + 2) ? sp->decim - dig: 0;
	// // printf("k = %d, l = %d\n", k, l);
	// k -= l;
//видимо l главнее
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->numb > dig + 2) ? sp->numb - dig - 2 : 0;

	if (sp->minus)
	{
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
		if (num != 0)
		{
			k1 = ft_itoa_base_unsigned(num, 16, 0) + 2;
		}
		else
		{
			return (2 + k);		
		}
		ft_put_n_chars(32, k);
		k += k1;
	}
	else
	{
	// printf("k = %d, l = %d\n", k, l);
		ft_put_n_chars(32, k);
		write(1, "0x", 2);
		ft_put_n_chars(48, l);
		if (num != 0)
			k += ft_itoa_base_unsigned(num, 16, 0) + 2;
		else
			return (2 + k);
	}
	return (k + l);
}
