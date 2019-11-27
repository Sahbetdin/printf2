#include "test_header.h"


/* При поиске % мы можем пропускать числа, точку, пробел и таб.
Иначе если находим %, возвращаем указатель.
Иначе возвращаем НУЛЬ.
*/

// char *find_spec(char *p, t_specif *sp)
// {
// 	char *tmp;
// 	char *lett;

// 	lett = ft_strdup("diuoxXfFeEgGaAcspn%");

// 	while (*p)
// 	{
// 		if (*p == ' ' || *p == '\t' || *p == '.' || (*p >= '0' && *p <= '9'))
// 			p++;
// 		else if ((tmp = ft_strchr(lett, *p)))
// 		{
// 			printf("WAS ");
// 			sp->specif = *p;
// 			return (p);
// 		}
// 		else
// 			return (NULL);
// 		p++;
// 	}
// 	free(lett);
// 	return (NULL);
// }

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

void	clear_spec(t_specif *sp)
{
	sp->specif = '\0';
	sp->zero = 0;
	sp->point = 0;
	sp->numb = 0;
	sp->decim = 0;
	sp->sign = 0;
	return ;
}

void print_sp(t_specif *sp)
{
	printf("spec: %c\n", sp->specif);
	printf("zero: %d\n", sp->zero);
	printf("point: %d\n", sp->point);
	printf("numb: %d\n", sp->numb);
	printf("decim: %d\n", sp->decim);
	printf("plus: %d\n", sp->plus);
	printf("minus: %d\n\n", sp->minus);
	return ;
}


/*we search between p and s-1 */
/*we search before any letter or  */
char *set_zero(char *p, char *s, t_specif *sp)
{	
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '+' || *p == '-' || *p == '#')
//!!проверить, надо ли ПРПУСКАТЬ #!!!
 			p++;
		else if (*p == '0')
		{
			sp->zero = *p;
			return (p); 
		}
		else
			return (NULL);
	}
	return (NULL);
}

char *set_sign(char *p, char *s, t_specif *sp)
{
	char *ptr;
	int flag;

	ptr = p;
	//проверяем, нет ли + и - вместе
	while (ptr < s)
	{
		if (!flag && (*ptr == '+' || *ptr == '-'))
			flag == 1;
		if (flag && (*ptr == '+' || *ptr == '-'))
			return (NULL);
		ptr++;
	}
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || *p == '#')
//!!проверить по оригиналу, надо ли ПРПУСКАТЬ #!!!
 			p++;
		else if (*p == '+' || *p == '-')
		{
			sp->sign = *p;
			return (p); 
		}
		else
			return (NULL);
	}
	return (NULL);
}


/*we search for point after we've searched for letter*/
/*we search between p and s-1 */
/*if found we set sp->point as 1 and return pointer to '.' */
char *set_point(char *p, char *s, t_specif *sp)
{
	while (*p && p < s)
	{
		if (*p == ' ' || *p == '\t' || (*p >= '0' && *p <= '9') 
		|| *p == '+' || *p == '-' || *p == '#')
			p++;
		else if (*p == '.')
		{
			sp->minus = 1;
			return (p);
		}
		else
			return (NULL);
	}
	return (NULL);
}




//сначала ищем букву. Ту , которая нужна
// ищем ноль (done)
// ищем плюс/минус
// ищем numb
// ищем точку (done)
// ищем decimal part

char *parse_specifier(char *p, t_specif *sp)
{
	char *ptr_lett;
	char *ptr_point;
	char *ptr_zero;

	clear_spec(sp);
	if ((ptr_lett = find_spec(p + 1, sp)))
	{
		ptr_zero = set_zero(p + 1, ptr_lett, sp);

	}




		// if ((ptr_p = set_point(p, ptr_lett, sp)))
		// 	//ищем numb
		// 	//ищем decimal part
		// else
		// 	//ищем numb

	return (ptr_lett);
}

int     ft_printf2(char *fmt, ...)
{
	va_list ap;
	char *p;
	int ret;
	char *s;
	char *lett;
	t_specif *sp;

	va_start(ap, fmt);
	p = fmt;
	ret = 0;
	while (*p)
	{
		if (*p == '%')
		{
			if ((s = parse_specifier(p + 1, sp)))
			{
				printf("%c", sp->specif);
				p = s + 1;
			}
//			printf("CH spec: %d\n", sp->specif);
//			s = parse_specifier(p + 1, sp);
//			printf("CH spec: %d\n", sp->specif);
//			printf("YOUR pointer: %p\n", s);
		}
		// else
		// {
		// 	ft_putchar(*p);
		// 	ret++;
		// }
		p++;
	}
	return (0);
}



