#include "test_header.h"

int		ft_put_prelimenaries(uint num, t_specif *sp)
{
	if (sp->hash && num)
	{
		if (sp->specif == 'o')
		{
			write(1, "0", 1);
			return (1);
		}
		else if (sp->specif == 'x')
			write(1, "0x", 2);
		else if (sp->specif == 'X')
			write(1, "0X", 2);
		if (sp->specif == 'x' || sp->specif == 'X')
			return (2);
		else
			return (0);
	}
	else
		return (0);
}




/*except decimals*/
int		ft_put_parsed_integer_u(long num, t_specif *sp)
{
	int		k;
	int		l;
	int		dig;
	int		n;

	if (sp->specif == 'u')
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->specif == 'o')
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->specif == 'x' || sp->specif == 'X' ||
		(sp->specif == 'l' && sp->specif1 == 'x'))
{
		dig = digits_in_base_unsigned(num, 16);

}


	// else if (sp->specif == 'd' || sp->specif == 'i')
	// {
	// 	return (ft_put_d((int)num, sp));
	// }

//dig is number of digits. Afterthat, it's number of printed characters
//we compare it with sp->decim if it exists or with sp->numb otherwise
	if (sp->hash && sp->specif == 'o')
		dig = dig + 1;
	else if (sp->hash && (sp->specif == 'x' || sp->specif == 'X'))
		dig = dig + 2;
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;
	if (k < 0)
		k = 0;
	if (sp->zero && !sp->minus)
	{
		l += k;
		k = 0;
	}
	n = 0;
	if (sp->point && num == 0)
	{
		if (sp->specif == 'o' && sp->hash)
		{
			ft_put_n_chars(32, sp->numb - 1);
			write(1, "0", 1);
			return ((sp->numb > 0) ? sp->numb : 1);
		}
		else if (sp->specif == 'x' || sp->specif == 'X')
		{
			ft_put_n_chars(32, sp->numb - sp->decim);
			ft_put_n_chars(48, sp->decim);
			return ((sp->numb > sp->decim) ? sp->numb : sp->decim);
		}
		ft_put_n_chars(32, sp->numb);
		return (sp->numb);
	}
	if (!sp->minus)
	{
		ft_put_n_chars(32, k);
		n += ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
	//	printf("k = %d, l= %d\n", k, l);
	//	write(1, "TOE\n", 4);
		n += ft_put_integer_u(num, sp);
	//	write(1, "TOE\n", 4);
		
	}
	else
	{
		n += ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
		n += ft_put_integer_u(num, sp);
		ft_put_n_chars(32, k);		
	}
//	print_sp(sp);
	return (n + k + l);
}

int ft_put_integer_u(long u_value, t_specif *sp)
{
	int n;
	n = 0;
	if (sp->specif == 'u')
		n += ft_itoa_base_unsigned(u_value, 10, 0);
	else if (sp->specif == 'o')
		n += ft_itoa_base_unsigned(u_value, 8, 0);
	else if (sp->specif == 'x' || 
		(sp->specif == 'l' && sp->specif1 == 'x'))
	{
//		write(1, "HA\n", 3);
//		printf("THIS = %lx\n", u_value);
		n += ft_itoa_base_unsigned(u_value, 16, 0);
	}
	else if (sp->specif == 'X')
		n += ft_itoa_base_unsigned(u_value, 16, 1);
	return (n);
}