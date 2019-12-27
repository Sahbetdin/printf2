#include "test_header.h"


void	ft_put_prelimenaries(long num, t_s *sp)
{
	if (sp->hash)
	{
		// if (sp->s == 'o' || 
		// 	(sp->s == 'h' && sp->s1 == 'o') ||
		// 	(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'o') ||
		// 	(sp->s == 'l' && sp->s1 == 'o') || 
		// 	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o'))
		// 	write(1, "0", 1);
		// else if (sp->s == 'x' ||
		// (sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'x') ||
		// (sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'x'))
		// 	write(1, "0x", 2);
		// else if (sp->s == 'X'||
		// (sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'X') ||
		// (sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'X'))
		// 	write(1, "0X", 2);
		if (sp->hash == 1)
			write(1, "0", 1);
		else if ((sp->s == 'x' || 
			(sp->s == 'h' && sp->s1 == 'x') ||
			(sp->s == 'l' && sp->s1 == 'x') ||			
			(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'x') ||
			(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'x')) && 
			sp->hash == 2)
			write(1, "0x", 2);	
		else if ((sp->s == 'X' || 
			(sp->s == 'h' && sp->s1 == 'X') ||
			(sp->s == 'l' && sp->s1 == 'X') ||
			(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'X') ||
			(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'X')) && 
			sp->hash == 2)
			write(1, "0X", 2);
	}
}


int ft_put_integer_u(ulong u_value, t_s *sp)
{
	int n;

	n = 0;
	if (sp->s == 'u' || (sp->s == 'l' && sp->s1 == 'u') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'u') ||
	(sp->s == 'h' && sp->s1 == 'u') ||
	(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'u'))
		n += ft_itoa_base_unsigned(u_value, 10, 0);
	else if (sp->s == 'o' ||
	(sp->s == 'h' && sp->s1 == 'o') ||
	(sp->s == 'l' && sp->s1 == 'o') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
	(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'o'))
		n += ft_itoa_base_unsigned(u_value, 8, 0);
	else if (sp->s == 'x' || 
		(sp->s == 'l' && sp->s1 == 'x') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'x') ||
		(sp->s == 'h' && sp->s1 == 'x') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'x'))
		n += ft_itoa_base_unsigned(u_value, 16, 0);
	else if (sp->s == 'X' ||
		(sp->s == 'l' && sp->s1 == 'X') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'X') ||
		(sp->s == 'h' && sp->s1 == 'X') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'X'))
		{
		n += ft_itoa_base_unsigned(u_value, 16, 1);
		}
//		printf("\nn = %d\n", n);
	return (n);
}

int ft_put_x_o(ulong num, t_s *sp)
{
	int n;
	int dig;
	int l;
	int k;
//casting first depending on siers.
//by default ulong is used
	if (sp->s == 'u' ||sp->s == 'o' ||
		sp->s == 'x' || sp->s == 'X')
		num = (uint)num;
	else if (sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X'))
		num = (unsigned short)num;
	else if (sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X' || sp->s2 == 'o'))
		num = (unsigned char)num;
	else if (sp->s == 'h' && (sp->s1 == 'o' || sp->s1 == 'u'))
		num = (unsigned short)num;
	
	if (sp->s == 'u' || (sp->s == 'l' && sp->s1 == 'u') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'u') ||
		(sp->s == 'h' && sp->s1 == 'u') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'u'))
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->s == 'o' ||
		(sp->s == 'l' && sp->s1 == 'o') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
		(sp->s == 'h' && sp->s1 == 'o') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'o'))
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->s == 'x' || sp->s == 'X' ||
		( (sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X'))) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X'))
		|| (sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X')))
		dig = digits_in_base_unsigned(num, 16);
	// printf("dig = %d\n", dig);
	
	if (sp->hash)
	{
		if (sp->s == 'x' || sp->s == 'X' ||
		(sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X')) ||
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X')))
			sp->hash = 2;
		if (num == 0 && (!sp->point || sp->hash == 2))
			sp->hash = 0;
		
	}
	// printf("dig = %d, l = %d, k = %d, sp->hash = %d\n",dig, l, k, sp->hash);
	
	if (sp->point)
	{
		if (num == 0)
			dig = 0;
		l = (sp->decim > dig) ? sp->decim - dig : 0;
		if (l > 2 && sp->hash == 1)
			l--;
		if (l == 0 && sp->hash == 1)
		{
			sp->hash = 0;
			l = 1;
		}
		k = (sp->numb > sp->decim) ? sp->numb: sp->decim;
//			if (num != 0)
		k -= dig + l + sp->hash;
		if (k < 0)
			k = 0;
		// printf("dig = %d, l = %d, k = %d\n",dig, l, k);


		if (sp->minus)
		{
			ft_put_prelimenaries(num, sp);
			ft_put_n_chars(48, l);
			if (num != 0)
				n = ft_put_integer_u(num, sp);
			ft_put_n_chars(32, k);
		}
		else
		{
			ft_put_n_chars(32, k);
			ft_put_prelimenaries(num, sp);
			ft_put_n_chars(48, l);
			if (num != 0)
				n = ft_put_integer_u(num, sp);
		}
	}
	else
	{

	// printf("sp->numb = %d\n", sp->numb);
		l = 0;
		k = (sp->numb > dig) ? sp->numb - dig : 0;
		k -= sp->hash;
		if (k < 0)
			k = 0;
		// printf("dig = %d, l = %d, k = %d, sp->hash = %d\n",dig, l, k, sp->hash);
		
		if (sp->minus)
		{
			ft_put_prelimenaries(num, sp);
			n = ft_put_integer_u(num, sp);
			ft_put_n_chars(32, k);
		}
		else
		{
		
// printf("dig = %d, l = %d, k = %d\n",dig, l, k);
			if (sp->zero)
			{
				ft_put_prelimenaries(num, sp);
				ft_put_n_chars(48, k);
			}
			else
			{
				ft_put_n_chars(32, k);

				// write(1, "FF\n", 3);

				ft_put_prelimenaries(num, sp);
				// write(1, "FF\n", 3);
				
			}
		//	printf("dig = %d, l = %d, k = %d\n",dig, l, k);
			n = ft_put_integer_u(num, sp);
		}
	}
//	print_sp(sp);
	return (n + k + l + sp->hash);
}