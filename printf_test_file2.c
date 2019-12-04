#include "test_header.h"


//надо сделать oct float!!
int	process_specifier(char *ptr, t_specif *sp, va_list ap)
{
	if (sp->specif == 'd' || sp->specif == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (sp->specif == 'o') //проблема с 0
		return (ft_itoa_base(va_arg(ap, int), 8, 0));
	else if (sp->specif == 'u')
		return (ft_putnbr_u(va_arg(ap, int)));
	else if (sp->specif == 'x')  //проблема с 0
		return (ft_itoa_base(va_arg(ap, int), 16, 0));
	else if (sp->specif == 'X') //проблема с 0 
		return (ft_itoa_base(va_arg(ap, int), 16, 1));
	else if (sp->specif == 'f')
		return (ft_put_whole_double(va_arg(ap, double), sp));
	else if (sp->specif == 'F')
		printf("%F\n", va_arg(ap, double));
	else if (sp->specif == 'e')
		return (ft_putscientific(va_arg(ap, double), sp));
	else if (sp->specif == 'c')
		ft_putchar(va_arg(ap, int));
	else if (sp->specif == 's')
		return(ft_putstr(va_arg(ap, char *)));
	else
		ft_putstr("AnoTher\n");
	return (0);
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
				ret += process_specifier(p + 1, sp, ap);
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
	return (ret);
}
