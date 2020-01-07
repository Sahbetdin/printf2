#include <stdio.h>

typedef unsigned char uchar;
typedef unsigned int uint;

typedef union
{
	double dbl;
	struct {
		long mantissa: 52;
		uint exponent: 11;
		uchar sign: 1;
	} parts;
} u_double;


void print_union(u_double *num_u)
{
	printf("%u\n", num_u->parts.exponent); 
	printf("%ld\n", num_u->parts.mantissa); 
	printf("%.15f\n", num_u->dbl); 
}

int main()
{
	u_double num;
	double x;

	x = 1234.23522222;
	num.dbl = x;
	print_union(&num);
	return (0);
}