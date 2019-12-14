#include "test_header.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_put_zeros_backsp(t_specif *sp)
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

int	ft_putchar_c(char c, t_specif *sp)
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

int digits_in_base(int value, int base)
{
	int i;
	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

int digits_in_base_unsigned(uint u_value, int base)
{
	int i;

	i = 0;
	if (!u_value)
		return (1);
	while (u_value)
	{
		u_value /= base;
		i++;
	}
	return (i);
}

/*ONLY Positives */
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

int	ft_putnbr_u(unsigned int n)
{
	int i;

	i = 0;
	if (n > 9)
		i += ft_putnbr_positive(n / 10);
	ft_putchar(n % 10 + '0');
	i++;
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

void print_sp(t_specif *sp)
{
	printf("spec: %c\n", sp->specif);
	printf("zero: %d\n", sp->zero);
	printf("point: %d\n", sp->point);
	printf("numb: %d\n", sp->numb);
	printf("decim: %d\n", sp->decim);
	printf("plus: %d\n", sp->plus);
	printf("minus: %d\n", sp->minus);
	printf("backsp: %d\n", sp->backsp);
	printf("sign: %d\n", sp->sign);
	printf("hash: %d\n", sp->hash);
	return ;
}

void	clear_spec(t_specif *sp)
{
	sp->specif = '\0';
	sp->zero = 0;
	sp->point = 0;
	sp->numb = 0;
	sp->decim = -1;
	sp->plus = 0;
	sp->minus = 0;
	sp->backsp = 0;
	sp->sign = 0;
	sp->hash = 0;
	return ;
}

/* При поиске % мы можем пропускать числа, точку, пробел и таб.
Иначе если находим %, возвращаем указатель.
Иначе возвращаем НУЛЬ.
*/

/*during the search we skip backspace, tab, any number, +, -, # 
otherwise we return pointer to required letter or NULL */
char *find_spec(char *p, t_specif *sp)
{
	char *lett;

	lett = ft_strdup("diuoxXfFeEgGaAcspn%");
	while (*p)
	{
		if (*p == ' ' || *p == '\t' || *p == '.' || (*p >= '0' && *p <= '9')
		 || *p == '+' || *p == '-' || *p == '#')
 			p++;
		else if (ft_strchr(lett, *p))
		{
			sp->specif = *p;
			return (p); 
		}
		else
			return (NULL);
	}
	free(lett);
	return (NULL);
}

/*we search between p and s-1 */
/*we search before any letter or  */
void	set_zero(char *p, char *s, t_specif *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '+' || *p == '-' || *p == '#')
 			p++;
		else if (*p == '0')
		{
			sp->zero = *p;
			return ; 
		}
		else
			return ;
	}
	return ;
}

void	set_plus(char *p, char *s, t_specif *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '#' || *p == '0' || *p == '-')
//!!проверить по оригиналу, надо ли ПРПУСКАТЬ #!!!
 			p++;
		else if (*p == '+')
		{
			sp->plus = 1;
			return ;
		}
		else
			return ;
	}
	return ;
}

void	set_minus(char *p, char *s, t_specif *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '#' || *p == '0' || *p == '+')
//!!проверить по оригиналу, надо ли ПРПУСКАТЬ #!!!
 			p++;
		else if (*p == '-')
		{
			sp->minus = 1;
			return ;
		}
		else
			return ;
	}
	return ;
}


//!!!НАДО ИСКАТЬ НА ВСЕМ ПРОТЯЖЕНИИ ОТ p ДО p_spec
void	set_backsp(char *p, char *s, t_specif *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ')
		{
			sp->backsp = 1;
			return ;
		}
		else
			p++;

	}
	return ;
}

/*we search for point after we've searched for letter*/
/*we search between p and s-1 */
/*if found we set sp->point as 1 and return [pointer to '.'] */
char *set_point(char *p, char *s, t_specif *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || (*p >= '0' && *p <= '9') 
		|| *p == '+' || *p == '-' || *p == '#')
			p++;
		else if (*p == '.')
		{
			sp->point = 1;
			return (p);
		}
		else
			return (NULL);
	}
	return (NULL);
}

/*we input pointer next after % as p
and ptr_spec or (ptr_point?) as s */
void	set_numb(char *p, char *s, t_specif *sp)
{
	while (*p && p < s && (*p == ' ' || *p == '\t' 
		|| *p == '+' || *p == '-' || *p == '#' || *p == '0'))
			p++;
	sp->numb = ft_atoi(p);
}

/*works ONLY if point was found */
void	set_decimal(char *p, t_specif *sp)
{
	sp->decim = ft_atoi(p);
}

void	set_hash(char *p, char *s, t_specif *sp)
{
	while (*p && p < s)
	{
		if (*p == '#')
		{
			sp->hash = 1;
			return ;
		}
		else
			p++;

	}
	return ;
}

//сначала ищем букву. Ту, которая нужна, то есть находится в массиве...
// ищем ноль
// ищем плюс/минус
// ищем numb which is before.
// ищем точку
// ищем decimal part
// ищем хэш
char *parse_specifier(char *p, t_specif *sp)
{
	char *ptr_lett;
	char *ptr_point;
	char *ptr_zero;

	clear_spec(sp);
	if ((ptr_lett = find_spec(p, sp)))
	{
		set_zero(p, ptr_lett, sp);
		set_plus(p, ptr_lett, sp);
		set_minus(p, ptr_lett, sp);
		set_numb(p, ptr_lett, sp);
		set_backsp(p, ptr_lett, sp);
		set_hash(p, ptr_lett, sp);
		ptr_point = set_point(p, ptr_lett, sp);
	//	printf("POINTER TO POINT %p\n", ptr_point);
		if (ptr_point)
			set_decimal(ptr_point + 1, sp);
	}
	else
	{
		ft_putstr("error");
		ptr_lett = NULL;
	}
	return (ptr_lett);
}

/*
for capitals use lett_type = 1;
for small letters use lett_type = 0; 
*/
// НЕ НУЖЕН!
// int		ft_itoa_base(int value, int base, int lett_type)
// {
// 	char	*s;
// 	int		n;
// 	int		i;
// 	char	*letters;
// 	uint	new_value;

// 	new_value = (uint)value;
// 	n = digits_in_base(new_value, base);
// 	if (lett_type)
// 		letters = ft_strdup("0123456789ABCDEF");
// 	else 
// 		letters = ft_strdup("0123456789abcdef");
// 	// if (value < 0)
// 	// {
// 	// 	ft_putstr("HERE\n");
// 	// 	n += 1;
// 	// }
// 	s = (char *)malloc(sizeof(char) * (n + 1));
// 	// if (value < 0)
// 	// {
// 	// 	ft_putstr("AND HERE\n");
// 	// 	s[0] = '-';
// 	// 	value = -value;
// 	// }
// 	s[n] = '\0';
// 	i = n - 1;
// 	while (new_value)
// 	{
// 		s[i] = letters[new_value % base];
// 		new_value /= base;
// 		i--;
// 	}
// 	free(letters);
// 	ft_putstr(s);
// 	free(s);
// 	return (n);
// }



/*We use only for octal, thus no hex allowed*/
int		ft_itoa_base_unsigned(uint u_value, int base, int lett_type)
{
	char	*s;
	int		n;
	int		i;
	char	*letters;

	if (u_value == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (lett_type)
		letters = ft_strdup("0123456789ABCDEF");
	else 
		letters = ft_strdup("0123456789abcdef");
	n = digits_in_base_unsigned(u_value, base);
	s = (char *)malloc(sizeof(char) * (n + 1));
	s[n] = '\0';
	i = n - 1;
	while (u_value)
	{
		s[i] = letters[u_value % base];
		u_value /= base;
		i--;
	}
	ft_putstr(s);
	free(letters);
	free(s);
	return (n);
}