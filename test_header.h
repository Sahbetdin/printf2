# ifndef __TEST_HEADER_H__
# define __TEST_HEADER_H__

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_specif
{
	char	specif;
	int		zero;
	int		point;
	int		numb;
	int		decim;
	char 	sign;
}				t_specif;


int		ft_putchar(char c);
size_t	ft_strlen(const char *s);
int		ft_putstr(char const *s);
int		ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);
int     ft_printf(char *fmt, ...);
int     ft_printf2(char *fmt, ...);
char	*ft_strdup(const char *s1);
int     ft_cut_backspaces(const char *s);
int		ft_atoi(const char *str);
int		ft_atoi2(const char *str, char *end);
int     digits_in_base(int value, int base);
int    ft_putdouble(double a, int prec);
int     ft_putlong(long n);
int		ft_isspace(char c);
int		ft_isspace2(char *p1, char *p2);
#endif
