#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *tmp;
    //printf("% 0   7.3f", 5.542);
//    printf("%  0 9.3f", 56.54562);
//    printf("%               0.50%");

    tmp = ft_strchr("diuoxXfFeEgGaAcspn%", 'd');
    printf("%p", tmp);

    return (0);
}