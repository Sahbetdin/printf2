#include "test_header.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

int	ft_putnbr(int n)
{
	unsigned int	m;

	m = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	if (n < 0)
		ft_putchar('-');
	if (m > 9)
		ft_putnbr(m / 10);
	ft_putchar(m % 10 + '0');
	return (0);
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

int digits_in_base(int value, int base)
{
	int i;

	i = 0;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

int	ft_putdouble(double a, int prec)
{
	long d;
	int i;

	i = 0;
	if (a < 0)
	{
		ft_putchar('-');
		i++;
		a = -a;
	}
	d = a;
	i += ft_putlong(d);
	ft_putchar('.');
	i++;
 	while (prec)
 	{
 		a = (a - d) * 10;
 		d = a;
 		if (prec == 1)
 		{
			if ((a - (long)a) * 10 > 4)
				d += 1;
 		}
		ft_putchar(d + '0');
		i++;
 		prec--;
 	}
	ft_putchar('\n'); //потом убрать!
	return (i);
}

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

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0); 
}

int		ft_isspace2(char *p1, char *p2)
{
	while (*p1 && p1 < p2)
	{
		if (*p1 == ' ' || *p1 == '\t' || *p1 == '\n' || *p1 == '\v' || *p1 == '\f' || *p1 == '\r')
			return (1);
		p1++;
	}
	return (0);
}