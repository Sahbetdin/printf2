#include "test_header.h"

char *ft_search_for_float(char *ptr)
{
	char *s;

	if ((s = ft_strchr(ptr, 'f')))
		return (s);
	else if ((s = ft_strchr(ptr, 'F')))
		return (s);
	else if ((s = ft_strchr(ptr, 'e')))
		return (s);
	else if ((s = ft_strchr(ptr, 'E')))
		return (s);
	else if ((s = ft_strchr(ptr, 'g')))
		return (s);
	else if ((s = ft_strchr(ptr, 'G')))
		return (s);
	else if ((s = ft_strchr(ptr, 'a')))
		return (s);
	else if ((s = ft_strchr(ptr, 'A')))
		return (s);
	else
		return (NULL);
}

char *ft_search_for_int(char *ptr)
{
	char *s;
	if ((s = ft_strchr(ptr, 'd')))
		return (s);
	else if ((s = ft_strchr(ptr, 'i')))
		return (s);
	else
		return (NULL);
}

char *ft_search_for_uint(char *ptr)
{
	char *s;
	if ((s = ft_strchr(ptr, 'u')))
		return (s);
	else
		return (NULL);
}

char *ft_search_for_oct(char *ptr)
{
	char *s;
	if ((s = ft_strchr(ptr, 'o')))
		return (s);
	else
		return (NULL);
}

char *ft_search_for_hex(char *ptr)
{
	char *s;
	if ((s = ft_strchr(ptr, 'x')))
		return (s);
	else
		return (NULL);
}

char *ft_search_for_HEX(char *ptr)
{
	char *s;
	if ((s = ft_strchr(ptr, 'X')))
		return (s);
	else
		return (NULL);
}


char *ft_search_point(char *ptr_start, char *ptr_end)
{
	char *s;

	s = ptr_start;
	while (s < ptr_end && *s)
	{
		if (*s == '.')
			return (s);
		s++;
	}
	return (NULL);
}

char *ft_search_zero(char *ptr_start, char *ptr_end)
{
	char *s;

	if (*ptr_start == '0')
		return (ptr_start);	
	s = ptr_start;
	while (s < ptr_end && *(s + 1))
	{
		if (*s == ' ' && *(s + 1) == '0')
			return (s + 1);
		s++;
	}
	return (NULL);
}

int ft_printf(char *fmt, ...)
{
	va_list ap;
	char *p;
	double x;
	char *p_spec;
	char *p_point;
	char *p_zero;
	int ret;
	int n;
	int m;
	int temp;
	int numb;

	va_start(ap, fmt);
	p = fmt;
	ret = 0;
	while (*p)
	{
		if (*p != '%')
		{
			ft_putchar(*p);
			ret++;

		}
		else
		{
			p++;
			p_spec = ft_search_for_float(p);
//			printf("p_spec: %p\n", p_spec);
			if (p_spec)
			{
				p_point = ft_search_point(p, p_spec);
				m = ft_atoi2(p_point + 1, p_spec);
				p_zero = ft_search_zero(p, p_point);
				if (p_zero)
					n = ft_atoi2(p_zero + 1, p_point);
				else
					n = ft_atoi2(p, p_point);
				x = va_arg(ap, double);
				/*
				если ноль идет сразу же после %, то ставим нули впереди [нужное количество] 
				если (между % и 0) или (между % и .) есть пробелы, то вначале пишем один пробел и 
				далее заполняем нулями 
				*/
				temp = n - m - 1 - digits_in_base((int)x, 10);
	//			printf("temp: %d %d %d\n", n, m, digits_in_base((int)x, 10));
				printf("temp: %d \n", temp);

	//			printf("%p\n", p);
	//			printf("%p\n", p_point);
	//			printf("%ld\n", p_point - p);
				if (p_zero && p == p_zero && !ft_isspace2(p, p_point)) //ноль идет сразу же после %
				{
					while (temp)
					{
						ft_putchar('0');
						ret++;
						temp--;
					}
				}
				else if (p_zero && ft_isspace2(p, p_point))
				{
					ft_putchar(' ');
					ret++;
					while (temp > 1) // можно было написать temp-- и цикл до 0
					{
						ft_putchar('0');
						ret++;
						temp--;
					}
				}
				else
				{
					while (temp > 0) //заполняем пробелами
					{
						ft_putchar(' ');
						ret++;
						temp--;
					}				
				}
				
				ret += ft_putdouble(x, m);
				p = p_spec; //чтобы не печатать то, что было в specifier, мы уходим дальше
	//			printf("after: %p\n", p);
			}
			p_spec = ft_search_for_float(p);
			if (p_spec)
			{
				numb = va_arg(ap, )
			}



//			if (*p //is number)
			//1. we need to find specifier and its parameters.
			//2.
//			continue;
			// if (*p == 'd')
			// 	ret += ft_putnbr(va_arg(ap, int));
			// else if (*p == 'c')
			// 	ret += ft_putchar(va_arg(ap, int));
			// else if (*p == 's')
			// 	ret += ft_putstr(va_arg(ap, char *));
		}
		p++;
	}
	va_end(ap);
	return (ret);
}
