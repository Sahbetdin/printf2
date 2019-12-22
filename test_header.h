# ifndef __TEST_HEADER_H__
# define __TEST_HEADER_H__

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


typedef struct s_specif
{
	char	specif;
	char	specif1;
	char	specif2;
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
typedef unsigned long ulong;

int		ft_putchar(char c);
int		ft_putchar_c(char c, t_specif *sp);
void	ft_put_zeros_backsp(t_specif *sp);
int		ft_put_backsp_str_minus(char *str, t_specif *sp);
int		ft_put_backsp_str(char *str, t_specif *sp);
size_t	ft_strlen(const char *s);
int		ft_putstr(char const *s);
int		ft_putnbr_positive(int n);
void	ft_put_sign(int num);
//int		ft_putnbr_u(unsigned int n);
char	*ft_strchr(const char *s, int c);
int		ft_printf(char *fmt, ...);
char	*ft_strdup(const char *s1);
int		ft_cut_backspaces(const char *s);
int		ft_atoi(const char *str);
int		ft_atoi2(const char *str, char *end);
int		digits_in_base(long long value, int base); //потом оставить long 
int		digits_in_base_unsigned(ulong u_value, int base);
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
int		ft_put_int_min(int num, t_specif *sp);
void	ft_put_long_long(long long num);
int		abs_v(int num);
int		ft_itoa_base_unsigned(ulong u_value, int base, int lett_type);
void	ft_put_n_chars(char c, int n);
int		ft_put_percentage(t_specif *sp);
int		ft_put_parsed_integer_u(uint num, t_specif *sp);
int		ft_put_integer_u(ulong u_value, t_specif *sp);
int		ft_put_string(char *str, t_specif *sp);
int		ft_put_d(long long num, t_specif *sp);
int		ft_put_d_withOUT_numb_point(long long num, t_specif *sp);
int		ft_put_d_with_numb_point(long long num, t_specif *sp, int dig);
int		ft_put_x_o(ulong num, t_specif *sp);
void	ft_put_prelimenaries(long num, t_specif *sp);
#endif