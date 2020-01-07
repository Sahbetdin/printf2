#include "test_header.h"

void	print_memory(uint *s)
{
	int i;
	char u;

	ft_putnbr_positive(s[0]);
	write(1, " ", 1);
	i = 1;
	while (i <= s[0])
	{
		u = (char )(s[i] + 48);
		write(1, &u, 1);
		i++;
		if (i % 4 == 1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int print_double_whole_part(uint *s)
{
	int i;
	int count;
	char u;

	i = s[0];
	count = 0;
	while (i && s[i] == 0)
		i--;
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (i > 0)
	{
		u = (char)s[i] + '0';
		write(1, &u, 1);
		count++;
		i--;
	}
	return (count);
}

//можно сделать void
int print_double_decimal_part(uint *s, int n)
{
	unsigned char u;
	int i;

	// write(1, "PP", 2);
	i = 1;
	while (i <= n)
	{
		u = (unsigned char)s[i] + '0';
		write(1, &u, 1);
		i++;
	}
	return (n);
}


void print_binary_uint(uint num)
{
	uint flag;
	int count;
	count = 0;

	flag = 1 << 31;
	while (flag && count < 40)
	{
		if (flag & num)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		// printf("flag = %u\n", flag);
		// count++;
		flag = flag >> 1;

		// printf("flag = %u\n", flag);
		// count++;
		// flag = flag >> 1;

	}
	write(1, "\n", 1);
}


void print_binary_ulong(ulong num)
{
	ulong flag;

	flag = 1LU << 63;
	while (flag)
	{
		if (flag & num)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		flag = flag >> 1;
	}
	write(1, "\n", 1);
}
