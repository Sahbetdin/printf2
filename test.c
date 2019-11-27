#include <stdio.h>

typedef struct s_point
{
    int x;
    int y;
} t_point;

void clear(t_point *pp)
{
    pp->x = -1;
}

int main()
{
    t_point *p;

    p->x = 5;
    clear(p);

    printf("%d", p->x);
    return (0);
}

/*
char *find_zero(char *p1, char *p2)
{
	while (*p1 && p1 < p2)
	{
		if (*p1 == '0')
			return (p1);
		p1++;
	}
	return (NULL);
}

char *find_plus(char *p1, char *p2)
{
	while (*p1 && p1 < p2)
	{
		if (*p1 == '+')
			return (p1);
		p1++;
	}
	return (NULL);
}


void	parse_perc(char *p1, char *p2)
{
	char *p_zero;
	char *p_plus;
	char *p_minus;
	int numb;

//	printf("%p\n", p1);
//	printf("%p\n", p2);
	p_zero = find_zero(p1, p2);
	p_plus = find_plus(p1, p2);
	p_minus = find_minus(p1, p2);
	numb = ft_atoi2(p1, p2);
//	printf("%c %c\n", *p1, *p2);
//	printf("%p %p %p %d", p_zero, p_plus, p_minus, numb);
	if (numb && p_zero)
	{
		ft_putchar('%');
		while (numb > 1)
		{
			ft_putchar('0');
			numb--;
		}
	}
	else if (numb && p_minus && p_zero)
	{
		while (numb > 1)
		{
			ft_putchar(' ');
			numb--;
		}
		ft_putchar('%');

	}
}


char *find_minus(char *p1, char *p2)
{
	while (*p1 && p1 < p2)
	{
		if (*p1 == '-')
			return (p1);
		p1++;
	}
	return (NULL);
}


*/


