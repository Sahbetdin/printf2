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
	int 	plus;
	int 	minus;
	int		backsp;
	char	sign;
	int		hash;
}				t_specif;
typedef unsigned int uint;

int		ft_putchar(char c);
int		ft_putchar_c(char c, t_specif *sp);
void	ft_put_zeros_backsp(t_specif *sp);
int		ft_put_backsp_str_minus(char *str, t_specif *sp);
int		ft_put_backsp_str(char *str, t_specif *sp);
size_t	ft_strlen(const char *s);
int		ft_putstr(char const *s);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
char	*ft_strchr(const char *s, int c);
int		ft_printf(char *fmt, ...);
char	*ft_strdup(const char *s1);
int		ft_cut_backspaces(const char *s);
int		ft_atoi(const char *str);
int		ft_atoi2(const char *str, char *end);
int		digits_in_base(int value, int base);
int 	digits_in_base_unsigned(uint u_value, int base);
int		ft_put_whole_double(double a, t_specif *sp);
int		ft_putdouble(double a, t_specif *sp);
int		ft_putscientific(double a, t_specif *sp);
int		ft_putlong(long n);
void	print_sp(t_specif *sp);
void	clear_spec(t_specif *sp);
char	*find_spec(char *p, t_specif *sp);
void	set_zero(char *p, char *s, t_specif *sp);
void	set_sign(char *p, char *s, t_specif *sp);
char	*set_point(char *p, char *s, t_specif *sp);
void	set_numb(char *p, char *s, t_specif *sp);
void	set_decimal(char *p, t_specif *sp);
void	set_backsp(char *p, char *s, t_specif *sp);
void	set_hash(char *p, char *s, t_specif *sp);
char	*parse_specifier(char *p, t_specif *sp);

int		abs_v(int num);
//int		ft_itoa_base(int value, int base, int lett_type);
int		ft_itoa_base_unsigned(uint u_value, int base, int lett_type);

void	ft_put_n_chars(char c, int n);
int		ft_put_percentage(t_specif *sp);
int		ft_put_parsed_integer_u(uint num, t_specif *sp);
int		ft_put_integer_u(uint u_value, t_specif *sp);
int		ft_put_string(char *str, t_specif *sp);
#endif