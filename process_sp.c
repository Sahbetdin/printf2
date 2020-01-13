#include "test_header.h"


void print_sp(t_s *sp)
{
	printf("spec: %c\n", sp->s);
	printf("spec1: %c\n", sp->s1);
	printf("spec2: %c\n", sp->s2);
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

void	clear_spec(t_s *sp)
{
	sp->s = '\0';
	sp->s1 = '\0';
	sp->s2 = '\0';
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
char *find_spec(char *p, t_s *sp)
{
	char *lett;

	lett = ft_strdup("diuolhxXfFLeEgGaAcspnVW%");
	while (*p)
	{
		if (*p == ' ' || *p == '\t' || *p == '.' || (*p >= '0' && *p <= '9')
		 || *p == '+' || *p == '-' || *p == '#')
 			p++;
		else if (ft_strchr(lett, *p))
		{
			sp->s = *p;
			if (*p == 'l')
			{
				sp->s1 = *(p + 1);
				if (sp->s1 == 'l')
					sp->s2 = *(p + 2);
			}
			else if (*p == 'h')
			{
				sp->s1 = *(p + 1);
				if (sp->s1 == 'h')
					sp->s2 = *(p + 2);
			}
			else if (*p == 'L')
				sp->s1 = *(p + 1);
			free(lett);
			return (p); 
		}
		else
		{
			free(lett);
			return (NULL);
		}
	}
	free(lett);
	return (NULL);
}

/*we search between p and s-1 */
/*we search before any letter or  */
void	set_zero(char *p, char *s, t_s *sp)
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

void	set_plus(char *p, char *s, t_s *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '#' || *p == '0' || *p == '-')
 		{
 			p++;
 		}
		else if (*p == '+')
		{
//			write(1, "U\n", 2);
			sp->plus = 1;
//			print_sp(sp);
			return ;
		}
		else
			return ;
	}
//	return ;
}

void	set_minus(char *p, char *s, t_s *sp)
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
void	set_backsp(char *p, char *s, t_s *sp)
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
char *set_point(char *p, char *s, t_s *sp)
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
void	set_numb(char *p, char *s, t_s *sp)
{
	while (*p && p < s && (*p == ' ' || *p == '\t' 
		|| *p == '+' || *p == '-' || *p == '#' || *p == '0'))
			p++;
	sp->numb = ft_atoi(p);
}

/*works ONLY if point was found */
void	set_decimal(char *p, t_s *sp)
{
	sp->decim = ft_atoi(p);
}

void	set_hash(char *p, char *s, t_s *sp)
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
char *parse_sier(char *p, t_s *sp)
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
		else if (sp->s == 'f' || sp->s == 'e' || sp->s == 'F' || sp->s == 'E' 
			|| ((sp->s == 'L' || sp->s == 'l') && sp->s1 == 'f'))
			sp->decim = 6;
	}
	else
	{
		// ft_putstr("error");
		ptr_lett = NULL;
	}
	return (ptr_lett);
}

//еще pointers распечатать!!!!!
//надо сделать oct float bonus!!
int	process_specifier(char *ptr, t_s *sp, va_list ap)
{
	int i;
	int l;
	int k;

	if (sp->s == 'u' || sp->s == 'x' 
	|| sp->s == 'X' || sp->s == 'o' ||
	(sp->s == 'l' && sp->s1 == 'u') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'u') ||
	(sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
	(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X')) ||
	(sp->s == 'l' && sp->s1 == 'o') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
	(sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
	(sp->s == 'h' && sp->s1 == 'o') ||
	(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X' || sp->s2 == 'o' || sp->s2 == 'u')) ||
	(sp->s == 'h' && sp->s1 == 'u'))
	{
		return (ft_put_x_o(va_arg(ap, ulong), sp));
	}
	else if (sp->s == 'd' || sp->s == 'i' ||
		(sp->s == 'h' && (sp->s1 == 'd' || sp->s1 == 'i')) || 
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'd' || sp->s2 == 'i')) ||
		(sp->s == 'l' && (sp->s1 == 'd' || sp->s1 == 'i')) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'd' || sp->s2 == 'i')))
	{
		return (ft_put_d(va_arg(ap, long long), sp));
	}
	else if (sp->s == 'f' || sp->s == 'F' ||
			sp->s == 'e' || sp->s == 'E' || (sp->s == 'l' && sp->s1 == 'f'))
			return (ft_put_whole_double(va_arg(ap, double), sp));
	else if ((sp->s == 'L') && (sp->s1 == 'f' || sp->s1 == 'F'))
			return (ft_put_LONG_double(va_arg(ap, long double), sp));
		
	// else if (sp->s == 'F')
	// 	printf("%F\n", va_arg(ap, double));
	// else if (sp->s == 'e')
		// return (ft_putscientific(va_arg(ap, double), sp));
	else if (sp->s == 'c')
		return (ft_putchar_c(va_arg(ap, int), sp));
	else if (sp->s == 'p')
		return (ft_put_p(va_arg(ap, long), sp));
	else if (sp->s == 's')
		return(ft_put_string(va_arg(ap, char *), sp));
	else if (sp->s == '%')
		return (ft_put_percentage(sp));
	else if (sp->s == 'V')
		return (ft_memory_float(va_arg(ap, double), sp));
	else if (sp->s == 'W')
		return (ft_memory_LDBL(va_arg(ap, long double), sp));
	// else
		// ft_putstr("Could not process specifier_");
		// ft_putstr("Could not process specifier_");
	return (0);
}


int     ft_printf(char *fmt, ...)
{
	va_list ap;
	char *p;
	int ret;
	char *s;
	char *lett;
	t_s *sp;


	sp = (t_s *)malloc(sizeof(t_s));
	va_start(ap, fmt);
	p = fmt;
	ret = 0;
	while (*p)
	{
		if (*p == '%')
		{
			if ((s = parse_sier(p + 1, sp)))
			{
				// print_sp(sp);
				//вызываем обработчик спарсенного
				//printf(" ret bef = %d \n", ret);
				ret += process_specifier(p + 1, sp, ap);
				//printf(" ret = %d \n", ret);
				if (sp->s1)
				{
					if (sp->s2)
						p = s + 3;
					else
						p = s + 2;
				}
				else
					p = s + 1;
				continue;
			}
			// else
			// {
			// 	ft_putstr("error");
			// 	return (-1);
			// }
		}
		else
		{
			ft_putchar(*p);
			ret++;
		}
		p++;
	}
	free(sp);
	va_end(ap);
	return (ret);
}
