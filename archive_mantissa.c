#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned int uint;
typedef unsigned char uchar;


typedef union
{
	long double ld;
	struct {
		uchar mantissa[14]: 112;
		uchar exponent[2]: 15;
		uchar sign: 1;
	} parts;
} ld_cast;

int main(void)
{
	float numb;
	ld_cast d1;
	uint mant;
	uint exp;
	uint sign;


	d1.ld = 263.3;
	sign = d1.parts.sign;
	exp = d1.parts.exponent;
	mant = d1.parts.mantissa;

	// printf("%u\n", exp);
	// printf("%u\n", mant);

	return (0);
}