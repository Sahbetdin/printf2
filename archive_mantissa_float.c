#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef unsigned int uint;

typedef union
{
	double long f;
	struct {
		__uint128_t mantissa: 112;
		uint exponent: 8;
		uint sign: 1; 
	} parts;
} double_cast;


int main(void)
{
	double_cast d1;

	d1.f = 263.3;
	printf("%zu\n", d1.parts.mantissa);






	// printf("%u\n", exp);
	// printf("%u\n", mant);

	return (0);
}