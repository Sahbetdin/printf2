#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() { 
	// printf("%lu\n", sizeof(float)); // some compilers print 8
	// printf("%lu\n", sizeof(double)); // some compilers print 8
	// printf("%lu\n", sizeof(long double)); // some compilers print 8


    printf("%lu\n", sizeof(int)); // some compilers print 16
    printf("%lu\n", sizeof(long)); // some compilers print 16
    // printf("%lu\n", sizeof(unsigned long long)); // some compilers print 16

    return 0;
}