#include "test_header.h"


int main()
{

	int c1, c2, c3, c4, c5, c6, n;
    unsigned int kl;
    char z;
    long zz;
    char a01;
    unsigned char a02;
    short a03;
    unsigned short a04;
    int a05;
    unsigned int a06;
    long a07;
    unsigned long a08;
    long long a09;
    unsigned long long a10;
    char *a11;
    void *a12;

//	char str[] = "goingGLOB";
	// printf("%+-5dA\n", 543);
	// printf("%+-5dA\n", -543);
//	printf("% 05dA\n", -536);
//	printf("% 05dA\n", 0);

    // kl = 4294967254;
    // n = digits_in_base_unsigned(kl, 16);
    // printf("dig = %d ", n);
    // c1 = printf("%.400fA\n", 0.1243741999999e-306);
    // c1 = printf("%.400fA\n", 0.1243741999999e-306);
c1  =    printf("%+15.4eA\n", 0.12323429999999999999e-4);
c2  = ft_printf("%+15.4eA\n", 0.12323429999999999999e-4);


//9.99999999999 ПРОБЛЕМА!!!!

       // 2.3499999 432569567
//     c1 = printf("%e\n", 23499999.432569567);
// c2  = ft_printf("%e\n", 23499999.432569567);
        // c1 = printf("%e\n", 0.012879);

// 9999943 2000000000
// 43256956700000000
  // c2 = ft_printf("%16p%16p%16p%16p\n", &c1, &c2, &c3, &c4);
  // c2 = ft_printf("%16p%16p%16p%16p\n", &c1, &c2, &c3, &c4);
   //    c3 = printf("%08dA\n", -536);
   // c4 = ft_printf("%08dA\n", -536);
   //    c5 = printf("%08dA\n", 0);
   // c6 = ft_printf("%08dA\n", 0);

// printf("c1 = %d\n", c1);
printf("c1 = %d, c2 = %d; diff = %d\n", c1, c2, c1 - c2);
// printf("c3 = %d, c4 = %d; diff = %d\n", c3, c4, c3 - c4);
// printf("c5 = %d, c6 = %d; diff = %d\n", c5, c6, c5 - c6);

    return (0);
}