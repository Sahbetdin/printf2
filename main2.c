#include "test_header.h"

int main()
{

	int c1, c2, c3, c4, c5, c6, n;
    unsigned int kl;
    char z;
    long zz;

//	char str[] = "goingGLOB";
	// printf("%+-5dA\n", 543);
	// printf("%+-5dA\n", -543);
//	printf("% 05dA\n", -536);
//	printf("% 05dA\n", 0);

    // kl = 4294967254;
    // n = digits_in_base_unsigned(kl, 16);
    // printf("dig = %d ", n);
     c1 = printf("%lldA\n", -9223372036854775808);
  c2 = ft_printf("%lldA\n", -9223372036854775808);
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