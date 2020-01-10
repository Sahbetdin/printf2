#include <unistd.h>
#include <stdio.h>
#include <limits.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_put_long_long_positive(unsigned long long num)
{
	unsigned long long c;
	unsigned long long m;
	int i;
	int dig;

	m = num;
	i = 0;
	c = 1;

	while (m > 9)
	{
		m /= 10;
		c *= 10;
		i++;
	}
	while (i >= 0)
	{
		dig = num / c;
		ft_putchar(dig + '0');
		num -= dig * c;
		c /= 10;
		i--;
	}
	return ;
}




int main()
{
	unsigned long long x;
	short y;

	x = 9223372;
	y = (short)x;
	
	ft_put_long_long_positive(y);
	return (0);
}