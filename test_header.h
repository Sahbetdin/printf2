# ifndef __TEST_HEADER_H__
# define __TEST_HEADER_H__

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


typedef struct s_s
{
	char	s;
	char	s1;
	char	s2;
	int		zero;
	int		point;
	int		numb;
	int		decim;
	int 	plus;
	int 	minus;
	int		backsp;
	char	sign;
	int		hash;
}				t_s;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef union
{
	double dbl;
	struct {
		long mantissa: 52;
		uint exponent: 11;
		uchar sign: 1;
	} parts;
} u_double;

typedef union
{
	long double l_dbl;
	struct {
		long mantissa: 64;
		uint exponent: 15;
		uchar sign: 1;
	} parts;
} u_long_dbl;

typedef struct s_long
{
	uint *whole;
	uint *decimal;
	ulong flag;
} t_long;

int		ft_printf(char *fmt, ...);
int		ft_putchar(char c);
int		ft_putchar_c(char c, t_s *sp);
void	ft_put_zeros_backsp(t_s *sp);
int		ft_put_backsp_str_minus(char *str, t_s *sp);
int		ft_put_backsp_str(char *str, t_s *sp);
size_t	ft_strlen(const char *s);
int		ft_putstr(char const *s);
int		ft_putnbr_positive(int n);
// void	ft_put_sign(long num); ее пока нет
//int		ft_putnbr_u(unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_cut_backspaces(const char *s);
int		ft_atoi(const char *str);
int		ft_atoi2(const char *str, char *end);
int		digits_in_base(long value, int base);
int		digits_in_base_unsigned(ulong u_value, int base);
int		ft_put_whole_double(double a, t_s *sp);
int		ft_putdouble(double a, t_s *sp);
int		ft_putscientific(double a, t_s *sp);
int		ft_putlong(long n);
void	print_sp(t_s *sp);
void	clear_spec(t_s *sp);
char	*find_spec(char *p, t_s *sp);
void	set_zero(char *p, char *s, t_s *sp);
void	set_sign(char *p, char *s, t_s *sp);
char	*set_point(char *p, char *s, t_s *sp);
void	set_numb(char *p, char *s, t_s *sp);
void	set_decimal(char *p, t_s *sp);
void	set_backsp(char *p, char *s, t_s *sp);
void	set_hash(char *p, char *s, t_s *sp);
char	*parse_sier(char *p, t_s *sp);
//int		ft_put_int_min(int num, t_s *sp);
int		ft_put_int_min_with_spec(int num, t_s *sp);
void	ft_put_long_long(long long num);
int		abs_v(int num);
int		ft_itoa_base_unsigned(ulong u_value, int base, int lett_type);
void	ft_put_n_chars(char c, int n);
int		ft_put_percentage(t_s *sp);
int		ft_put_parsed_integer_u(uint num, t_s *sp);
int		ft_put_integer_u(ulong u_value, t_s *sp);
int		ft_put_string(char *str, t_s *sp);
int		ft_put_d(long long num, t_s *sp);
int		ft_put_d_withOUT_numb_point(long long num, t_s *sp);
int		ft_put_d_with_numb_point(long long num, t_s *sp, int dig);
int		ft_put_x_o(ulong num, t_s *sp);
int	ft_put_prelimenaries(ulong num, t_s *sp);
//f, F, Lf, e, E
void	print_memory(uint *s);
int		print_double_whole_part(uint *s);
int		print_double_decimal_part(uint *s, int n);
uint	*power_of_2(uint pow, int n);
uint	*divide_by_2(uint *s);
uint	*divide_by_minus_2(uint *s, int n);
uint	*add_arithmetics(uint *a, uint *b);
uint	*set_arithmetic_zeros(int n);
uint	*add_arithmetics_minus(uint *a, uint *b);
uint	*set_whole_part(u_double *N);
void	normalize(uint *a, uint *s, int dig);
int		put_double_NEW(double x, t_s *sp);
int		ft_put_LONG_double(long double x, t_s *sp);
void	free_long_arithm(t_long *lng);
int		ft_put_whole_double(double a, t_s *sp);
int		ft_put_f_double(double a, t_s *sp);
t_long *create_long(double x, t_s *sp);
int		ft_put_whole_sci(double x, t_s *sp);
//help functions
void	print_binary_uint(uint num, int dig);
void	print_binary_ulong(ulong num, int dig);

//inf
int		put_inf(t_s *sp);
int		put_DLNG_inf(t_s *sp);
int		check_double_inf(double a, t_s *sp);
int		check_DLNG_inf(u_long_dbl *num_DBL, t_s *sp);
//p
int		ft_put_p(long num, t_s *sp);
//e
void ft_put_exp(t_s *sp, int dig);
int ft_put_exp_value(int exp_);
void normalize_sci(uint *s, int d);
uint *create_one_array_e(t_long *lng);
int ft_find_exp(t_long *lng);
void ft_fill_in_one_arr_e(uint *arr, t_long *lng, int j);
int ft_put_value_in_e(uint *arr, t_s *sp, int j);
int ft_put_e_zero(t_s *sp);
int ft_put_sci(double x, t_s *sp);
int ft_dig_db(double a);
int ft_get_k_for_e(double x, t_s *sp);
int ft_put_whole_sci(double x, t_s *sp);


//Le
int ft_put_sci_LDBL(long double x, t_s *sp);
int ft_dig_LONG(long double a);
int ft_get_k_for_e_LDBL(long double x, t_s *sp);
int ft_put_whole_sci_LDBL(long double x, t_s *sp);

t_long	*ft_create_LONG_pre(u_long_dbl *num_DBL);
t_long	*ft_create_LONG_whole(u_long_dbl *num_DBL);
int ft_create_n_temp(uint exp_, int d);
uint *ft_create_b_temp(uint exp_, int d, int n);
void	ft_create_LONG_decimal(t_long *lng2, u_long_dbl *num_DBL, int d);
int		ft_put_LONG_only(u_long_dbl *num_DBL, t_s *sp);
int ft_dig_LDBL(long double a);
void	ft_put_from_specif_LDBL_minus(u_long_dbl *num_DBL, t_s *sp, int k);
void	ft_put_from_specif_LDBL(u_long_dbl *num_DBL, t_s *sp, int k);
int		ft_put_LONG_double(long double x, t_s *sp);

//sign
void	ft_put_sign(t_s *sp);
//memory print
int		ft_memory_float(double a, t_s *sp);
int		ft_memory_LDBL(long double a, t_s *sp);

#endif
