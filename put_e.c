#include "test_header.h"

//j is digit from which we will write.
//thus, if j is in "a"(whole part), we look the j - 1.
//otherwise, if j < 0 and it is in "s"(decimal part), we look the j + 1.
void normalize_sci(uint *a, uint *s, int j)
{
	uint y;
	int i;

	if (j < 0)
	{
		i = -j;
		// printf("i = %d\n", i);
		// printf("s[i] = %d\n", s[i]);
		// printf("s[i + 1] = %d\n", s[i + 1]);
		if (s[i + 1] > 4)
		{
			s[i]++;
			while (s[i] > 9 && i > 1)
			{
				s[i] -= 10;
				s[i - 1]++;
				i--;
			}
			if (i == 1)
				j = 1;
			else
				return ;
		}
	}
	if (j == 1 && s[1] > 9)
	{
		s[1] -= 10;
		a[1]++;
		y = a[1];
	}
	else if (j == 1)
	{
		i = 1;
		y = s[1];
	}
	else if (j > 1)
	{
		i = j;
		y = a[i - 1];
	}
	if (y > 4)
	{
		a[i]++;
		while (a[i] > 9)
		{
			a[i] -= 10;
			a[i + 1]++;
			i++;
		}
	}
	// print_memory(s);
	// printf("j = %d\n", j);
}

void ft_put_sign(t_s *sp)
{
	if (sp->sign)
		write(1, "-", 1);
	else if (sp->plus)
		write(1, "+", 1);
}

void ft_put_e_plus(char ch)
{
	if (ch == 'e')
		write(1, "e+", 2);
	else if (ch == 'E')
		write(1, "E+", 2);
}

int		ft_put_e_plus00(char ch)
{
	if (ch == 'e')
		write(1, "e+00", 4);
	else if (ch == 'E')
		write(1, "E+00", 4);
	return (4);
}

void	ft_put_e_minus(char ch)
{
	if (ch == 'e')
		write(1, "e-", 2);
	else if (ch == 'E')
		write(1, "E-", 2);
}

void	ft_add_e_exp_dig(int exp_)
{
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
	}
	else
		ft_putnbr_positive(exp_);
}

int ft_set_k_for_e(t_s *sp, int exp_, int *d)
{
	int k;

	if (exp_ < 100)
		*d = 2;
	else if (exp_ < 1000)
		*d = 3;
	k = sp->numb - (*d + 3 + sp->point);
	if (sp->point)
	k -= sp->decim + (sp->plus || sp->sign);
	if (k < 0)
		k = 0;
	if (k == 0 && sp->backsp)
		k = 1;
	if (!sp->zero)
		ft_put_n_chars(32, k);
	if (sp->zero && !sp->minus)
		ft_put_n_chars(48, k);
	return (k);
}

//help function for writing whole part in ..gr1
void ft_put_e_whole_gr(uint *a, int *addr_i, t_s *sp, int m1)
{
	ft_putchar(a[*addr_i] + '0');
	if (sp->decim > 0)
		write(1, ".", 1);
	*addr_i = *addr_i - 1;
	while (*addr_i >= m1 && *addr_i > 0)
	{
		ft_putchar(a[*addr_i] + '0');
		*addr_i = *addr_i - 1;
	}
}

void	ft_put_e_decim_gr(uint *s, int m1)
{
	int i;

	i = 1;
	while (i <= -m1)
	{
		ft_putchar(s[i] + '0');
		i++;
	}
}

void	ft_put_e_exp_gr(int exp_, int *addr_m1)
{
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
		*addr_m1 = *addr_m1 + 1;
	}
	else
		ft_putnbr_positive(exp_);
}


int put_scientific_gr_1(uint *a, uint *s, t_s *sp)
{
	int m1;  //кол-во взятых чисел из целой части, если m1 >= 1, иначе в том числе и кол-во из s
	int i;
	int exp_;
	int dig_exp_;
	int k;
	int count;

	count = 0;
	i = a[0];
	while (i && a[i] == 0)
		i--;
	exp_ = i - 1;
	m1 = (exp_ >= sp->decim) ? i - sp->decim : exp_ - sp->decim;
	normalize_sci(a, s, m1);
	if (a[i + 1] != 0)
	{
		exp_++;
		i++;
		m1++;
	}
	// write(1, "T", 1);
	if (sp->minus)
	{
		ft_put_sign(sp);
		ft_put_e_whole_gr(a, &i, sp, m1);
		ft_put_e_decim_gr(s, m1);
		ft_put_e_plus(sp->s);
		ft_put_e_exp_gr(exp_, &m1);
		k = ft_set_k_for_e(sp, exp_, &dig_exp_);
	}
	else
	{
		k = ft_set_k_for_e(sp, exp_, &dig_exp_);
		ft_put_sign(sp);
		ft_put_e_whole_gr(a, &i, sp, m1);
		ft_put_e_decim_gr(s, m1);
		ft_put_e_plus(sp->s);
		ft_put_e_exp_gr(exp_, &m1);
	}
	// write(1, "G", 1);

	count = k + (sp->plus || sp->sign) + 3 + dig_exp_;
	if (sp->decim > 0)
		count += sp->decim + 1;
	return (count);
}

//help function
void ft_put_e_whole(int *addr_exp_, uint *s, uint a, int *addr_flag)
{
	if (*addr_exp_ == 1 && s[*addr_exp_] == 0 && a == 1) //????
	{
		ft_putchar('1');
		*addr_exp_ = 0;
		*addr_flag = 1;
	}
	else if (s[*addr_exp_ - 1] == 1)
	{
		ft_putchar('1');
		*addr_exp_ = *addr_exp_ - 1;
	}
	else
		ft_putchar(s[*addr_exp_] + '0');
}

int put_scientific_less_1(uint *a, uint *s, t_s *sp)
{
	int	i;
	int	exp_; //negative power
	int	flag; //for 1.0000000e+00;
	int	count;
	int dig_exp_;
	int k;

	// write(1, "R", 1);
	flag = 0;
	count = 0;
	if (sp->sign)
	{
		write(1, "-", 1);
		count++;
	}
	i = s[0];
	i = 1;
	while (i <= s[0] && s[i] == 0)
		i++;
	exp_ = i;
	normalize_sci(a, s, -(exp_ + sp->decim));

	k = ft_set_k_for_e(sp, exp_, &dig_exp_);

	ft_put_e_whole(&exp_, s, a[1], &flag);
	if (sp->decim > 0)
		write(1, ".", 1);
	if (sp->decim > 0)
		count += 1 + sp->decim; //  "."
	i = exp_;
	while (++i <= exp_ + sp->decim)
		ft_putchar(s[i] + '0');
	if (flag)
		return (count += ft_put_e_plus00(sp->s));
	else 
		ft_put_e_minus(sp->s);
	ft_add_e_exp_dig(exp_);
	return(count + k + dig_exp_ + 3 + (sp->plus || sp->sign));
}

int ft_put_sci(double a, t_s *sp)
{
	int k;
	int n;
	t_long *lng;

	if (!(lng = create_long(a, sp)))
		return (0);
	if (a >= 1)
	 	return (put_scientific_gr_1(lng->whole, lng->decimal, sp));
	else
		return (put_scientific_less_1(lng->whole, lng->decimal, sp));
}


