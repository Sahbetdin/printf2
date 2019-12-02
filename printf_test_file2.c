#include "test_header.h"





void	process_specifier(char *ptr, t_specif *sp, va_list ap)
{
	if (sp->specif == 'd')
		printf("%d\n", va_arg(ap, int));
	else if (sp->specif == 'i')
		printf("%i\n", va_arg(ap, int));
	else if (sp->specif == 'o')
		printf("%o\n", va_arg(ap, int));
	else if (sp->specif == 'u')
		printf("%u\n", va_arg(ap, int)); //should be unsigned decimal
	else if (sp->specif == 'x')
		printf("%x\n", va_arg(ap, int));
	else if (sp->specif == 'X')
		printf("%X\n", va_arg(ap, int));
	else if (sp->specif == 'f')
		ft_put_whole_double(va_arg(ap, double), sp);
	else if (sp->specif == 'F')
		printf("%F\n", va_arg(ap, double));
	else if (sp->specif == 'c')
		ft_putchar(va_arg(ap, int));
	else if (sp->specif == 's')
		ft_putstr(va_arg(ap, char *));
	else
		ft_putstr("AnoTher\n");
	return ;
}


int     ft_printf(char *fmt, ...)
{
	va_list ap;
	char *p;
	int ret;
	char *s;
	char *lett;
	t_specif *sp;


	sp = (t_specif *)malloc(sizeof(t_specif));
	va_start(ap, fmt);
	p = fmt;
	ret = 0;
	while (*p)
	{
		if (*p == '%')
		{
			if ((s = parse_specifier(p + 1, sp)))
			{
			//	print_sp(sp);
				//вызываем обработчик спарсенного
				process_specifier(p + 1, sp, ap);
				p = s + 1;
				continue;
			}
			else
			{
				ft_putstr("error");
				return (-1);
			}
		}
		else
		{
			ft_putchar(*p);
			ret++;
		}
		p++;
	}
	free(sp);
	return (0);
}





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



