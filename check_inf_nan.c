#include "test_header.h"


//writes "inf" or "INF" depending on %f or %F specifier
int put_inf(t_s *sp)
{
	if (sp->s == 'f' || sp->s == 'e')
		write(1, "inf", 3);
	else if (sp->s == 'F' || sp->s == 'E')
		write(1, "INF", 3);
	return (3);
}

int put_DLNG_inf(t_s *sp)
{
	if (sp->s1 == 'f')
		write(1, "inf", 3);
	else if (sp->s1 == 'F')
		write(1, "INF", 3);
	return (3);

}


void ft_put_nan(t_s *sp)
{
	if (sp->s == 'f' || sp->s == 'e' || sp->s1 == 'f')
		write (1, "nan", 3);
	else if (sp->s == 'F' || sp->s == 'E' || sp->s1 == 'F')
		write (1, "NAN", 3);
}
//this function checks if the exponent is equal to 2047
//if yes then the number is candidate to NaN or inf
//if mantissa is 0 then it's inf. Otherwise, NaN.
int check_double_inf(double a, t_s *sp)
{
	u_double num;
	int i;
	int k;

	num.dbl = a;
	
	if (num.parts.exponent == 2047)
	{
		k = (sp->numb > 3 + (int)num.parts.sign) ? sp->numb - 3 - (int)num.parts.sign : 0;		
		ft_put_n_chars(32, k);
		i = 0;
		if (a < 0)
		{
			write(1, "-", 1);
			i++;
		}
		if (num.parts.mantissa == 0)
			return (put_inf(sp) + i + k);
		else
		{
			ft_put_nan(sp);
			return (3 + k);
		}
	}
	else
		return (0);
}

int check_DLNG_inf(u_long_dbl *num_DBL, t_s *sp)
{
	int i;
	int k;
	

	if (num_DBL->parts.exponent == 32767)
	{
		k = sp->numb - 3 - (int)num_DBL->parts.sign;
		ft_put_n_chars(32, k);
		i = 0;
		if (num_DBL->parts.sign)
		{
			write(1, "-", 1);
			i++;
		}
		if ((ulong)num_DBL->parts.mantissa == 1LU << 63)
			return (put_DLNG_inf(sp) + i + k);
		else
		{
			ft_put_nan(sp);
			return (3 + k);
		}
	}
	else
		return (0);
}