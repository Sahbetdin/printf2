#include "test_header.h"


void ft_put_sign(t_s *sp)
{
	if (sp->sign)
		write(1, "-", 1);
	else if (sp->plus)
		write(1, "+", 1);
}


void ft_put_exp(t_s *sp, int dig)
{
	if (sp->s == 'e' || sp->s1 == 'e')
		write(1, "e", 1);
	else if (sp->s == 'E' || sp->s1 == 'E')
		write(1, "E", 1);
	if (dig < 0)
		write(1, "-", 1);
	else
		write(1, "+", 1);
}

int ft_put_exp_value(int exp_)
{
	// printf("exp_ = %d\n", exp_);
	if (exp_ < 0)
		exp_ = -exp_;
	else
		exp_ -= 1;
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
	}
	else
		ft_putnbr_positive(exp_);
	if (exp_ < 100)
		return (2);
	else if (exp_ < 1000)
		return (3);
	else if (exp_ < 10000)
		return (4);
	else
		return (5);
}


//s это не ДЕСЯТАЯ ЧАСТЬ, это элемент объединенного массива
void normalize_sci(uint *s, int d)
{
	int i;

	i = d;
	if (s[i + 1] > 4)
	{
		s[i]++;
		while (s[i] > 9 && i > 1)
		{
			s[i] -= 10;
			s[i - 1]++;
			i--;
		}
	}
}


//we create new array "arr" where whole and decimal parts stored
uint *create_one_array_e(t_long *lng)
{
	uint *arr;
	int i;

	if (!(arr = (uint *)malloc(sizeof(uint) * (lng->whole[0] + lng->decimal[0] + 1))))
		return (NULL);
	arr[0] = lng->whole[0] + lng->decimal[0];
	//malloc and fill in with zeros

	i = 0;
	while (++i < arr[0])
		arr[i] = 0;

	return (arr);
}


//!! if (j == s[0] - 1) is still an open question.
//possibly just make function for x = 0.0
int ft_find_exp(t_long *lng)
{
	int i;
	int j;
//find exponent which is j

	i = lng->whole[0];
	while (i > 0 && lng->whole[i] == 0)
		i--;
	j = i;
	// printf("j = %d\n", j);
	if (j <= 0)
	{
		i = 1;
		while (i < lng->decimal[0] && lng->decimal[i] == 0)
			i++;
		j = -i;
	}
	return (j);          
}

void ft_fill_in_one_arr_e(uint *arr, t_long *lng, int j)
{
	int i;
	int k;

	if (j > 0)
	{
		i = j + 1;
		while (--i > 0)
			arr[j - i + 1] = lng->whole[i];
		i = 1;
		while (i < lng->decimal[0])
		{
			arr[j + i] = lng->decimal[i];
			i++;
		}
	}
	else
	{
		// printf("j = %d\n", j);
		// print_memory(lng->decimal);
		i = 1;
		while (i <= lng->decimal[0] + j)
		{
			// ft_putnbr_positive(i);
			// write(1, " ", 1);
			// ft_putnbr_positive(lng->decimal[i - j - 1]);
			// write(1, "\n", 1);

			arr[i] = lng->decimal[i - j - 1];
			i++;

		}
		// print_memory(lng->decimal);
		// print_memory(arr);
	}
}


int ft_put_value_in_e(uint *arr, t_s *sp, int j)	
{
	int dig;
	int i;

	dig = sp->decim + 1;
	normalize_sci(arr, dig);
	if (arr[1] > 9)
	{
		ft_putchar('1');
		if (dig > 1)
			write(1, ".", 1);
		ft_put_n_chars(48, dig - 1);
		j++;
	}
	else
	{
		ft_putchar(arr[1] + '0');
		if (dig > 1)
			write(1, ".", 1);
		i = 1;
		while (++i <= dig)
			ft_putchar(arr[i] + '0');
	}
	free(arr);
	// sp->decim--;
	ft_put_exp(sp, j);
	return (j);
}

int ft_put_e_zero(t_s *sp)
{
	write(1, "0", 1);
	if(sp->decim > 0)
	{
		write(1, ".", 1);
		ft_put_n_chars(48, sp->decim);			
	}
	if (sp->s == 'e')
		write(1, "e+00", 4);
	else if (sp->s == 'E')
		write(1, "E+00", 4);
	return (sp->point + sp->decim + 5);
}

//ниже x = 0 рассматривается отдельно
int ft_put_sci(double x, t_s *sp)
{
	int i;
	int j; //кол-во записанных в "arr" целых чисел
	t_long *lng;
	uint *arr; //new array where whole and decimal parts stored
	int count;

	if (x == 0)
		return (ft_put_e_zero(sp));
	if (!(lng = create_long(x, sp)))
		return (0);
    // print_memory(lng->decimal);

	if (!(arr = create_one_array_e(lng)))
		return (0);
	j = ft_find_exp(lng);
	ft_fill_in_one_arr_e(arr, lng, j);
	j = ft_put_value_in_e(arr, sp, j);

    // print_memory(lng->decimal);
	// print_memory(arr);


//write down exponent value
	count = 1 + 2 + (sp->plus || sp->sign); //целая часть и e+
	if (sp->decim > 0)
		count += sp->decim + 1; //точка
	return (count + ft_put_exp_value(j));
}

int ft_dig_db(double a)
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

int ft_get_k_for_e(double x, t_s *sp)
{
	int k;
	int dig;

	if (sp->decim > 0)
		sp->point = 1;
	else
		sp->point = 0;
	k = sp->numb - sp->decim - sp->point;
	dig = ft_dig_db(x);
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

int ft_put_whole_sci(double x, t_s *sp)
{
	int n;
	int k;

	k = ft_get_k_for_e(x, sp);
	if (sp->minus)
	{
		ft_put_sign(sp); 
		n = ft_put_sci(x, sp);
		ft_put_n_chars(32, k);
		return (k + n);
	}
	else
	{
		printf("k = %d \n", k);
		ft_put_n_chars(32, k);
		
		ft_put_sign(sp);
		return (ft_put_sci(x, sp) + k);
	}
}


/////////
// void ft_put_sign(t_s *sp);
// void ft_put_exp(t_s *sp, int dig);
// int ft_put_exp_value(int exp_);
// void normalize_sci(uint *s, int d);
// uint *create_one_array_e(t_long *lng);
// int ft_find_exp(t_long *lng);
// void ft_fill_in_one_arr_e(uint *arr, t_long *lng, int j);
// int ft_put_value_in_e(uint *arr, t_s *sp, int j);
// int ft_put_e_zero(t_s *sp);
// int ft_put_sci(double x, t_s *sp);
// int ft_dig_db(double a);
// int ft_get_k_for_e(double x, t_s *sp);
// int ft_put_whole_sci(double x, t_s *sp);

