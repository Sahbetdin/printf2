#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned int uint;

typedef union
{
    float f;
    struct {
        uint mantissa: 23;
        uint exponent: 8;
        uint sign: 1; 
    } parts;
} float_cast;

void    print_int(uint *s, int n)
{
    int i;
    char u;

    i = 0;
    while (i < n)
    {
        u = (char )(s[i] + 48);
        write(1, &u, 1);
        i++;
        if (i % 4 == 0)
            write(1, " ", 1);
    }
}

int main(void)
{
    float numb;
    float_cast d1;
    uint mant;
    uint exp;
    uint exp_2; //2 ^ exp;
    uint sign;
    uint *s;
    int i;
    int n;
    int x;

    d1.f = 263.3;
    sign = d1.parts.sign;
    exp = d1.parts.exponent - 127;
    mant = d1.parts.mantissa;
    n = 100;
    s = (uint *)malloc(sizeof(uint) * n);
    i = -1;
    while (++i)
        s[i] = 0;

    x = 127;
    i = 0;
    while (x)
    {
        s[i] = x % 10;
        x /= 10;
        i++;
    }
    print_int(s, n);
//научиться складывать число в длинную арифметику
//научиться умножать число в длинную арифметику

    // exp_2 = (1 << 28) * 9;
    // printf("%u\n", exp_2);
    // printf("%u\n", mant);

    free(s);
    return (0);
}