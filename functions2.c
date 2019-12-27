#include "test_header.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_put_zeros_backsp(t_s *sp)
{
	if (sp->numb > 1)
	{

		if (sp->zero)
			ft_put_n_chars(48, sp->numb - 1);
		else
			ft_put_n_chars(32, sp->numb - 1);
	}
	else
		sp->numb = 1;
}

int	ft_putchar_c(char c, t_s *sp)
{
	int k;
	if (sp->minus)
	{
		write(1, &c, 1);
		ft_put_zeros_backsp(sp);
	}
	else
	{
		ft_put_zeros_backsp(sp);
		write(1, &c, 1);
	}
	return (sp->numb);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int abs_v(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int	ft_putstr(char const *s)
{
	int n;

	if (s)
	{
		n = (int)ft_strlen(s);
		write(1, s, n);
		return (n);
	}
	else
		return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	char	*p;
	size_t	i;
	size_t	n;

	i = 0;
	p = (char *)s1;
	while (p[++i])
		;
	n = i;
	if (!(tmp = (char *)malloc(sizeof(char ) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = p[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	ft_cut_backspaces(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' \
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
		i++;
	return (i);
}


int			ft_atoi(const char *str)
{
	int			i;
	long long	res;
	long long	sign;

	res = 0;
	i = 0;
	sign = 1;
	i += ft_cut_backspaces(&str[i]);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0 && sign == 1)
			return (-1);
		else if (res < 0 && sign == -1)
			return (0);
		i++;
	}
	return (sign * res);
}


int			ft_atoi2(const char *str, char *end)
{
	int			i;
	long long	res;
	long long	sign;

	res = 0;
	i = 0;
	sign = 1;
	i += ft_cut_backspaces(&str[i]);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str + i < end)
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0 && sign == 1)
			return (-1);
		else if (res < 0 && sign == -1)
			return (0);
		i++;
	}
	return (sign * res);
}

int digits_in_base(long long value, int base)
{
	int i;
	i = 0;

	if (value == 0)
		return (1);
//	write(1, "HERE\n", 5);
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}



int digits_in_base_unsigned(ulong u_value, int base)
{
	int i;

	i = 0;
	if (u_value == 0)
		return (1);
	while (u_value)
	{
		u_value /= base;
		i++;
	}
	return (i);
}



/*ONLY Positives and zero*/
int	ft_putnbr_positive(int n)
{
	int i;

	i = (n < 0) ? 1 : 0;
	if (n > 9)
		i += ft_putnbr_positive(n / 10);
	ft_putchar(n % 10 + '0');
	i++;
	return (i);
}


//переделать putnbr_positive, чтобы было
//без рекурсии
// использовать для вывода short, char
//делать cast в начале функции
//long
//long long
//то есть принимать long long, а 
//далее в зав-ти от sier кастить
//если hhd, lld, то дописывать d в конец выдачи
//


int        ft_putlong(long n)
{
	int     i;
	long    max_d;
	long    digit;

	i = 0;
	if (n < 0)
	{
	    ft_putchar('-');
	    n = -n;
	    i++;
	}
	max_d = 1;
	while (max_d <= n/10)
	    max_d *= 10;
	// printf("%ld\n", max_d);
	while (max_d)
	{
	    digit = n / max_d;
	    ft_putchar(digit + '0');
	    n -= max_d * digit;
	    max_d /= 10;
	    i++;
    }
    return (i);
}

int		ft_itoa_base_unsigned(ulong u_value, int base, int lett_type)
{
	char	*s;
	int		n;
	int		i;
	char	*letters;


//printf("%lx\n", u_value);
	if (u_value == 0)
	{
		ft_putchar('0');
		return (1);
	}
	// else if (sp->sign)
	// 	write(1, "-", 1);
// write(1, "GO!\n", 4);
	if (lett_type)
		letters = ft_strdup("0123456789ABCDEF");
	else 
		letters = ft_strdup("0123456789abcdef");
	n = digits_in_base_unsigned(u_value, base);

// write(1, "GO!\n", 4);
	// write(1, "Z", 1);
	// printf("\nn = %d\n", n);

// write(1,"G", 1);
	s = (char *)malloc(sizeof(char) * (n + 1));
	s[n] = '\0';
	i = n - 1;
	while (u_value)
	{
		s[i] = letters[u_value % base];
		u_value /= base;
		i--;
	}
	//  write(1, "R", 1);
	ft_putstr(s);
	free(letters);
	free(s);
	return (n);
}