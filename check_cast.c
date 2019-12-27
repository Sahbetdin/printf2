//check casting
//23rd Dec2019
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long ulong;


typedef union
{
	double dbl;
	struct {
		// uchar a1: 8;
		// uchar a2: 8;
		// uchar a3: 8;
		// uchar a4: 8;
		// uchar a5: 8;
		// uchar a6: 8;
		// uchar a7: 8;
		// uchar a8: 8;
		// uint s1: 32;
		// uint s2: 32;
		// uint mant1: 32;
		// uchar sign: 1;
		// uint exp: 10;
		// ulong m: 64;
		ulong mantissa: 52;
		ulong exponent: 11;
		ulong sign: 1;
	} parts;
} u_double;



int main()
{
	u_double num;
	double x;

	ulong m;
	ulong e;
	ulong s;
	ulong flag;

	//x = -1.500030517578125;
	//x = 2.500030517578125;
	x= 2;
	num.dbl = x;

	// printf("sign = %hhu\n", num.parts.sign);
	// printf("a3 = %d\n", num.parts.a3);
	// printf("a4 = %d\n", num.parts.a4);
	// printf("a5 = %d\n", num.parts.a5);
	// printf("a6 = %d\n", num.parts.a6);
	// printf("a7 = %d\n", num.parts.a7);
	// printf("a8 = %d\n", num.parts.a8);


	// m = num.parts.mantissa;
	// e = num.parts.exponent;
	// s = num.parts.sign;
	m = num.parts.mantissa;
	e = num.parts.exponent;
	s = num.parts.sign;
	printf("s3 = %lu\n", s);
	printf("s2 = %lu\n", e);
	printf("s1 = %lu\n", m);
	// flag = 1UL << 35;
	// printf("flag = %lu\n", flag);
//101 10111000 01010001 11101010 10101110 01011111 00100011


//m = 1110 1010 1010 1110 0101 1111 0010 0011
//e = 0100 0000 0100 0101 1011 1000 0101 0001

//у них:
// 0100 0000 0100 0101 1011 1000 0101 0001
// 1110 1010 1010 1110 0101 1111 0010 0011






	return (0);
}
