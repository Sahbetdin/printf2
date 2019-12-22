#include "test_header.h"

//old one
// int		ft_put_prelimenaries(uint num, t_specif *sp)
// {
// 	if (sp->hash && num)
// 	{
// 		if (sp->specif == 'o')
// 		{
// 			write(1, "0", 1);
// 			return (1);
// 		}
// 		else if (sp->specif == 'x')
// 			write(1, "0x", 2);
// 		else if (sp->specif == 'X')
// 			write(1, "0X", 2);
// 		if (sp->specif == 'x' || sp->specif == 'X')
// 			return (2);
// 		else
// 			return (0);
// 	}
// 	else
// 		return (0);
// }

void	ft_put_prelimenaries(long num, t_specif *sp)
{
	if (sp->hash)
	{
		if (sp->specif == 'o')
			write(1, "0", 1);
		else if (sp->specif == 'x' ||
		(sp->specif == 'l' && sp->specif1 == 'l' && sp->specif2 == 'x') ||
		(sp->specif == 'h' && sp->specif1 == 'h' && sp->specif2 == 'x'))
			write(1, "0x", 2);
		else if (sp->specif == 'X'||
		(sp->specif == 'l' && sp->specif1 == 'l' && sp->specif2 == 'X') ||
		(sp->specif == 'h' && sp->specif1 == 'h' && sp->specif2 == 'X'))
			write(1, "0X", 2);
	}
}


int ft_put_integer_u(ulong u_value, t_specif *sp)
{
	int n;

	n = 0;
	if (sp->specif == 'u' || (sp->specif == 'l' && sp->specif1 == 'u') ||
	(sp->specif == 'l' && sp->specif1 == 'l' && sp->specif2 == 'u'))
		n += ft_itoa_base_unsigned(u_value, 10, 0);
	else if (sp->specif == 'o')
		n += ft_itoa_base_unsigned(u_value, 8, 0);
	else if (sp->specif == 'x' || 
		(sp->specif == 'l' && sp->specif1 == 'x') ||
		(sp->specif == 'l' && sp->specif1 == 'l' && sp->specif2 == 'x') ||
		(sp->specif == 'h' && sp->specif1 == 'x') ||
		(sp->specif == 'h' && sp->specif1 == 'h' && sp->specif2 == 'x'))
		n += ft_itoa_base_unsigned(u_value, 16, 0);
	else if (sp->specif == 'X' ||
		(sp->specif == 'l' && sp->specif1 == 'X') ||
		(sp->specif == 'l' && sp->specif1 == 'l' && sp->specif2 == 'X') ||
		(sp->specif == 'h' && sp->specif1 == 'h' && sp->specif2 == 'X'))
		{
		n += ft_itoa_base_unsigned(u_value, 16, 1);

		}
	return (n);
}

//(sp->specif == 'h' && sp->specif1 == 'h' && sp->specif2 == 'X')

int ft_put_x_o(ulong num, t_specif *sp)
{
	int n;
	int dig;
	int l;
	int k;
//casting first depending on specifiers.
//by default ulong is used
	if (sp->specif == 'u' ||sp->specif == 'o' ||
		sp->specif == 'x' || sp->specif == 'X')
		num = (uint)num;
	else if (sp->specif == 'h' && (sp->specif1 == 'x' || sp->specif1 == 'X'))
		num = (short)num;
	else if (sp->specif == 'h' && sp->specif1 == 'h' && (sp->specif2 == 'x' || sp->specif2 == 'X'))
		num = (char)num;
	
	if (sp->specif == 'u' || (sp->specif == 'l' && sp->specif1 == 'u')
	|| (sp->specif == 'l' && sp->specif1 == 'l' && sp->specif2 == 'u'))
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->specif == 'o')
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->specif == 'x' || sp->specif == 'X' ||
		( (sp->specif == 'l' && (sp->specif1 == 'x' || sp->specif1 == 'X'))) ||
		(sp->specif == 'l' && sp->specif1 == 'l' && (sp->specif2 == 'x' || sp->specif2 == 'X'))
		|| (sp->specif == 'h' && sp->specif1 == 'x') ||
		(sp->specif == 'h' && sp->specif1 == 'h' && (sp->specif2 == 'x' || sp->specif2 == 'X')))
		dig = digits_in_base_unsigned(num, 16);
	// printf("dig = %d\n", dig);
	
	if (sp->hash)
	{
		if (sp->specif == 'x' || sp->specif == 'X' ||
		(sp->specif == 'l' && sp->specif1 == 'l' && (sp->specif2 == 'x' || sp->specif2 == 'X')) ||
		(sp->specif == 'h' && sp->specif1 == 'h' && (sp->specif2 == 'x' || sp->specif2 == 'X')))
			sp->hash = 2;
		if (num == 0 && (!sp->point || sp->hash == 2))
			sp->hash = 0;
		
	}
	// printf("dig = %d, l = %d, k = %d\n",dig, l, k);
	
	if (sp->point)
	{
		if (num == 0)
			dig = 0;
		l = (sp->decim > dig) ? sp->decim - dig : 0;
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
				ft_put_integer_u(num, sp);
			ft_put_n_chars(32, k);
		}
		else
		{
			ft_put_n_chars(32, k);
			ft_put_prelimenaries(num, sp);
			ft_put_n_chars(48, l);
			if (num != 0)
				ft_put_integer_u(num, sp);
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
		
		if (sp->minus)
		{
			ft_put_prelimenaries(num, sp);
			ft_put_integer_u(num, sp);
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
				ft_put_prelimenaries(num, sp);
			}
		//	printf("dig = %d, l = %d, k = %d\n",dig, l, k);
			ft_put_integer_u(num, sp);
		}
	}
//	print_sp(sp);
	return (dig + k + l + sp->hash);
}