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

void ft_put_e_minus(char ch)
{
	if (ch == 'e')
		write(1, "e-", 2);
	else if (ch == 'E')
		write(1, "E-", 2);
}

int put_scientific_gr_1(uint *a, uint *s, t_s *sp)
{
	int m1;  //кол-во взятых чисел из целой части, если m1 >= 1, иначе в том числе и кол-во из s
	int i;
	int exp_;
	int dig_exp_;
	int k;
	int count;

	i = a[0];
	while (i && a[i] == 0)
		i--;
	exp_ = i - 1;
	// printf("exp = %d\n", exp);
	m1 = (exp_ >= sp->decim) ? i - sp->decim : exp_ - sp->decim;
	// print_memory(a);
	// print_memory(s);
	// printf("m1 = %d\n", m1);
	normalize_sci(a, s, m1);
	// print_memory(a);
	// print_memory(s);

	if (a[i + 1] != 0)
	{
		exp_++;
		i++;
		m1++;
	}

//now work with exp_
	if (exp_ < 10)
		dig_exp_ = 1;
	else
		dig_exp_ = digits_in_base(exp_, 10);
	k = sp->numb - (dig_exp_ + 3 + (sp->plus || sp->sign));
	if (sp->decim > 0)
		k -= 1 + sp->decim;
	if (k < 0)
		k = 0;
	// printf("k = %d\n", k);
	if (sp->zero)
	{
		ft_put_sign(sp);
		ft_put_n_chars(48, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_sign(sp);
	}


	ft_putchar(a[i] + '0');
	if (sp->decim > 0)
		write(1, ".", 1);
	i--;
	while (i >= m1 && i > 0)
	{
		ft_putchar(a[i] + '0');
		i--;
	}
	i = 1;
	while (i <= -m1)
	{
		ft_putchar(s[i] + '0');
		i++;
	}
	ft_put_e_plus(sp->s);

	//optimize this:
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
		m1++;		
	}
	else
		ft_putnbr_positive(exp_);
	count = (sp->plus || sp->sign) + k + (sp->point && sp->decim);
	if (sp->decim > 0)
		count += sp->decim;
	if (exp_ < 10)
		return (6 + count);
	else
		return (3 + digits_in_base(exp_, 10) + count);
}


int put_scientific_less_1(uint *a, uint *s, t_s *sp)
{
	int	i;
	int	exp_; //negative power
	int	flag; //for 1.0000000e+00;
	int	count;
	int dig_exp_;
	int k;


	flag = 0;
	count = 0;
	if (sp->sign)
	{
		write(1, "-", 1);
		count++;
	}
	i = s[0];
	// print_memory(a);
	// print_memory(s);
	i = 1;
	while (i <= s[0] && s[i] == 0)
		i++;
	exp_ = i;
	normalize_sci(a, s, -(exp_ + sp->decim));
	// printf("exp_ = %d\n", exp_);
	// printf("s[exp_] = %d\n", s[exp_]);
	// print_memory(a);
	// print_memory(s);
	if (exp_ == 1 && s[exp_] == 0 && a[1] == 1)
	{
		ft_putchar('1');
		exp_ = 0;
		flag = 1;
	}
	else if (s[exp_ - 1] == 1)
	{
		ft_putchar('1');
		exp_--;
	}
	else
		ft_putchar(s[exp_] + '0');
//now we can work with exp_
	if (exp_ < 10)
		dig_exp_ = 1;
	else
		dig_exp_ = digits_in_base(exp_, 10);
	k = sp->numb - (dig_exp_ + 2 + sp->decim);
	if (k < 0)
		k = 0;
	// printf("k = %d\n", k);
///
	write(1, ".", 1);
	count += 2; // whole part 1 digit + "."
	i = exp_;
	while (++i <= exp_ + sp->decim)
		ft_putchar(s[i] + '0');
	count += sp->decim;
	if (flag)
	{
		if (sp->s == 'e')
			write(1, "e+00", 4);
		else if (sp->s == 'E')
			write(1, "E+00", 4);
		return (count + 4);	
	}
	else 
	{	
		ft_put_e_minus(sp->s);
		// if (sp->s == 'e')
		// 	write(1, "e-", 2);
		// else if (sp->s == 'E')
		// 	write(1, "E-", 2);
	}
	count += 2;
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
		count++;
	}
	else
		ft_putnbr_positive(exp_);

	return(count + dig_exp_);
}

int ft_if_sci(double a, t_s *sp)
{
	t_long *lng;

	if (!(lng = create_long(a, sp)))
		return (0);
	// print_memory(lng->decimal);
//	normalize_sci(lng->whole, lng->decimal, sp->decim);
	// print_memory(lng->whole);
	// print_memory(lng->decimal);
	if (a >= 1)
	 	return (put_scientific_gr_1(lng->whole, lng->decimal, sp));
	else
		return (put_scientific_less_1(lng->whole, lng->decimal, sp));
}

int ft_put_sci(double a, t_s *sp)
{
	int k;
	int n;
//здесь
//сделать флаги для "е"

	// n = 1 + (sp->plus || sp->backsp || sp->sign);
	// k = (sp->numb > n) ? sp->numb - n : 0;

	// if (!(sp->numb || sp->decim))
	// {
	// 	if (sp->plus && !sp->sign)
	// 		write(1, "+", 1);
	// 	else if (sp->backsp && !sp->sign)
	// 		write(1, " ", 1);
	// 	if (sp->sign)
	// 		write(1, "-", 1);
	// 	return ((sp->plus || sp->backsp || sp->sign) + ft_if_sci(a, sp)); 
	// }
	// else
	// {
		// if (sp->zero)
		// 	ft_put_n_chars(48, k);
		// else
		// 	ft_put_n_chars(32, k);
		// if (sp->sign)
		// 	write(1, "-", 1);
		// write(1, "JJ", 2);
		return (ft_if_sci(a, sp));
	// }
}


