#include "test_header.h"


void ft_put_sign(t_s *sp)
{
	if (sp->sign)
		write(1, "-", 1);
	else if (sp->plus)
		write(1, "+", 1);
}


void ft_put_exp(char ch, int dig)
{
	if (ch == 'e')
		write(1, "e", 1);
	else if (ch == 'E')
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
	printf("j = %d\n", j);
	if (j <= 0)
	{
		i = 1;
		while (i < lng->decimal[0] && lng->decimal[i] == 0)
			i++;
		// if (i == lng->decimal[0])
		// 	return (0);
		// printf("i = %d\n", i);
		// printf("... = %d\n", lng->decimal[0]);
		j = -i;
	}
	return (j);          
}

// void	ft_one_array(double x, t_s *sp, )
// {
// 	uint *arr;
// 	t_long *lng;

// //create whole and decimal parts
// 	if (!(lng = create_long(x, sp)))
// 		return (0);
// 	arr = ft_find_exp(lng);
// //malloc and fill in with zeros
// // 	arr = (uint *)malloc(sizeof(uint) * (lng->whole[0] + lng->decimal[0] + 1));
// // 	arr[0] = lng->whole[0] + lng->decimal[0];
// // 	i = 0;
// // 	while (++i < arr[0])
// // 		arr[i] = 0;
// // //find exponent which is j
// // 	i = lng->whole[0];
// // 	while (i > 0 && lng->whole[i] == 0)
// // 		i--;
// // 	j = i;
	
// 	return (arr);
// }

void ft_fill_in_one_arr_e(uint *arr, t_long *lng, int j)
{
	int i;
	// printf("j = %d\n", j);

	if (j > 0)
	{
		i = j;
		// write(1, "KK\n",3);
		while (i > 0)
		{
			arr[lng->whole[0] - i] = lng->whole[i];
			i--;
		}
	printf("KK\n");
	print_memory(arr);
	printf("KK\n");
		i = 1;
		while (i < lng->decimal[0])
		{
			arr[j + i] = lng->decimal[i];
			i++;
		}

	}
	else
	{
		// i = 1;
		// while (i < lng->decimal[0] && lng->decimal[i] == 0)
		// 	i++;
		// j = -i;
		i = 1;
		while (i <= lng->decimal[0] + j)
		{
			arr[i] = lng->decimal[i - j - 1];
			i++;
		}
	}

}

int ft_put_e_zero(t_s *sp)
{
	if (sp->decim > 0)
		sp->point = 1;
	else
		sp->point = 0;
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
	int k;
	int n;
	int i;
	int j; //кол-во записанных в "arr" целых чисел
	t_long *lng;
	uint *a;
	uint *s;
	uint *arr; //new array where whole and decimal parts stored
	int count;

	if (x == 0)
		return (ft_put_e_zero(sp));
	if (!(lng = create_long(x, sp)))
		return (0);
	if (!(arr = create_one_array_e(lng)))
		return (0);
	j = ft_find_exp(lng);

	print_memory(lng->whole);
	// print_memory(arr);

//	print_memory(lng->decimal);
// 
	ft_fill_in_one_arr_e(arr, lng, j);
	ft_putstr("gf\n");


////
	//ft_put_arr_e(uint *arr, t_s *sp)
	i = 2;
	sp->decim++;
	normalize_sci(arr, sp->decim);
	ft_putchar(arr[1] + '0');
	if (sp->decim > 1)
		write(1, ".", 1);
	if (j >= 0)
	{
		while (i <= sp->decim)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
	}
	else
	{
		while (i <= sp->decim)
		{
			ft_putchar(arr[i] + '0');
			i++;
		}
	}
	sp->decim--;
	ft_put_exp(sp->s, j);
////

//write down exponent value
	count = 1 + 2 + (sp->plus || sp->sign || sp->backsp); //целая часть и e+
	if (sp->decim > 0)
		count += sp->decim + 1; //точка
	n = ft_put_exp_value(j);
	return (count + n);
}

// k = sp->numb - sp->decim - sp->point - 5;
// if (k < 0)
// 	k = 0;
// 		ft_put_n_chars(32, k);

