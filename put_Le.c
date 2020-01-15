#include "test_header.h"


//ниже x = 0 рассматривается отдельно
int ft_put_sci_LDBL(long double x, t_s *sp)
{
	int i;
	int j; //кол-во записанных в "arr" целых чисел
	t_long *lng;
	uint *arr; //new array where whole and decimal parts stored
	int count;
    u_long_dbl num;

	if (x == 0)
		return (ft_put_e_zero(sp));

    num.l_dbl = x;

    
    lng = ft_create_LONG_whole(&num);
	ft_create_LONG_decimal(lng, &num, sp->decim);

    // print_memory(lng->decimal);


	if (!(arr = create_one_array_e(lng)))
		return (0);
	j = ft_find_exp(lng);
	ft_fill_in_one_arr_e(arr, lng, j);
	j = ft_put_value_in_e(arr, sp, j);	
//write down exponent value
	count = 1 + 2 + (sp->plus || sp->sign); //целая часть и e+
	if (sp->decim > 0)
		count += sp->decim + 1; //точка
	return (count + ft_put_exp_value(j));
}

int ft_dig_LONG(long double a)
{
	int i;

	if (a < 1)
		return (1);
	i = 0;
	while (a >= 1)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int ft_get_k_for_e_LDBL(long double x, t_s *sp)
{
	int k;
	int dig;

	if (sp->decim > 0)
		sp->point = 1;
	else
		sp->point = 0;
	k = sp->numb - sp->decim - sp->point;
	dig = ft_dig_LDBL(x);
	if (dig < 100)
		k -= 2 + 3;
	else if (dig < 1000)
		k -= 3 + 3;
	if (sp->plus || sp->sign)
		k--;
	if (k < 0)
		k = 0;
   	if (k == 0 && sp->backsp)
		k = 1;
	return (k);
}

int ft_put_whole_sci_LDBL(long double x, t_s *sp)
{
	int n;
	int k;

	k = ft_get_k_for_e_LDBL(x, sp);
	if (sp->minus)
	{
		ft_put_sign(sp); 
		n = ft_put_sci_LDBL(x, sp);
		ft_put_n_chars(32, k);
		return (k + n);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_sign(sp);
		return (ft_put_sci_LDBL(x, sp) + k);
	}
}


/////////////////////
// int ft_put_sci_LDBL(long double x, t_s *sp);
// int ft_dig_LONG(long double a);
// int ft_get_k_for_e_LDBL(long double x, t_s *sp);
// int ft_put_whole_sci_LDBL(long double x, t_s *sp);
